#!/bin/bash
# Install deps

if command -v apt-get 2>/dev/null; then
    apt-get update
    apt-get install -y g++ cmake clang-tidy clang-format xorg-dev
elif command -v pacman 2>/dev/null; then
    pacman -S g++ cmake clang
elif command -v dnf 2>/dev/null; then
    dnf install -y libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel cmake clang-tools-extra gcc-c++ make cmake
else
    echo "Unsupported package manager"
    exit 12
fi
