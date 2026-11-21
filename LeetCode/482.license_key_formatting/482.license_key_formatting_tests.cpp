#include "482.license_key_formatting.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace LC482;

TEST_CASE("LeetCode 482 - License Key Formatting", "[LeetCode][482][string]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"5F3Z-2e-9-w\", k = 4")
    {
        REQUIRE(Solution::licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
    }

    SECTION("Example 2: s = \"2-5g-3-J\", k = 2")
    {
        REQUIRE(Solution::licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length single character: s = \"a\", k = 1")
    {
        REQUIRE(Solution::licenseKeyFormatting("a", 1) == "A");
    }

    SECTION("Only dashes with no alphanumeric characters: s = \"---\", k = 3")
    {
        REQUIRE(Solution::licenseKeyFormatting("---", 3) == "");
    }

    SECTION("Leading and trailing dashes: s = \"--a-a-a-a--\", k = 2")
    {
        REQUIRE(Solution::licenseKeyFormatting("--a-a-a-a--", 2) == "AA-AA");
    }

    SECTION("Minimum k = 1: s = \"a-b-c\", k = 1")
    {
        REQUIRE(Solution::licenseKeyFormatting("a-b-c", 1) == "A-B-C");
    }

    SECTION("k larger than total alphanumeric length: s = \"2-4A0r7-4k\", k = 100")
    {
        REQUIRE(Solution::licenseKeyFormatting("2-4A0r7-4k", 100) == "24A0R74K");
    }

    SECTION("No existing dashes with exact multiple of k: s = \"abcdef\", k = 3")
    {
        REQUIRE(Solution::licenseKeyFormatting("abcdef", 3) == "ABC-DEF");
    }

    SECTION("Digits only with shorter first group: s = \"1234567\", k = 3")
    {
        REQUIRE(Solution::licenseKeyFormatting("1234567", 3) == "1-234-567");
    }
}
