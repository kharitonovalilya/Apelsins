#include <fstream>
#include <iostream>
#include <read_and_parse.h>
#include <sstream>
#include <string>

std::vector<std::vector<double>> read_and_parse() {
  std::ifstream file("data.csv");
  std::vector<std::vector<double>> columns;
  std::string line;
  if (!std::getline(file, line)) {
    return columns;
  }
  std::stringstream ss(line);
  std::string cell;
  while (std::getline(ss, cell, ';')) {
    std::vector<double> value;
    value.push_back(std::stod(cell));
    columns.push_back(value);
  }
  size_t numCols = columns.size();
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string cell;
    size_t colIndex = 0;
    while (std::getline(ss, cell, ';') && colIndex < numCols) {
      double value = std::stod(cell);
      columns[colIndex].push_back(value);
      ++colIndex;
    }
    while (colIndex < numCols) {
      columns[colIndex].push_back(0.0);
      ++colIndex;
    }
  }
  return columns;
}