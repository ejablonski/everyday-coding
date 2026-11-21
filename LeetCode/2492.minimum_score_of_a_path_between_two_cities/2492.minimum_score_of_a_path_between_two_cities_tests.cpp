#include "2492.minimum_score_of_a_path_between_two_cities.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2492;

TEST_CASE("LeetCode 2492 - Minimum Score of a Path Between Two Cities", "[LeetCode][2492][depth-first-search][breadth-first-search][union-find][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 4, minimum road lies directly on path 1 -> 2 -> 4")
    {
        std::vector<std::vector<int>> roads = { { 1, 2, 9 }, { 2, 3, 6 }, { 2, 4, 5 }, { 1, 4, 7 } };
        REQUIRE(Solution::minScore(4, roads) == 5);
    }

    SECTION("Example 2: n = 4, minimum road requires detour and revisiting city 1")
    {
        std::vector<std::vector<int>> roads = { { 1, 2, 2 }, { 1, 3, 4 }, { 3, 4, 7 } };
        REQUIRE(Solution::minScore(4, roads) == 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: two cities with single maximum-weight road")
    {
        std::vector<std::vector<int>> roads = { { 1, 2, 10000 } };
        REQUIRE(Solution::minScore(2, roads) == 10000);
    }

    SECTION("Smaller road in disconnected component must be ignored")
    {
        std::vector<std::vector<int>> roads = { { 1, 5, 50 }, { 2, 3, 1 }, { 3, 4, 2 } };
        REQUIRE(Solution::minScore(5, roads) == 50);
    }

    SECTION("Minimum road is a side detour branching off city n")
    {
        std::vector<std::vector<int>> roads = { { 1, 4, 100 }, { 4, 3, 1 }, { 3, 2, 50 } };
        REQUIRE(Solution::minScore(4, roads) == 1);
    }

    SECTION("Minimum distance boundary (1) at the end of a side chain")
    {
        std::vector<std::vector<int>> roads = {
            { 1, 6, 9999 }, { 1, 2, 8000 }, { 2, 3, 7000 }, { 3, 4, 6000 }, { 4, 5, 1 }
        };
        REQUIRE(Solution::minScore(6, roads) == 1);
    }

    SECTION("Cycle with identical road weights")
    {
        std::vector<std::vector<int>> roads = { { 1, 2, 42 }, { 2, 3, 42 }, { 3, 4, 42 }, { 4, 1, 42 } };
        REQUIRE(Solution::minScore(4, roads) == 42);
    }
}
