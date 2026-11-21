#include "41.first_missing_positive.hpp"

#include <catch2/catch_test_macros.hpp>
#include <limits>
#include <vector>

using namespace LC41;

TEST_CASE("LeetCode 41 - First Missing Positive", "[LeetCode][41][array][hash-table]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1, 2, 0]")
    {
        std::vector<int> nums = {1, 2, 0};
        REQUIRE(Solution::firstMissingPositive(nums) == 3);
    }

    SECTION("Example 2: nums = [3, 4, -1, 1]")
    {
        std::vector<int> nums = {3, 4, -1, 1};
        REQUIRE(Solution::firstMissingPositive(nums) == 2);
    }

    SECTION("Example 3: nums = [7, 8, 9, 11, 12]")
    {
        std::vector<int> nums = {7, 8, 9, 11, 12};
        REQUIRE(Solution::firstMissingPositive(nums) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element equal to 1: nums = [1]")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::firstMissingPositive(nums) == 2);
    }

    SECTION("Single non-positive element: nums = [0]")
    {
        std::vector<int> nums = {0};
        REQUIRE(Solution::firstMissingPositive(nums) == 1);
    }

    SECTION("Extreme 32-bit integer boundaries and negatives")
    {
        std::vector<int> nums = {
            std::numeric_limits<int>::min(), -100, 0, std::numeric_limits<int>::max()};
        REQUIRE(Solution::firstMissingPositive(nums) == 1);
    }

    SECTION("Consecutive 1..n in reverse order: nums = [5, 4, 3, 2, 1]")
    {
        std::vector<int> nums = {5, 4, 3, 2, 1};
        REQUIRE(Solution::firstMissingPositive(nums) == 6);
    }

    SECTION("Duplicate valid positive values: nums = [1, 1, 2, 2, 3, 3]")
    {
        std::vector<int> nums = {1, 1, 2, 2, 3, 3};
        REQUIRE(Solution::firstMissingPositive(nums) == 4);
    }

    SECTION("Mixed duplicates, negatives, and large values with gap in middle")
    {
        std::vector<int> nums = {2, 2, -3, 1, 4, 100, 1};
        REQUIRE(Solution::firstMissingPositive(nums) == 3);
    }
}
