#include "1129.shortest_path_with_alternating_colors.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1129;

TEST_CASE("LeetCode 1129 - Shortest Path with Alternating Colors",
          "[LeetCode][1129][breadth-first-search][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []")
    {
        std::vector<std::vector<int>> redEdges = {{0, 1}, {1, 2}};
        std::vector<std::vector<int>> blueEdges = {};
        std::vector<int> expected = {0, 1, -1};
        REQUIRE(Solution::shortestAlternatingPaths(3, redEdges, blueEdges) == expected);
    }

    SECTION("Example 2: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]")
    {
        std::vector<std::vector<int>> redEdges = {{0, 1}};
        std::vector<std::vector<int>> blueEdges = {{2, 1}};
        std::vector<int> expected = {0, 1, -1};
        REQUIRE(Solution::shortestAlternatingPaths(3, redEdges, blueEdges) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: single node n = 1 with no edges")
    {
        std::vector<std::vector<int>> redEdges = {};
        std::vector<std::vector<int>> blueEdges = {};
        std::vector<int> expected = {0};
        REQUIRE(Solution::shortestAlternatingPaths(1, redEdges, blueEdges) == expected);
    }

    SECTION("Alternating path starting with a blue edge")
    {
        std::vector<std::vector<int>> redEdges = {{1, 2}};
        std::vector<std::vector<int>> blueEdges = {{0, 1}, {2, 3}};
        std::vector<int> expected = {0, 1, 2, 3};
        REQUIRE(Solution::shortestAlternatingPaths(4, redEdges, blueEdges) == expected);
    }

    SECTION("Parallel red and blue edges between the same nodes")
    {
        std::vector<std::vector<int>> redEdges = {{0, 1}, {1, 2}};
        std::vector<std::vector<int>> blueEdges = {{0, 1}, {1, 2}};
        std::vector<int> expected = {0, 1, 2};
        REQUIRE(Solution::shortestAlternatingPaths(3, redEdges, blueEdges) == expected);
    }

    SECTION("Self-loop needed to flip edge color")
    {
        std::vector<std::vector<int>> redEdges = {{0, 1}, {1, 2}};
        std::vector<std::vector<int>> blueEdges = {{1, 1}};
        std::vector<int> expected = {0, 1, 3};
        REQUIRE(Solution::shortestAlternatingPaths(3, redEdges, blueEdges) == expected);
    }

    SECTION("Cycle requiring revisiting nodes with the opposite color")
    {
        std::vector<std::vector<int>> redEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        std::vector<std::vector<int>> blueEdges = {{1, 2}, {2, 3}, {3, 1}};
        std::vector<int> expected = {0, 1, 2, 3, 7};
        REQUIRE(Solution::shortestAlternatingPaths(5, redEdges, blueEdges) == expected);
    }

    SECTION("Disconnected graph with no edges")
    {
        std::vector<std::vector<int>> redEdges = {};
        std::vector<std::vector<int>> blueEdges = {};
        std::vector<int> expected = {0, -1, -1, -1};
        REQUIRE(Solution::shortestAlternatingPaths(4, redEdges, blueEdges) == expected);
    }
}
