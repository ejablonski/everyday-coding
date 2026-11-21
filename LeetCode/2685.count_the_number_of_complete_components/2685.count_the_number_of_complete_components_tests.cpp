#include "2685.count_the_number_of_complete_components.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2685;

TEST_CASE("LeetCode 2685 - Count the Number of Complete Components", "[LeetCode][2685][depth-first-search][breadth-first-search][union-find][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 6, triangle, single edge, and isolated vertex are all complete")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 3, 4 } };
        REQUIRE(Solution::countCompleteComponents(6, edges) == 3);
    }

    SECTION("Example 2: n = 6, one triangle complete and one path of length 2 incomplete")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 3, 4 }, { 3, 5 } };
        REQUIRE(Solution::countCompleteComponents(6, edges) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single isolated vertex is complete")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::countCompleteComponents(1, edges) == 1);
    }

    SECTION("All isolated vertices with no edges")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::countCompleteComponents(5, edges) == 5);
    }

    SECTION("Single complete graph K4")
    {
        std::vector<std::vector<int>> edges = {
            { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 }, { 2, 3 }
        };
        REQUIRE(Solution::countCompleteComponents(4, edges) == 1);
    }

    SECTION("Nearly complete component missing a single edge from K4")
    {
        std::vector<std::vector<int>> edges = {
            { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 }
        };
        REQUIRE(Solution::countCompleteComponents(4, edges) == 0);
    }

    SECTION("Mixed components including regular 4-cycle that is not complete")
    {
        std::vector<std::vector<int>> edges = {
            { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 2 }, { 1, 3 }, { 2, 3 },
            { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 },
            { 8, 9 }
        };
        REQUIRE(Solution::countCompleteComponents(11, edges) == 3);
    }
}
