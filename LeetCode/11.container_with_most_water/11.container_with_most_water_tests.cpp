#include "11.container_with_most_water.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC11;

TEST_CASE("LeetCode 11 - Container With Most Water", "[LeetCode][11][array][two-pointers][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: height = [1,8,6,2,5,4,8,3,7]")
    {
        std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        REQUIRE(Solution::maxArea(height) == 49);
    }

    SECTION("Example 2: height = [1,1]")
    {
        std::vector<int> height = {1, 1};
        REQUIRE(Solution::maxArea(height) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum height values: all zeros")
    {
        std::vector<int> height = {0, 0, 0};
        REQUIRE(Solution::maxArea(height) == 0);
    }

    SECTION("Minimum length with one zero height")
    {
        std::vector<int> height = {0, 5};
        REQUIRE(Solution::maxArea(height) == 0);
    }

    SECTION("Maximum height values at endpoints")
    {
        std::vector<int> height = {10000, 1, 1, 10000};
        REQUIRE(Solution::maxArea(height) == 30000);
    }

    SECTION("Narrow tall container beats wide shallow container")
    {
        std::vector<int> height = {1, 2, 100, 100, 2, 1};
        REQUIRE(Solution::maxArea(height) == 100);
    }

    SECTION("Strictly increasing heights")
    {
        std::vector<int> height = {1, 2, 3, 4, 5};
        REQUIRE(Solution::maxArea(height) == 6);
    }

    SECTION("Strictly decreasing heights")
    {
        std::vector<int> height = {5, 4, 3, 2, 1};
        REQUIRE(Solution::maxArea(height) == 6);
    }
}
