#include "1541.minimum_insertions_to_balance_a_parentheses_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 1541 - Minimum Insertions to Balance a Parentheses String", "[LeetCode][1541][string][greedy][stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"(()))\"")
    {
        std::string s = "(()))";
        REQUIRE(Solution::minInsertions(s) == 1);
    }

    SECTION("Example 2: s = \"())\"")
    {
        std::string s = "())";
        REQUIRE(Solution::minInsertions(s) == 0);
    }

    SECTION("Example 3: s = \"))())(\"")
    {
        std::string s = "))())(";
        REQUIRE(Solution::minInsertions(s) == 3);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single opening parenthesis: s = \"(\"")
    {
        std::string s = "(";
        REQUIRE(Solution::minInsertions(s) == 2);
    }

    SECTION("Single closing parenthesis: s = \")\"")
    {
        std::string s = ")";
        REQUIRE(Solution::minInsertions(s) == 2);
    }

    SECTION("All opening parentheses: s = \"(((\"")
    {
        std::string s = "(((";
        REQUIRE(Solution::minInsertions(s) == 6);
    }

    SECTION("All closing parentheses: s = \"))))))\"")
    {
        std::string s = "))))))";
        REQUIRE(Solution::minInsertions(s) == 3);
    }
}
