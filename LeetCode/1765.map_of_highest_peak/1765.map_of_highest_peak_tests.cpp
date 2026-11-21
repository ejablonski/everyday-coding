#include "1765.map_of_highest_peak.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <cstdlib>
#include <vector>

using namespace LC1765;

namespace
{
void verifyHighestPeak(
    const std::vector<std::vector<int>>& isWater,
    const std::vector<std::vector<int>>& height,
    int expectedMaxHeight)
{
    const std::size_t rows = isWater.size();
    const std::size_t cols = isWater[0].size();

    REQUIRE(height.size() == rows);
    for (std::size_t r = 0; r < rows; ++r)
    {
        REQUIRE(height[r].size() == cols);
    }

    int maxHeight = -1;
    for (std::size_t r = 0; r < rows; ++r)
    {
        for (std::size_t c = 0; c < cols; ++c)
        {
            REQUIRE(height[r][c] >= 0);
            if (isWater[r][c] == 1)
            {
                REQUIRE(height[r][c] == 0);
            }
            if (r + 1 < rows)
            {
                REQUIRE(std::abs(height[r][c] - height[r + 1][c]) <= 1);
            }
            if (c + 1 < cols)
            {
                REQUIRE(std::abs(height[r][c] - height[r][c + 1]) <= 1);
            }
            maxHeight = std::max(maxHeight, height[r][c]);
        }
    }

    REQUIRE(maxHeight == expectedMaxHeight);
}
} // namespace

TEST_CASE("LeetCode 1765 - Map of Highest Peak", "[LeetCode][1765][array][breadth-first-search][matrix]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: 2x2 grid with one water cell")
    {
        std::vector<std::vector<int>> isWater = { { 0, 1 }, { 0, 0 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 2);
    }

    SECTION("Example 2: 3x3 grid with two water cells")
    {
        std::vector<std::vector<int>> isWater = { { 0, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 2);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: 1x1 single water cell")
    {
        std::vector<std::vector<int>> isWater = { { 1 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 0);
    }

    SECTION("All water cells in rectangular grid")
    {
        std::vector<std::vector<int>> isWater = { { 1, 1, 1 }, { 1, 1, 1 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 0);
    }

    SECTION("Single row with water at one end")
    {
        std::vector<std::vector<int>> isWater = { { 1, 0, 0, 0, 0 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 4);
    }

    SECTION("Single column with water at both ends")
    {
        std::vector<std::vector<int>> isWater = { { 1 }, { 0 }, { 0 }, { 0 }, { 1 } };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 2);
    }

    SECTION("Single corner water cell in 4x4 grid")
    {
        std::vector<std::vector<int>> isWater = {
            { 1, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 6);
    }

    SECTION("Four corner water cells in 5x5 grid")
    {
        std::vector<std::vector<int>> isWater = {
            { 1, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 1 }
        };
        const auto original = isWater;
        const auto result = Solution::highestPeak(isWater);
        verifyHighestPeak(original, result, 4);
    }
}
