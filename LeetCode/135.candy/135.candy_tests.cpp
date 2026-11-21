#include "135.candy.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC135;

TEST_CASE("LeetCode 135 - Candy", "[LeetCode][135][array][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: ratings = [1,0,2]")
    {
        std::vector<int> ratings = {1, 0, 2};
        REQUIRE(Solution::candy(ratings) == 5);
    }

    SECTION("Example 2: ratings = [1,2,2]")
    {
        std::vector<int> ratings = {1, 2, 2};
        REQUIRE(Solution::candy(ratings) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length and rating: single child with rating 0")
    {
        std::vector<int> ratings = {0};
        REQUIRE(Solution::candy(ratings) == 1);
    }

    SECTION("All equal ratings receive one candy each")
    {
        std::vector<int> ratings = {5, 5, 5, 5};
        REQUIRE(Solution::candy(ratings) == 4);
    }

    SECTION("Strictly increasing ratings")
    {
        std::vector<int> ratings = {1, 2, 3, 4, 5};
        REQUIRE(Solution::candy(ratings) == 15);
    }

    SECTION("Strictly decreasing ratings")
    {
        std::vector<int> ratings = {5, 4, 3, 2, 1};
        REQUIRE(Solution::candy(ratings) == 15);
    }

    SECTION("Asymmetric mountain where peak depends on longer descending slope")
    {
        std::vector<int> ratings = {1, 2, 5, 4, 3, 2, 1};
        REQUIRE(Solution::candy(ratings) == 18);
    }

    SECTION("Valley plateau with boundary ratings 0 and 50000")
    {
        std::vector<int> ratings = {50000, 0, 0, 50000};
        REQUIRE(Solution::candy(ratings) == 6);
    }
}
