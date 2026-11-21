#include "215.kth_largest_element_in_an_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC215;

TEST_CASE("LeetCode 215 - Kth Largest Element in an Array",
          "[LeetCode][215][array][divide-and-conquer][sorting][heap][priority-queue][quickselect]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [3,2,1,5,6,4], k = 2")
    {
        std::vector<int> nums = {3, 2, 1, 5, 6, 4};
        REQUIRE(Solution::findKthLargest(nums, 2) == 5);
    }

    SECTION("Example 2: nums = [3,2,3,1,2,4,5,5,6], k = 4")
    {
        std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        REQUIRE(Solution::findKthLargest(nums, 4) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (n = 1, k = 1)")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::findKthLargest(nums, 1) == 42);
    }

    SECTION("Largest element (k = 1) with boundary values")
    {
        std::vector<int> nums = {-10000, 0, 10000, -5, 5};
        REQUIRE(Solution::findKthLargest(nums, 1) == 10000);
    }

    SECTION("Smallest element (k = n) with all negative numbers")
    {
        std::vector<int> nums = {-10000, -1, -500, -2, -9999};
        REQUIRE(Solution::findKthLargest(nums, 5) == -10000);
    }

    SECTION("All elements identical")
    {
        std::vector<int> nums = {7, 7, 7, 7, 7};
        REQUIRE(Solution::findKthLargest(nums, 3) == 7);
    }

    SECTION("Duplicate values spanning k boundary")
    {
        std::vector<int> nums = {5, 5, 5, 4, 4, 3};
        REQUIRE(Solution::findKthLargest(nums, 3) == 5);
    }

    SECTION("Already sorted ascending array")
    {
        std::vector<int> nums = {-10, -5, 0, 5, 10};
        REQUIRE(Solution::findKthLargest(nums, 2) == 5);
    }
}
