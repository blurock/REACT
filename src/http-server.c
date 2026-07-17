/*
 * Minimal HTTP wrapper for REACT/chemdb.
 *
 * Supported endpoints:
 *   GET  /           - API summary
 *   GET  /health     - Health check
 *   POST /api/run    - Execute chemdb with JSON body: {"args":["--help"]}
 */

#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define MAX_ARGS 32
#define MAX_REQUEST_SIZE (1024 * 1024)
#define READ_CHUNK 4096

static volatile sig_atomic_t keep_running = 1;

static void handle_signal(int signum)
{
    (void) signum;
    keep_running = 0;
}

static const char *status_text(int status)
{
    switch (status) {
    case 200:
        return "OK";
    case 400:
        return "Bad Request";
    case 404:
        return "Not Found";
    case 405:
        return "Method Not Allowed";
    case 500:
        return "Internal Server Error";
    default:
        return "OK";
    }
}

static int send_all(int fd, const char *buffer, size_t length)
{
    size_t written = 0;

    while (written < length) {
        ssize_t current = write(fd, buffer + written, length - written);
        if (current < 0) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }
        written += (size_t) current;
    }

    return 0;
}

static int send_response(int fd, int status, const char *content_type, const char *body)
{
    char header[512];
    size_t body_length = strlen(body);
    int header_length;

    header_length = snprintf(
        header,
        sizeof(header),
        "HTTP/1.1 %d %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n",
        status,
        status_text(status),
        content_type,
        body_length);

    if (header_length < 0 || (size_t) header_length >= sizeof(header)) {
        return -1;
    }

    if (send_all(fd, header, (size_t) header_length) != 0) {
        return -1;
    }

    return send_all(fd, body, body_length);
}

static char *json_escape(const char *input)
{
    size_t length = 0;
    size_t i;
    char *output;
    char *cursor;

    for (i = 0; input[i] != '\0'; ++i) {
        switch (input[i]) {
        case '\\':
        case '"':
            length += 2;
            break;
        case '\n':
        case '\r':
        case '\t':
            length += 2;
            break;
        default:
            if ((unsigned char) input[i] < 0x20) {
                length += 6;
            } else {
                length += 1;
            }
            break;
        }
    }

    output = (char *) malloc(length + 1);
    if (output == NULL) {
        return NULL;
    }

    cursor = output;
    for (i = 0; input[i] != '\0'; ++i) {
        switch (input[i]) {
        case '\\':
            *cursor++ = '\\';
            *cursor++ = '\\';
            break;
        case '"':
            *cursor++ = '\\';
            *cursor++ = '"';
            break;
        case '\n':
            *cursor++ = '\\';
            *cursor++ = 'n';
            break;
        case '\r':
            *cursor++ = '\\';
            *cursor++ = 'r';
            break;
        case '\t':
            *cursor++ = '\\';
            *cursor++ = 't';
            break;
        default:
            if ((unsigned char) input[i] < 0x20) {
                cursor += sprintf(cursor, "\\u%04x", (unsigned char) input[i]);
            } else {
                *cursor++ = input[i];
            }
            break;
        }
    }

    *cursor = '\0';
    return output;
}

static char *build_json_message(const char *template_text, ...)
{
    va_list arguments;
    va_list arguments_copy;
    int length;
    char *message;

    va_start(arguments, template_text);
    va_copy(arguments_copy, arguments);
    length = vsnprintf(NULL, 0, template_text, arguments_copy);
    va_end(arguments_copy);

    if (length < 0) {
        va_end(arguments);
        return NULL;
    }

    message = (char *) malloc((size_t) length + 1);
    if (message == NULL) {
        va_end(arguments);
        return NULL;
    }

    vsnprintf(message, (size_t) length + 1, template_text, arguments);
    va_end(arguments);
    return message;
}

static int find_header_end(const char *buffer, size_t length, size_t *header_end)
{
    size_t i;

    if (length < 4) {
        return 0;
    }

    for (i = 0; i + 3 < length; ++i) {
        if (buffer[i] == '\r' && buffer[i + 1] == '\n' &&
            buffer[i + 2] == '\r' && buffer[i + 3] == '\n') {
            *header_end = i + 4;
            return 1;
        }
    }

    return 0;
}

