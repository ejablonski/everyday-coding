#include "l3q2.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Pascal's Triangle", "[LeetCode][quest][maths][l3q2]")
{
    Solution solution;

    SECTION("Example 1: numRows = 5")
    {
        std::vector<std::vector<int>> expected = {
            {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        REQUIRE(solution.generate(5) == expected);
    }

    SECTION("Example 2: numRows = 1")
    {
        std::vector<std::vector<int>> expected = {{1}};
        REQUIRE(solution.generate(1) == expected);
    }

    SECTION("numRows = 2")
    {
        std::vector<std::vector<int>> expected = {{1}, {1, 1}};
        REQUIRE(solution.generate(2) == expected);
    }
}
