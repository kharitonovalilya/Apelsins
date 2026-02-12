# Task 3 - Simulation of Infection Spread

This project simulates the spread of an "infection" over a two-dimensional grid. The rule is used: at each step, each infected cell (value 1) infects its four neighbors (top, bottom, left, right). The program demonstrates the basic concepts of C++. The build system is managed using CMake, and unit testing is performed using the Catch2 framework.

## Project Structure
```
seminar-3/
├── CMakeLists.txt                # CMake configuration file
├── Readme.md                     # About our project (this file)
├── include/                      # Header files 
│   ├── input_and_print.h         # Grid input/output interface
│   └── logic.h                   # Simulation logic interface
├── src/                          # Source files
│   ├── main.cpp                  # Program entry point
│   ├── input_and_print.cpp       # Implementation of I/O functions
│   └── logic.cpp                 # Implementation of simulation logic
└── tests/                        # Unit tests directory
    ├── test_main.cpp             # Catch2 test runner entry point
    ├── test_count_infected.cpp   # Tests for counting infected cells
    ├── test_neighbour_vir.cpp    # Tests for neighbour infection logic
    └── test_step.cpp             # Tests for the step() function
```

## Requirements
- CMake 
- C++ Compiler with C++17 support (for example, GCC, CLANG)
- Git
- ninja

## Build & Run
### Configure the build system:
```bash
cmake -S . -B build -G Ninja
```
### Build the project:
```bash
ninja -C build
```
### Run the project:
```bash
./build/seminar-3
```

## Program Behavior

The program reads the initial grid, then prompts the user to enter the number of simulation steps (k). It then:
1. Run a simulation for k steps 
2. Outputs the final matrix after k infection steps

### Example Usage

```
Enter the amount of rows first, then the amount of columns: 3 4
Start entering a row 1: 0 0 1 0
Start entering a row 2: 0 0 0 0
Start entering a row 3: 0 1 0 0
1
Infected cells: 8
0 1 1 1
0 1 1 0
1 1 1 0
```


## Unit Testing
Run the tests:
```bash
ninja -C build test
```
All tests use the Catch2 testing framework and are automatically executed when you run the test target.

