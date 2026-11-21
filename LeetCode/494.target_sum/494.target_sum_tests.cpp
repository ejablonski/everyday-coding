#include "494.target_sum.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC494;

TEST_CASE(
    "LeetCode 494 - Target Sum",
    "[LeetCode][494][array][dynamic-programming][backtracking][knapsack-problem][0-1-knapsack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1,1,1,1,1], target = 3")
    {
        std::vector<int> nums = {1, 1, 1, 1, 1};
        REQUIRE(Solution::findTargetSumWays(nums, 3) == 5);
    }

    SECTION("Example 2: nums = [1], target = 1")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::findTargetSumWays(nums, 1) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single zero has two valid sign assignments (+0 and -0)")
    {
        std::vector<int> nums = {0};
        REQUIRE(Solution::findTargetSumWays(nums, 0) == 2);
    }

    SECTION("Multiple zeros double valid combinations")
    {
        std::vector<int> nums = {0, 0, 1};
        REQUIRE(Solution::findTargetSumWays(nums, 1) == 4);
    }

    SECTION("Reachable negative target")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::findTargetSumWays(nums, -4) == 1);
    }

    SECTION("Unreachable target exceeding sum(nums)")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::findTargetSumWays(nums, 7) == 0);
    }

    SECTION("Unreachable target due to parity mismatch")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::findTargetSumWays(nums, 1) == 0);
    }

    SECTION("Boundary value: single element 1000 with target -1000")
    {
        std::vector<int> nums = {1000};
        REQUIRE(Solution::findTargetSumWays(nums, -1000) == 1);
    }

    SECTION("Maximum length constraint: twenty zeros with target 0")
    {
        std::vector<int> nums(20, 0);
        REQUIRE(Solution::findTargetSumWays(nums, 0) == 1048576);
    }
}
