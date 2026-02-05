#include <logic.h>

int countInfected(const std::vector<std::vector<int>> &grid) {
  int result = 0;
  for (int index_row = 0; index_row < grid.size(); ++index_row) {
    for (int index_col = 0; index_col < grid[0].size(); ++index_col) {
      result += grid[index_row][index_col];
    }
  }
  return result;
}