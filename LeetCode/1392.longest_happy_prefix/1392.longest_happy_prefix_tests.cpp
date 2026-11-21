#include "1392.longest_happy_prefix.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC1392;

TEST_CASE("LeetCode 1392 - Longest Happy Prefix",
          "[LeetCode][1392][string][rolling-hash][string-matching][hash-function]"
          "[z-algorithm][knuth-morris-pratt-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"level\"")
    {
        REQUIRE(Solution::longestPrefix("level") == "l");
    }

    SECTION("Example 2: s = \"ababab\"")
    {
        REQUIRE(Solution::longestPrefix("ababab") == "abab");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single character has no proper prefix/suffix (minimum constraint n = 1)")
    {
        REQUIRE(Solution::longestPrefix("a") == "");
    }

    SECTION("No happy prefix exists")
    {
        REQUIRE(Solution::longestPrefix("abcdef") == "");
    }

    SECTION("All identical characters returns length n - 1")
    {
        REQUIRE(Solution::longestPrefix("aaaaa") == "aaaa");
    }

    SECTION("Two identical characters")
    {
        REQUIRE(Solution::longestPrefix("aa") == "a");
    }

    SECTION("Nested repeating pattern")
    {
        REQUIRE(Solution::longestPrefix("abacaba") == "aba");
    }

    SECTION("Periodic overlapping happy prefix")
    {
        REQUIRE(Solution::longestPrefix("abcabcabc") == "abcabc");
    }
}
