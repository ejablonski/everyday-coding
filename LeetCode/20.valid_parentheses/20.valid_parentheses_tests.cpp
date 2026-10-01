#include "20.valid_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 20 - Valid Parentheses", "[LeetCode][20][stack][string]")
{
    Solution solution;

    SECTION("Example 1: s = \"()\"")
    {
        std::string s = "()";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Example 2: s = \"()[]{}\"")
    {
        std::string s = "()[]{}";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Example 3: s = \"(]\"")
    {
        std::string s = "(]";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Example 4: s = \"([])\"")
    {
        std::string s = "([])";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Example 5: s = \"([)]\"")
    {
        std::string s = "([)]";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Single opening bracket: s = \"[\"")
    {
        std::string s = "[";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Single closing bracket: s = \"]\"")
    {
        std::string s = "]";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Reversed brackets: s = \")(\"")
    {
        std::string s = ")(";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Unclosed brackets at the end: s = \"()(\"")
    {
        std::string s = "()(";
        REQUIRE(solution.isValid(s) == false);
    }

    SECTION("Complex nested valid: s = \"{[()]()}\"")
    {
        std::string s = "{[()]()}";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Deeply nested valid brackets")
    {
        std::string s = "(((((((((())))))))))";
        REQUIRE(solution.isValid(s) == true);
    }

    SECTION("Mismatched opening and closing counts: s = \"((())\"")
    {
        std::string s = "((())";
        REQUIRE(solution.isValid(s) == false);
    }
}
