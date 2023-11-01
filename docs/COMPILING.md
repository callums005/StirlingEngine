# Compiling the Stirling Engine for your system

Table of Contents
1. [Requirements](#requirements)
2. [Building for Windows](#building-for-windows)

## Requirements  
- CMake Version 3.2 or above
- G++ Compiler (MinGW for Windows, GNU for Linux)

## Building for Windows

Download the source code from GitHub:
```bash
mkdir SandboxProject && cd SandboxProject
git init
git clone https://github.com/callums005/StirlingEngine.git
```

Build the Engine:
```bash
cd StirlingEngine
cmake -B ./build/
cmake --build ./build
```

Return back to the project root:
```bash
cd ..
```


Build your Game Project:
```bash
cmake -B ./build/
cmake --build ./build
```

Run your Game Project:
```bash
./build/bin/Debug/Sandbox.exe
```