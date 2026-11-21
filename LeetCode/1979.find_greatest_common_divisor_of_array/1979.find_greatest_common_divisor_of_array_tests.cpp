#include "1979.find_greatest_common_divisor_of_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1979;

TEST_CASE(
    "LeetCode 1979 - Find Greatest Common Divisor of Array",
    "[LeetCode][1979][array][math][number-theory][euclidean-algorithm][greatest-common-divisor]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [2,5,6,9,10]")
    {
        std::vector<int> nums = {2, 5, 6, 9, 10};
        REQUIRE(Solution::findGCD(nums) == 2);
    }

    SECTION("Example 2: nums = [7,5,6,8,3]")
    {
        std::vector<int> nums = {7, 5, 6, 8, 3};
        REQUIRE(Solution::findGCD(nums) == 1);
    }

    SECTION("Example 3: nums = [3,3]")
    {
        std::vector<int> nums = {3, 3};
        REQUIRE(Solution::findGCD(nums) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Boundary values: minimum 1 and maximum 1000")
    {
        std::vector<int> nums = {1, 1000};
        REQUIRE(Solution::findGCD(nums) == 1);
    }

    SECTION("Both elements at maximum value 1000")
    {
        std::vector<int> nums = {1000, 1000};
        REQUIRE(Solution::findGCD(nums) == 1000);
    }

    SECTION("Non-trivial GCD strictly less than minimum element")
    {
        std::vector<int> nums = {12, 18, 15};
        REQUIRE(Solution::findGCD(nums) == 6);
    }

    SECTION("Consecutive Fibonacci numbers as min and max (coprime)")
    {
        std::vector<int> nums = {610, 987, 750};
        REQUIRE(Solution::findGCD(nums) == 1);
    }

    SECTION("Unsorted array with duplicate minimum and maximum elements")
    {
        std::vector<int> nums = {36, 24, 48, 24, 48, 30};
        REQUIRE(Solution::findGCD(nums) == 24);
    }
}
