#include "1021.remove_outermost_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 1021 - Remove Outermost Parentheses", "[LeetCode][1021][string][stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"(()())(())\"")
    {
        std::string s = "(()())(())";
        REQUIRE(Solution::removeOuterParentheses(s) == "()()()");
    }

    SECTION("Example 2: s = \"(()())(())(()(()))\"")
    {
        std::string s = "(()())(())(()(()))";
        REQUIRE(Solution::removeOuterParentheses(s) == "()()()()(())");
    }

    SECTION("Example 3: s = \"()()\"")
    {
        std::string s = "()()";
        REQUIRE(Solution::removeOuterParentheses(s) == "");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single primitive valid string: s = \"(())\"")
    {
        std::string s = "(())";
        REQUIRE(Solution::removeOuterParentheses(s) == "()");
    }

    SECTION("Deeply nested single primitive: s = \"(((())))\"")
    {
        std::string s = "(((())))";
        REQUIRE(Solution::removeOuterParentheses(s) == "((()))");
    }

    SECTION("Empty strings result from minimal primitives: s = \"()()()()\"")
    {
        std::string s = "()()()()";
        REQUIRE(Solution::removeOuterParentheses(s) == "");
    }
}
