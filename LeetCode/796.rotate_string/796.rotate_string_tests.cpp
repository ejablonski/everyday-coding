#include "796.rotate_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC796;

TEST_CASE("LeetCode 796 - Rotate String", "[LeetCode][796][string][string-matching]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"abcde\", goal = \"cdeab\"")
    {
        REQUIRE(Solution::rotateString("abcde", "cdeab"));
    }

    SECTION("Example 2: s = \"abcde\", goal = \"abced\"")
    {
        REQUIRE_FALSE(Solution::rotateString("abcde", "abced"));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length matching single characters: s = \"a\", goal = \"a\"")
    {
        REQUIRE(Solution::rotateString("a", "a"));
    }

    SECTION("Minimum length non-matching single characters: s = \"a\", goal = \"b\"")
    {
        REQUIRE_FALSE(Solution::rotateString("a", "b"));
    }

    SECTION("Zero shifts needed (already equal): s = \"abcde\", goal = \"abcde\"")
    {
        REQUIRE(Solution::rotateString("abcde", "abcde"));
    }

    SECTION("Different lengths where goal is a prefix of s")
    {
        REQUIRE_FALSE(Solution::rotateString("abc", "ab"));
        REQUIRE_FALSE(Solution::rotateString("aa", "a"));
    }

    SECTION("Repeated characters with valid rotation: s = \"bbbacddceeb\", goal = \"ceebbbbacdd\"")
    {
        REQUIRE(Solution::rotateString("bbbacddceeb", "ceebbbbacdd"));
    }

    SECTION("Same character frequencies but not a rotation: s = \"aabb\", goal = \"abab\"")
    {
        REQUIRE_FALSE(Solution::rotateString("aabb", "abab"));
    }
}
