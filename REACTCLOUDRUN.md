# REACT CloudRun - Chemistry System for Google Cloud Run

A containerized version of the REACT Chemistry System optimized for deployment on Google Cloud Run.

## What is REACT?

REACT is a sophisticated chemistry software system for:
- Molecular structure generation and analysis
- Chemical reaction pathway analysis
- Thermodynamic property calculations
- Database management for chemical compounds

## What is REACTCloudRun?

REACTCloudRun packages the REACT system in a Docker container designed for:
- **Cloud-Native Deployment**: Optimized for Google Cloud Run serverless platform
- **Dual-Mode Operation**: CLI for batch processing or HTTP API for web requests
- **Minimal Dependencies**: Only requires gdbm and standard C libraries
- **Multi-Stage Build**: Optimized image size (~XXX MB - TBD after build)

## Quick Links

- 📖 [Deployment Guide](docs/DEPLOY.md) - Deploy to Cloud Run
- 📋 [Implementation Plan](../../../session-state/96213969-ef5c-47f8-8b14-138695a0c189/files/implementation_plan.md) - Project roadmap
- 📚 [Original REACT Docs](README.md) - Original REACT documentation
- 🔧 [Installation Guide](INSTALL.txt) - Original REACT installation

## Project Structure

```
.
├── Dockerfile              # Multi-stage Docker build
├── docker-compose.yml      # Local development setup
├── .dockerignore           # Files excluded from Docker context
├── src/
│   ├── entrypoint.sh       # Container entry point (CLI/HTTP mode selector)
│   └── http-server.c       # HTTP API wrapper (Phase 4)
├── docs/
│   └── DEPLOY.md           # Cloud Run deployment guide
├── tests/
│   └── README.md           # Test cases and test data
├── bin/                    # Original REACT binaries (built in container)
├── data/                   # Chemistry data files
├── lib/                    # Compiled libraries (built in container)
└── [other REACT directories...]
```

## Getting Started

### 1. Local Development

```bash
# Build and run with Docker Compose
docker-compose build
docker-compose up

# The service will be available at http://localhost:8080
```

### 2. Deploy to Google Cloud Run

See [DEPLOY.md](docs/DEPLOY.md) for detailed Cloud Run deployment instructions.

### 3. Run CLI Commands

```bash
# Get help
docker run reactcloudrun:latest cli --help

# Run a calculation
docker run reactcloudrun:latest cli [options] input.txt
```

## Architecture Overview

### Dual-Mode Entrypoint

The container can run in two modes:

#### 1. CLI Mode (Default)
- Process batch jobs
- Run from command line with arguments
- Suitable for Cloud Tasks, Cloud Scheduler

#### 2. HTTP Mode
- Expose chemistry operations via REST API
- Listen on port 8080
- JSON request/response format
- Suitable for Cloud Run HTTP endpoints

### Container Layers (Multi-Stage Build)

**Build Stage**
- Ubuntu 22.04 base
- Build tools: gcc, make, build-essential
- Development libraries: gdbm-dev, libc6-dev
- Compiles entire REACT system

**Runtime Stage**
- Ubuntu 22.04-slim base
- Only runtime libraries: libc6, libgdbm6
- Copies compiled binaries from build stage
- Final size: ~XXX MB

## External Dependencies

### System Libraries
- C Standard Library (libc) - included in base image
- POSIX System APIs - included in base image  
- RPC/XDR - included in glibc

### Third-Party Libraries
- **GNU DBM (gdbm)** - Database functionality
  - Runtime package: `libgdbm6`
  - Development package: `gdbm-dev` (only in build stage)

## Compilation & Build Status

### Original REACT
- Last compiled: ~12 years ago
- Compiler: GNU cc (gcc)
- Status: Requires modernization for current gcc

### REACTCloudRun Build Process
- **Phase 2** (In Progress): Initial Dockerfile setup
- **Phase 3** (TBD): Update C code for modern compiler
- **Phase 4** (TBD): HTTP server implementation
- **Phase 5** (TBD): Local testing
- **Phase 6** (TBD): Production optimization

## Configuration

### Environment Variables

| Variable | Default | Description |
|----------|---------|-------------|
| `PORT` | 8080 | HTTP server port |
| `REACTROOT` | /opt/react | REACT installation directory |
| `CCROOT` | /opt/react | REACT installation directory |

### Dockerfile Build Args

None currently, but can be added in Phase 6 for optimization.

## Performance Considerations

- **Memory**: Recommend 2 GB minimum for Cloud Run
- **Timeout**: 3600 seconds recommended (1 hour)
- **Concurrency**: Depends on workload, typically 1-10 instances

## Troubleshooting

### Issue: Build fails with compiler errors
**Solution**: Check Phase 3 documentation for C code updates needed

### Issue: Container won't start
**Solution**: Verify entrypoint.sh is executable and check logs

### Issue: HTTP port not responding
**Solution**: Ensure PORT environment variable is set to 8080

See [DEPLOY.md](docs/DEPLOY.md) for more troubleshooting.

## Development Phases

✅ **Phase 1**: Project Setup - Docker structure, .gitignore, initial files
⏳ **Phase 2**: Dockerfile Creation - Multi-stage build
⏳ **Phase 3**: C Code Updates - Fix compiler issues  
⏳ **Phase 4**: Entry Point - HTTP server wrapper
⏳ **Phase 5**: Local Testing - Docker Compose validation
⏳ **Phase 6**: Optimization - Image size, caching

## Contributing

When working on REACTCloudRun:
1. Keep changes isolated to docker-related files
2. Don't modify core REACT source files unnecessarily
3. Update documentation as you go
4. Test locally with docker-compose before committing
5. Follow the phase-based approach in implementation_plan.md

## Branch

This work is on the `react-cloudrun` branch. Original REACT remains on `master`.

## License

Inherits from original REACT project. See LICENSE file.

## Next Steps

To continue development:

1. **Phase 2**: Finalize Dockerfile and test build
2. **Phase 3**: Run initial Docker build and capture compiler errors
3. **Phase 4**: Implement HTTP server wrapper
4. **Phase 5**: Test locally with docker-compose
5. **Phase 6**: Optimize for production and Cloud Run

See [Implementation Plan](../../../session-state/96213969-ef5c-47f8-8b14-138695a0c189/files/implementation_plan.md) for details.
