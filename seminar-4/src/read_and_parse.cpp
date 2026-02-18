#include <fstream>
#include <iostream>
#include <map>
#include <read_and_parse.h>
#include <sstream>
#include <string>

std::map<std::string, std::vector<double>>
read_and_parse(const std::string &filename, char delimeter) {
  std::ifstream file(filename);
  std::map<std::string, std::vector<double>> columns;
  std::string line;
  if (!std::getline(file, line)) {
    return columns;
  }
  std::vector<std::string> headers;
  std::stringstream header_stream(line);
  std::string header;
  while (std::getline(header_stream, header, delimeter)) {
    headers.push_back(header);
    columns[header] = {};
  }
  size_t numCols = columns.size();
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string cell;
    size_t colIndex = 0;
    while (std::getline(ss, cell, delimeter) && colIndex < numCols) {
      double value = std::stod(cell);
      columns[headers[colIndex]].push_back(value);
      ++colIndex;
    }
    while (colIndex < numCols) {
      columns[headers[colIndex]].push_back(0.0);
      ++colIndex;
    }
  }
  return columns;
}