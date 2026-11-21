#include "1200.minimum_absolute_difference.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1200;

TEST_CASE("LeetCode 1200 - Minimum Absolute Difference", "[LeetCode][1200][array][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: arr = [4, 2, 1, 3]")
    {
        std::vector<int> arr = {4, 2, 1, 3};
        std::vector<std::vector<int>> expected = {{1, 2}, {2, 3}, {3, 4}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("Example 2: arr = [1, 3, 6, 10, 15]")
    {
        std::vector<int> arr = {1, 3, 6, 10, 15};
        std::vector<std::vector<int>> expected = {{1, 3}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("Example 3: arr = [3, 8, -10, 23, 19, -4, -14, 27]")
    {
        std::vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
        std::vector<std::vector<int>> expected = {{-14, -10}, {19, 23}, {23, 27}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length unsorted pair: arr = [10, -5]")
    {
        std::vector<int> arr = {10, -5};
        std::vector<std::vector<int>> expected = {{-5, 10}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("Constraint boundary extremes: arr = [1000000, -1000000]")
    {
        std::vector<int> arr = {1000000, -1000000};
        std::vector<std::vector<int>> expected = {{-1000000, 1000000}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("All negative values with tied minimum difference: arr = [-1, -5, -3, -9]")
    {
        std::vector<int> arr = {-1, -5, -3, -9};
        std::vector<std::vector<int>> expected = {{-5, -3}, {-3, -1}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("Reverse-sorted arithmetic progression: arr = [20, 15, 10, 5, 0]")
    {
        std::vector<int> arr = {20, 15, 10, 5, 0};
        std::vector<std::vector<int>> expected = {{0, 5}, {5, 10}, {10, 15}, {15, 20}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }

    SECTION("Unique minimum difference at upper end after larger gaps")
    {
        std::vector<int> arr = {-100, 0, 50, 51, -200};
        std::vector<std::vector<int>> expected = {{50, 51}};
        REQUIRE(Solution::minimumAbsDifference(arr) == expected);
    }
}
