# Multi-stage Docker build for REACT Chemistry System
# Phase 2: This is a placeholder - will be completed in Phase 2

# Stage 1: Builder
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive
ENV REACTROOT=/opt/react
ENV CCROOT=/opt/react

# Install build dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    g++ \
    make \
    libc6-dev \
    gdbm-dev \
    libgdbm-dev \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

# Copy source code
WORKDIR /opt/react
COPY . .

# Build REACT system
RUN make install

# Stage 2: Runtime
FROM ubuntu:22.04-slim

ENV DEBIAN_FRONTEND=noninteractive
ENV REACTROOT=/opt/react
ENV CCROOT=/opt/react
ENV PORT=8080

# Install runtime dependencies only
RUN apt-get update && apt-get install -y --no-install-recommends \
    libc6 \
    libgdbm6 \
    && rm -rf /var/lib/apt/lists/*

# Create app directory
WORKDIR /opt/react

# Copy compiled binaries and libraries from builder
COPY --from=builder /opt/react/bin /opt/react/bin
COPY --from=builder /opt/react/lib /opt/react/lib
COPY --from=builder /opt/react/data /opt/react/data

# Copy runtime configuration and scripts
COPY --from=builder /opt/react/programs /opt/react/programs

# Create entrypoint script
COPY src/entrypoint.sh /opt/react/entrypoint.sh
RUN chmod +x /opt/react/entrypoint.sh

# Expose port for HTTP mode
EXPOSE 8080

# Set entrypoint
ENTRYPOINT ["/opt/react/entrypoint.sh"]
