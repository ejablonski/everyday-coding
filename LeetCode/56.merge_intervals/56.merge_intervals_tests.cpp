#include "56.merge_intervals.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

using namespace LC56;

TEST_CASE("LeetCode 56 - Merge Intervals", "[LeetCode][56][array][sorting][quicksort]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: intervals = [[1,3],[2,6],[8,10],[15,18]]")
    {
        std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        std::vector<std::vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 2: intervals = [[1,4],[4,5]]")
    {
        std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};
        std::vector<std::vector<int>> expected = {{1, 5}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Example 3: intervals = [[4,7],[1,4]]")
    {
        std::vector<std::vector<int>> intervals = {{4, 7}, {1, 4}};
        std::vector<std::vector<int>> expected = {{1, 7}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single zero-length interval at minimum boundary")
    {
        std::vector<std::vector<int>> intervals = {{0, 0}};
        std::vector<std::vector<int>> expected = {{0, 0}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Unsorted completely disjoint intervals")
    {
        std::vector<std::vector<int>> intervals = {{10, 12}, {0, 2}, {5, 7}};
        std::vector<std::vector<int>> expected = {{0, 2}, {5, 7}, {10, 12}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("One outer interval encloses all inner intervals")
    {
        std::vector<std::vector<int>> intervals = {{1, 10}, {2, 3}, {4, 8}, {9, 10}};
        std::vector<std::vector<int>> expected = {{1, 10}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Duplicate and point intervals touching endpoints")
    {
        std::vector<std::vector<int>> intervals = {{2, 2}, {2, 2}, {2, 5}, {5, 5}};
        std::vector<std::vector<int>> expected = {{2, 5}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }

    SECTION("Reverse-ordered chain merging across full constraint range [0, 10000]")
    {
        std::vector<std::vector<int>> intervals = {{8000, 10000}, {4000, 8000}, {0, 4000}};
        std::vector<std::vector<int>> expected = {{0, 10000}};
        REQUIRE_THAT(Solution::merge(intervals), Catch::Matchers::UnorderedEquals(expected));
    }
}
