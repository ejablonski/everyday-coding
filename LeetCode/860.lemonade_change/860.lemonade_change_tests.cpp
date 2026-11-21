#include "860.lemonade_change.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC860;

TEST_CASE("LeetCode 860 - Lemonade Change", "[LeetCode][860][array][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: bills = [5,5,5,10,20]")
    {
        std::vector<int> bills = {5, 5, 5, 10, 20};
        REQUIRE(Solution::lemonadeChange(bills));
    }

    SECTION("Example 2: bills = [5,5,10,10,20]")
    {
        std::vector<int> bills = {5, 5, 10, 10, 20};
        REQUIRE_FALSE(Solution::lemonadeChange(bills));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length: single $5 bill")
    {
        std::vector<int> bills = {5};
        REQUIRE(Solution::lemonadeChange(bills));
    }

    SECTION("First customer pays with $10 (no initial change)")
    {
        std::vector<int> bills = {10};
        REQUIRE_FALSE(Solution::lemonadeChange(bills));
    }

    SECTION("First customer pays with $20 (no initial change)")
    {
        std::vector<int> bills = {20};
        REQUIRE_FALSE(Solution::lemonadeChange(bills));
    }

    SECTION("Give $15 change for $20 using three $5 bills")
    {
        std::vector<int> bills = {5, 5, 5, 20};
        REQUIRE(Solution::lemonadeChange(bills));
    }

    SECTION("Change sequence with mixed $5, $10, and $20 bills")
    {
        std::vector<int> bills = {5, 5, 5, 5, 10, 20, 10, 10};
        REQUIRE(Solution::lemonadeChange(bills));
    }

    SECTION("Fails after exhausting $5 bills on earlier $20")
    {
        std::vector<int> bills = {5, 5, 5, 20, 10};
        REQUIRE_FALSE(Solution::lemonadeChange(bills));
    }
}
