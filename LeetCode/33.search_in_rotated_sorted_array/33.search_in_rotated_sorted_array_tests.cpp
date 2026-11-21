#include "33.search_in_rotated_sorted_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC33;

TEST_CASE("LeetCode 33 - Search in Rotated Sorted Array", "[LeetCode][33][array][binary-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [4,5,6,7,0,1,2], target = 0")
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        REQUIRE(Solution::search(nums, 0) == 4);
    }

    SECTION("Example 2: nums = [4,5,6,7,0,1,2], target = 3")
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        REQUIRE(Solution::search(nums, 3) == -1);
    }

    SECTION("Example 3: nums = [1], target = 0")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::search(nums, 0) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element found")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::search(nums, 1) == 0);
    }

    SECTION("Unrotated sorted array with boundary values [-10000, 10000]")
    {
        std::vector<int> nums = {-10000, -5, 0, 5, 10000};
        REQUIRE(Solution::search(nums, 10000) == 4);
    }

    SECTION("Two-element rotated array finding smaller element")
    {
        std::vector<int> nums = {3, 1};
        REQUIRE(Solution::search(nums, 1) == 1);
    }

    SECTION("Target at first index (index 0)")
    {
        std::vector<int> nums = {6, 7, 8, 1, 2, 3, 4, 5};
        REQUIRE(Solution::search(nums, 6) == 0);
    }

    SECTION("Target at last index")
    {
        std::vector<int> nums = {6, 7, 8, 1, 2, 3, 4, 5};
        REQUIRE(Solution::search(nums, 5) == 7);
    }

    SECTION("Target at rotation minimum with negative values")
    {
        std::vector<int> nums = {1, 2, 3, -10, -5, -1};
        REQUIRE(Solution::search(nums, -10) == 3);
    }
}
