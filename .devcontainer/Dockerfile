FROM mcr.microsoft.com/vscode/devcontainers/base:bookworm
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install \
    build-essential \
    automake \ 
    cmake \
    make \
    gcc-aarch64-linux-gnu \
    g++-aarch64-linux-gnu \
    binutils-aarch64-linux-gnu \
    libc6-dev-arm64-cross \
    wget \ 
    pkg-config \
    bison \
    autoconf \
    libtool \
    zlib1g-dev \
    libdrm-dev \
    libgbm-dev \
    libpulse-dev \
    libasound2-dev \
    libwayland-dev \
    libgles2-mesa \
    libgles2-mesa-dev \
    libudev-dev \
    libx11-dev \
    libxrandr-dev \
    squashfs-tools \
    xxd