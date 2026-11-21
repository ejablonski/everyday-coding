#include "394.decode_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC394;

TEST_CASE("LeetCode 394 - Decode String", "[LeetCode][394][string][stack][recursion]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"3[a]2[bc]\"")
    {
        REQUIRE(Solution::decodeString("3[a]2[bc]") == "aaabcbc");
    }

    SECTION("Example 2: s = \"3[a2[c]]\"")
    {
        REQUIRE(Solution::decodeString("3[a2[c]]") == "accaccacc");
    }

    SECTION("Example 3: s = \"2[abc]3[cd]ef\"")
    {
        REQUIRE(Solution::decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length plain character without brackets: s = \"a\"")
    {
        REQUIRE(Solution::decodeString("a") == "a");
    }

    SECTION("Minimum repeat count k = 1: s = \"1[a]1[bc]\"")
    {
        REQUIRE(Solution::decodeString("1[a]1[bc]") == "abc");
    }

    SECTION("Multi-digit repeat count at maximum k = 300: s = \"300[z]\"")
    {
        REQUIRE(Solution::decodeString("300[z]") == std::string(300, 'z'));
    }

    SECTION("Deeply nested brackets with prefix and suffix: s = \"x2[a3[b2[c]d]e]y\"")
    {
        REQUIRE(Solution::decodeString("x2[a3[b2[c]d]e]y") == "xabccdbccdbccdeabccdbccdbccdey");
    }

    SECTION("Adjacent sibling brackets inside outer bracket: s = \"2[2[a]3[b]]\"")
    {
        REQUIRE(Solution::decodeString("2[2[a]3[b]]") == "aabbbaabbb");
    }
}
