#include "l2q3.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Find All Numbers Disappeared in an Array",
          "[LeetCode][quest][data structures and algorithms][l2q3]")
{
    Solution solution;

    SECTION("Example 1: nums = [4, 3, 2, 7, 8, 2, 3, 1]")
    {
        std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
        std::vector<int> expected{5, 6};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("Example 2: nums = [1, 1]")
    {
        std::vector<int> nums{1, 1};
        std::vector<int> expected{2};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("Single element present: nums = [1]")
    {
        std::vector<int> nums{1};
        std::vector<int> expected{};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("All numbers present and sorted: nums = [1, 2, 3, 4, 5]")
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        std::vector<int> expected{};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("All numbers present but unsorted: nums = [3, 1, 4, 2]")
    {
        std::vector<int> nums{3, 1, 4, 2};
        std::vector<int> expected{};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("All elements identical: nums = [2, 2, 2, 2]")
    {
        std::vector<int> nums{2, 2, 2, 2};
        std::vector<int> expected{1, 3, 4};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("All elements identical to 1: nums = [1, 1, 1]")
    {
        std::vector<int> nums{1, 1, 1};
        std::vector<int> expected{2, 3};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("Missing first and last numbers: nums = [2, 2, 3, 3]")
    {
        std::vector<int> nums{2, 2, 3, 3};
        std::vector<int> expected{1, 4};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }

    SECTION("Multiple duplicates interspersed: nums = [1, 2, 2, 4, 4, 6]")
    {
        std::vector<int> nums{1, 2, 2, 4, 4, 6};
        std::vector<int> expected{3, 5};
        REQUIRE(solution.findDisappearedNumbers(nums) == expected);
    }
}
