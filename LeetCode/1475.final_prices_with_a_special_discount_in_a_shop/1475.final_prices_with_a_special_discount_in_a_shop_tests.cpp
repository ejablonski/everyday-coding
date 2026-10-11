#include "1475.final_prices_with_a_special_discount_in_a_shop.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 1475 - Final Prices With a Special Discount in a Shop", "[LeetCode][1475][array][stack][monotonic-stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: prices = [8,4,6,2,3]")
    {
        std::vector<int> prices = {8, 4, 6, 2, 3};
        std::vector<int> expected = {4, 2, 4, 2, 3};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    SECTION("Example 2: prices = [1,2,3,4,5]")
    {
        std::vector<int> prices = {1, 2, 3, 4, 5};
        std::vector<int> expected = {1, 2, 3, 4, 5};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    SECTION("Example 3: prices = [10,1,1,6]")
    {
        std::vector<int> prices = {10, 1, 1, 6};
        std::vector<int> expected = {9, 0, 1, 6};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single element array (n = 1)")
    {
        std::vector<int> prices = {5};
        std::vector<int> expected = {5};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    SECTION("All elements equal: duplicate discounts")
    {
        std::vector<int> prices = {7, 7, 7};
        std::vector<int> expected = {0, 0, 7};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    SECTION("Strictly decreasing order: each item discounted by immediate neighbor")
    {
        std::vector<int> prices = {5, 4, 3, 2, 1};
        std::vector<int> expected = {1, 1, 1, 1, 1};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }

    SECTION("Boundary values: maximum allowed price")
    {
        std::vector<int> prices = {1000, 1000};
        std::vector<int> expected = {0, 1000};
        REQUIRE(Solution::finalPrices(prices) == expected);
    }
}
