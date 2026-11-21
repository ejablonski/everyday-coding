#include "424.longest_repeating_character_replacement.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC424;

TEST_CASE("LeetCode 424 - Longest Repeating Character Replacement",
          "[LeetCode][424][hash-table][string][sliding-window]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"ABAB\", k = 2")
    {
        REQUIRE(Solution::characterReplacement("ABAB", 2) == 4);
    }

    SECTION("Example 2: s = \"AABABBA\", k = 1")
    {
        REQUIRE(Solution::characterReplacement("AABABBA", 1) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single character with k = 0 (minimum constraints)")
    {
        REQUIRE(Solution::characterReplacement("Z", 0) == 1);
    }

    SECTION("k = 0 returns longest existing contiguous run")
    {
        REQUIRE(Solution::characterReplacement("AAABBBCCCCDD", 0) == 4);
    }

    SECTION("k equals string length converts entire string")
    {
        REQUIRE(Solution::characterReplacement("ABCDEF", 6) == 6);
    }

    SECTION("All characters identical with k = 0")
    {
        REQUIRE(Solution::characterReplacement("AAAAA", 0) == 5);
    }

    SECTION("Optimal window shifts to a different dominant letter near the end")
    {
        REQUIRE(Solution::characterReplacement("AAABCDDDDD", 1) == 6);
    }

    SECTION("Bridging two separated runs of the same character")
    {
        REQUIRE(Solution::characterReplacement("ABBBACBBB", 2) == 8);
    }
}
