#include <input_and_print.h>
#include <iostream>
#include <logic.h>

int main() {
  std::vector<std::vector<int>> grid = readGrid();
  int k = 0;
  std::cin >> k;
  for (int iteration = 0; iteration < k; ++iteration) {
    grid = step(grid);
  }
  std::cout << countInfected(grid) << '\n';
}