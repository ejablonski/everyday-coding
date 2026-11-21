#include "481.magical_string.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC481;

TEST_CASE("LeetCode 481 - Magical String", "[LeetCode][481][two-pointers][string]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 6")
    {
        REQUIRE(Solution::magicalString(6) == 3);
    }

    SECTION("Example 2: n = 1")
    {
        REQUIRE(Solution::magicalString(1) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Small prefix n = 2 (\"12\")")
    {
        REQUIRE(Solution::magicalString(2) == 1);
    }

    SECTION("Initial seed length n = 3 (\"122\")")
    {
        REQUIRE(Solution::magicalString(3) == 1);
    }

    SECTION("Boundary splitting a pair of ones: n = 4 (\"1221\")")
    {
        REQUIRE(Solution::magicalString(4) == 2);
    }

    SECTION("Medium prefix n = 10 (\"1221121221\")")
    {
        REQUIRE(Solution::magicalString(10) == 5);
    }

    SECTION("Later boundary splitting a pair of ones: n = 13 (\"1221121221221\")")
    {
        REQUIRE(Solution::magicalString(13) == 6);
    }

    SECTION("Full documented prefix n = 19 (\"1221121221221121122\")")
    {
        REQUIRE(Solution::magicalString(19) == 9);
    }
}
