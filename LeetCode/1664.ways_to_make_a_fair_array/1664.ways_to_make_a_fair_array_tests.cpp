#include "1664.ways_to_make_a_fair_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1664;

TEST_CASE("LeetCode 1664 - Ways to Make a Fair Array", "[LeetCode][1664][array][prefix-sum]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [2, 1, 6, 4]")
    {
        std::vector<int> nums = {2, 1, 6, 4};
        REQUIRE(Solution::waysToMakeFair(nums) == 1);
    }

    SECTION("Example 2: nums = [1, 1, 1]")
    {
        std::vector<int> nums = {1, 1, 1};
        REQUIRE(Solution::waysToMakeFair(nums) == 3);
    }

    SECTION("Example 3: nums = [1, 2, 3]")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::waysToMakeFair(nums) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element leaves empty fair array: nums = [5]")
    {
        std::vector<int> nums = {5};
        REQUIRE(Solution::waysToMakeFair(nums) == 1);
    }

    SECTION("Two positive elements can never be fair after one removal: nums = [4, 4]")
    {
        std::vector<int> nums = {4, 4};
        REQUIRE(Solution::waysToMakeFair(nums) == 0);
    }

    SECTION("Even length all equal elements: nums = [7, 7, 7, 7]")
    {
        std::vector<int> nums = {7, 7, 7, 7};
        REQUIRE(Solution::waysToMakeFair(nums) == 0);
    }

    SECTION("Odd length all equal max-value elements")
    {
        std::vector<int> nums = {10000, 10000, 10000, 10000, 10000};
        REQUIRE(Solution::waysToMakeFair(nums) == 5);
    }

    SECTION("Fair removals include both first and last indices: nums = [1, 2, 2, 1, 1]")
    {
        std::vector<int> nums = {1, 2, 2, 1, 1};
        REQUIRE(Solution::waysToMakeFair(nums) == 3);
    }
}
