#include "912.sort_an_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC912;

TEST_CASE("LeetCode 912 - Sort an Array",
          "[LeetCode][912][array][divide-and-conquer][sorting][heap][priority-queue][merge-sort]"
          "[bucket-sort][radix-sort][counting-sort]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [5,2,3,1]")
    {
        std::vector<int> nums = {5, 2, 3, 1};
        std::vector<int> expected = {1, 2, 3, 5};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("Example 2: nums = [5,1,1,2,0,0]")
    {
        std::vector<int> nums = {5, 1, 1, 2, 0, 0};
        std::vector<int> expected = {0, 0, 1, 1, 2, 5};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (minimum length)")
    {
        std::vector<int> nums = {0};
        std::vector<int> expected = {0};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("Already sorted with boundary values [-50000, 50000]")
    {
        std::vector<int> nums = {-50000, -1, 0, 1, 50000};
        std::vector<int> expected = {-50000, -1, 0, 1, 50000};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("Reverse sorted descending with boundary values")
    {
        std::vector<int> nums = {50000, 100, 0, -100, -50000};
        std::vector<int> expected = {-50000, -100, 0, 100, 50000};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("All elements identical")
    {
        std::vector<int> nums = {7, 7, 7, 7, 7, 7};
        std::vector<int> expected = {7, 7, 7, 7, 7, 7};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("All negative values with duplicates")
    {
        std::vector<int> nums = {-3, -1, -4, -1, -5, -9, -2, -6};
        std::vector<int> expected = {-9, -6, -5, -4, -3, -2, -1, -1};
        REQUIRE(Solution::sortArray(nums) == expected);
    }

    SECTION("Two elements in descending order")
    {
        std::vector<int> nums = {2, -2};
        std::vector<int> expected = {-2, 2};
        REQUIRE(Solution::sortArray(nums) == expected);
    }
}
