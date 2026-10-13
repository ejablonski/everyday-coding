#include "3727.maximum_alternating_sum_of_squares.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 3727 - Maximum Alternating Sum of Squares", "[LeetCode][3727][array][greedy][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1, 2, 3]")
    {
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(Solution::maxAlternatingSum(nums) == 12LL);
    }

    SECTION("Example 2: nums = [1, -1, 2, -2, 3, -3]")
    {
        std::vector<int> nums = {1, -1, 2, -2, 3, -3};
        REQUIRE(Solution::maxAlternatingSum(nums) == 16LL);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single positive element (minimum length n = 1): nums = [5]")
    {
        std::vector<int> nums = {5};
        REQUIRE(Solution::maxAlternatingSum(nums) == 25LL);
    }

    SECTION("Single negative boundary element: nums = [-40000]")
    {
        std::vector<int> nums = {-40000};
        REQUIRE(Solution::maxAlternatingSum(nums) == 1600000000LL);
    }

    SECTION("Two elements (n = 2): nums = [2, 3]")
    {
        std::vector<int> nums = {2, 3};
        REQUIRE(Solution::maxAlternatingSum(nums) == 5LL);
    }

    SECTION("Two elements with mixed signs: nums = [-3, 2]")
    {
        std::vector<int> nums = {-3, 2};
        REQUIRE(Solution::maxAlternatingSum(nums) == 5LL);
    }

    SECTION("All zeros: nums = [0, 0, 0]")
    {
        std::vector<int> nums = {0, 0, 0};
        REQUIRE(Solution::maxAlternatingSum(nums) == 0LL);
    }

    SECTION("Zero included with symmetric values: nums = [0, -5, 5]")
    {
        std::vector<int> nums = {0, -5, 5};
        REQUIRE(Solution::maxAlternatingSum(nums) == 50LL);
    }

    SECTION("All identical elements with even length (cancellation to zero): nums = [3, 3, 3, 3]")
    {
        std::vector<int> nums = {3, 3, 3, 3};
        REQUIRE(Solution::maxAlternatingSum(nums) == 0LL);
    }

    SECTION("Maximum boundary values: nums = [40000, -40000, 40000]")
    {
        std::vector<int> nums = {40000, -40000, 40000};
        REQUIRE(Solution::maxAlternatingSum(nums) == 1600000000LL);
    }
}
