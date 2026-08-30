#include "l2q3.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Self Dividing Numbers", "[LeetCode][quest][maths][l2q3]")
{
    Solution solution;

    SECTION("Example 1: left = 1, right = 22")
    {
        REQUIRE(solution.selfDividingNumbers(1, 22) ==
                std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22});
    }
    SECTION("Example 2: left = 47, right = 85")
    {
        REQUIRE(solution.selfDividingNumbers(47, 85) == std::vector<int>{48, 55, 66, 77});
    }
    SECTION("Single number valid: 128")
    {
        REQUIRE(solution.selfDividingNumbers(128, 128) == std::vector<int>{128});
    }
    SECTION("Single number invalid: 10")
    {
        REQUIRE(solution.selfDividingNumbers(10, 10).empty());
    }
    SECTION("Range with no valid numbers: 20 to 21")
    {
        REQUIRE(solution.selfDividingNumbers(20, 21).empty());
    }
    SECTION("Range with zeroes: 100 to 110")
    {
        REQUIRE(solution.selfDividingNumbers(100, 110).empty());
    }
}
