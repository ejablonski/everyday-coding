#include "292.nim_game.hpp"

#include <catch2/catch_test_macros.hpp>
#include <limits>

using namespace LC292;

TEST_CASE("LeetCode 292 - Nim Game",
          "[LeetCode][292][math][brainteaser][minimax-algorithm][game-theory][nim-game][impartial-game]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 4")
    {
        REQUIRE_FALSE(Solution::canWinNim(4));
    }

    SECTION("Example 2: n = 1")
    {
        REQUIRE(Solution::canWinNim(1));
    }

    SECTION("Example 3: n = 2")
    {
        REQUIRE(Solution::canWinNim(2));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Take all three stones on first turn: n = 3")
    {
        REQUIRE(Solution::canWinNim(3));
    }

    SECTION("Small values: n = 5..8")
    {
        REQUIRE(Solution::canWinNim(5));
        REQUIRE(Solution::canWinNim(6));
        REQUIRE(Solution::canWinNim(7));
        REQUIRE_FALSE(Solution::canWinNim(8));
    }

    SECTION("Medium values: n = 12..15 and 100")
    {
        REQUIRE_FALSE(Solution::canWinNim(12));
        REQUIRE(Solution::canWinNim(13));
        REQUIRE(Solution::canWinNim(14));
        REQUIRE(Solution::canWinNim(15));
        REQUIRE_FALSE(Solution::canWinNim(100));
    }

    SECTION("Large value near upper bound: n = 2^31 - 4")
    {
        constexpr int largeN = std::numeric_limits<int>::max() - 3;
        REQUIRE_FALSE(Solution::canWinNim(largeN));
    }

    SECTION("Maximum constraint: n = 2^31 - 1")
    {
        constexpr int maxN = std::numeric_limits<int>::max();
        REQUIRE(Solution::canWinNim(maxN));
    }
}
