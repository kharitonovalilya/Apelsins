#include <logic.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check heighbours if they are viruses") {
  SECTION("Check neighbours") {
    std::vector<std::vector<int>> grid = {
      {1, 0, 1}, 
      {0, 0, 1}, 
      {0, 0, 1}};
    std::vector<std::vector<int>> simple_grid = {{1}};
    REQUIRE(neighbour_vir(grid, 0, 0) == false);
    REQUIRE(neighbour_vir(grid, 1, 1) == true);
    REQUIRE(neighbour_vir(grid, 2, 0) == false);
    REQUIRE(neighbour_vir(grid, 0, 2) == true);
    REQUIRE(neighbour_vir(simple_grid, 0, 0) == false);
  }
}