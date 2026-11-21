#include "2508.add_edges_to_make_degrees_of_all_nodes_even.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2508;

TEST_CASE("LeetCode 2508 - Add Edges to Make Degrees of All Nodes Even", "[LeetCode][2508][hash-table][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 5, two odd-degree nodes connected by one new edge")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 2 }, { 1, 4 }, { 2, 5 } };
        REQUIRE(Solution::isPossible(5, edges) == true);
    }

    SECTION("Example 2: n = 4, four odd-degree nodes fixed with two new edges")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 3, 4 } };
        REQUIRE(Solution::isPossible(4, edges) == true);
    }

    SECTION("Example 3: n = 4, star graph cannot be fixed")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 1, 3 }, { 1, 4 } };
        REQUIRE_FALSE(Solution::isPossible(4, edges));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Already all even degrees: triangle with minimum n = 3")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 2, 3 }, { 1, 3 } };
        REQUIRE(Solution::isPossible(3, edges) == true);
    }

    SECTION("Minimum constraints: n = 3 with two edges forming a path")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 2, 3 } };
        REQUIRE(Solution::isPossible(3, edges) == true);
    }

    SECTION("Two already-adjacent odd nodes bridged via an isolated helper node")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 1, 3 }, { 2, 3 }, { 1, 4 } };
        REQUIRE(Solution::isPossible(5, edges) == true);
    }

    SECTION("Two already-adjacent odd nodes with no valid helper node")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 1, 3 }, { 2, 3 }, { 1, 4 } };
        REQUIRE_FALSE(Solution::isPossible(4, edges));
    }

    SECTION("Four odd-degree nodes where only one specific pairing is missing")
    {
        std::vector<std::vector<int>> edges = {
            { 1, 2 }, { 2, 4 }, { 4, 3 }, { 3, 1 }, { 1, 5 }, { 2, 5 }, { 3, 5 }, { 4, 5 }
        };
        REQUIRE(Solution::isPossible(5, edges) == true);
    }

    SECTION("Four odd-degree nodes where every pairing collides with an existing edge")
    {
        std::vector<std::vector<int>> edges = {
            { 1, 2 }, { 1, 3 }, { 2, 3 }, { 1, 4 }, { 2, 5 }, { 3, 6 }, { 4, 5 }
        };
        REQUIRE_FALSE(Solution::isPossible(6, edges));
    }

    SECTION("More than four odd-degree nodes is always impossible")
    {
        std::vector<std::vector<int>> edges = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
        REQUIRE_FALSE(Solution::isPossible(6, edges));
    }
}
