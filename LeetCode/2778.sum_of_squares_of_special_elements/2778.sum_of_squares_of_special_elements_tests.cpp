#include "2778.sum_of_squares_of_special_elements.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 2778 - Sum of Squares of Special Elements", "[LeetCode][2778][array][math][simulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1,2,3,4]")
    {
        std::vector<int> nums = {1, 2, 3, 4};
        REQUIRE(Solution::sumOfSquares(nums) == 21);
    }

    SECTION("Example 2: nums = [2,7,1,19,18,3]")
    {
        std::vector<int> nums = {2, 7, 1, 19, 18, 3};
        REQUIRE(Solution::sumOfSquares(nums) == 63);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single element array (n = 1)")
    {
        std::vector<int> nums = {5};
        REQUIRE(Solution::sumOfSquares(nums) == 25);
    }

    SECTION("Prime length array: only 1 and n divide n")
    {
        std::vector<int> nums = {3, 4, 5};
        REQUIRE(Solution::sumOfSquares(nums) == 34);
    }

    SECTION("Boundary values: maximum allowed elements")
    {
        std::vector<int> nums = {50, 50};
        REQUIRE(Solution::sumOfSquares(nums) == 5000);
    }
}
