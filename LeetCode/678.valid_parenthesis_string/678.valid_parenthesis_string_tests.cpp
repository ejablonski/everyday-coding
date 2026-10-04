#include "678.valid_parenthesis_string.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 678 - Valid Parenthesis String",
          "[LeetCode][678][string][dynamic-programming][memoization][greedy]")
{
    SECTION("[DP] Example 1: s = \"()\"")
    {
        std::string s = "()";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Example 2: s = \"(*)\"")
    {
        std::string s = "(*)";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Example 3: s = \"(*))\"")
    {
        std::string s = "(*))";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Example 4: s = \"(\"")
    {
        std::string s = "(";
        REQUIRE(Solution::checkValidString(s) == false);
    }

    SECTION("[DP] Edge Case: All stars")
    {
        std::string s = "***";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Edge Case: Closing bracket first")
    {
        std::string s = ")(";
        REQUIRE(Solution::checkValidString(s) == false);
    }

    SECTION("[DP] Edge Case: Star before closing bracket")
    {
        std::string s = "*)";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Edge Case: Insufficient stars")
    {
        std::string s = ")*(";
        REQUIRE(Solution::checkValidString(s) == false);
    }

    SECTION("[DP] Constraint Case: Single character")
    {
        std::string s1 = "*";
        REQUIRE(Solution::checkValidString(s1) == true);

        std::string s2 = ")";
        REQUIRE(Solution::checkValidString(s2) == false);
    }

    SECTION("[DP] Complex matching")
    {
        std::string s = "(((((*)))**";
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Complex mismatching")
    {
        std::string s = "*(**)";
        REQUIRE(Solution::checkValidString(s) == true);

        std::string s_fail = "*(**)))))";
        REQUIRE(Solution::checkValidString(s_fail) == false);
    }

    SECTION("[DP] Performance Case: 60 Asterisks")
    {
        std::string s(60, '*');
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[DP] Performance Case: 60 Asterisks")
    {
        std::string s(60, '*');
        REQUIRE(Solution::checkValidString(s) == true);
    }

    SECTION("[Greedy] Example 1: s = \"()\"")
    {
        std::string s = "()";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Example 2: s = \"(*)\"")
    {
        std::string s = "(*)";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Example 3: s = \"(*))\"")
    {
        std::string s = "(*))";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Example 4: s = \"(\"")
    {
        std::string s = "(";
        REQUIRE(Solution::checkValidStringGreedy(s) == false);
    }

    SECTION("[Greedy] Edge Case: All stars")
    {
        std::string s = "***";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Edge Case: Closing bracket first")
    {
        std::string s = ")(";
        REQUIRE(Solution::checkValidStringGreedy(s) == false);
    }

    SECTION("[Greedy] Edge Case: Star before closing bracket")
    {
        std::string s = "*)";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Edge Case: Insufficient stars")
    {
        std::string s = ")*(";
        REQUIRE(Solution::checkValidStringGreedy(s) == false);
    }

    SECTION("[Greedy] Constraint Case: Single character")
    {
        std::string s1 = "*";
        REQUIRE(Solution::checkValidStringGreedy(s1) == true);

        std::string s2 = ")";
        REQUIRE(Solution::checkValidStringGreedy(s2) == false);
    }

    SECTION("[Greedy] Complex matching")
    {
        std::string s = "(((((*)))**";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Complex mismatching")
    {
        std::string s = "*(**)";
        REQUIRE(Solution::checkValidStringGreedy(s) == true);

        std::string s_fail = "*(**)))))";
        REQUIRE(Solution::checkValidStringGreedy(s_fail) == false);
    }

    SECTION("[Greedy] Performance Case: 60 Asterisks")
    {
        std::string s(60, '*');
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }

    SECTION("[Greedy] Performance Case: 60 Asterisks")
    {
        std::string s(60, '*');
        REQUIRE(Solution::checkValidStringGreedy(s) == true);
    }
}
