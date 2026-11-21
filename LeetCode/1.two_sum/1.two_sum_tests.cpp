#include "1.two_sum.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC1;

TEST_CASE("LeetCode 1 - Two Sum", "[LeetCode][1][array][hash-table]")
{
    using Catch::Matchers::UnorderedEquals;

    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [2, 7, 11, 15], target = 9")
    {
        std::vector<int> nums = {2, 7, 11, 15};
        REQUIRE_THAT(Solution::twoSum(nums, 9), UnorderedEquals(std::vector<int>{0, 1}));
    }

    SECTION("Example 2: nums = [3, 2, 4], target = 6")
    {
        std::vector<int> nums = {3, 2, 4};
        REQUIRE_THAT(Solution::twoSum(nums, 6), UnorderedEquals(std::vector<int>{1, 2}));
    }

    SECTION("Example 3: nums = [3, 3], target = 6")
    {
        std::vector<int> nums = {3, 3};
        REQUIRE_THAT(Solution::twoSum(nums, 6), UnorderedEquals(std::vector<int>{0, 1}));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("All negative values summing to negative target")
    {
        std::vector<int> nums = {-10, -3, -7, -1};
        REQUIRE_THAT(Solution::twoSum(nums, -13), UnorderedEquals(std::vector<int>{0, 1}));
    }

    SECTION("Mixed negative, zero, and positive with zero target")
    {
        std::vector<int> nums = {-4, 0, 5, 4, 2};
        REQUIRE_THAT(Solution::twoSum(nums, 0), UnorderedEquals(std::vector<int>{0, 3}));
    }

    SECTION("Duplicate zeros summing to zero")
    {
        std::vector<int> nums = {0, 4, 3, 0};
        REQUIRE_THAT(Solution::twoSum(nums, 0), UnorderedEquals(std::vector<int>{0, 3}));
    }

    SECTION("Solution at endpoints while half-target element appears once")
    {
        std::vector<int> nums = {5, 1, 7, 2, 9};
        REQUIRE_THAT(Solution::twoSum(nums, 14), UnorderedEquals(std::vector<int>{0, 4}));
    }

    SECTION("Large constraint boundary values near +/-10^9")
    {
        std::vector<int> nums = {-1000000000, 500000000, 1000000000, 499999999};
        REQUIRE_THAT(Solution::twoSum(nums, 999999999), UnorderedEquals(std::vector<int>{1, 3}));
    }
}
