#include "463.island_perimeter.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC463;

TEST_CASE("LeetCode 463 - Island Perimeter", "[LeetCode][463][array][depth-first-search][breadth-first-search][matrix]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: 4x4 grid with irregular island")
    {
        std::vector<std::vector<int>> grid = {
            { 0, 1, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 0, 0 }
        };
        REQUIRE(Solution::islandPerimeter(grid) == 16);
    }

    SECTION("Example 2: minimum 1x1 grid with single land cell")
    {
        std::vector<std::vector<int>> grid = { { 1 } };
        REQUIRE(Solution::islandPerimeter(grid) == 4);
    }

    SECTION("Example 3: 1x2 grid with one land cell and one water cell")
    {
        std::vector<std::vector<int>> grid = { { 1, 0 } };
        REQUIRE(Solution::islandPerimeter(grid) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single horizontal row of all land cells")
    {
        std::vector<std::vector<int>> grid = { { 1, 1, 1, 1 } };
        REQUIRE(Solution::islandPerimeter(grid) == 10);
    }

    SECTION("Single vertical column of all land cells")
    {
        std::vector<std::vector<int>> grid = { { 1 }, { 1 }, { 1 }, { 1 } };
        REQUIRE(Solution::islandPerimeter(grid) == 10);
    }

    SECTION("Solid 3x3 square filling the entire grid")
    {
        std::vector<std::vector<int>> grid = {
            { 1, 1, 1 },
            { 1, 1, 1 },
            { 1, 1, 1 }
        };
        REQUIRE(Solution::islandPerimeter(grid) == 12);
    }

    SECTION("L-shaped island fully surrounded by water border")
    {
        std::vector<std::vector<int>> grid = {
            { 0, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 }
        };
        REQUIRE(Solution::islandPerimeter(grid) == 10);
    }

    SECTION("Concave U-shaped island with inner indentation")
    {
        std::vector<std::vector<int>> grid = {
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 1, 1 }
        };
        REQUIRE(Solution::islandPerimeter(grid) == 16);
    }
}
