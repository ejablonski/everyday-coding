#include "1569.number_of_ways_to_reorder_array_to_get_same_bst.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 1569 - Number of Ways to Reorder Array to Get Same BST",
          "[LeetCode][1569][array][math][tree][binary-search-tree][combinatorics]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [2, 1, 3]")
    {
        std::vector<int> nums{2, 1, 3};
        REQUIRE(Solution::numOfWays(nums) == 1);
    }

    SECTION("Example 2: nums = [3, 4, 5, 1, 2]")
    {
        std::vector<int> nums{3, 4, 5, 1, 2};
        REQUIRE(Solution::numOfWays(nums) == 5);
    }

    SECTION("Example 3: nums = [1, 2, 3]")
    {
        std::vector<int> nums{1, 2, 3};
        REQUIRE(Solution::numOfWays(nums) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum size single element: nums = [1]")
    {
        std::vector<int> nums{1};
        REQUIRE(Solution::numOfWays(nums) == 0);
    }

    SECTION("Two elements strictly decreasing: nums = [2, 1]")
    {
        std::vector<int> nums{2, 1};
        REQUIRE(Solution::numOfWays(nums) == 0);
    }

    SECTION("Strictly decreasing degenerate tree: nums = [3, 2, 1]")
    {
        std::vector<int> nums{3, 2, 1};
        REQUIRE(Solution::numOfWays(nums) == 0);
    }

    SECTION("Mixed subtree sizes: nums = [2, 1, 4, 3]")
    {
        std::vector<int> nums{2, 1, 4, 3};
        REQUIRE(Solution::numOfWays(nums) == 2);
    }

    SECTION("Balanced complete BST: nums = [4, 2, 6, 1, 3, 5, 7]")
    {
        std::vector<int> nums{4, 2, 6, 1, 3, 5, 7};
        REQUIRE(Solution::numOfWays(nums) == 79);
    }

    SECTION("Large input requiring modulo and 64-bit products: 36 elements")
    {
        std::vector<int> nums{31, 23, 14, 24, 15, 12, 25, 28, 5,  35, 17, 6,
                              9,  11, 1,  27, 18, 20, 2,  3,  33, 10, 13, 4,
                              7,  36, 32, 29, 8,  30, 26, 19, 34, 22, 21, 16};
        REQUIRE(Solution::numOfWays(nums) == 936157466);
    }
}
