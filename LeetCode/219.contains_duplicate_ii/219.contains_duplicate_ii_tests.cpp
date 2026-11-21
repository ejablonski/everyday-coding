#include "219.contains_duplicate_ii.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC219;

TEST_CASE("LeetCode 219 - Contains Duplicate II",
          "[LeetCode][219][array][hash-table][sliding-window]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1,2,3,1], k = 3")
    {
        std::vector<int> nums = {1, 2, 3, 1};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 3) == true);
    }

    SECTION("Example 2: nums = [1,0,1,1], k = 1")
    {
        std::vector<int> nums = {1, 0, 1, 1};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 1) == true);
    }

    SECTION("Example 3: nums = [1,2,3,1,2,3], k = 2")
    {
        std::vector<int> nums = {1, 2, 3, 1, 2, 3};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 2) == false);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("k = 0 always returns false even with adjacent duplicates")
    {
        std::vector<int> nums = {1, 1, 1};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 0) == false);
    }

    SECTION("Single element (minimum constraint n = 1)")
    {
        std::vector<int> nums = {7};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 5) == false);
    }

    SECTION("k larger than array length (maximum constraint k = 10^5)")
    {
        std::vector<int> nums = {4, 2, 7, 4};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 100000) == true);
    }

    SECTION("Duplicate at exact distance k vs k + 1")
    {
        std::vector<int> nums1 = {10, 20, 30, 40, 10};
        REQUIRE(Solution::containsNearbyDuplicate(nums1, 4) == true);

        std::vector<int> nums2 = {10, 20, 30, 40, 10};
        REQUIRE(Solution::containsNearbyDuplicate(nums2, 3) == false);
    }

    SECTION("Boundary values (-10^9 and 10^9)")
    {
        std::vector<int> nums = {-1000000000, 1000000000, 0, -1000000000};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 3) == true);
    }

    SECTION("Earlier duplicate out of range but later duplicate within range")
    {
        std::vector<int> nums = {5, 1, 2, 3, 5, 4, 5};
        REQUIRE(Solution::containsNearbyDuplicate(nums, 2) == true);
    }
}