static char *find_header_value(char *headers, const char *name)
{
    size_t name_length = strlen(name);
    char *line = headers;

    while (line != NULL && *line != '\0') {
        char *next = strstr(line, "\r\n");
        if (next != NULL) {
            *next = '\0';
        }

        if (strncasecmp(line, name, name_length) == 0 && line[name_length] == ':') {
            char *value = line + name_length + 1;
            while (*value != '\0' && isspace((unsigned char) *value)) {
                ++value;
            }
            if (next != NULL) {
                *next = '\r';
            }
            return value;
        }

        if (next == NULL) {
            break;
        }

        *next = '\r';
        line = next + 2;
    }

    return NULL;
}

static int read_request(int fd, char **request, size_t *request_length, size_t *header_end)
{
    char *buffer = NULL;
    size_t capacity = 0;
    size_t total = 0;
    size_t end = 0;
    size_t expected_length = 0;
    int have_headers = 0;

    while (total < MAX_REQUEST_SIZE) {
        ssize_t current;

        if (capacity - total < READ_CHUNK) {
            size_t next_capacity = capacity == 0 ? READ_CHUNK * 2 : capacity * 2;
            char *next_buffer = (char *) realloc(buffer, next_capacity);
            if (next_buffer == NULL) {
                free(buffer);
                return -1;
            }
            buffer = next_buffer;
            capacity = next_capacity;
        }

        current = read(fd, buffer + total, capacity - total);
        if (current < 0) {
            if (errno == EINTR) {
                continue;
            }
            free(buffer);
            return -1;
        }
        if (current == 0) {
            break;
        }

        total += (size_t) current;

        if (!have_headers && find_header_end(buffer, total, &end)) {
            char saved;
            char *headers;
            char *value;

            have_headers = 1;
            headers = buffer;
            saved = headers[end - 2];
            headers[end - 2] = '\0';
            value = find_header_value(headers, "Content-Length");
            if (value != NULL) {
                expected_length = end + (size_t) strtoul(value, NULL, 10);
            } else {
                expected_length = end;
            }
            headers[end - 2] = saved;
        }

        if (have_headers && total >= expected_length) {
            break;
        }
    }

    if (!have_headers) {
        free(buffer);
        return -1;
    }

    if (total == capacity) {
        char *next_buffer = (char *) realloc(buffer, capacity + 1);
        if (next_buffer == NULL) {
            free(buffer);
            return -1;
        }
        buffer = next_buffer;
    }

    buffer[total] = '\0';
    *request = buffer;
    *request_length = total;
    *header_end = end;
    return 0;
}

static void skip_whitespace(const char **cursor)
{
    while (**cursor != '\0' && isspace((unsigned char) **cursor)) {
        ++(*cursor);
    }
}

static char *parse_json_string(const char **cursor)
{
    const char *input = *cursor;
    size_t capacity = 64;
    size_t length = 0;
    char *output;

    if (*input != '"') {
        return NULL;
    }
    ++input;

    output = (char *) malloc(capacity);
    if (output == NULL) {
        return NULL;
    }

    while (*input != '\0' && *input != '"') {
        char value;

        if (length + 2 > capacity) {
            char *next_output;
            capacity *= 2;
            next_output = (char *) realloc(output, capacity);
            if (next_output == NULL) {
                free(output);
                return NULL;
            }
            output = next_output;
        }

        if (*input == '\\') {
            ++input;
            switch (*input) {
            case '"':
            case '\\':
            case '/':
                value = *input;
                break;
            case 'b':
                value = '\b';
                break;
            case 'f':
                value = '\f';
                break;
            case 'n':
                value = '\n';
                break;
            case 'r':
                value = '\r';
                break;
            case 't':
                value = '\t';
                break;
            default:
                free(output);
                return NULL;
            }
        } else {
            value = *input;
        }

        output[length++] = value;
        ++input;
    }

    if (*input != '"') {
        free(output);
        return NULL;
    }

    output[length] = '\0';
    *cursor = input + 1;
    return output;
}

