#!/bin/zsh
# Install dependencies

brew install cmake
brew install llvm
ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
ln -s "$(brew --prefix llvm)/bin/clang-format" "/usr/local/bin/clang-format"
