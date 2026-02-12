#include <logic.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check one step of viruses spread on board") {
  SECTION("Step") {
    std::vector<std::vector<int>> grid1 = {
      {1, 0, 1}, 
      {0, 0, 1}, 
      {0, 0, 1}};
    std::vector<std::vector<int>> grid1_new = {
      {1, 1, 1}, 
      {1, 1, 1}, 
      {0, 1, 1}};
    REQUIRE(step(grid1) == grid1_new);
    std::vector<std::vector<int>> grid2 = {
        {1, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    std::vector<std::vector<int>> grid2_new = {
        {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 1, 1}};
    REQUIRE(step(grid2) == grid2_new);
  }
}