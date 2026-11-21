#include "2076.process_restricted_friend_requests.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC2076;

TEST_CASE("LeetCode 2076 - Process Restricted Friend Requests",
          "[LeetCode][2076][union-find][graph]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]")
    {
        std::vector<std::vector<int>> restrictions = {{0, 1}};
        std::vector<std::vector<int>> requests = {{0, 2}, {2, 1}};
        std::vector<bool> expected = {true, false};
        REQUIRE(Solution::friendRequests(3, restrictions, requests) == expected);
    }

    SECTION("Example 2: n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]")
    {
        std::vector<std::vector<int>> restrictions = {{0, 1}};
        std::vector<std::vector<int>> requests = {{1, 2}, {0, 2}};
        std::vector<bool> expected = {true, false};
        REQUIRE(Solution::friendRequests(3, restrictions, requests) == expected);
    }

    SECTION("Example 3: n = 5, chain restrictions and indirect conflict")
    {
        std::vector<std::vector<int>> restrictions = {{0, 1}, {1, 2}, {2, 3}};
        std::vector<std::vector<int>> requests = {{0, 4}, {1, 2}, {3, 1}, {3, 4}};
        std::vector<bool> expected = {true, false, true, false};
        REQUIRE(Solution::friendRequests(5, restrictions, requests) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints with no restrictions: n = 2")
    {
        std::vector<std::vector<int>> restrictions = {};
        std::vector<std::vector<int>> requests = {{0, 1}};
        std::vector<bool> expected = {true};
        REQUIRE(Solution::friendRequests(2, restrictions, requests) == expected);
    }

    SECTION("Undirected restriction symmetry: n = 2, restrictions = [[0,1]]")
    {
        std::vector<std::vector<int>> restrictions = {{0, 1}};
        std::vector<std::vector<int>> requests = {{0, 1}, {1, 0}};
        std::vector<bool> expected = {false, false};
        REQUIRE(Solution::friendRequests(2, restrictions, requests) == expected);
    }

    SECTION("Repeated requests between already direct or indirect friends succeed")
    {
        std::vector<std::vector<int>> restrictions = {{0, 3}};
        std::vector<std::vector<int>> requests = {{0, 1}, {1, 2}, {0, 2}, {1, 0}, {2, 3}};
        std::vector<bool> expected = {true, true, true, true, false};
        REQUIRE(Solution::friendRequests(4, restrictions, requests) == expected);
    }

    SECTION("Rejected request does not mutate components for subsequent requests")
    {
        std::vector<std::vector<int>> restrictions = {{0, 1}, {2, 4}};
        std::vector<std::vector<int>> requests = {{0, 2}, {1, 2}, {1, 4}, {0, 3}, {3, 4}};
        std::vector<bool> expected = {true, false, true, true, false};
        REQUIRE(Solution::friendRequests(5, restrictions, requests) == expected);
    }

    SECTION("Merging two multi-node components blocked by non-endpoint restriction")
    {
        std::vector<std::vector<int>> restrictions = {{0, 5}};
        std::vector<std::vector<int>> requests = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {2, 3}};
        std::vector<bool> expected = {true, true, true, true, false};
        REQUIRE(Solution::friendRequests(6, restrictions, requests) == expected);
    }
}
