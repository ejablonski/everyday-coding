#include "724.find_the_pivot_integer.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LeetCode 724 - Find the Pivot Integer", "[LeetCode][724][array][prefix-sum]")
{
    Solution solution;

    SECTION("Example 1: n = 8") { REQUIRE(solution.pivotInteger(8) == 6); }
    SECTION("Example 2: n = 1") { REQUIRE(solution.pivotInteger(1) == 1); }
    SECTION("Example 3: n = 4") { REQUIRE(solution.pivotInteger(4) == -1); }
    SECTION("Larger integer with pivot: n = 49") { REQUIRE(solution.pivotInteger(49) == 35); }
    SECTION("Larger integer without pivot: n = 50") { REQUIRE(solution.pivotInteger(50) == -1); }
}
