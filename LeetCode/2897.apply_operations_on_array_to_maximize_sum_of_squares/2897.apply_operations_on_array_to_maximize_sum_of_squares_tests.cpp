#include "2897.apply_operations_on_array_to_maximize_sum_of_squares.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2897 - Apply Operations on Array to Maximize Sum of Squares",
          "[LeetCode][2897][array][math][greedy][bit-manipulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [2,6,5,8], k = 2")
    {
        std::vector<int> nums = {2, 6, 5, 8};
        int k = 2;
        REQUIRE(Solution::maxSum(nums, k) == 261);
    }

    SECTION("Example 2: nums = [4,5,4,7], k = 3")
    {
        std::vector<int> nums = {4, 5, 4, 7};
        int k = 3;
        REQUIRE(Solution::maxSum(nums, k) == 90);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single element (n = 1, k = 1)")
    {
        std::vector<int> nums = {5};
        int k = 1;
        REQUIRE(Solution::maxSum(nums, k) == 25);
    }

    SECTION("k = 1: collect all bits into a single maximum number")
    {
        std::vector<int> nums = {1, 2, 4};
        int k = 1;
        // Bits 1, 2, 4 combine into (1 | 2 | 4) = 7, 7^2 = 49
        REQUIRE(Solution::maxSum(nums, k) == 49);
    }

    SECTION("k = n: operations increase sum of squares even when choosing all elements")
    {
        std::vector<int> nums = {2, 4};
        int k = 2;
        // (2 AND 4) = 0, (2 OR 4) = 6 -> 6^2 + 0^2 = 36
        REQUIRE(Solution::maxSum(nums, k) == 36);
    }

    SECTION("All elements are identical")
    {
        std::vector<int> nums = {3, 3, 3};
        int k = 2;
        // 3^2 + 3^2 = 18
        REQUIRE(Solution::maxSum(nums, k) == 18);
    }

    SECTION("Large values modulo 10^9 + 7: nums[0] = 10^9, k = 1")
    {
        std::vector<int> nums = {1000000000};
        int k = 1;
        // (10^9)^2 mod (10^9 + 7) = (-7)^2 mod (10^9 + 7) = 49
        REQUIRE(Solution::maxSum(nums, k) == 49);
    }
}
