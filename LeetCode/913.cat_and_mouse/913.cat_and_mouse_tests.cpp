#include "913.cat_and_mouse.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC913;

TEST_CASE(
    "LeetCode 913 - Cat and Mouse",
    "[LeetCode][913][math][dynamic-programming][graph][topological-sort][memoization][minimax-algorithm][game-theory][zero-sum-game]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: Draw")
    {
        std::vector<std::vector<int>> graph = {{2, 5},    {3},    {0, 4, 5},
                                               {1, 4, 5}, {2, 3}, {0, 2, 3}};
        REQUIRE(Solution::catMouseGame(graph) == 0);
    }

    SECTION("Example 2: Mouse wins")
    {
        std::vector<std::vector<int>> graph = {{1, 3}, {0}, {3}, {0, 2}};
        REQUIRE(Solution::catMouseGame(graph) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum size graph (n = 3): Mouse reaches hole on turn 1")
    {
        std::vector<std::vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};
        REQUIRE(Solution::catMouseGame(graph) == 1);
    }

    SECTION("Minimum size graph (n = 3): Cat blocks hole and catches Mouse immediately")
    {
        // Path 0 - 2 - 1: Mouse at 1 is forced to move onto Cat at 2
        std::vector<std::vector<int>> graph = {{2}, {2}, {0, 1}};
        REQUIRE(Solution::catMouseGame(graph) == 2);
    }

    SECTION("Cat corners Mouse in a cycle away from the hole")
    {
        // Hole 0 connects only through Cat at 2; Mouse cannot escape triangle {1, 3, 4}
        std::vector<std::vector<int>> graph = {{2}, {3, 4}, {0, 3}, {1, 2, 4}, {1, 3}};
        REQUIRE(Solution::catMouseGame(graph) == 2);
    }

    SECTION("Mouse avoids shorter trap and escapes via longer bypass path")
    {
        // Going 1 -> 3 loses to Cat 2 -> 3, so Mouse takes 1 -> 4 -> 5 -> 0
        std::vector<std::vector<int>> graph = {{3, 5}, {3, 4}, {3}, {0, 1, 2}, {1, 5}, {0, 4}};
        REQUIRE(Solution::catMouseGame(graph) == 1);
    }

    SECTION("Draw on 4-cycle when Cat guards the bridge to the hole")
    {
        // Mouse cannot pass through 5 -> 2 -> 0, but maintains opposite parity on cycle 1-3-5-4-1
        std::vector<std::vector<int>> graph = {{2}, {3, 4}, {0, 5}, {1, 5}, {1, 5}, {2, 3, 4}};
        REQUIRE(Solution::catMouseGame(graph) == 0);
    }

    SECTION("Delayed Cat win around the hole")
    {
        std::vector<std::vector<int>> graph = {
            {5, 6}, {3, 4}, {6}, {1, 4, 5}, {1, 3, 5}, {0, 3, 4, 6}, {0, 2, 5}};
        REQUIRE(Solution::catMouseGame(graph) == 2);
    }
}
