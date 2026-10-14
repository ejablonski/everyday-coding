#include "3723.maximize_sum_of_squares_of_digits.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 3723 - Maximize Sum of Squares of Digits", "[LeetCode][3723][math][greedy][string]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: num = 2, sum = 3")
    {
        REQUIRE(Solution::maxSumOfSquares(2, 3) == "30");
    }

    SECTION("Example 2: num = 2, sum = 17")
    {
        REQUIRE(Solution::maxSumOfSquares(2, 17) == "98");
    }

    SECTION("Example 3: num = 1, sum = 10")
    {
        REQUIRE(Solution::maxSumOfSquares(1, 10) == "");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single digit minimum: num = 1, sum = 1")
    {
        REQUIRE(Solution::maxSumOfSquares(1, 1) == "1");
    }

    SECTION("Single digit maximum: num = 1, sum = 9")
    {
        REQUIRE(Solution::maxSumOfSquares(1, 9) == "9");
    }

    SECTION("Sum exceeds 9 * num (impossible): num = 2, sum = 19")
    {
        REQUIRE(Solution::maxSumOfSquares(2, 19) == "");
    }

    SECTION("Minimum sum for multi-digit: num = 3, sum = 1")
    {
        REQUIRE(Solution::maxSumOfSquares(3, 1) == "100");
    }

    SECTION("Sum strictly less than 9 with trailing zeros: num = 4, sum = 5")
    {
        REQUIRE(Solution::maxSumOfSquares(4, 5) == "5000");
    }

    SECTION("All maximum digits: num = 3, sum = 27")
    {
        REQUIRE(Solution::maxSumOfSquares(3, 27) == "999");
    }

    SECTION("Multiple nines with non-zero remainder and trailing zero: num = 4, sum = 20")
    {
        REQUIRE(Solution::maxSumOfSquares(4, 20) == "9920");
    }

    SECTION("Exact multiple of 9 with trailing zeros: num = 3, sum = 18")
    {
        REQUIRE(Solution::maxSumOfSquares(3, 18) == "990");
    }
}
