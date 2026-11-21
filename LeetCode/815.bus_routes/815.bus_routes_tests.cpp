#include "815.bus_routes.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC815;

TEST_CASE("LeetCode 815 - Bus Routes", "[LeetCode][815][array][hash-table][breadth-first-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: routes = [[1,2,7],[3,6,7]], source = 1, target = 6")
    {
        std::vector<std::vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
        REQUIRE(Solution::numBusesToDestination(routes, 1, 6) == 2);
    }

    SECTION("Example 2: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12")
    {
        std::vector<std::vector<int>> routes = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
        REQUIRE(Solution::numBusesToDestination(routes, 15, 12) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Source equals target on a bus route requires 0 buses")
    {
        std::vector<std::vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
        REQUIRE(Solution::numBusesToDestination(routes, 7, 7) == 0);
    }

    SECTION("Source equals target not present in any route requires 0 buses")
    {
        std::vector<std::vector<int>> routes = {{1, 2, 3}};
        REQUIRE(Solution::numBusesToDestination(routes, 99, 99) == 0);
    }

    SECTION("Direct single bus with cyclic wrap-around order")
    {
        std::vector<std::vector<int>> routes = {{10, 20, 30, 40}};
        REQUIRE(Solution::numBusesToDestination(routes, 40, 10) == 1);
    }

    SECTION("Multiple transfer paths selects fewest buses")
    {
        std::vector<std::vector<int>> routes = {{0, 1, 2}, {2, 3}, {3, 4}, {1, 4}};
        REQUIRE(Solution::numBusesToDestination(routes, 0, 4) == 2);
    }

    SECTION("Target stop not served by any route returns -1")
    {
        std::vector<std::vector<int>> routes = {{1, 2}, {2, 3}};
        REQUIRE(Solution::numBusesToDestination(routes, 1, 99) == -1);
    }

    SECTION("Boundary stop IDs 0 and 999999 across a 3-bus chain")
    {
        std::vector<std::vector<int>> routes = {
            {0, 500000}, {500000, 750000}, {750000, 999999}};
        REQUIRE(Solution::numBusesToDestination(routes, 0, 999999) == 3);
    }
}
