# Dockerfile for qtty-cpp development and testing
FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    python3 \
    python3-pip \
    curl \
    pkg-config \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Install Rust and Cargo
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

# Set working directory
WORKDIR /workspace

# Copy the project files
COPY . /workspace/

# Initialize and update git submodules (qtty-ffi)
RUN git submodule update --init --recursive || true

# Create build directory
RUN mkdir -p build

# Set the default command to bash for interactive use
CMD ["/bin/bash"]
