#include "520.detect_capital.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC520;

TEST_CASE("LeetCode 520 - Detect Capital", "[LeetCode][520][string]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: word = \"USA\"")
    {
        REQUIRE(Solution::detectCapitalUse("USA"));
    }

    SECTION("Example 2: word = \"FlaG\"")
    {
        REQUIRE_FALSE(Solution::detectCapitalUse("FlaG"));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("All lowercase letters: word = \"leetcode\"")
    {
        REQUIRE(Solution::detectCapitalUse("leetcode"));
    }

    SECTION("Title case (only first letter capital): word = \"Google\"")
    {
        REQUIRE(Solution::detectCapitalUse("Google"));
    }

    SECTION("Minimum length single uppercase letter: word = \"A\"")
    {
        REQUIRE(Solution::detectCapitalUse("A"));
    }

    SECTION("Minimum length single lowercase letter: word = \"a\"")
    {
        REQUIRE(Solution::detectCapitalUse("a"));
    }

    SECTION("Two-character casing combinations")
    {
        REQUIRE(Solution::detectCapitalUse("AB"));
        REQUIRE(Solution::detectCapitalUse("Ab"));
        REQUIRE(Solution::detectCapitalUse("ab"));
        REQUIRE_FALSE(Solution::detectCapitalUse("aB"));
    }

    SECTION("Two leading capitals followed by lowercase: word = \"USa\"")
    {
        REQUIRE_FALSE(Solution::detectCapitalUse("USa"));
    }

    SECTION("Lowercase prefix with internal capital: word = \"leetCode\"")
    {
        REQUIRE_FALSE(Solution::detectCapitalUse("leetCode"));
    }

    SECTION("Maximum constraint length (100 characters)")
    {
        REQUIRE(Solution::detectCapitalUse(std::string(100, 'a')));
        REQUIRE_FALSE(Solution::detectCapitalUse(std::string(99, 'A') + "a"));
    }
}
