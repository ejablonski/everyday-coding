#include "128.longest_consecutive_sequence.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC128;

TEST_CASE("LeetCode 128 - Longest Consecutive Sequence",
          "[LeetCode][128][array][hash-table][union-find]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [100,4,200,1,3,2]")
    {
        std::vector<int> nums = {100, 4, 200, 1, 3, 2};
        REQUIRE(Solution::longestConsecutive(nums) == 4);
    }

    SECTION("Example 2: nums = [0,3,7,2,5,8,4,6,0,1]")
    {
        std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        REQUIRE(Solution::longestConsecutive(nums) == 9);
    }

    SECTION("Example 3: nums = [1,0,1,2]")
    {
        std::vector<int> nums = {1, 0, 1, 2};
        REQUIRE(Solution::longestConsecutive(nums) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint empty array: nums = []")
    {
        std::vector<int> nums = {};
        REQUIRE(Solution::longestConsecutive(nums) == 0);
    }

    SECTION("Single element: nums = [42]")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::longestConsecutive(nums) == 1);
    }

    SECTION("All duplicate elements: nums = [5,5,5,5]")
    {
        std::vector<int> nums = {5, 5, 5, 5};
        REQUIRE(Solution::longestConsecutive(nums) == 1);
    }

    SECTION("Negative numbers crossing zero")
    {
        std::vector<int> nums = {-2, -3, -1, 0, 1, 10, 11};
        REQUIRE(Solution::longestConsecutive(nums) == 5);
    }

    SECTION("Extreme value boundaries: -10^9 and 10^9")
    {
        std::vector<int> nums = {-1000000000, -999999999, 999999998, 999999999, 1000000000};
        REQUIRE(Solution::longestConsecutive(nums) == 3);
    }

    SECTION("All elements isolated with no consecutive neighbors")
    {
        std::vector<int> nums = {10, 30, 50, 70, 90};
        REQUIRE(Solution::longestConsecutive(nums) == 1);
    }
}
