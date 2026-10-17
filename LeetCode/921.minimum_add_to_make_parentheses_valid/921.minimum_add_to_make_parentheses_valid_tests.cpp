#include "921.minimum_add_to_make_parentheses_valid.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 921 - Minimum Add to Make Parentheses Valid",
          "[LeetCode][921][string][stack][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"())\"")
    {
        REQUIRE(Solution::minAddToMakeValid("())") == 1);
    }

    SECTION("Example 2: s = \"(((\"")
    {
        REQUIRE(Solution::minAddToMakeValid("(((") == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single opening bracket (minimum constraint length 1): s = \"(\"")
    {
        REQUIRE(Solution::minAddToMakeValid("(") == 1);
    }

    SECTION("Single closing bracket (minimum constraint length 1): s = \")\"")
    {
        REQUIRE(Solution::minAddToMakeValid(")") == 1);
    }

    SECTION("Already valid simple and nested parentheses: s = \"()\", s = \"(())\"")
    {
        REQUIRE(Solution::minAddToMakeValid("()") == 0);
        REQUIRE(Solution::minAddToMakeValid("(())") == 0);
        REQUIRE(Solution::minAddToMakeValid("()()((()))") == 0);
    }

    SECTION("Inverted brackets: s = \")(\"")
    {
        REQUIRE(Solution::minAddToMakeValid(")(") == 2);
    }

    SECTION("All closing brackets: s = \")))\"")
    {
        REQUIRE(Solution::minAddToMakeValid(")))") == 3);
    }

    SECTION("Mixed unmatched brackets: s = \"()))((\"")
    {
        REQUIRE(Solution::minAddToMakeValid("()))((") == 4);
    }

    SECTION("Maximum boundary length (1000 brackets): perfectly balanced")
    {
        const std::string s = std::string(500, '(') + std::string(500, ')');
        REQUIRE(Solution::minAddToMakeValid(s) == 0);
    }

    SECTION("Maximum boundary length (1000 brackets): all opening")
    {
        const std::string s = std::string(1000, '(');
        REQUIRE(Solution::minAddToMakeValid(s) == 1000);
    }
}
