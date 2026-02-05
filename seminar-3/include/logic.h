#ifndef LOGIC_H
#define LOGIC_H

#include <vector>

int countInfected(const std::vector<std::vector<int>> &grid);
bool neighbour_vir(const std::vector<std::vector<int>> &grid, int pos_x,
                   int pos_y);
std::vector<std::vector<int>> step(const std::vector<std::vector<int>> &grid);

#endif