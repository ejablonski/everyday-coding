#include "16.3sum_closest.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC16;

TEST_CASE("LeetCode 16 - 3Sum Closest", "[LeetCode][16][array][two-pointers][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [-1,2,1,-4], target = 1")
    {
        std::vector<int> nums = {-1, 2, 1, -4};
        REQUIRE(Solution::threeSumClosest(nums, 1) == 2);
    }

    SECTION("Example 2: nums = [0,0,0], target = 1")
    {
        std::vector<int> nums = {0, 0, 0};
        REQUIRE(Solution::threeSumClosest(nums, 1) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Exact target match exists")
    {
        std::vector<int> nums = {-3, -1, 1, 2, 5};
        REQUIRE(Solution::threeSumClosest(nums, 4) == 4);
    }

    SECTION("Minimum size (n = 3) with minimum element and target bounds")
    {
        std::vector<int> nums = {-1000, -1000, -1000};
        REQUIRE(Solution::threeSumClosest(nums, -10000) == -3000);
    }

    SECTION("Maximum element values and maximum target bound")
    {
        std::vector<int> nums = {1000, 1000, 1000, -1000};
        REQUIRE(Solution::threeSumClosest(nums, 10000) == 3000);
    }

    SECTION("Closest sum is strictly less than target")
    {
        std::vector<int> nums = {1, 2, 5, 10, 20};
        REQUIRE(Solution::threeSumClosest(nums, 19) == 17);
    }

    SECTION("All negative values with duplicates")
    {
        std::vector<int> nums = {-10, -10, -5, -2, -1};
        REQUIRE(Solution::threeSumClosest(nums, -9) == -8);
    }

    SECTION("Negative target with mixed positive and negative elements")
    {
        std::vector<int> nums = {-7, -3, 0, 2, 9};
        REQUIRE(Solution::threeSumClosest(nums, -6) == -5);
    }
}
