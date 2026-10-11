#include "84.largest_rectangle_in_histogram.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 84 - Largest Rectangle in Histogram", "[LeetCode][84][array][stack][monotonic-stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: heights = [2,1,5,6,2,3]")
    {
        std::vector<int> heights = {2, 1, 5, 6, 2, 3};
        REQUIRE(Solution::largestRectangleArea(heights) == 10);
    }

    SECTION("Example 2: heights = [2,4]")
    {
        std::vector<int> heights = {2, 4};
        REQUIRE(Solution::largestRectangleArea(heights) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single positive bar (n = 1)")
    {
        std::vector<int> heights = {7};
        REQUIRE(Solution::largestRectangleArea(heights) == 7);
    }

    SECTION("Single bar with zero height (n = 1, heights[0] = 0)")
    {
        std::vector<int> heights = {0};
        REQUIRE(Solution::largestRectangleArea(heights) == 0);
    }

    SECTION("All bars have zero height")
    {
        std::vector<int> heights = {0, 0, 0};
        REQUIRE(Solution::largestRectangleArea(heights) == 0);
    }

    SECTION("All bars have equal height")
    {
        std::vector<int> heights = {3, 3, 3, 3};
        REQUIRE(Solution::largestRectangleArea(heights) == 12);
    }

    SECTION("Monotonically increasing heights")
    {
        std::vector<int> heights = {1, 2, 3, 4, 5};
        REQUIRE(Solution::largestRectangleArea(heights) == 9);
    }

    SECTION("Monotonically decreasing heights")
    {
        std::vector<int> heights = {5, 4, 3, 2, 1};
        REQUIRE(Solution::largestRectangleArea(heights) == 9);
    }

    SECTION("Valley with zero: isolated peaks separated by 0")
    {
        std::vector<int> heights = {6, 0, 6};
        REQUIRE(Solution::largestRectangleArea(heights) == 6);
    }
}
