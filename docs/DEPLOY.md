# REACT CloudRun Deployment Guide

## Overview
This is the CloudRun-ready containerized version of the REACT Chemistry System.

## Quick Start

### Local Development with Docker Compose

```bash
# Build the Docker image
docker compose build

# Start in HTTP mode (port 8080)
docker compose up

# In another terminal, test the API
curl http://localhost:8080/health
curl -X POST http://localhost:8080/api/run \
  -H 'Content-Type: application/json' \
  -d '{"args":["--help"]}'

curl -X POST http://localhost:8080/api/run-input \
  -H 'Content-Type: application/json' \
  -d '{"inputFile":"PrintRxnPatternsList.inp","root":"printpats"}'
```

### Running in CLI Mode

```bash
# Run chemdb with help
docker run --rm reactcloudrun:latest --help

# Run a chemistry calculation (example)
docker run --rm -v "$PWD/data:/opt/react/data" reactcloudrun:latest [chemdb args...]
```

## Architecture

### Multi-Stage Build
- **Stage 1 (Builder)**: Ubuntu 22.04 + build tools + compilation
- **Stage 2 (Runtime)**: Ubuntu 22.04-slim + runtime libraries only

### Dual-Mode Operation
1. **CLI Mode**: Pass-through to `chemdb` when you pass CLI args or explicitly use `cli`
2. **HTTP Mode**: Starts automatically when the container has no args and `PORT` is set, or when you explicitly use `http`

### Environment Variables
- `PORT` - HTTP server port (default: 8080)
- `REACTROOT` - REACT installation directory (default: /opt/react)
- `CCROOT` - REACT installation directory (default: /opt/react)
- `REACT_MODE` - Optional explicit mode override (`cli` or `http`)

### HTTP API

#### `GET /health`
Returns a simple health payload:

```json
{"status":"ok","service":"chemdb"}
```

#### `POST /api/run`
Runs `chemdb` with a JSON array of CLI arguments:

```bash
curl -X POST http://localhost:8080/api/run \
  -H 'Content-Type: application/json' \
  -d '{"args":["--help"]}'
```

Example response:

```json
{
  "exitCode": 0,
  "output": "..."
}
```

#### `POST /api/run-input`
Runs `runchem.sh` by piping a template file from `programs/inputs/*.inp`.

Request body fields:
- `inputFile` (required): safe `.inp` filename in `programs/inputs`
- `root` (optional): run root name (default: `api`)
- `replacements` (optional): key/value substitutions applied to template text before execution

Example (`PrintRxnPatternsList.inp`):

```bash
curl -X POST http://localhost:8080/api/run-input \
  -H 'Content-Type: application/json' \
  -d '{"inputFile":"PrintRxnPatternsList.inp","root":"printpats"}'
```

## Deploying to Google Cloud Run

### Prerequisites
- Google Cloud account with billing enabled
- `gcloud` CLI installed and authenticated
- Docker installed locally

### Build and Push to Cloud Registry

```bash
# Set your GCP project ID
export PROJECT_ID="your-project-id"
export IMAGE_NAME="react-chemdb"
export REGION="us-central1"

# Build locally
docker build -t gcr.io/$PROJECT_ID/$IMAGE_NAME:latest .

# Push to Google Container Registry
docker push gcr.io/$PROJECT_ID/$IMAGE_NAME:latest

# Deploy to Cloud Run
gcloud run deploy $IMAGE_NAME \
  --image gcr.io/$PROJECT_ID/$IMAGE_NAME:latest \
  --platform managed \
  --region $REGION \
  --allow-unauthenticated \
  --set-env-vars PORT=8080 \
  --memory 2Gi \
  --timeout 3600 \
  --max-instances 10
```

### Cloud Run Configuration

Recommended settings:
- **Memory**: 2 GB (adjust based on workload)
- **Timeout**: 3600 seconds (1 hour for long-running jobs)
- **Max Instances**: 10 (adjust based on concurrency needs)
- **CPU**: 2 (allocated when requests are being processed)

## Monitoring and Logs

```bash
# View logs from Cloud Run
gcloud run logs read $IMAGE_NAME --region $REGION

# Stream logs in real-time
gcloud run logs read $IMAGE_NAME --region $REGION --follow
```

## Troubleshooting

### Build Fails
- Check compiler errors in Phase 3 documentation
- Ensure all required system libraries are installed

### Container Doesn't Start
- Check entrypoint.sh permissions
- Verify `chemdb` exists at `/opt/react/bin/chemdb`
- Verify `http-server` exists at `/opt/react/bin/http-server`
- Check environment variables are set correctly

### HTTP Server Issues
- Ensure `PORT` is set correctly
- Confirm requests use JSON like `{"args":["--help"]}` for `/api/run`
- Check firewall/routing rules on Cloud Run

## Development Notes

### Phase Status
- ✅ Phase 1: Project Setup
- ✅ Phase 2: Dockerfile Creation
- ✅ Phase 3: C Code Updates
- ✅ Phase 4: Entry Point Wrapper
- ⏳ Phase 5: Local Testing
- ⏳ Phase 6: Production Optimization

See ../implementation_plan.md for detailed information.

## Support

For issues or questions, refer to:
- REACT documentation: /README.md
- Installation guide: /INSTALL.txt
- Implementation plan: /../../session-state/.../implementation_plan.md
