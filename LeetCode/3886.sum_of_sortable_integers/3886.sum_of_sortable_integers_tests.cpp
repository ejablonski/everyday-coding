#include "3886.sum_of_sortable_integers.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 3886 - Sum of Sortable Integers", "[LeetCode][3886][array][math]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [3, 1, 2]")
    {
        std::vector<int> nums{3, 1, 2};
        REQUIRE(Solution::sortableIntegers(nums) == 3);
    }

    SECTION("Example 2: nums = [7, 6, 5]")
    {
        std::vector<int> nums{7, 6, 5};
        REQUIRE(Solution::sortableIntegers(nums) == 0);
    }

    SECTION("Example 3: nums = [5, 8]")
    {
        std::vector<int> nums{5, 8};
        REQUIRE(Solution::sortableIntegers(nums) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element array: nums = [42]")
    {
        std::vector<int> nums{42};
        REQUIRE(Solution::sortableIntegers(nums) == 1);
    }

    SECTION("All elements identical: nums = [3, 3, 3, 3]")
    {
        std::vector<int> nums{3, 3, 3, 3};
        REQUIRE(Solution::sortableIntegers(nums) == 7);
    }

    SECTION("Already sorted array: nums = [1, 2, 3, 4]")
    {
        std::vector<int> nums{1, 2, 3, 4};
        REQUIRE(Solution::sortableIntegers(nums) == 7);
    }

    SECTION("Reverse-sorted array: nums = [4, 3, 2, 1]")
    {
        std::vector<int> nums{4, 3, 2, 1};
        REQUIRE(Solution::sortableIntegers(nums) == 0);
    }

    SECTION("Subarray length 2 is sortable: nums = [2, 1, 4, 3]")
    {
        std::vector<int> nums{2, 1, 4, 3};
        REQUIRE(Solution::sortableIntegers(nums) == 2);
    }

    SECTION("Subarray length 3 is sortable: nums = [2, 3, 1, 5, 6, 4]")
    {
        std::vector<int> nums{2, 3, 1, 5, 6, 4};
        REQUIRE(Solution::sortableIntegers(nums) == 3);
    }
}
