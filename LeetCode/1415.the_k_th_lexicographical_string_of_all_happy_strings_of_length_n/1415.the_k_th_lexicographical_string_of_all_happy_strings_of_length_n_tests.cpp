#include "1415.the_k_th_lexicographical_string_of_all_happy_strings_of_length_n.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC1415;

TEST_CASE("LeetCode 1415 - The k-th Lexicographical String of All Happy Strings of Length n",
          "[LeetCode][1415][string][backtracking]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 1, k = 3")
    {
        REQUIRE(Solution::getHappyString(1, 3) == "c");
    }

    SECTION("Example 2: n = 1, k = 4")
    {
        REQUIRE(Solution::getHappyString(1, 4).empty());
    }

    SECTION("Example 3: n = 3, k = 9")
    {
        REQUIRE(Solution::getHappyString(3, 9) == "cab");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 1, k = 1")
    {
        REQUIRE(Solution::getHappyString(1, 1) == "a");
    }

    SECTION("Exact last valid happy string and first out-of-range for n = 2")
    {
        REQUIRE(Solution::getHappyString(2, 6) == "cb");
        REQUIRE(Solution::getHappyString(2, 7).empty());
    }

    SECTION("Maximum k = 100 exceeding total happy strings for n = 5 (48 total)")
    {
        REQUIRE(Solution::getHappyString(5, 100).empty());
    }

    SECTION("Maximum length n = 10 with k = 1")
    {
        REQUIRE(Solution::getHappyString(10, 1) == "ababababab");
    }

    SECTION("Maximum constraints: n = 10, k = 100")
    {
        REQUIRE(Solution::getHappyString(10, 100) == "abacbabacb");
    }
}
