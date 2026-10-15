#include "2913.subarrays_distinct_element_sum_of_squares_i.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2913 - Subarrays Distinct Element Sum of Squares I",
          "[LeetCode][2913][array][hash-table]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1, 2, 1]")
    {
        std::vector<int> nums = {1, 2, 1};
        REQUIRE(Solution::sumCounts(nums) == 15);
    }

    SECTION("Example 2: nums = [1, 1]")
    {
        std::vector<int> nums = {1, 1};
        REQUIRE(Solution::sumCounts(nums) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (minimum constraint n = 1): nums = [1]")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::sumCounts(nums) == 1);
    }

    SECTION("Single element with different value: nums = [42]")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::sumCounts(nums) == 1);
    }

    SECTION("All identical elements: nums = [2, 2, 2]")
    {
        std::vector<int> nums = {2, 2, 2};
        REQUIRE(Solution::sumCounts(nums) == 6);
    }

    SECTION("All distinct elements: nums = [1, 2, 3]")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::sumCounts(nums) == 20);
    }

    SECTION("Alternating repeating elements: nums = [1, 2, 1, 2]")
    {
        std::vector<int> nums = {1, 2, 1, 2};
        REQUIRE(Solution::sumCounts(nums) == 28);
    }

    SECTION("Two distinct elements with upper boundary value: nums = [1, 100]")
    {
        std::vector<int> nums = {1, 100};
        REQUIRE(Solution::sumCounts(nums) == 6);
    }
}
