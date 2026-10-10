#include "636.exclusive_time_of_functions.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("LeetCode 636 - Exclusive Time of Functions", "[LeetCode][636][stack][array]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: Basic nested functions")
    {
        int n = 2;
        std::vector<std::string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
        std::vector<int> expected = {3, 4};
        REQUIRE(Solution::exclusiveTime(n, logs) == expected);
    }

    SECTION("Example 2: Recursive calls")
    {
        int n = 1;
        std::vector<std::string> logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
        std::vector<int> expected = {8};
        REQUIRE(Solution::exclusiveTime(n, logs) == expected);
    }

    SECTION("Example 3: Recursive and subsequent function call")
    {
        int n = 2;
        std::vector<std::string> logs = {"0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"};
        std::vector<int> expected = {7, 1};
        REQUIRE(Solution::exclusiveTime(n, logs) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: 1 function, 2 logs (instant start and end)")
    {
        int n = 1;
        std::vector<std::string> logs = {"0:start:0", "0:end:0"};
        std::vector<int> expected = {1};
        REQUIRE(Solution::exclusiveTime(n, logs) == expected);
    }

    SECTION("Sequential function execution without nesting")
    {
        int n = 2;
        std::vector<std::string> logs = {"0:start:0", "0:end:2", "1:start:3", "1:end:5"};
        std::vector<int> expected = {3, 3};
        REQUIRE(Solution::exclusiveTime(n, logs) == expected);
    }
}