static int parse_args_array(const char *body, char **args, int *arg_count)
{
    const char *args_key = strstr(body, "\"args\"");
    const char *cursor;
    int count = 0;

    if (args_key == NULL) {
        return -1;
    }

    cursor = strchr(args_key, ':');
    if (cursor == NULL) {
        return -1;
    }
    ++cursor;
    skip_whitespace(&cursor);

    if (*cursor != '[') {
        return -1;
    }
    ++cursor;

    for (;;) {
        skip_whitespace(&cursor);

        if (*cursor == ']') {
            ++cursor;
            break;
        }

        if (count >= MAX_ARGS) {
            return -1;
        }

        args[count] = parse_json_string(&cursor);
        if (args[count] == NULL) {
            return -1;
        }
        ++count;

        skip_whitespace(&cursor);
        if (*cursor == ',') {
            ++cursor;
            continue;
        }
        if (*cursor == ']') {
            ++cursor;
            break;
        }
        return -1;
    }

    *arg_count = count;
    return count > 0 ? 0 : -1;
}

static void free_args(char **args, int arg_count)
{
    int i;
    for (i = 0; i < arg_count; ++i) {
        free(args[i]);
    }
}

static int run_chemdb(char **args, int arg_count, char **output, int *exit_code)
{
    const char *reactroot = getenv("REACTROOT");
    char path_buffer[1024];
    char **argv;
    int pipefd[2];
    pid_t child;
    size_t capacity = READ_CHUNK;
    size_t used = 0;
    char *buffer;
    int i;
    int status = 0;

    if (reactroot == NULL || *reactroot == '\0') {
        reactroot = "/opt/react";
    }

    if (snprintf(path_buffer, sizeof(path_buffer), "%s/bin/chemdb", reactroot) >= (int) sizeof(path_buffer)) {
        return -1;
    }

    argv = (char **) calloc((size_t) arg_count + 2, sizeof(char *));
    if (argv == NULL) {
        return -1;
    }

    argv[0] = path_buffer;
    for (i = 0; i < arg_count; ++i) {
        argv[i + 1] = args[i];
    }
    argv[arg_count + 1] = NULL;

    if (pipe(pipefd) != 0) {
        free(argv);
        return -1;
    }

    child = fork();
    if (child < 0) {
        close(pipefd[0]);
        close(pipefd[1]);
        free(argv);
        return -1;
    }

    if (child == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execv(path_buffer, argv);
        perror("execv");
        _exit(127);
    }

    close(pipefd[1]);
    free(argv);

    buffer = (char *) malloc(capacity);
    if (buffer == NULL) {
        close(pipefd[0]);
        waitpid(child, &status, 0);
        return -1;
    }

    for (;;) {
        ssize_t current;

        if (used + READ_CHUNK + 1 > capacity) {
            char *next_buffer;
            capacity *= 2;
            next_buffer = (char *) realloc(buffer, capacity);
            if (next_buffer == NULL) {
                free(buffer);
                close(pipefd[0]);
                waitpid(child, &status, 0);
                return -1;
            }
            buffer = next_buffer;
        }

        current = read(pipefd[0], buffer + used, capacity - used - 1);
        if (current < 0) {
            if (errno == EINTR) {
                continue;
            }
            free(buffer);
            close(pipefd[0]);
            waitpid(child, &status, 0);
            return -1;
        }
        if (current == 0) {
            break;
        }
        used += (size_t) current;
    }

    close(pipefd[0]);
    waitpid(child, &status, 0);

    buffer[used] = '\0';
    *output = buffer;
    if (WIFEXITED(status)) {
        *exit_code = WEXITSTATUS(status);
    } else {
        *exit_code = 1;
    }

    return 0;
}

static int create_server_socket(int port)
{
    int server_fd;
    int enable = 1;
    struct sockaddr_in address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        return -1;
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons((unsigned short) port);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) != 0) {
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 16) != 0) {
        close(server_fd);
        return -1;
    }

    return server_fd;
}

