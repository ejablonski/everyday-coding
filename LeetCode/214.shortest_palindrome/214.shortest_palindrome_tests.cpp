#include "214.shortest_palindrome.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC214;

TEST_CASE("LeetCode 214 - Shortest Palindrome",
          "[LeetCode][214][string][rolling-hash][string-matching][hash-function]"
          "[manacher][z-algorithm][knuth-morris-pratt-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"aacecaaa\"")
    {
        REQUIRE(Solution::shortestPalindrome("aacecaaa") == "aaacecaaa");
    }

    SECTION("Example 2: s = \"abcd\"")
    {
        REQUIRE(Solution::shortestPalindrome("abcd") == "dcbabcd");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Empty string (minimum constraint n = 0)")
    {
        REQUIRE(Solution::shortestPalindrome("") == "");
    }

    SECTION("Single character")
    {
        REQUIRE(Solution::shortestPalindrome("a") == "a");
    }

    SECTION("Already a palindrome")
    {
        REQUIRE(Solution::shortestPalindrome("racecar") == "racecar");
    }

    SECTION("Even-length palindromic prefix")
    {
        REQUIRE(Solution::shortestPalindrome("abbacd") == "dcabbacd");
    }

    SECTION("Palindrome appears only in suffix, not prefix")
    {
        REQUIRE(Solution::shortestPalindrome("baaa") == "aaabaaa");
    }

    SECTION("Odd-length palindromic prefix with longer trailing suffix")
    {
        REQUIRE(Solution::shortestPalindrome("abacdfg") == "gfdcabacdfg");
    }
}
