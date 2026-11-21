#include "797.all_paths_from_source_to_target.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC797;

TEST_CASE("LeetCode 797 - All Paths From Source to Target", "[LeetCode][797][backtracking][depth-first-search][breadth-first-search][graph][directed-acyclic-graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: diamond DAG with two paths")
    {
        std::vector<std::vector<int>> graph = { { 1, 2 }, { 3 }, { 3 }, {} };
        const std::vector<std::vector<int>> expected = { { 0, 1, 3 }, { 0, 2, 3 } };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 2: five-node DAG with five paths")
    {
        std::vector<std::vector<int>> graph = { { 4, 3, 1 }, { 3, 2, 4 }, { 3 }, { 4 }, {} };
        const std::vector<std::vector<int>> expected = {
            { 0, 4 }, { 0, 3, 4 }, { 0, 1, 3, 4 }, { 0, 1, 2, 3, 4 }, { 0, 1, 4 }
        };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 2 with direct edge")
    {
        std::vector<std::vector<int>> graph = { { 1 }, {} };
        const std::vector<std::vector<int>> expected = { { 0, 1 } };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Minimum constraints: n = 2 with no path to target")
    {
        std::vector<std::vector<int>> graph = { {}, {} };
        REQUIRE(Solution::allPathsSourceTarget(graph).empty());
    }

    SECTION("Dead-end branch excluded from results")
    {
        std::vector<std::vector<int>> graph = { { 1, 2 }, { 3 }, {}, {} };
        const std::vector<std::vector<int>> expected = { { 0, 1, 3 } };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Non-monotonic node order along valid DAG path")
    {
        std::vector<std::vector<int>> graph = { { 2 }, { 3 }, { 1 }, {} };
        const std::vector<std::vector<int>> expected = { { 0, 2, 1, 3 } };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Complete forward DAG of size 4")
    {
        std::vector<std::vector<int>> graph = { { 1, 2, 3 }, { 2, 3 }, { 3 }, {} };
        const std::vector<std::vector<int>> expected = {
            { 0, 3 }, { 0, 1, 3 }, { 0, 2, 3 }, { 0, 1, 2, 3 }
        };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Target node has outgoing edge to a dead-end node")
    {
        std::vector<std::vector<int>> graph = { { 2 }, {}, { 1 } };
        const std::vector<std::vector<int>> expected = { { 0, 2 } };
        REQUIRE_THAT(Solution::allPathsSourceTarget(graph), Catch::Matchers::UnorderedEquals(expected));
    }
}