static int handle_run_request(int client_fd, const char *body)
{
    char *args[MAX_ARGS];
    int arg_count = 0;
    char *command_output = NULL;
    char *escaped_output = NULL;
    char *response = NULL;
    int exit_code = 1;
    int i;

    for (i = 0; i < MAX_ARGS; ++i) {
        args[i] = NULL;
    }

    if (parse_args_array(body, args, &arg_count) != 0) {
        return send_response(
            client_fd,
            400,
            "application/json",
            "{\"error\":\"Request body must be JSON with a non-empty args array, for example {\\\"args\\\":[\\\"--help\\\"]}.\"}");
    }

    if (run_chemdb(args, arg_count, &command_output, &exit_code) != 0) {
        free_args(args, arg_count);
        return send_response(
            client_fd,
            500,
            "application/json",
            "{\"error\":\"Unable to execute chemdb.\"}");
    }

    escaped_output = json_escape(command_output);
    if (escaped_output == NULL) {
        free(command_output);
        free_args(args, arg_count);
        return send_response(
            client_fd,
            500,
            "application/json",
            "{\"error\":\"Unable to encode chemdb output.\"}");
    }

    response = build_json_message(
        "{\"exitCode\":%d,\"output\":\"%s\"}",
        exit_code,
        escaped_output);

    free(escaped_output);
    free(command_output);
    free_args(args, arg_count);

    if (response == NULL) {
        return send_response(
            client_fd,
            500,
            "application/json",
            "{\"error\":\"Unable to build response.\"}");
    }

    i = send_response(client_fd, 200, "application/json", response);
    free(response);
    return i;
}

static int handle_request(int client_fd)
{
    char *request = NULL;
    size_t request_length = 0;
    size_t header_end = 0;
    char method[16];
    char path[256];
    char *body;
    int result;

    if (read_request(client_fd, &request, &request_length, &header_end) != 0) {
        return send_response(
            client_fd,
            400,
            "application/json",
            "{\"error\":\"Invalid HTTP request.\"}");
    }

    if (sscanf(request, "%15s %255s", method, path) != 2) {
        free(request);
        return send_response(
            client_fd,
            400,
            "application/json",
            "{\"error\":\"Unable to parse request line.\"}");
    }

    body = request + header_end;
    (void) request_length;

    if (strcmp(method, "GET") == 0 && strcmp(path, "/health") == 0) {
        result = send_response(
            client_fd,
            200,
            "application/json",
            "{\"status\":\"ok\",\"service\":\"chemdb\"}");
    } else if (strcmp(method, "GET") == 0 && strcmp(path, "/") == 0) {
        result = send_response(
            client_fd,
            200,
            "application/json",
            "{\"service\":\"chemdb\",\"endpoints\":[\"GET /health\",\"POST /api/run\"],\"example\":{\"args\":[\"--help\"]}}");
    } else if (strcmp(method, "POST") == 0 && strcmp(path, "/api/run") == 0) {
        result = handle_run_request(client_fd, body);
    } else if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        result = send_response(
            client_fd,
            405,
            "application/json",
            "{\"error\":\"Only GET and POST are supported.\"}");
    } else {
        result = send_response(
            client_fd,
            404,
            "application/json",
            "{\"error\":\"Endpoint not found.\"}");
    }

    free(request);
    return result;
}

int main(int argc, char *argv[])
{
    int port = DEFAULT_PORT;
    int server_fd;
    int i;

    for (i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--port") == 0 && i + 1 < argc) {
            port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s [--port PORT]\n", argv[0]);
            return 0;
        }
    }

    if (port <= 0) {
        fprintf(stderr, "Invalid port: %d\n", port);
        return 1;
    }

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    server_fd = create_server_socket(port);
    if (server_fd < 0) {
        perror("create_server_socket");
        return 1;
    }

    printf("chemdb HTTP server listening on port %d\n", port);
    fflush(stdout);

    while (keep_running) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            close(server_fd);
            return 1;
        }

        handle_request(client_fd);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
