# Overview

This project is an Operating System Error Emulator designed to simulate and demonstrate various programming errors and common problems in operating systems. The primary goal is educational - allowing students and interested individuals to observe, in a practical way, how different types of system-level errors occur and behave.

The project is written in C and provides a structured approach to understanding critical system errors including memory leaks, race conditions, deadlocks, segmentation faults, and buffer overflows through hands-on demonstration.

# User Preferences

Preferred communication style: Simple, everyday language.

# System Architecture

## Core Design Pattern
The project follows a modular demonstration architecture where each type of error is isolated into its own C source file. This separation allows for:
- Independent compilation of error examples
- Easy addition of new error types
- Clear isolation of different problem domains

## Directory Structure
The project uses a three-tier directory organization:
- **erros/**: Contains individual C files, each demonstrating a specific type of system error
- **output/**: Auto-generated directory for compiled executables
- **runner/**: Contains the main runner program and build scripts

## Build System
The project uses a shell-script-based build system (`run.sh`) that:
- Automatically compiles all error demonstration files
- Creates a unified executable output directory
- Provides a single entry point for building the entire project

## Interactive Menu System
The architecture includes a central runner program (`runner.c`) that provides:
- Interactive menu selection for different error types
- Controlled execution environment for dangerous operations
- User-friendly interface for educational demonstrations

## Error Isolation Strategy
Each error type is completely isolated in its own source file, preventing:
- Cross-contamination between different error demonstrations
- Compilation issues affecting unrelated examples
- Difficulty in understanding individual error types

# External Dependencies

## System Dependencies
- **GCC Compiler**: Required for compiling C source files
- **POSIX Threading Library** (`pthread`): Used for race condition and deadlock demonstrations
- **Standard C Library**: For memory management and basic system operations

## Operating System Requirements
- **Linux/Unix Environment**: The build scripts and threading examples are designed for POSIX-compliant systems
- **Shell Environment**: Bash shell required for the automated build process

## No External Libraries
The project intentionally avoids external dependencies beyond standard system libraries to:
- Maintain simplicity and educational focus
- Ensure compatibility across different Linux distributions
- Keep the focus on core operating system concepts rather than library-specific implementations