#include <logic.h>

int countInfected(const std::vector<std::vector<int>> &grid) {
  int result = 0;
  for (int index_row = 0; index_row < grid.size(); ++index_row) {
    for (int index_col = 0; index_col < grid[index_row].size(); ++index_col) {
      result += grid[index_row][index_col];
    }
  }
  return result;
}

bool neighbour_vir(const std::vector<std::vector<int>> &grid, int pos_x,
                   int pos_y) {
  int x_size = static_cast<int>(grid.size());
  int y_size = static_cast<int>(grid[0].size());
  if (pos_x + 1 < x_size && grid[pos_x + 1][pos_y] == 1) {
    return true;
  }
  if (pos_x - 1 >= 0 && grid[pos_x - 1][pos_y] == 1) {
    return true;
  }
  if (pos_y + 1 < y_size && grid[pos_x][pos_y + 1] == 1) {
    return true;
  }
  if (pos_y - 1 >= 0 && grid[pos_x][pos_y - 1] == 1) {
    return true;
  }
  return false;
}

std::vector<std::vector<int>> step(const std::vector<std::vector<int>> &grid) {
  int x_size = static_cast<int>(grid.size());
  int y_size = static_cast<int>(grid[0].size());
  std::vector<std::vector<int>> new_grid = grid;
  for (int pos_x = 0; pos_x < x_size; pos_x++) {
    for (int pos_y = 0; pos_y < y_size; pos_y++) {
      if (grid[pos_x][pos_y] == 1) {
        new_grid[pos_x][pos_y] = 1;
      } else if (neighbour_vir(grid, pos_x, pos_y)) {
        new_grid[pos_x][pos_y] = 1;
      } else {
        new_grid[pos_x][pos_y] = 0;
      }
    }
  }
  return new_grid;
}