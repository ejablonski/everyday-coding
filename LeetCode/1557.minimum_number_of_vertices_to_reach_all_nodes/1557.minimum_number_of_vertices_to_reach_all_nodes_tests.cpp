#include "1557.minimum_number_of_vertices_to_reach_all_nodes.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC1557;

TEST_CASE("LeetCode 1557 - Minimum Number of Vertices to Reach All Nodes", "[LeetCode][1557][graph][directed-acyclic-graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 6, two source vertices")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 2, 5 }, { 3, 4 }, { 4, 2 } };
        const std::vector<int> expected = { 0, 3 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(6, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 2: n = 5, three source vertices")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 2, 1 }, { 3, 1 }, { 1, 4 }, { 2, 4 } };
        const std::vector<int> expected = { 0, 2, 3 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(5, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 2 with single directed edge from higher index")
    {
        std::vector<std::vector<int>> edges = { { 1, 0 } };
        const std::vector<int> expected = { 1 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(2, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Linear chain: single source at highest vertex index")
    {
        std::vector<std::vector<int>> edges = { { 4, 3 }, { 3, 2 }, { 2, 1 }, { 1, 0 } };
        const std::vector<int> expected = { 4 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(5, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Star converging to single sink: all other vertices required")
    {
        std::vector<std::vector<int>> edges = { { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 } };
        const std::vector<int> expected = { 0, 1, 2, 3 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(5, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Disconnected DAG with isolated vertices")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 } };
        const std::vector<int> expected = { 0, 2, 3, 4 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(5, edges), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Diamond DAG with transitive shortcut edge")
    {
        std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 2, 3 }, { 0, 3 } };
        const std::vector<int> expected = { 0 };
        REQUIRE_THAT(Solution::findSmallestSetOfVertices(4, edges), Catch::Matchers::UnorderedEquals(expected));
    }
}
