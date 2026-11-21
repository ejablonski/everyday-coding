#include "1492.the_kth_factor_of_n.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC1492;

TEST_CASE("LeetCode 1492 - The kth Factor of n",
          "[LeetCode][1492][math][number-theory][prime-factorization]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 12, k = 3")
    {
        REQUIRE(Solution::kthFactor(12, 3) == 3);
    }

    SECTION("Example 2: n = 7, k = 2")
    {
        REQUIRE(Solution::kthFactor(7, 2) == 7);
    }

    SECTION("Example 3: n = 4, k = 4")
    {
        REQUIRE(Solution::kthFactor(4, 4) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 1, k = 1")
    {
        REQUIRE(Solution::kthFactor(1, 1) == 1);
    }

    SECTION("Perfect square avoids double-counting sqrt(n): n = 36")
    {
        // Factors of 36: [1, 2, 3, 4, 6, 9, 12, 18, 36]
        REQUIRE(Solution::kthFactor(36, 5) == 6);
        REQUIRE(Solution::kthFactor(36, 6) == 9);
        REQUIRE(Solution::kthFactor(36, 9) == 36);
        REQUIRE(Solution::kthFactor(36, 10) == -1);
    }

    SECTION("Largest prime within constraints: n = 997")
    {
        // Factors of 997: [1, 997]
        REQUIRE(Solution::kthFactor(997, 1) == 1);
        REQUIRE(Solution::kthFactor(997, 2) == 997);
        REQUIRE(Solution::kthFactor(997, 3) == -1);
    }

    SECTION("Upper-half paired factors of composite number: n = 24")
    {
        // Factors of 24: [1, 2, 3, 4, 6, 8, 12, 24]
        REQUIRE(Solution::kthFactor(24, 5) == 6);
        REQUIRE(Solution::kthFactor(24, 8) == 24);
        REQUIRE(Solution::kthFactor(24, 9) == -1);
    }

    SECTION("Maximum constraints: n = 1000")
    {
        // Factors of 1000: [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000]
        REQUIRE(Solution::kthFactor(1000, 8) == 25);
        REQUIRE(Solution::kthFactor(1000, 9) == 40);
        REQUIRE(Solution::kthFactor(1000, 16) == 1000);
        REQUIRE(Solution::kthFactor(1000, 17) == -1);
        REQUIRE(Solution::kthFactor(1000, 1000) == -1);
    }
}
