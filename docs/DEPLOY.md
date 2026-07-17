# REACT CloudRun Deployment Guide

## Overview
This is the CloudRun-ready containerized version of the REACT Chemistry System.

## Quick Start

### Local Development with Docker Compose

```bash
# Build the Docker image
docker-compose build

# Start in HTTP mode (port 8080)
docker-compose up

# In another terminal, test the API
curl -X GET http://localhost:8080/health
```

### Running in CLI Mode

```bash
# Run chemdb with help
docker run reactcloudrun:latest cli --help

# Run a chemistry calculation (example)
docker run reactcloudrun:latest cli --input file.txt --output result.txt
```

## Architecture

### Multi-Stage Build
- **Stage 1 (Builder)**: Ubuntu 22.04 + build tools + compilation
- **Stage 2 (Runtime)**: Ubuntu 22.04-slim + runtime libraries only

### Dual-Mode Operation
1. **CLI Mode** (default): Pass-through to chemdb binary
2. **HTTP Mode**: Simple HTTP wrapper (Phase 4)

### Environment Variables
- `PORT` - HTTP server port (default: 8080)
- `REACTROOT` - REACT installation directory (default: /opt/react)
- `CCROOT` - REACT installation directory (default: /opt/react)

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
- Verify chemdb binary exists at /opt/react/bin/chemdb
- Check environment variables are set correctly

### HTTP Server Issues
- Ensure PORT is set correctly
- Check firewall/routing rules on Cloud Run

## Development Notes

### Phase Status
- ✅ Phase 1: Project Setup
- ⏳ Phase 2: Dockerfile Creation
- ⏳ Phase 3: C Code Updates
- ⏳ Phase 4: Entry Point Wrapper
- ⏳ Phase 5: Local Testing
- ⏳ Phase 6: Production Optimization

See ../implementation_plan.md for detailed information.

## Support

For issues or questions, refer to:
- REACT documentation: /README.md
- Installation guide: /INSTALL.txt
- Implementation plan: /../../session-state/.../implementation_plan.md
