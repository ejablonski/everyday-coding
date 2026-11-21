#include "440.k_th_smallest_in_lexicographical_order.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC440;

TEST_CASE("LeetCode 440 - K-th Smallest in Lexicographical Order", "[LeetCode][440][trie]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 13, k = 2")
    {
        REQUIRE(Solution::findKthNumber(13, 2) == 10);
    }

    SECTION("Example 2: n = 1, k = 1")
    {
        REQUIRE(Solution::findKthNumber(1, 1) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("First element (k = 1) for multi-digit n")
    {
        REQUIRE(Solution::findKthNumber(100, 1) == 1);
    }

    SECTION("Subtree boundary transition for n = 13")
    {
        REQUIRE(Solution::findKthNumber(13, 5) == 13);
        REQUIRE(Solution::findKthNumber(13, 6) == 2);
        REQUIRE(Solution::findKthNumber(13, 13) == 9);
    }

    SECTION("Power-of-10 boundary for n = 100")
    {
        REQUIRE(Solution::findKthNumber(100, 3) == 100);
        REQUIRE(Solution::findKthNumber(100, 4) == 11);
        REQUIRE(Solution::findKthNumber(100, 12) == 19);
        REQUIRE(Solution::findKthNumber(100, 13) == 2);
        REQUIRE(Solution::findKthNumber(100, 100) == 99);
    }

    SECTION("Descending deeper into prefix subtree for n = 1000")
    {
        REQUIRE(Solution::findKthNumber(1000, 10) == 106);
    }

    SECTION("Maximum constraint n = 10^9 boundary values")
    {
        constexpr int kMaxN = 1'000'000'000;
        REQUIRE(Solution::findKthNumber(kMaxN, 1) == 1);
        REQUIRE(Solution::findKthNumber(kMaxN, 10) == kMaxN);
        REQUIRE(Solution::findKthNumber(kMaxN, 111'111'112) == 199'999'999);
        REQUIRE(Solution::findKthNumber(kMaxN, 111'111'113) == 2);
        REQUIRE(Solution::findKthNumber(kMaxN, kMaxN) == 999'999'999);
    }
}
