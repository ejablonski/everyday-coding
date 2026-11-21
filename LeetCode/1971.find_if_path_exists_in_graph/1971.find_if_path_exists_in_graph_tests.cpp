#include "1971.find_if_path_exists_in_graph.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1971;

TEST_CASE("LeetCode 1971 - Find if Path Exists in Graph", "[LeetCode][1971][depth-first-search][breadth-first-search][union-find][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 3, triangle graph with path from 0 to 2")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 2, 0 } };
        REQUIRE(Solution::validPath(3, edges, 0, 2) == true);
    }

    SECTION("Example 2: n = 6, two disconnected components")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 3, 5 }, { 5, 4 }, { 4, 3 } };
        REQUIRE_FALSE(Solution::validPath(6, edges, 0, 5));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single vertex with no edges")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::validPath(1, edges, 0, 0) == true);
    }

    SECTION("Source equals destination in edgeless multi-vertex graph")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::validPath(4, edges, 2, 2) == true);
    }

    SECTION("No edges between distinct source and destination")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE_FALSE(Solution::validPath(4, edges, 0, 3));
    }

    SECTION("Bidirectional traversal along reverse-listed chain")
    {
        std::vector<std::vector<int>> edges = { { 4, 3 }, { 3, 2 }, { 2, 1 }, { 1, 0 } };
        REQUIRE(Solution::validPath(5, edges, 0, 4) == true);
    }

    SECTION("Cycle component with unreachable isolated destination")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 } };
        REQUIRE_FALSE(Solution::validPath(5, edges, 0, 4));
    }
}
