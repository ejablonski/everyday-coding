#include "493.reverse_pairs.hpp"

#include <catch2/catch_test_macros.hpp>
#include <limits>
#include <vector>

using namespace LC493;

TEST_CASE("LeetCode 493 - Reverse Pairs",
          "[LeetCode][493][array][binary-search][divide-and-conquer][binary-indexed-tree]"
          "[segment-tree][merge-sort][ordered-set][treap]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1,3,2,3,1]")
    {
        std::vector<int> nums = {1, 3, 2, 3, 1};
        REQUIRE(Solution::reversePairs(nums) == 2);
    }

    SECTION("Example 2: nums = [2,4,3,5,1]")
    {
        std::vector<int> nums = {2, 4, 3, 5, 1};
        REQUIRE(Solution::reversePairs(nums) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (minimum constraint n = 1)")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::reversePairs(nums) == 0);
    }

    SECTION("Exact equality nums[i] == 2 * nums[j] is not a reverse pair")
    {
        std::vector<int> nums = {8, 4, 2, 1};
        REQUIRE(Solution::reversePairs(nums) == 3);
    }

    SECTION("Negative duplicates satisfy nums[i] > 2 * nums[j]")
    {
        std::vector<int> nums = {-5, -5};
        REQUIRE(Solution::reversePairs(nums) == 1);
    }

    SECTION("Values at INT_MAX boundary")
    {
        constexpr int kMax = std::numeric_limits<int>::max();
        std::vector<int> nums = {kMax, kMax, kMax, kMax};
        REQUIRE(Solution::reversePairs(nums) == 0);
    }

    SECTION("Mix of INT_MIN and INT_MAX values")
    {
        constexpr int kMax = std::numeric_limits<int>::max();
        constexpr int kMin = std::numeric_limits<int>::min();
        std::vector<int> nums = {kMax, 1073741823, kMin, kMin};
        REQUIRE(Solution::reversePairs(nums) == 6);
    }

    SECTION("Sorted non-negative array with zeros has no reverse pairs")
    {
        std::vector<int> nums = {0, 0, 0, 1, 2, 5};
        REQUIRE(Solution::reversePairs(nums) == 0);
    }

    SECTION("Strictly decreasing array where every pair is a reverse pair")
    {
        std::vector<int> nums = {100, 40, 15, 5, 1};
        REQUIRE(Solution::reversePairs(nums) == 10);
    }
}
