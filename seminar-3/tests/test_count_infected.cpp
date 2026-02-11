#include <catch2/catch_test_macros.hpp>
#include <logic.h>

TEST_CASE("Counting infected cells works correctly") {
  SECTION("Ordinary fields") {
    std::vector<std::vector<int>> grid_1 = {{0}, {1}, {0}};
    std::vector<std::vector<int>> grid_2 = {{0, 1}, {0, 0}, {1, 1}};
    std::vector<std::vector<int>> grid_3 = {{0, 1, 1}, {0, 1, 1}, {0, 0, 0}};
    std::vector<std::vector<int>> grid_4 = {
        {0, 1, 1, 1, 1}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}};
    std::vector<std::vector<int>> grid_5 = {
        {0, 1}, {0, 1}, {0, 0}, {1, 0}, {0, 0}};
    REQUIRE(countInfected(grid_1) == 1);
    REQUIRE(countInfected(grid_2) == 3);
    REQUIRE(countInfected(grid_3) == 4);
    REQUIRE(countInfected(grid_4) == 8);
    REQUIRE(countInfected(grid_5) == 3);
  }
}