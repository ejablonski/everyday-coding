#include "720.longest_word_in_dictionary.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace LC720;

TEST_CASE("LeetCode 720 - Longest Word in Dictionary",
          "[LeetCode][720][array][hash-table][string][trie][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: words = [\"w\",\"wo\",\"wor\",\"worl\",\"world\"]")
    {
        std::vector<std::string> words{"w", "wo", "wor", "worl", "world"};
        REQUIRE(Solution::longestWord(words) == "world");
    }

    SECTION("Example 2: lexicographical tie between \"apple\" and \"apply\"")
    {
        std::vector<std::string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
        REQUIRE(Solution::longestWord(words) == "apple");
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum size dictionary with single-character word")
    {
        std::vector<std::string> words{"z"};
        REQUIRE(Solution::longestWord(words) == "z");
    }

    SECTION("No single-character prefix returns empty string")
    {
        std::vector<std::string> words{"ab", "abc", "bc", "bcd"};
        REQUIRE(Solution::longestWord(words).empty());
    }

    SECTION("Tie-breaking among single-character words")
    {
        std::vector<std::string> words{"m", "z", "a", "b"};
        REQUIRE(Solution::longestWord(words) == "a");
    }

    SECTION("Broken prefix chain rejects longer unbuildable word")
    {
        std::vector<std::string> words{"a", "ab", "abcd", "b", "bc", "bcd"};
        REQUIRE(Solution::longestWord(words) == "bcd");
    }

    SECTION("Duplicate words and equal-length buildable chains")
    {
        std::vector<std::string> words{"c", "ca", "cat", "car", "b", "ba", "bat", "b", "bat"};
        REQUIRE(Solution::longestWord(words) == "bat");
    }

    SECTION("Maximum word length boundary (length 30) in reverse order")
    {
        std::vector<std::string> words;
        words.reserve(30);
        for (int len = 30; len >= 1; --len) {
            words.emplace_back(static_cast<std::size_t>(len), 'a');
        }
        REQUIRE(Solution::longestWord(words) == std::string(30, 'a'));
    }
}
