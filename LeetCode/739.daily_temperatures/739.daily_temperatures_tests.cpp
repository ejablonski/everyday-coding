#include "739.daily_temperatures.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 739 - Daily Temperatures", "[LeetCode][739][array][stack][monotonic-stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: temperatures = [73,74,75,71,69,72,76,73]")
    {
        std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("Example 2: temperatures = [30,40,50,60]")
    {
        std::vector<int> temperatures = {30, 40, 50, 60};
        std::vector<int> expected = {1, 1, 1, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("Example 3: temperatures = [30,60,90]")
    {
        std::vector<int> temperatures = {30, 60, 90};
        std::vector<int> expected = {1, 1, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single day (n = 1)")
    {
        std::vector<int> temperatures = {70};
        std::vector<int> expected = {0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("Monotonically decreasing temperatures: never gets warmer")
    {
        std::vector<int> temperatures = {90, 80, 70, 60, 50};
        std::vector<int> expected = {0, 0, 0, 0, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("All identical temperatures: strictly warmer required")
    {
        std::vector<int> temperatures = {50, 50, 50};
        std::vector<int> expected = {0, 0, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("Boundary values: minimum and maximum allowed temperatures")
    {
        std::vector<int> temperatures = {30, 100};
        std::vector<int> expected = {1, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }

    SECTION("Plateau followed by warmer temperature")
    {
        std::vector<int> temperatures = {40, 35, 35, 42};
        std::vector<int> expected = {3, 2, 1, 0};
        REQUIRE(Solution::dailyTemperatures(temperatures) == expected);
    }
}
