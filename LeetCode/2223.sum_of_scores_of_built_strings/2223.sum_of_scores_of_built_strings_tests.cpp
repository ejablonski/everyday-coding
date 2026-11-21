#include "2223.sum_of_scores_of_built_strings.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC2223;

TEST_CASE(
    "LeetCode 2223 - Sum of Scores of Built Strings",
    "[LeetCode][2223][string][binary-search][rolling-hash][suffix-array][string-matching]"
    "[hash-function][z-algorithm][knuth-morris-pratt-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"babab\"")
    {
        REQUIRE(Solution::sumScores("babab") == 9LL);
    }

    SECTION("Example 2: s = \"azbazbzaz\"")
    {
        REQUIRE(Solution::sumScores("azbazbzaz") == 14LL);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length single character: s = \"a\"")
    {
        REQUIRE(Solution::sumScores("a") == 1LL);
    }

    SECTION("All identical characters: s = \"aaaaa\"")
    {
        REQUIRE(Solution::sumScores("aaaaa") == 15LL);
    }

    SECTION("All distinct characters: s = \"abcdef\"")
    {
        REQUIRE(Solution::sumScores("abcdef") == 6LL);
    }

    SECTION("Periodic alternating string: s = \"ababab\"")
    {
        REQUIRE(Solution::sumScores("ababab") == 12LL);
    }

    SECTION("Overlapping partial prefix matches: s = \"aabaaab\"")
    {
        REQUIRE(Solution::sumScores("aabaaab") == 14LL);
    }

    SECTION("Maximum length identical characters")
    {
        std::string s(100000, 'a');
        REQUIRE(Solution::sumScores(s) == 5000050000LL);
    }
}
