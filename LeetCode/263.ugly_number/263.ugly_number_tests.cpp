#include "263.ugly_number.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LeetCode 263 - Ugly Number", "[LeetCode][263][math]")
{
    Solution solution;

    SECTION("Example 1: n = 6") { REQUIRE(solution.isUgly(6)); }
    SECTION("Example 2: n = 1") { REQUIRE(solution.isUgly(1)); }
    SECTION("Example 3: n = 14") { REQUIRE_FALSE(solution.isUgly(14)); }
    SECTION("Example 4: n = 101") { REQUIRE_FALSE(solution.isUgly(101)); }
    SECTION("Example 5: n = 937351770") { REQUIRE_FALSE(solution.isUgly(937351770)); }
    SECTION("Non-positive number") { REQUIRE_FALSE(solution.isUgly(-2147483648)); }
    SECTION("Composite with only prime factors 2, 3, 5: n = 30") { REQUIRE(solution.isUgly(30)); }
    SECTION("Prime number other than 2, 3, 5: n = 11") { REQUIRE_FALSE(solution.isUgly(11)); }
}
