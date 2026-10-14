#include "301.remove_invalid_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

TEST_CASE("LeetCode 301 - Remove Invalid Parentheses",
          "[LeetCode][301][string][backtracking][breadth-first-search]")
{
    using Catch::Matchers::UnorderedEquals;

    // --- Official Markdown Examples ---
    SECTION("Example 1: s = \"()())()\"")
    {
        const std::string s = "()())()";
        const std::vector<std::string> expected = {"(())()", "()()()"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Example 2: s = \"(a)())()\"")
    {
        const std::string s = "(a)())()";
        const std::vector<std::string> expected = {"(a())()", "(a)()()"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Example 3: s = \")(\"")
    {
        const std::string s = ")(";
        const std::vector<std::string> expected = {""};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single opening parenthesis: s = \"(\"")
    {
        const std::string s = "(";
        const std::vector<std::string> expected = {""};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Single closing parenthesis: s = \")\"")
    {
        const std::string s = ")";
        const std::vector<std::string> expected = {""};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Single letter (minimum constraint): s = \"a\"")
    {
        const std::string s = "a";
        const std::vector<std::string> expected = {"a"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Only letters without parentheses: s = \"leetcode\"")
    {
        const std::string s = "leetcode";
        const std::vector<std::string> expected = {"leetcode"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Already valid string with letters: s = \"(a)(b)\"")
    {
        const std::string s = "(a)(b)";
        const std::vector<std::string> expected = {"(a)(b)"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("All invalid parentheses with letters: s = \")a(\"")
    {
        const std::string s = ")a(";
        const std::vector<std::string> expected = {"a"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Extra opening parentheses: s = \"(()\"")
    {
        const std::string s = "(()";
        const std::vector<std::string> expected = {"()"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }

    SECTION("Multiple invalid surrounding letters: s = \")((a))(\"")
    {
        const std::string s = ")((a))(";
        const std::vector<std::string> expected = {"((a))"};
        REQUIRE_THAT(Solution::removeInvalidParentheses(s), UnorderedEquals(expected));
    }
}
