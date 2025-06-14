#!/bin/pwsh
# Compil using cmake

$ErrorActionPreference = 'Stop'

if ($args.Count -gt 0 -and $args[0] -eq '--no-tidy') {
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DNO_USE_CLANG_TIDY=true
} else {
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
}

cmake --build build -- /m
