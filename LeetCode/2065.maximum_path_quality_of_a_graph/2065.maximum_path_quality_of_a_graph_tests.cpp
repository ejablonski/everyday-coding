#include "2065.maximum_path_quality_of_a_graph.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2065;

TEST_CASE("LeetCode 2065 - Maximum Path Quality of a Graph", "[LeetCode][2065][array][backtracking][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: visit branches 1 and 3 within maxTime = 49")
    {
        std::vector<int> values = { 0, 32, 10, 43 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 1, 2, 15 }, { 0, 3, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 49) == 75);
    }

    SECTION("Example 2: choose higher-value single branch within maxTime = 30")
    {
        std::vector<int> values = { 5, 10, 15, 20 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 1, 2, 10 }, { 0, 3, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 30) == 25);
    }

    SECTION("Example 3: traverse deeper node and backtrack within maxTime = 50")
    {
        std::vector<int> values = { 1, 2, 3, 4 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 1, 2, 11 }, { 2, 3, 12 }, { 1, 3, 13 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 50) == 7);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single node with no edges")
    {
        std::vector<int> values = { 42 };
        std::vector<std::vector<int>> edges = {};
        REQUIRE(Solution::maximalPathQuality(values, edges, 10) == 42);
    }

    SECTION("Insufficient maxTime to make any round trip from node 0")
    {
        std::vector<int> values = { 7, 100 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 19) == 7);
    }

    SECTION("Cycle completed at exact maxTime boundary")
    {
        std::vector<int> values = { 10, 20, 30 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 1, 2, 10 }, { 0, 2, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 30) == 60);
    }

    SECTION("Revisiting node 0 does not double-count its value")
    {
        std::vector<int> values = { 100, 15, 25 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 0, 2, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 40) == 140);
    }

    SECTION("Disconnected high-value component and maximum node value boundary")
    {
        std::vector<int> values = { 100000000, 100000000, 100000000, 100000000 };
        std::vector<std::vector<int>> edges = { { 0, 1, 10 }, { 2, 3, 10 } };
        REQUIRE(Solution::maximalPathQuality(values, edges, 100) == 200000000);
    }
}
