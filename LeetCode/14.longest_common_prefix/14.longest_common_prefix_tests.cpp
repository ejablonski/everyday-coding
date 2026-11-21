#include "14.longest_common_prefix.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace LC14;

TEST_CASE("LeetCode 14 - Longest Common Prefix", "[LeetCode][14][array][string][trie]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: strs = [\"flower\",\"flow\",\"flight\"]")
    {
        std::vector<std::string> strs = {"flower", "flow", "flight"};
        REQUIRE(Solution::longestCommonPrefix(strs) == "fl");
    }

    SECTION("Example 2: strs = [\"dog\",\"racecar\",\"car\"]")
    {
        std::vector<std::string> strs = {"dog", "racecar", "car"};
        REQUIRE(Solution::longestCommonPrefix(strs).empty());
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint: single non-empty string")
    {
        std::vector<std::string> strs = {"interspecies"};
        REQUIRE(Solution::longestCommonPrefix(strs) == "interspecies");
    }

    SECTION("Minimum constraint: single empty string")
    {
        std::vector<std::string> strs = {""};
        REQUIRE(Solution::longestCommonPrefix(strs).empty());
    }

    SECTION("Empty string among non-empty strings yields empty prefix")
    {
        std::vector<std::string> strs = {"abc", "", "ab"};
        REQUIRE(Solution::longestCommonPrefix(strs).empty());
    }

    SECTION("All strings identical")
    {
        std::vector<std::string> strs = {"same", "same", "same"};
        REQUIRE(Solution::longestCommonPrefix(strs) == "same");
    }

    SECTION("Shortest string placed last is full prefix of all others")
    {
        std::vector<std::string> strs = {"prefixlong", "prefixlonger", "prefix"};
        REQUIRE(Solution::longestCommonPrefix(strs) == "prefix");
    }

    SECTION("Maximum string length 200 diverging at the final character")
    {
        std::string shared(199, 'a');
        std::vector<std::string> strs = {shared + 'b', shared + 'c', shared + 'd'};
        REQUIRE(Solution::longestCommonPrefix(strs) == shared);
    }
}
