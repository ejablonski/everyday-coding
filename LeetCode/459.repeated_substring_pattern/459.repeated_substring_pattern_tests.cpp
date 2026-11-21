#include "459.repeated_substring_pattern.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC459;

TEST_CASE("LeetCode 459 - Repeated Substring Pattern", "[LeetCode][459][string][string-matching]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"abab\"")
    {
        REQUIRE(Solution::repeatedSubstringPattern("abab"));
    }

    SECTION("Example 2: s = \"aba\"")
    {
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("aba"));
    }

    SECTION("Example 3: s = \"abcabcabcabc\"")
    {
        REQUIRE(Solution::repeatedSubstringPattern("abcabcabcabc"));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint single character: s = \"a\"")
    {
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("a"));
    }

    SECTION("Two identical characters: s = \"aa\"")
    {
        REQUIRE(Solution::repeatedSubstringPattern("aa"));
    }

    SECTION("Two distinct characters: s = \"ab\"")
    {
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("ab"));
    }

    SECTION("Odd prime length with all identical characters: s = \"aaaaa\"")
    {
        REQUIRE(Solution::repeatedSubstringPattern("aaaaa"));
    }

    SECTION("Odd prime length with no repeated pattern: s = \"abcde\"")
    {
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("abcde"));
    }

    SECTION("Partial repeating substrings that do not tile the whole string")
    {
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("abac"));
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("ababa"));
        REQUIRE_FALSE(Solution::repeatedSubstringPattern("ababba"));
    }

    SECTION("Longer repeating pattern: s = \"abaababaab\"")
    {
        REQUIRE(Solution::repeatedSubstringPattern("abaababaab"));
    }
}
