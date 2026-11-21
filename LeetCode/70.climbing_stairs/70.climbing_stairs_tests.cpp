#include "70.climbing_stairs.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC70;

TEST_CASE("LeetCode 70 - Climbing Stairs", "[LeetCode][70][math][dynamic-programming][memoization]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 2")
    {
        REQUIRE(Solution::climbStairs(2) == 2);
    }

    SECTION("Example 2: n = 3")
    {
        REQUIRE(Solution::climbStairs(3) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: n = 1")
    {
        REQUIRE(Solution::climbStairs(1) == 1);
    }

    SECTION("Small staircase: n = 4")
    {
        REQUIRE(Solution::climbStairs(4) == 5);
    }

    SECTION("Medium staircase: n = 10")
    {
        REQUIRE(Solution::climbStairs(10) == 89);
    }

    SECTION("Larger staircase: n = 20")
    {
        REQUIRE(Solution::climbStairs(20) == 10946);
    }

    SECTION("Maximum constraint: n = 45")
    {
        REQUIRE(Solution::climbStairs(45) == 1836311903);
    }
}
