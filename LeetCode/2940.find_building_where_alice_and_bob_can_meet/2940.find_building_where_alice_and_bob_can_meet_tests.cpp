#include "2940.find_building_where_alice_and_bob_can_meet.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2940;

TEST_CASE("LeetCode 2940 - Find Building Where Alice and Bob Can Meet",
          "[LeetCode][2940][array][binary-search][stack][binary-indexed-tree][segment-tree]"
          "[heap][priority-queue][monotonic-stack]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: heights = [6,4,8,5,2,7]")
    {
        std::vector<int> heights{6, 4, 8, 5, 2, 7};
        std::vector<std::vector<int>> queries{{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{2, 5, -1, 5, 2});
    }

    SECTION("Example 2: heights = [5,3,8,2,6,1,4,6]")
    {
        std::vector<int> heights{5, 3, 8, 2, 6, 1, 4, 6};
        std::vector<std::vector<int>> queries{{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{7, 6, -1, 4, 6});
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single building (minimum constraint)")
    {
        std::vector<int> heights{1};
        std::vector<std::vector<int>> queries{{0, 0}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) == std::vector<int>{0});
    }

    SECTION("All buildings have equal height (strict inequality required)")
    {
        std::vector<int> heights{5, 5, 5, 5};
        std::vector<std::vector<int>> queries{{0, 0}, {0, 1}, {2, 1}, {0, 3}, {3, 3}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{0, -1, -1, -1, 3});
    }

    SECTION("Strictly increasing heights allow direct moves regardless of query order")
    {
        std::vector<int> heights{1, 2, 3, 4, 5};
        std::vector<std::vector<int>> queries{{0, 4}, {4, 0}, {1, 3}, {3, 2}, {2, 2}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{4, 4, 3, 3, 2});
    }

    SECTION("Strictly decreasing heights forbid all cross-building meetings")
    {
        std::vector<int> heights{10, 8, 6, 4, 2};
        std::vector<std::vector<int>> queries{{0, 1}, {1, 3}, {4, 0}, {2, 2}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{-1, -1, -1, 2});
    }

    SECTION("Equal-height endpoints and maximum height constraint (10^9)")
    {
        std::vector<int> heights{1'000'000'000, 500'000'000, 500'000'000, 999'999'999,
                                 1'000'000'000};
        std::vector<std::vector<int>> queries{{1, 2}, {2, 1}, {0, 4}, {1, 3}, {3, 0}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{3, 3, -1, 3, -1});
    }

    SECTION("Multiple taller candidates select the leftmost building")
    {
        std::vector<int> heights{5, 1, 6, 10, 7};
        std::vector<std::vector<int>> queries{{0, 1}, {1, 0}, {0, 2}, {0, 3}, {2, 4}};

        REQUIRE(Solution::leftmostBuildingQueries(heights, queries) ==
                std::vector<int>{2, 2, 2, 3, 4});
    }
}
