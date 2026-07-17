#!/bin/bash
# REACTCloudRun Entrypoint Script
# This script handles both CLI and HTTP modes

set -e

# Default mode
MODE="${1:-cli}"
PORT="${PORT:-8080}"
REACTROOT="${REACTROOT:-/opt/react}"
CCROOT="${CCROOT:-/opt/react}"

export REACTROOT CCROOT

echo "[entrypoint.sh] Starting REACT system..."
echo "[entrypoint.sh] Mode: $MODE"
echo "[entrypoint.sh] Port: $PORT"
echo "[entrypoint.sh] REACTROOT: $REACTROOT"

case "$MODE" in
    http)
        # Start HTTP server mode
        echo "[entrypoint.sh] Starting HTTP server on port $PORT..."
        exec "$REACTROOT/bin/http-server" --port "$PORT"
        ;;
    cli)
        # CLI mode - pass through all arguments to chemdb
        echo "[entrypoint.sh] Starting CLI mode..."
        shift  # Remove mode argument
        exec "$REACTROOT/bin/chemdb" "$@"
        ;;
    *)
        echo "[entrypoint.sh] Unknown mode: $MODE"
        echo "Usage: $0 {cli|http} [args...]"
        exit 1
        ;;
esac
