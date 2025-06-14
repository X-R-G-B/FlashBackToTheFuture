#!/bin/pwsh
# Install deps

winget list -e LLVM
if ($LASTEXITCODE -ne 0) {
    if ($args.Count -gt 0 -and $args[0] -eq '--interactive') {
        winget install --accept-package-agreements --accept-source-agreements LLVM -e -i
    } else {
        winget install --accept-package-agreements --accept-source-agreements LLVM -e
    }
}

winget list -e CMake
if ($LASTEXITCODE -ne 0) {
    if ($args.Count -gt 0 -and $args[0] -eq '--interactive') {
        winget install --accept-package-agreements --accept-source-agreements CMake -e -i
    } else {
        winget install --accept-package-agreements --accept-source-agreements CMake -e
    }
}
