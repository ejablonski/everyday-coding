#include "1354.construct_target_array_with_multiple_sums.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1354;

TEST_CASE("LeetCode 1354 - Construct Target Array With Multiple Sums",
          "[LeetCode][1354][array][heap][priority-queue]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: target = [9, 3, 5]")
    {
        std::vector<int> target{9, 3, 5};
        REQUIRE(Solution::isPossible(target));
    }

    SECTION("Example 2: target = [1, 1, 1, 2]")
    {
        std::vector<int> target{1, 1, 1, 2};
        REQUIRE_FALSE(Solution::isPossible(target));
    }

    SECTION("Example 3: target = [8, 5]")
    {
        std::vector<int> target{8, 5};
        REQUIRE(Solution::isPossible(target));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: single element [1]")
    {
        std::vector<int> target{1};
        REQUIRE(Solution::isPossible(target));
    }

    SECTION("Single element greater than 1: [2]")
    {
        std::vector<int> target{2};
        REQUIRE_FALSE(Solution::isPossible(target));
    }

    SECTION("Already all ones: [1, 1, 1]")
    {
        std::vector<int> target{1, 1, 1};
        REQUIRE(Solution::isPossible(target));
    }

    SECTION("Two equal non-one elements: [2, 2]")
    {
        std::vector<int> target{2, 2};
        REQUIRE_FALSE(Solution::isPossible(target));
    }

    SECTION("Two even values: [2, 4]")
    {
        std::vector<int> target{2, 4};
        REQUIRE_FALSE(Solution::isPossible(target));
    }

    SECTION("Multi-step construction: [1, 5, 27]")
    {
        std::vector<int> target{1, 5, 27};
        REQUIRE(Solution::isPossible(target));
    }

    SECTION("Single large value at constraint bound: [1, 1000000000]")
    {
        std::vector<int> target{1, 1000000000};
        REQUIRE(Solution::isPossible(target));
    }

    SECTION("Three values at maximum constraint: [1000000000, 1000000000, 1000000000]")
    {
        std::vector<int> target{1000000000, 1000000000, 1000000000};
        REQUIRE_FALSE(Solution::isPossible(target));
    }
}
