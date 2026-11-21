#include "686.repeated_string_match.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC686;

TEST_CASE("LeetCode 686 - Repeated String Match", "[LeetCode][686][string][string-matching]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: a = \"abcd\", b = \"cdabcdab\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abcd", "cdabcdab") == 3);
    }

    SECTION("Example 2: a = \"a\", b = \"aa\"")
    {
        REQUIRE(Solution::repeatedStringMatch("a", "aa") == 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: a = \"a\", b = \"a\"")
    {
        REQUIRE(Solution::repeatedStringMatch("a", "a") == 1);
    }

    SECTION("b is already a substring of a (1 repetition): a = \"abcdef\", b = \"cde\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abcdef", "cde") == 1);
    }

    SECTION("b shorter than a but wraps across boundary: a = \"abcd\", b = \"da\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abcd", "da") == 2);
    }

    SECTION("Match spanning boundaries on both ends: a = \"abc\", b = \"cabcabca\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abc", "cabcabca") == 4);
    }

    SECTION("Exact multiple with no offset: a = \"xyz\", b = \"xyzxyzxyz\"")
    {
        REQUIRE(Solution::repeatedStringMatch("xyz", "xyzxyzxyz") == 3);
    }

    SECTION("Impossible despite matching character set: a = \"abcd\", b = \"abdc\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abcd", "abdc") == -1);
    }

    SECTION("Impossible due to unseen character: a = \"abc\", b = \"xyz\"")
    {
        REQUIRE(Solution::repeatedStringMatch("abc", "xyz") == -1);
    }
}
