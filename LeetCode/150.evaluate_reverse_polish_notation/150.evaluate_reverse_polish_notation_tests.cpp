#include "150.evaluate_reverse_polish_notation.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("LeetCode 150 - Evaluate Reverse Polish Notation", "[LeetCode][150][stack][math][array]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: tokens = [\"2\",\"1\",\"+\",\"3\",\"*\"]")
    {
        std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
        REQUIRE(Solution::evalRPN(tokens) == 9);
    }

    SECTION("Example 2: tokens = [\"4\",\"13\",\"5\",\"/\",\"+\"]")
    {
        std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
        REQUIRE(Solution::evalRPN(tokens) == 6);
    }

    SECTION("Example 3: Complex nested expression")
    {
        std::vector<std::string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                                           "/",  "*", "17", "+", "5", "+"};
        REQUIRE(Solution::evalRPN(tokens) == 22);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: single positive integer")
    {
        std::vector<std::string> tokens = {"42"};
        REQUIRE(Solution::evalRPN(tokens) == 42);
    }

    SECTION("Minimum constraints: single negative integer (boundary)")
    {
        std::vector<std::string> tokens = {"-200"};
        REQUIRE(Solution::evalRPN(tokens) == -200);
    }

    SECTION("Division truncating towards zero with negative result")
    {
        std::vector<std::string> tokens = {"10", "-3", "/"};
        REQUIRE(Solution::evalRPN(tokens) == -3);
    }

    SECTION("Tricky one")
    {
        std::vector<std::string> tokens = {"4", "3", "-"};
        REQUIRE(Solution::evalRPN(tokens) == 1);
    }
}
