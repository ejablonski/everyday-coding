#include "1046.last_stone_weight.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1046;

TEST_CASE("LeetCode 1046 - Last Stone Weight",
          "[LeetCode][1046][array][heap][priority-queue][simulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: stones = [2, 7, 4, 1, 8, 1]")
    {
        std::vector<int> stones{2, 7, 4, 1, 8, 1};
        REQUIRE(Solution::lastStoneWeight(stones) == 1);
    }

    SECTION("Example 2: stones = [1]")
    {
        std::vector<int> stones{1};
        REQUIRE(Solution::lastStoneWeight(stones) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single stone at max weight: stones = [1000]")
    {
        std::vector<int> stones{1000};
        REQUIRE(Solution::lastStoneWeight(stones) == 1000);
    }

    SECTION("Two equal stones annihilate completely: stones = [5, 5]")
    {
        std::vector<int> stones{5, 5};
        REQUIRE(Solution::lastStoneWeight(stones) == 0);
    }

    SECTION("Two unequal stones: stones = [3, 9]")
    {
        std::vector<int> stones{3, 9};
        REQUIRE(Solution::lastStoneWeight(stones) == 6);
    }

    SECTION("All equal stones with odd count: stones = [4, 4, 4]")
    {
        std::vector<int> stones{4, 4, 4};
        REQUIRE(Solution::lastStoneWeight(stones) == 4);
    }

    SECTION("All equal stones with even count: stones = [4, 4, 4, 4]")
    {
        std::vector<int> stones{4, 4, 4, 4};
        REQUIRE(Solution::lastStoneWeight(stones) == 0);
    }

    SECTION("Unequal stones cancel out completely: stones = [1, 2, 3]")
    {
        std::vector<int> stones{1, 2, 3};
        REQUIRE(Solution::lastStoneWeight(stones) == 0);
    }

    SECTION("Dominant heavy stone reduced by smaller stones: stones = [10, 4, 3, 2]")
    {
        std::vector<int> stones{10, 4, 3, 2};
        REQUIRE(Solution::lastStoneWeight(stones) == 1);
    }

    SECTION("Maximum constraint length and weight: 30 stones of weight 1000")
    {
        std::vector<int> stones(30, 1000);
        REQUIRE(Solution::lastStoneWeight(stones) == 0);
    }
}
