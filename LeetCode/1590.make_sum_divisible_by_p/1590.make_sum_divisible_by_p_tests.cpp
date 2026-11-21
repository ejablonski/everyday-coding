#include "1590.make_sum_divisible_by_p.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1590;

TEST_CASE("LeetCode 1590 - Make Sum Divisible by P",
          "[LeetCode][1590][array][hash-table][prefix-sum]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [3, 1, 4, 2], p = 6")
    {
        std::vector<int> nums = {3, 1, 4, 2};
        REQUIRE(Solution::minSubarray(nums, 6) == 1);
    }

    SECTION("Example 2: nums = [6, 3, 5, 2], p = 9")
    {
        std::vector<int> nums = {6, 3, 5, 2};
        REQUIRE(Solution::minSubarray(nums, 9) == 2);
    }

    SECTION("Example 3: nums = [1, 2, 3], p = 3")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::minSubarray(nums, 3) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Impossible without removing whole array: nums = [1, 2, 3], p = 7")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::minSubarray(nums, 7) == -1);
    }

    SECTION("Single element divisible by p: nums = [10], p = 5")
    {
        std::vector<int> nums = {10};
        REQUIRE(Solution::minSubarray(nums, 5) == 0);
    }

    SECTION("Single element not divisible by p: nums = [10], p = 3")
    {
        std::vector<int> nums = {10};
        REQUIRE(Solution::minSubarray(nums, 3) == -1);
    }

    SECTION("Minimum divisor p = 1 always needs zero removals")
    {
        std::vector<int> nums = {7, 13, 29};
        REQUIRE(Solution::minSubarray(nums, 1) == 0);
    }

    SECTION("Large 10^9 values near upper bound")
    {
        std::vector<int> nums = {1000000000, 1000000000, 1000000000, 5};
        REQUIRE(Solution::minSubarray(nums, 1000000000) == 1);
    }

    SECTION("Multiple valid subarrays of different lengths picks shortest")
    {
        std::vector<int> nums = {1, 2, 1, 4, 5};
        REQUIRE(Solution::minSubarray(nums, 9) == 1);
    }

    SECTION("Shortest removable subarray in middle of array")
    {
        std::vector<int> nums = {5, 3, 3, 2};
        REQUIRE(Solution::minSubarray(nums, 7) == 2);
    }
}
