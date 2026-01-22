# Task 1 - Subtraction calculator

This project provides a demonstration of a basic command-line calculator capable of performing integer subtraction. It highlights key C++ programming concepts, the use of CMake for project building and Catch2 for testing.

## Project Structure
```
seminar-1/
├── CMakeLists.txt        # CMake configuration
├── Readme.md             # About our project (this file)
├── include/              # Header files
│   └── sub.h             # Subtraction function declaration
├── src/                  # Source files
│   ├── main.cpp          # Main application entry point
│   └── sub.cpp           # Subtraction function implementation
└── tests/                # Test files
    └── test_sub.cpp      # Unit tests using Catch2
```

## Requirements
- CMake 
- C++ Compiler with C++17 support (for example, GCC, CLANG)
- Git
- ninja

## Build
### Configure the build system:
```bash
cmake -S . -B build -G Ninja
```
### Build the project:
```bash
ninja -C build
```
## Run the project:
```bash
./build/seminar-1
```

The program will prompt you to enter two integer numbers. It will:
1. Handle invalid input and terminate the program
2. If your input is correct, display the difference of the two numbers (first minus second) and terminate

### Example Usage
```
Enter two integer numbers:
a b
Invalid input
```
```
Enter two integer numbers:
2 3
-1
```

## Unit Testing
Run the tests:
```bash
ninja test
```
All tests use the Catch2 testing framework and are automatically executed when you run the test target.

## Mathematical Operation
The calculator performs the operation:  
**result = first_number - second_number**

Example:  
- Input: `8 3` Output: `5` (8 - 3 = 5)
- Input: `5 10` Output: `-5` (5 - 10 = -5)
- Input: `-4 -2` Output: `-2` (-4 - (-2) = -2)

