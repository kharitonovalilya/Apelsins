#include <input_and_print.h>
#include <iostream>

std::vector<std::vector<int>> readGrid() {
  int rows = 0, columns = 0, element = 0;
  std::vector<std::vector<int>> field;
  std::cout << "Enter the amount of rows first, then the amount of columns: ";
  if (!(std::cin >> rows >> columns) || rows <= 0 || columns <= 0) {
    std::cout << "Incorrect input, error!" << std::endl;
    return {};
  }
  for (int index_row = 0; index_row < rows; index_row++) {
    std::vector<int> row;
    std::cout << "Start entering a row " << index_row + 1 << ": ";
    for (int index_col = 0; index_col < columns; index_col++) {
      if (!(std::cin >> element) || !(element == 0 || element == 1)) {
        std::cout << "Incorrect input, error!" << std::endl;
        return {};
      }
      row.push_back(element);
    }
    field.push_back(row);
  }
  return field;
}

void printGrid(const std::vector<std::vector<int>> &grid) {
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      std::cout << grid[i][j];
      if (j == grid[i].size() - 1) {
        std::cout << '\n';
      } else {
        std::cout << ' ';
      }
    }
  }
}
