#include "l1q1.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Concatenation of Array", "[LeetCode][quest][data structures and algorithms][l1q1]")
{
    Solution solution;

    SECTION("Example 1: nums = [1, 2, 1]")
    {
        std::vector<int> nums{1, 2, 1};
        std::vector<int> expected{1, 2, 1, 1, 2, 1};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }

    SECTION("Example 2: nums = [1, 3, 2, 1]")
    {
        std::vector<int> nums{1, 3, 2, 1};
        std::vector<int> expected{1, 3, 2, 1, 1, 3, 2, 1};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }

    SECTION("Minimum length: n = 1")
    {
        std::vector<int> nums{42};
        std::vector<int> expected{42, 42};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }

    SECTION("Array with two elements: nums = [1, 2]")
    {
        std::vector<int> nums{1, 2};
        std::vector<int> expected{1, 2, 1, 2};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }

    SECTION("Array with identical elements: nums = [7, 7, 7]")
    {
        std::vector<int> nums{7, 7, 7};
        std::vector<int> expected{7, 7, 7, 7, 7, 7};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }

    SECTION("Multiple elements: nums = [10, 20, 30, 40, 50]")
    {
        std::vector<int> nums{10, 20, 30, 40, 50};
        std::vector<int> expected{10, 20, 30, 40, 50, 10, 20, 30, 40, 50};
        REQUIRE(solution.getConcatenation(nums) == expected);
    }
}

