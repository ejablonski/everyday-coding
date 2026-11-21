#include "1311.get_watched_videos_by_your_friends.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace LC1311;

TEST_CASE("LeetCode 1311 - Get Watched Videos by Your Friends", "[LeetCode][1311][array][hash-table][breadth-first-search][graph][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: id = 0, level = 1")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "A", "B" }, { "C" }, { "B", "C" }, { "D" } };
        std::vector<std::vector<int>> friends = { { 1, 2 }, { 0, 3 }, { 0, 3 }, { 1, 2 } };
        const std::vector<std::string> expected = { "B", "C" };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 1) == expected);
    }

    SECTION("Example 2: id = 0, level = 2")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "A", "B" }, { "C" }, { "B", "C" }, { "D" } };
        std::vector<std::vector<int>> friends = { { 1, 2 }, { 0, 3 }, { 0, 3 }, { 1, 2 } };
        const std::vector<std::string> expected = { "D" };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 2) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 2 with alphabetical tie-breaking")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "X" }, { "Z", "A", "M" } };
        std::vector<std::vector<int>> friends = { { 1 }, { 0 } };
        const std::vector<std::string> expected = { "A", "M", "Z" };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 1) == expected);
    }

    SECTION("Isolated user with no friends at level 1")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "A" }, { "B" }, { "C" } };
        std::vector<std::vector<int>> friends = { {}, { 2 }, { 1 } };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 1).empty());
    }

    SECTION("No person at requested level and self must not be revisited")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "A" }, { "B" }, { "C" } };
        std::vector<std::vector<int>> friends = { { 1 }, { 0, 2 }, { 1 } };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 1, 2).empty());
    }

    SECTION("Triangle shortcut: shortest path distance determines level")
    {
        std::vector<std::vector<std::string>> watchedVideos = { { "A" }, { "B" }, { "C" }, { "D" } };
        std::vector<std::vector<int>> friends = { { 1, 2 }, { 0, 2, 3 }, { 0, 1 }, { 1 } };
        const std::vector<std::string> expected = { "D" };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 2) == expected);
    }

    SECTION("Multiple frequency tiers with lexicographical tie-breaking")
    {
        std::vector<std::vector<std::string>> watchedVideos = {
            { "self" },
            { "vid2", "vid1", "alpha" },
            { "vid1", "beta", "alpha" },
            { "alpha", "vid2", "gamma" }
        };
        std::vector<std::vector<int>> friends = { { 1, 2, 3 }, { 0 }, { 0 }, { 0 } };
        const std::vector<std::string> expected = { "beta", "gamma", "vid1", "vid2", "alpha" };
        REQUIRE(Solution::watchedVideosByFriends(watchedVideos, friends, 0, 1) == expected);
    }
}
