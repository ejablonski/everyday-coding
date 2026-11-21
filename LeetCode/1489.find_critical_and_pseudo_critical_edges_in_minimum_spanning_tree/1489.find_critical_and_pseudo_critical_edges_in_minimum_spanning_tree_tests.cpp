#include "1489.find_critical_and_pseudo_critical_edges_in_minimum_spanning_tree.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC1489;

TEST_CASE("LeetCode 1489 - Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree",
          "[LeetCode][1489][union-find][graph][sorting][minimum-spanning-tree]"
          "[strongly-connected-component][prims-algorithm][kruskals-algorithm][boruvkas-algorithm]")
{
    using Catch::Matchers::UnorderedEquals;

    // --- Official Markdown Examples ---
    SECTION("Example 1: mixed critical, pseudo-critical, and excluded edges")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2},
                                            {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(5, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{0, 1}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{2, 3, 4, 5}));
    }

    SECTION("Example 2: equal-weight 4-cycle makes all edges pseudo-critical")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(4, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{0, 1, 2, 3}));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum graph (n = 2, single edge at max weight 1000)")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1000}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(2, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{0}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{}));
    }

    SECTION("Input graph is already a tree so every edge is critical")
    {
        std::vector<std::vector<int>> edges{{0, 1, 5}, {1, 2, 1}, {2, 3, 10}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(4, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{0, 1, 2}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{}));
    }

    SECTION("Unique MST with strictly heavier redundant edges")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1},  {1, 2, 2},  {2, 3, 3},
                                            {0, 2, 10}, {0, 3, 20}, {1, 3, 30}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(4, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{0, 1, 2}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{}));
    }

    SECTION("Heavy critical bridge combined with equal-weight triangle and unused edge")
    {
        std::vector<std::vector<int>> edges{{0, 1, 2},   {1, 2, 2}, {0, 2, 2},
                                            {2, 3, 100}, {3, 4, 1}, {2, 4, 200}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(5, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{3, 4}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{0, 1, 2}));
    }

    SECTION("Equal-weight critical bridge vs excluded cycle chord")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1}, {1, 2, 1}, {0, 2, 5}, {2, 3, 5}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(4, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{0, 1, 3}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{}));
    }

    SECTION("Complete graph K4 with identical maximum edge weights")
    {
        std::vector<std::vector<int>> edges{{0, 1, 1000}, {0, 2, 1000}, {0, 3, 1000},
                                            {1, 2, 1000}, {1, 3, 1000}, {2, 3, 1000}};
        const auto result = Solution::findCriticalAndPseudoCriticalEdges(4, edges);

        REQUIRE(result.size() == 2);
        REQUIRE_THAT(result[0], UnorderedEquals(std::vector<int>{}));
        REQUIRE_THAT(result[1], UnorderedEquals(std::vector<int>{0, 1, 2, 3, 4, 5}));
    }
}
