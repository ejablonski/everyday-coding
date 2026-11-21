#include "2203.minimum_weighted_subgraph_with_the_required_paths.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2203;

TEST_CASE("LeetCode 2203 - Minimum Weighted Subgraph With the Required Paths",
          "[LeetCode][2203][graph][heap][priority-queue][shortest-path]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 6, src1 = 0, src2 = 1, dest = 5")
    {
        std::vector<std::vector<int>> edges = {{0, 2, 2}, {0, 5, 6}, {1, 0, 3},
                                               {1, 4, 5}, {2, 1, 1}, {2, 3, 3},
                                               {2, 3, 4}, {3, 4, 2}, {4, 5, 1}};
        REQUIRE(Solution::minimumWeight(6, edges, 0, 1, 5) == 9LL);
    }

    SECTION("Example 2: n = 3, src1 = 0, src2 = 1, dest = 2 (unreachable)")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 1}, {2, 1, 1}};
        REQUIRE(Solution::minimumWeight(3, edges, 0, 1, 2) == -1LL);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint n = 3 with empty edge list")
    {
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::minimumWeight(3, edges, 0, 1, 2) == -1LL);
    }

    SECTION("Disjoint paths merging only at dest beat routing through other source")
    {
        std::vector<std::vector<int>> edges = {{0, 2, 4}, {1, 2, 5}, {0, 1, 10}};
        REQUIRE(Solution::minimumWeight(3, edges, 0, 1, 2) == 9LL);
    }

    SECTION("Shared intermediate meeting node beats independent shortest paths")
    {
        std::vector<std::vector<int>> edges = {
            {0, 2, 1}, {1, 2, 1}, {2, 3, 10}, {0, 3, 15}, {1, 3, 15}};
        REQUIRE(Solution::minimumWeight(4, edges, 0, 1, 3) == 12LL);
    }

    SECTION("Optimal subgraph routes src1 directly through src2 to dest")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 2}, {1, 2, 3}};
        REQUIRE(Solution::minimumWeight(3, edges, 0, 1, 2) == 5LL);
    }

    SECTION("Parallel directed edges select minimum weight")
    {
        std::vector<std::vector<int>> edges = {{0, 2, 100}, {0, 2, 3}, {1, 2, 50}, {1, 2, 4}};
        REQUIRE(Solution::minimumWeight(3, edges, 0, 1, 2) == 7LL);
    }

    SECTION("Maximum edge weights along chain")
    {
        constexpr int kEdges = 22000;
        constexpr int kWeight = 100000;
        std::vector<std::vector<int>> edges;
        edges.reserve(kEdges);
        for (int i = 0; i < kEdges; ++i) {
            edges.push_back({i, i + 1, kWeight});
        }
        REQUIRE(Solution::minimumWeight(kEdges + 1, edges, 0, 1, kEdges) == 2'200'000'000LL);
    }
}
