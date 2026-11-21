#include "704.binary_search.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC704;

TEST_CASE("LeetCode 704 - Binary Search", "[LeetCode][704][array][binary-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [-1,0,3,5,9,12], target = 9")
    {
        std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
        REQUIRE(Solution::search(nums, 9) == 4);
    }

    SECTION("Example 2: nums = [-1,0,3,5,9,12], target = 2")
    {
        std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
        REQUIRE(Solution::search(nums, 2) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element found")
    {
        std::vector<int> nums = {5};
        REQUIRE(Solution::search(nums, 5) == 0);
    }

    SECTION("Single element not found")
    {
        std::vector<int> nums = {5};
        REQUIRE(Solution::search(nums, -5) == -1);
    }

    SECTION("Target at first index (minimum boundary value -9999)")
    {
        std::vector<int> nums = {-9999, -100, 0, 100, 9999};
        REQUIRE(Solution::search(nums, -9999) == 0);
    }

    SECTION("Target at last index (maximum boundary value 9999)")
    {
        std::vector<int> nums = {-9999, -100, 0, 100, 9999};
        REQUIRE(Solution::search(nums, 9999) == 4);
    }

    SECTION("Target smaller than all elements")
    {
        std::vector<int> nums = {1, 3, 5, 7, 9};
        REQUIRE(Solution::search(nums, -9999) == -1);
    }

    SECTION("Target larger than all elements")
    {
        std::vector<int> nums = {-50, -20, -10, -1};
        REQUIRE(Solution::search(nums, 9999) == -1);
    }
}
