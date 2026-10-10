#include "2333.minimum_sum_of_squared_difference.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2333 - Minimum Sum of Squared Difference", "[LeetCode][2333][array][math][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: k1 = 0, k2 = 0")
    {
        std::vector<int> nums1 = {1, 2, 3, 4};
        std::vector<int> nums2 = {2, 10, 20, 19};
        int k1 = 0;
        int k2 = 0;
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 579);
    }

    SECTION("Example 2: k1 = 1, k2 = 1")
    {
        std::vector<int> nums1 = {1, 4, 10, 12};
        std::vector<int> nums2 = {5, 8, 6, 9};
        int k1 = 1;
        int k2 = 1;
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 43);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element array, exact k to reduce difference to zero")
    {
        std::vector<int> nums1 = {10};
        std::vector<int> nums2 = {5};
        int k1 = 2;
        int k2 = 3;
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 0);
    }

    SECTION("Total k is significantly larger than absolute difference")
    {
        std::vector<int> nums1 = {1, 1};
        std::vector<int> nums2 = {2, 2};
        int k1 = 10;
        int k2 = 10;
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 0);
    }

    SECTION("Zero difference initially, k > 0")
    {
        std::vector<int> nums1 = {5, 5};
        std::vector<int> nums2 = {5, 5};
        int k1 = 2;
        int k2 = 2;
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 0);
    }

    SECTION("Large values testing 64-bit integer overflow")
    {
        std::vector<int> nums1 = {100000, 100000};
        std::vector<int> nums2 = {0, 0};
        int k1 = 0;
        int k2 = 0;
        // Difference is 10^5, squared is 10^10 per element, sum is 2 * 10^10.
        REQUIRE(Solution::minSumSquareDiff(nums1, nums2, k1, k2) == 20000000000LL);
    }
}
