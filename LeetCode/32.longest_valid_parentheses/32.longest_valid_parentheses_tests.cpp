#include "32.longest_valid_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 32 - Longest Valid Parentheses",
          "[LeetCode][32][string][dynamic-programming][stack]")
{
    SECTION("Example 1: s = \"(()\"")
    {
        std::string s = "(()";
        REQUIRE(Solution::longestValidParentheses(s) == 2);
    }

    SECTION("Example 2: s = \")()())\"")
    {
        std::string s = ")()())";
        REQUIRE(Solution::longestValidParentheses(s) == 4);
    }

    SECTION("Example 3: empty string")
    {
        std::string s = "";
        REQUIRE(Solution::longestValidParentheses(s) == 0);
    }

    SECTION("Valid nested parentheses")
    {
        std::string s = "(((())))";
        REQUIRE(Solution::longestValidParentheses(s) == 8);
    }

    SECTION("Multiple disconnected valid segments")
    {
        std::string s = "()()";
        REQUIRE(Solution::longestValidParentheses(s) == 4);
    }

    SECTION("Consecutive valid segments")
    {
        std::string s = "()(())";
        REQUIRE(Solution::longestValidParentheses(s) == 6);
    }

    SECTION("Invalid opening only")
    {
        std::string s = "(((((";
        REQUIRE(Solution::longestValidParentheses(s) == 0);
    }

    SECTION("Invalid closing only")
    {
        std::string s = "))))))";
        REQUIRE(Solution::longestValidParentheses(s) == 0);
    }

    SECTION("Valid ending early")
    {
        std::string s = "(()))";
        REQUIRE(Solution::longestValidParentheses(s) == 4);
    }
}
