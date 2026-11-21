#include "139.word_break.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace LC139;

TEST_CASE(
    "LeetCode 139 - Word Break",
    "[LeetCode][139][array][hash-table][string][dynamic-programming][trie][memoization]"
    "[brute-force-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"leetcode\", wordDict = [\"leet\",\"code\"]")
    {
        std::vector<std::string> wordDict = {"leet", "code"};
        REQUIRE(Solution::wordBreak("leetcode", wordDict));
    }

    SECTION("Example 2: s = \"applepenapple\", wordDict = [\"apple\",\"pen\"]")
    {
        std::vector<std::string> wordDict = {"apple", "pen"};
        REQUIRE(Solution::wordBreak("applepenapple", wordDict));
    }

    SECTION("Example 3: s = \"catsandog\", wordDict = [\"cats\",\"dog\",\"sand\",\"and\",\"cat\"]")
    {
        std::vector<std::string> wordDict = {"cats", "dog", "sand", "and", "cat"};
        REQUIRE_FALSE(Solution::wordBreak("catsandog", wordDict));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length: single character matching dictionary")
    {
        std::vector<std::string> wordDict = {"a"};
        REQUIRE(Solution::wordBreak("a", wordDict));
    }

    SECTION("Minimum length: single character not in dictionary")
    {
        std::vector<std::string> wordDict = {"b"};
        REQUIRE_FALSE(Solution::wordBreak("a", wordDict));
    }

    SECTION("Overlapping dictionary words (case 1)")
    {
        std::vector<std::string> wordDict = {"car", "ca", "rs"};
        REQUIRE(Solution::wordBreak("cars", wordDict));
    }

    SECTION("Overlapping dictionary words (case 2)")
    {
        std::vector<std::string> wordDict = {"a", "ab", "bc"};
        REQUIRE(Solution::wordBreak("abbc", wordDict));
    }

    SECTION("All dictionary words longer than target string")
    {
        std::vector<std::string> wordDict = {"cats", "caterpillar"};
        REQUIRE_FALSE(Solution::wordBreak("cat", wordDict));
    }

    SECTION("Long repeating prefix failing on final character")
    {
        std::vector<std::string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa"};
        REQUIRE_FALSE(Solution::wordBreak("aaaaaaaaaaaaaaaaaaaaaab", wordDict));
    }
}
