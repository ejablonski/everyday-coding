#include "1441.build_an_array_with_stack_operations.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("LeetCode 1441 - Build an Array With Stack Operations",
          "[LeetCode][1441][array][stack][simulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: target = [1,3], n = 3")
    {
        std::vector<int> target = {1, 3};
        int n = 3;
        std::vector<std::string> expected = {"Push", "Push", "Pop", "Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }

    SECTION("Example 2: target = [1,2,3], n = 3")
    {
        std::vector<int> target = {1, 2, 3};
        int n = 3;
        std::vector<std::string> expected = {"Push", "Push", "Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }

    SECTION("Example 3: target = [1,2], n = 4")
    {
        std::vector<int> target = {1, 2};
        int n = 4;
        std::vector<std::string> expected = {"Push", "Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: target = [1], n = 1")
    {
        std::vector<int> target = {1};
        int n = 1;
        std::vector<std::string> expected = {"Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }

    SECTION("Target value at end of n: target = [3], n = 3")
    {
        std::vector<int> target = {3};
        int n = 3;
        std::vector<std::string> expected = {"Push", "Pop", "Push", "Pop", "Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }

    SECTION("Tricky one: target = [2,3,4], n = 4")
    {
        std::vector<int> target = {2, 3, 4};
        int n = 4;
        std::vector<std::string> expected = {"Push", "Pop", "Push", "Push", "Push"};
        REQUIRE(Solution::buildArray(target, n) == expected);
    }
}
