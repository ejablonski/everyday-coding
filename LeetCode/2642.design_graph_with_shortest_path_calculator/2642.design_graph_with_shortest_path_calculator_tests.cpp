#include "2642.design_graph_with_shortest_path_calculator.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2642;

TEST_CASE("LeetCode 2642 - Design Graph With Shortest Path Calculator",
          "[LeetCode][2642][graph][design][heap][priority-queue][shortest-path]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: initial edges, shortestPath queries, and addEdge update")
    {
        std::vector<std::vector<int>> edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
        Graph graph(4, edges);

        REQUIRE(graph.shortestPath(3, 2) == 6);
        REQUIRE(graph.shortestPath(0, 3) == -1);
        graph.addEdge({1, 3, 4});
        REQUIRE(graph.shortestPath(0, 3) == 6);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: single node n = 1 with no edges")
    {
        std::vector<std::vector<int>> edges = {};
        Graph graph(1, edges);

        REQUIRE(graph.shortestPath(0, 0) == 0);
    }

    SECTION("Empty initial graph incrementally connected and shortened via addEdge")
    {
        std::vector<std::vector<int>> edges = {};
        Graph graph(4, edges);

        REQUIRE(graph.shortestPath(0, 3) == -1);
        graph.addEdge({0, 3, 100});
        REQUIRE(graph.shortestPath(0, 3) == 100);
        graph.addEdge({0, 1, 10});
        graph.addEdge({1, 2, 10});
        graph.addEdge({2, 3, 10});
        REQUIRE(graph.shortestPath(0, 3) == 30);
        REQUIRE(graph.shortestPath(3, 0) == -1);
    }

    SECTION("Same source and destination always has cost 0")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 0, 5}};
        Graph graph(3, edges);

        REQUIRE(graph.shortestPath(0, 0) == 0);
        REQUIRE(graph.shortestPath(2, 2) == 0);
    }

    SECTION("Directed edges with asymmetric forward and reverse path costs")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {2, 1, 10}, {1, 0, 20}};
        Graph graph(3, edges);

        REQUIRE(graph.shortestPath(0, 2) == 5);
        REQUIRE(graph.shortestPath(2, 0) == 30);
    }

    SECTION("Maximum edge cost 10^6 accumulated across multiple hops")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 1'000'000}, {1, 2, 1'000'000}};
        Graph graph(4, edges);

        REQUIRE(graph.shortestPath(0, 3) == -1);
        graph.addEdge({2, 3, 1'000'000});
        REQUIRE(graph.shortestPath(0, 3) == 3'000'000);
    }
}
