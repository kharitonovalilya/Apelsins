# Task 2 - Expression Calculator

This project implements a statistical data processor. The program reads numerical data from files, calculates statistical measures (minimum, maximum, mean, median, standard deviation), and exports the results to CSV format. It demonstrates C++ programming concepts such as file I/O, data parsing, statistical computations, and error handling. The project uses CMake for building.



## Project Structure
```
seminar-4/
├── CMakeLists.txt                # CMake configuration file
├── Readme.md                     # About our project (this file)
├── include/                      # Header files directory
│   ├── read_and_parse.h          # Data reading interface
│   ├── statistics.h              # Statistical calculations interface
│   └── write_statistics_csv.h    # CSV export interface
├── src/                          # Source files directory
│   ├── main.cpp                  # Main application entry point
│   ├── read_and_parse.cpp        # Data reading implementation
│   ├── statistics.cpp            # Statistical calculations implementation
│   └── write_statistics_csv.cpp  # CSV export implementation
└── data/ 
    ├── input.cav                  # Data files to be processed
    └── output.csv
                        
```


## Requirements
- CMake (minimum version 3.5)
- C++ Compiler with C++17 support (e.g., GCC, Clang, MSVC)

## Build & Run

### Configure the build system:
```bash
cmake -S . -B build

```
### Build the project:
```bash
cmake --build build
```
### Run the project:
```bash
./build/seminar-4
```

## Program Behavior

The program processes numerical data files and generates comprehensive statistical summaries:

1. **Reads data files** from the `data/` directory
2. **Parses numerical values** from each file (supports CSV format with headers)
3. **Calculates statistics** for each dataset:
   - Count (number of values)
   - Sum of all values
   - Mean (average)
   - Minimum value
   - Maximum value
   - Range (max - min)
   - Median
   - Variance
   - Standard deviation
   - First quartile (Q1)
   - Second quartile (Q2, same as median)
   - Third quartile (Q3)
   - Interquartile range (IQR = Q3 - Q1)
4. **Exports results** to CSV format

## Input File Format

The program accepts data files in CSV format. Example input file `data/input.cav`:





## Output Format

The program generates a CSV file containing comprehensive statistics for each column in the input data. The output includes the following statistical measures:

- **column**: Name of the data column
- **count**: Number of valid values
- **sum**: Sum of all values
- **mean**: Arithmetic mean
- **min**: Minimum value
- **max**: Maximum value
- **range**: Range (max - min)
- **median**: Median value
- **variance**: Population variance
- **std_deviation**: Population standard deviation
- **q1**: First quartile (25th percentile)
- **q2**: Second quartile (50th percentile, same as median)
- **q3**: Third quartile (75th percentile)
- **iqr**: Interquartile range (Q3 - Q1)

## Example
data/output.csv


### Input File (`data/input.cav`):
