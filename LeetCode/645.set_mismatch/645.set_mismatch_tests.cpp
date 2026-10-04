#include "645.set_mismatch.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 645 - Set Mismatch", "[LeetCode][645][array][hash-table][bit-manipulation][sorting]")
{
    Solution solution;

    SECTION("Example 1: nums = [1, 2, 2, 4]")
    {
        std::vector<int> nums{1, 2, 2, 4};
        std::vector<int> expected{2, 3};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("Example 2: nums = [1, 1]")
    {
        std::vector<int> nums{1, 1};
        std::vector<int> expected{1, 2};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("Minimum length with 1 missing: nums = [2, 2]")
    {
        std::vector<int> nums{2, 2};
        std::vector<int> expected{2, 1};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("Last number missing: nums = [1, 2, 3, 4, 3]")
    {
        std::vector<int> nums{1, 2, 3, 4, 3};
        std::vector<int> expected{3, 5};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("First number missing: nums = [3, 2, 3, 4, 5]")
    {
        std::vector<int> nums{3, 2, 3, 4, 5};
        std::vector<int> expected{3, 1};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("Unsorted input: nums = [3, 1, 2, 5, 3]")
    {
        std::vector<int> nums{3, 1, 2, 5, 3};
        std::vector<int> expected{3, 4};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }

    SECTION("Larger input: nums = [1, 5, 3, 2, 2, 6, 7]")
    {
        std::vector<int> nums{1, 5, 3, 2, 2, 6, 7};
        std::vector<int> expected{2, 4};
        REQUIRE(solution.findErrorNums(nums) == expected);
    }
}


