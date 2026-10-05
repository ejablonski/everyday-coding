#include "856.score_of_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 856 - Score of Parentheses", "[LeetCode][856][string][stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"()\"")
    {
        std::string s = "()";
        REQUIRE(Solution::scoreOfParentheses(s) == 1);
    }

    SECTION("Example 2: s = \"(())\"")
    {
        std::string s = "(())";
        REQUIRE(Solution::scoreOfParentheses(s) == 2);
    }

    SECTION("Example 3: s = \"()()\"")
    {
        std::string s = "()()";
        REQUIRE(Solution::scoreOfParentheses(s) == 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Deeply nested string")
    {
        std::string s = "((((()))))";
        REQUIRE(Solution::scoreOfParentheses(s) == 16);
    }

    SECTION("Multiple adjacent components")
    {
        std::string s = "()()()()";
        REQUIRE(Solution::scoreOfParentheses(s) == 4);
    }

    SECTION("Complex combination: s = \"(()(()))\"")
    {
        std::string s = "(()(()))";
        // inner: () = 1, (()) = 2 => sum = 3. Outer bracket multiplies by 2 => 6
        REQUIRE(Solution::scoreOfParentheses(s) == 6);
    }

    SECTION("Max constraint length: 50 characters (25 pairs nested)")
    {
        std::string s(25, '(');
        s.append(25, ')');
        // Score is 2^24 = 16777216
        REQUIRE(Solution::scoreOfParentheses(s) == 16777216);
    }
}
