#include "22.generate_parentheses.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <unordered_set>
#include <vector>

TEST_CASE("LeetCode 22 - Generate Parentheses", "[LeetCode][22][backtracking][string]")
{
    SECTION("Example 1: n = 3")
    {
        const std::vector<std::string> expected = {"((()))", "(()())", "(())()", "()(())",
                                                   "()()()"};
        REQUIRE(Solution::generateParenthesis(3) == expected);
    }

    SECTION("Example 2: n = 1 (minimum constraint)")
    {
        const std::vector<std::string> expected = {"()"};
        REQUIRE(Solution::generateParenthesis(1) == expected);
    }

    SECTION("n = 2")
    {
        const std::vector<std::string> expected = {"(())", "()()"};
        REQUIRE(Solution::generateParenthesis(2) == expected);
    }

    SECTION("n = 4")
    {
        const std::vector<std::string> expected = {
            "(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()",
            "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()"};
        REQUIRE(Solution::generateParenthesis(4) == expected);
    }

    SECTION("Output counts for n = 1 through 8 match Catalan numbers")
    {
        const std::vector<size_t> expected_catalan = {1, 2, 5, 14, 42, 132, 429, 1430};
        for (int n = 1; n <= 8; ++n) {
            REQUIRE(Solution::generateParenthesis(n).size() == expected_catalan[n - 1]);
        }
    }

    SECTION("Maximum constraint: n = 8 validity and uniqueness")
    {
        const auto result = Solution::generateParenthesis(8);
        REQUIRE(result.size() == 1430);

        const std::unordered_set<std::string> unique_results(result.begin(), result.end());
        REQUIRE(unique_results.size() == 1430);

        bool all_valid = true;
        for (const auto& s : result) {
            if (s.length() != 16) {
                all_valid = false;
                break;
            }
            int balance = 0;
            for (char ch : s) {
                if (ch == '(') {
                    ++balance;
                } else if (ch == ')') {
                    --balance;
                }
                if (balance < 0) {
                    all_valid = false;
                    break;
                }
            }
            if (balance != 0) {
                all_valid = false;
                break;
            }
        }
        REQUIRE(all_valid);
    }
}
