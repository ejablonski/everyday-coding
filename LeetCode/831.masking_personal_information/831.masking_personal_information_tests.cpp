#include "831.masking_personal_information.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC831;

TEST_CASE("LeetCode 831 - Masking Personal Information", "[LeetCode][831][string]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: email s = \"LeetCode@LeetCode.com\"")
    {
        REQUIRE(Solution::maskPII("LeetCode@LeetCode.com") == "l*****e@leetcode.com");
    }

    SECTION("Example 2: 2-letter email name s = \"AB@qq.com\"")
    {
        REQUIRE(Solution::maskPII("AB@qq.com") == "a*****b@qq.com");
    }

    SECTION("Example 3: 10-digit phone number s = \"1(234)567-890\"")
    {
        REQUIRE(Solution::maskPII("1(234)567-890") == "***-***-7890");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length uppercase email (8 chars): s = \"XY@AB.CD\"")
    {
        REQUIRE(Solution::maskPII("XY@AB.CD") == "x*****y@ab.cd");
    }

    SECTION("Long mixed-case email: s = \"AliceBobCharlie@Example.ORG\"")
    {
        REQUIRE(Solution::maskPII("AliceBobCharlie@Example.ORG") == "a*****e@example.org");
    }

    SECTION("Phone number with 0-digit country code and no separators: s = \"1234567890\"")
    {
        REQUIRE(Solution::maskPII("1234567890") == "***-***-7890");
    }

    SECTION("Phone number with 1-digit country code: s = \"+1(234)567-8901\"")
    {
        REQUIRE(Solution::maskPII("+1(234)567-8901") == "+*-***-***-8901");
    }

    SECTION("Phone number with 2-digit country code: s = \"86-(10)12345678\"")
    {
        REQUIRE(Solution::maskPII("86-(10)12345678") == "+**-***-***-5678");
    }

    SECTION("Phone number with 3-digit country code: s = \"+886 123 456 7890\"")
    {
        REQUIRE(Solution::maskPII("+886 123 456 7890") == "+***-***-***-7890");
    }
}
