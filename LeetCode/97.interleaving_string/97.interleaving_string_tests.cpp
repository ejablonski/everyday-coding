#include "97.interleaving_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC97;

TEST_CASE("LeetCode 97 - Interleaving String", "[LeetCode][97][string][dynamic-programming]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s1 = \"aabcc\", s2 = \"dbbca\", s3 = \"aadbbcbcac\"")
    {
        REQUIRE(Solution::isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    }

    SECTION("Example 2: s1 = \"aabcc\", s2 = \"dbbca\", s3 = \"aadbbbaccc\"")
    {
        REQUIRE_FALSE(Solution::isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    }

    SECTION("Example 3: s1 = \"\", s2 = \"\", s3 = \"\"")
    {
        REQUIRE(Solution::isInterleave("", "", ""));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Length mismatch returns false")
    {
        REQUIRE_FALSE(Solution::isInterleave("a", "b", "a"));
        REQUIRE_FALSE(Solution::isInterleave("", "", "a"));
    }

    SECTION("Empty s1 with matching s2 and s3")
    {
        REQUIRE(Solution::isInterleave("", "abc", "abc"));
    }

    SECTION("Empty s2 with non-matching s1 and s3")
    {
        REQUIRE_FALSE(Solution::isInterleave("abc", "", "acb"));
    }

    SECTION("Ambiguous shared prefixes")
    {
        REQUIRE(Solution::isInterleave("aa", "ab", "aaba"));
    }

    SECTION("Same character counts but invalid relative order")
    {
        REQUIRE_FALSE(Solution::isInterleave("ab", "cd", "badc"));
    }

    SECTION("Strict single-character alternation across both strings")
    {
        REQUIRE(Solution::isInterleave("abcde", "fghij", "afbgchdiej"));
    }
}
