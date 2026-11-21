#include "198.house_robber.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC198;

TEST_CASE("LeetCode 198 - House Robber", "[LeetCode][198][array][dynamic-programming]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1,2,3,1]")
    {
        std::vector<int> nums = {1, 2, 3, 1};
        REQUIRE(Solution::rob(nums) == 4);
    }

    SECTION("Example 2: nums = [2,7,9,3,1]")
    {
        std::vector<int> nums = {2, 7, 9, 3, 1};
        REQUIRE(Solution::rob(nums) == 12);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length: single house")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::rob(nums) == 42);
    }

    SECTION("Two houses: choose the larger amount")
    {
        std::vector<int> nums = {10, 25};
        REQUIRE(Solution::rob(nums) == 25);
    }

    SECTION("Optimal choice skips two consecutive houses")
    {
        std::vector<int> nums = {2, 1, 1, 2};
        REQUIRE(Solution::rob(nums) == 4);
    }

    SECTION("Minimum value constraint: all zeros")
    {
        std::vector<int> nums = {0, 0, 0, 0};
        REQUIRE(Solution::rob(nums) == 0);
    }

    SECTION("Strictly increasing house values")
    {
        std::vector<int> nums = {1, 2, 3, 4, 5, 6};
        REQUIRE(Solution::rob(nums) == 12);
    }

    SECTION("Maximum length and value constraints: 100 houses of value 400")
    {
        std::vector<int> nums(100, 400);
        REQUIRE(Solution::rob(nums) == 20000);
    }
}
