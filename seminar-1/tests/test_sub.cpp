#define CATCH_CONFIG_MAIN
#include "sub.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Subtraction works correctly") {
  SECTION("Ordinary numbers") { REQUIRE(sub(5, 2) == 3); }
  SECTION("Negative numbers") {
    REQUIRE(sub(5, -2) == 7);
    REQUIRE(sub(-5, 2) == -7);
    REQUIRE(sub(-5, -2) == -3);
  }
  SECTION("Subtraction with zero") {
    REQUIRE(sub(5, 0) == 5);
    REQUIRE(sub(0, 5) == -5);
  }
}
