#include "1584.min_cost_to_connect_all_points.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1584;

TEST_CASE("LeetCode 1584 - Min Cost to Connect All Points",
          "[LeetCode][1584][array][union-find][graph][minimum-spanning-tree][prims-algorithm]"
          "[kruskals-algorithm][boruvkas-algorithm]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: five points with MST cost 20")
    {
        std::vector<std::vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
        REQUIRE(Solution::minCostConnectPoints(points) == 20);
    }

    SECTION("Example 2: three points including negative coordinates")
    {
        std::vector<std::vector<int>> points{{3, 12}, {-2, 5}, {-4, 1}};
        REQUIRE(Solution::minCostConnectPoints(points) == 18);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single point requires zero connection cost")
    {
        std::vector<std::vector<int>> points{{0, 0}};
        REQUIRE(Solution::minCostConnectPoints(points) == 0);
    }

    SECTION("Two points at opposite coordinate constraint boundaries (-10^6 and 10^6)")
    {
        std::vector<std::vector<int>> points{{-1'000'000, -1'000'000}, {1'000'000, 1'000'000}};
        REQUIRE(Solution::minCostConnectPoints(points) == 4'000'000);
    }

    SECTION("Unsorted collinear points along a horizontal line")
    {
        std::vector<std::vector<int>> points{{10, 5}, {-4, 5}, {3, 5}, {0, 5}};
        REQUIRE(Solution::minCostConnectPoints(points) == 14);
    }

    SECTION("Unit square with multiple equal-cost MSTs")
    {
        std::vector<std::vector<int>> points{{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        REQUIRE(Solution::minCostConnectPoints(points) == 3);
    }

    SECTION("Star layout centered at origin")
    {
        std::vector<std::vector<int>> points{{0, 0}, {0, 5}, {0, -5}, {5, 0}, {-5, 0}};
        REQUIRE(Solution::minCostConnectPoints(points) == 20);
    }

    SECTION("Tight negative cluster connected to a distant positive outlier")
    {
        std::vector<std::vector<int>> points{
            {-10, -10}, {-10, -9}, {-9, -10}, {-9, -9}, {10, 10}};
        REQUIRE(Solution::minCostConnectPoints(points) == 41);
    }
}
