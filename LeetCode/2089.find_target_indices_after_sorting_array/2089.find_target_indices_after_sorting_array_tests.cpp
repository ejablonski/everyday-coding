#include "2089.find_target_indices_after_sorting_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2089 - Find Target Indices After Sorting Array",
          "[LeetCode][2089][array][sorting][binary-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1, 2, 5, 2, 3], target = 2")
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        int target = 2;
        std::vector<int> expected{1, 2};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Example 2: nums = [1, 2, 5, 2, 3], target = 3")
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        int target = 3;
        std::vector<int> expected{3};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Example 3: nums = [1, 2, 5, 2, 3], target = 5")
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        int target = 5;
        std::vector<int> expected{4};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Target not found in array")
    {
        std::vector<int> nums{1, 2, 5, 2, 3};
        int target = 4;
        std::vector<int> expected{};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Single element matches target")
    {
        std::vector<int> nums{1};
        int target = 1;
        std::vector<int> expected{0};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Single element does not match target")
    {
        std::vector<int> nums{1};
        int target = 2;
        std::vector<int> expected{};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("All elements equal to target")
    {
        std::vector<int> nums{2, 2, 2, 2};
        int target = 2;
        std::vector<int> expected{0, 1, 2, 3};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Target smaller than all elements")
    {
        std::vector<int> nums{5, 6, 7};
        int target = 1;
        std::vector<int> expected{};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Target larger than all elements")
    {
        std::vector<int> nums{5, 6, 7};
        int target = 10;
        std::vector<int> expected{};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }

    SECTION("Boundary values: min 1 and max 100")
    {
        std::vector<int> nums{100, 1, 100, 1};
        int target = 100;
        std::vector<int> expected{2, 3};
        REQUIRE(Solution::targetIndices(nums, target) == expected);
    }
}
