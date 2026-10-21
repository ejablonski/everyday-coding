#include "3863.minimum_operations_to_sort_a_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 3863 - Minimum Operations to Sort a String",
          "[LeetCode][3863][string][greedy][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"dog\"")
    {
        std::string s = "dog";
        REQUIRE(Solution::minOperations(s) == 1);
    }

    SECTION("Example 2: s = \"card\"")
    {
        std::string s = "card";
        REQUIRE(Solution::minOperations(s) == 2);
    }

    SECTION("Example 3: s = \"gf\"")
    {
        std::string s = "gf";
        REQUIRE(Solution::minOperations(s) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single character string is already sorted: s = \"a\"")
    {
        std::string s = "a";
        REQUIRE(Solution::minOperations(s) == 0);
    }

    SECTION("Already sorted two-character string: s = \"ab\"")
    {
        std::string s = "ab";
        REQUIRE(Solution::minOperations(s) == 0);
    }

    SECTION("All characters identical: s = \"aaaa\"")
    {
        std::string s = "aaaa";
        REQUIRE(Solution::minOperations(s) == 0);
    }

    SECTION("Already sorted string of longer length: s = \"abcde\"")
    {
        std::string s = "abcde";
        REQUIRE(Solution::minOperations(s) == 0);
    }

    SECTION("Unsorted two-character string is impossible: s = \"ba\"")
    {
        std::string s = "ba";
        REQUIRE(Solution::minOperations(s) == -1);
    }

    SECTION("Single operation on prefix: s = \"bac\"")
    {
        std::string s = "bac";
        REQUIRE(Solution::minOperations(s) == 1);
    }

    SECTION("Single operation on inner substring: s = \"acbd\"")
    {
        std::string s = "acbd";
        REQUIRE(Solution::minOperations(s) == 1);
    }

    SECTION("Two operations with duplicate characters: s = \"bbaa\"")
    {
        std::string s = "bbaa";
        REQUIRE(Solution::minOperations(s) == 2);
    }

    SECTION("Three operations when max is at start and min is at end: s = \"cba\"")
    {
        std::string s = "cba";
        REQUIRE(Solution::minOperations(s) == 3);
    }

    SECTION("Three operations for fully reverse-sorted string: s = \"dcba\"")
    {
        std::string s = "dcba";
        REQUIRE(Solution::minOperations(s) == 3);
    }
}
