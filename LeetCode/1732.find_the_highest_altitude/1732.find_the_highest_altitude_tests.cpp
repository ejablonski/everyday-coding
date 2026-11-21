#include "1732.find_the_highest_altitude.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1732;

TEST_CASE("LeetCode 1732 - Find the Highest Altitude", "[LeetCode][1732][array][prefix-sum]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: gain = [-5, 1, 5, 0, -7]")
    {
        std::vector<int> gain = {-5, 1, 5, 0, -7};
        REQUIRE(Solution::largestAltitude(gain) == 1);
    }

    SECTION("Example 2: gain = [-4, -3, -2, -1, 4, 3, 2]")
    {
        std::vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
        REQUIRE(Solution::largestAltitude(gain) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single maximum positive gain: gain = [100]")
    {
        std::vector<int> gain = {100};
        REQUIRE(Solution::largestAltitude(gain) == 100);
    }

    SECTION("Single minimum negative gain: gain = [-100]")
    {
        std::vector<int> gain = {-100};
        REQUIRE(Solution::largestAltitude(gain) == 0);
    }

    SECTION("Strictly climbing path reaching peak at end")
    {
        std::vector<int> gain = {10, 20, 30, 40};
        REQUIRE(Solution::largestAltitude(gain) == 100);
    }

    SECTION("Flat trip with all zero gains")
    {
        std::vector<int> gain = {0, 0, 0, 0};
        REQUIRE(Solution::largestAltitude(gain) == 0);
    }

    SECTION("Early peak followed by deep descent below zero")
    {
        std::vector<int> gain = {50, 50, -100, -100, 20};
        REQUIRE(Solution::largestAltitude(gain) == 100);
    }
}
