# Task 2 - Expression Calculator

This project implements a mathematical expression calculator. The program reads the mathematical expression entered by the user, analyzes it for correctness and calculates its value. It supports arithmetic operations of addition and subtraction and demonstrates C++ programming concepts such as working with strings and error handling. The project uses CMake for building and Catch2 for unit testing.

## Project Structure
```
seminar-2/
├── CMakeLists.txt              # CMake configuration file
├── Readme.md                   # About our project (this file)
├── include/                    # Header files directory
│   ├── calculate.h             # Expression calculation interface
│   └── input_checkers.h        # Input validation interface
├── src/                        # Source files directory
│   ├── main.cpp                # Main application entry point
│   ├── calculate.cpp           # Expression calculation implementation
│   └── input_checkers.cpp      # Input validation implementation 
└── tests/                      # Test files directore
    
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
./build/seminar-2
```

## Program Behavior

The program will prompt you to enter a mathematical expression. It will:
1. Validate the input for:
   · Valid characters (digits, spaces, plus '+', minus '-')
   · Correct syntax
2. Handle invalid input:
   · If the expression contains invalid characters, display: Invalid input
   · If the operations are in wrong order (like - 2 3 or 2 +- 3), display: Invalid input
   · Terminate the program after displaying the error
3. Process valid expressions:
   · Remove all whitespace characters
   · Parse and calculate the result 
   · Display the final result

Supported Operations
· Addition (+)
· Subtraction (-)
· Multi-digit numbers

### Example Usage

#### Valid Expressions:

```
2+3
5
```
```
10 - 3 + 5
12
```
```
100 + 200 - 50
250
```

#### Invalid Expressions:

##### Invalid characters:
```
2 * 3
Invalid input
```
```
abc + 123
Invalid input
```

##### Wrong operation order:
```
+ 2 3
Invalid input
```
```
2 ++ 3
Invalid input
```
```
2 3 +
Invalid input
```

##### Empty input:
```

Invalid input
```

