#include "1358.number_of_substrings_containing_all_three_characters.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC1358;

TEST_CASE("LeetCode 1358 - Number of Substrings Containing All Three Characters",
          "[LeetCode][1358][hash-table][string][sliding-window]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"abcabc\"")
    {
        REQUIRE(Solution::numberOfSubstrings("abcabc") == 10);
    }

    SECTION("Example 2: s = \"aaacb\"")
    {
        REQUIRE(Solution::numberOfSubstrings("aaacb") == 3);
    }

    SECTION("Example 3: s = \"abc\"")
    {
        REQUIRE(Solution::numberOfSubstrings("abc") == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length (n = 3) missing one character")
    {
        REQUIRE(Solution::numberOfSubstrings("aab") == 0);
    }

    SECTION("Longer string containing only two distinct characters")
    {
        REQUIRE(Solution::numberOfSubstrings("ababababa") == 0);
    }

    SECTION("Third character appears only at the very end")
    {
        REQUIRE(Solution::numberOfSubstrings("aaaaabbbbbc") == 5);
    }

    SECTION("All three characters appear at the start followed by repeats")
    {
        REQUIRE(Solution::numberOfSubstrings("cbaccccc") == 11);
    }

    SECTION("Minimum length (n = 3) in reverse order")
    {
        REQUIRE(Solution::numberOfSubstrings("cba") == 1);
    }

    SECTION("Interleaved characters with repeated clusters")
    {
        REQUIRE(Solution::numberOfSubstrings("acbbcac") == 11);
    }
}
