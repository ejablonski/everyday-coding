#include "3551.minimum_swaps_to_sort_by_digit_sum.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 3551 - Minimum Swaps to Sort by Digit Sum",
          "[LeetCode][3551][array][sorting][greedy][graph]")
{
    Solution solution;

    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [37, 100]")
    {
        std::vector<int> nums = {37, 100};
        REQUIRE(solution.minSwaps(nums) == 1);
    }

    SECTION("Example 2: nums = [22, 14, 33, 7]")
    {
        std::vector<int> nums = {22, 14, 33, 7};
        REQUIRE(solution.minSwaps(nums) == 0);
    }

    SECTION("Example 3: nums = [18, 43, 34, 16]")
    {
        std::vector<int> nums = {18, 43, 34, 16};
        REQUIRE(solution.minSwaps(nums) == 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (minimum constraint n = 1): nums = [42]")
    {
        std::vector<int> nums = {42};
        REQUIRE(solution.minSwaps(nums) == 0);
    }

    SECTION("Two elements already sorted: nums = [10, 20]")
    {
        std::vector<int> nums = {10, 20};
        REQUIRE(solution.minSwaps(nums) == 0);
    }

    SECTION("Tie-breaking by numerical value on equal digit sums: nums = [21, 12]")
    {
        std::vector<int> nums = {21, 12};
        REQUIRE(solution.minSwaps(nums) == 1);
    }

    SECTION("Single 3-cycle permutation: nums = [3, 1, 2]")
    {
        std::vector<int> nums = {3, 1, 2};
        REQUIRE(solution.minSwaps(nums) == 2);
    }

    SECTION("Multiple disjoint cycles (3-cycle and 2-cycle): nums = [20, 30, 10, 50, 40]")
    {
        std::vector<int> nums = {20, 30, 10, 50, 40};
        REQUIRE(solution.minSwaps(nums) == 3);
    }

    SECTION("Upper boundary values up to 10^9: nums = [999999999, 1000000000]")
    {
        std::vector<int> nums = {999999999, 1000000000};
        REQUIRE(solution.minSwaps(nums) == 1);
    }
}
