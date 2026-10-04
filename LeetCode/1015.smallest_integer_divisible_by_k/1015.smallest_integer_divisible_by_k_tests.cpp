#include "1015.smallest_integer_divisible_by_k.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LeetCode 1015 - Smallest Integer Divisible by K", "[LeetCode][1015][math][hash-table]")
{
    Solution solution;

    SECTION("Example 1: k = 1") { REQUIRE(solution.smallestRepunitDivByK(1) == 1); }
    SECTION("Example 2: k = 2") { REQUIRE(solution.smallestRepunitDivByK(2) == -1); }
    SECTION("Example 3: k = 3") { REQUIRE(solution.smallestRepunitDivByK(3) == 3); }
    SECTION("Even number k cannot divide repunit: k = 4")
    {
        REQUIRE(solution.smallestRepunitDivByK(4) == -1);
    }
    SECTION("Multiple of 5 cannot divide repunit: k = 5")
    {
        REQUIRE(solution.smallestRepunitDivByK(5) == -1);
    }
    SECTION("Prime k = 7 (repunit 111111)") { REQUIRE(solution.smallestRepunitDivByK(7) == 6); }
    SECTION("Prime k = 13 (repunit 111111)") { REQUIRE(solution.smallestRepunitDivByK(13) == 6); }
}
