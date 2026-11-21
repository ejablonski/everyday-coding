#include "743.network_delay_time.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC743;

TEST_CASE("LeetCode 743 - Network Delay Time",
          "[LeetCode][743][depth-first-search][breadth-first-search][graph][heap][priority-queue]"
          "[shortest-path][dijkstra]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2")
    {
        std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        REQUIRE(Solution::networkDelayTime(times, 4, 2) == 2);
    }

    SECTION("Example 2: times = [[1,2,1]], n = 2, k = 1")
    {
        std::vector<std::vector<int>> times = {{1, 2, 1}};
        REQUIRE(Solution::networkDelayTime(times, 2, 1) == 1);
    }

    SECTION("Example 3: times = [[1,2,1]], n = 2, k = 2")
    {
        std::vector<std::vector<int>> times = {{1, 2, 1}};
        REQUIRE(Solution::networkDelayTime(times, 2, 2) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Zero-weight edges boundary w_i = 0")
    {
        std::vector<std::vector<int>> times = {{1, 2, 0}, {2, 3, 0}};
        REQUIRE(Solution::networkDelayTime(times, 3, 1) == 0);
    }

    SECTION("Multi-hop path shorter than direct edge")
    {
        std::vector<std::vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 10}};
        REQUIRE(Solution::networkDelayTime(times, 3, 1) == 3);
    }

    SECTION("Directed cycle in reachable network")
    {
        std::vector<std::vector<int>> times = {{1, 2, 2}, {2, 3, 3}, {3, 1, 1}, {3, 4, 4}};
        REQUIRE(Solution::networkDelayTime(times, 4, 1) == 9);
    }

    SECTION("Partially reachable graph with isolated node")
    {
        std::vector<std::vector<int>> times = {{1, 2, 1}, {2, 3, 1}, {3, 1, 1}};
        REQUIRE(Solution::networkDelayTime(times, 4, 1) == -1);
    }

    SECTION("Maximum edge weight w_i = 100 along a chain")
    {
        std::vector<std::vector<int>> times = {
            {1, 2, 100}, {2, 3, 100}, {3, 4, 100}, {4, 5, 100}};
        REQUIRE(Solution::networkDelayTime(times, 5, 1) == 400);
    }
}
