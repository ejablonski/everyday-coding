#include "1334.find_the_city_with_the_smallest_number_of_neighbors_at_a_threshold_distance.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1334;

TEST_CASE("LeetCode 1334 - Find the City With the Smallest Number of Neighbors at a Threshold "
          "Distance",
          "[LeetCode][1334][dynamic-programming][graph][shortest-path][dijkstra]"
          "[bellman-ford-algorithm][floyd-warshall-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 4, distanceThreshold = 4")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
        REQUIRE(Solution::findTheCity(4, edges, 4) == 3);
    }

    SECTION("Example 2: n = 5, distanceThreshold = 2")
    {
        std::vector<std::vector<int>> edges = {
            {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
        REQUIRE(Solution::findTheCity(5, edges, 2) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint n = 2 with exact threshold tie returns greatest city")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 5}};
        REQUIRE(Solution::findTheCity(2, edges, 5) == 1);
    }

    SECTION("All edges exceed threshold returns greatest city index")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}};
        REQUIRE(Solution::findTheCity(4, edges, 5) == 3);
    }

    SECTION("Disconnected graph selects isolated city with zero neighbors")
    {
        std::vector<std::vector<int>> edges = {{0, 2, 1}, {2, 3, 1}};
        REQUIRE(Solution::findTheCity(4, edges, 5) == 1);
    }

    SECTION("Multi-hop shortest path shorter than direct edge brings city within threshold")
    {
        std::vector<std::vector<int>> edges = {
            {0, 1, 1}, {0, 2, 10}, {0, 3, 2}, {1, 2, 2}, {1, 3, 2}};
        REQUIRE(Solution::findTheCity(4, edges, 3) == 3);
    }

    SECTION("Maximum boundary weights and distanceThreshold = 10^4")
    {
        std::vector<std::vector<int>> edges = {{0, 1, 10000}, {1, 2, 10000}};
        REQUIRE(Solution::findTheCity(3, edges, 10000) == 2);
    }
}
