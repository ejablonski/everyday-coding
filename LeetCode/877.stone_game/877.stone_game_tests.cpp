#include "877.stone_game.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC877;

TEST_CASE("LeetCode 877 - Stone Game",
          "[LeetCode][877][array][math][dynamic-programming][minimax-algorithm][game-theory][zero-sum-game]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: piles = [5, 3, 4, 5]")
    {
        std::vector<int> piles = {5, 3, 4, 5};
        REQUIRE(Solution::stoneGame(piles));
    }

    SECTION("Example 2: piles = [3, 7, 2, 3]")
    {
        std::vector<int> piles = {3, 7, 2, 3};
        REQUIRE(Solution::stoneGame(piles));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length two piles with min and max values")
    {
        std::vector<int> smallPiles = {1, 2};
        REQUIRE(Solution::stoneGame(smallPiles));

        std::vector<int> largePiles = {500, 499};
        REQUIRE(Solution::stoneGame(largePiles));
    }

    SECTION("Four piles with large inner element")
    {
        std::vector<int> piles = {3, 2, 10, 4};
        REQUIRE(Solution::stoneGame(piles));
    }

    SECTION("Dominant pile at an even index")
    {
        std::vector<int> piles = {1, 1, 500, 1, 1, 1};
        REQUIRE(Solution::stoneGame(piles));
    }

    SECTION("Dominant pile at an odd index")
    {
        std::vector<int> piles = {1, 500, 1, 1, 1, 1};
        REQUIRE(Solution::stoneGame(piles));
    }

    SECTION("Maximum length constraint: 500 piles near maximum value")
    {
        std::vector<int> piles(500, 500);
        piles[249] = 499;
        REQUIRE(Solution::stoneGame(piles));
    }
}
