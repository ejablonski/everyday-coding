#include "1470.shuffle_the_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 1470 - Shuffle the Array", "[LeetCode][1470][array]")
{
    Solution solution;

    SECTION("Example 1: nums = [2, 5, 1, 3, 4, 7], n = 3")
    {
        std::vector<int> nums{2, 5, 1, 3, 4, 7};
        std::vector<int> expected{2, 3, 5, 4, 1, 7};
        REQUIRE(solution.shuffle(nums, 3) == expected);
    }

    SECTION("Example 2: nums = [1, 2, 3, 4, 4, 3, 2, 1], n = 4")
    {
        std::vector<int> nums{1, 2, 3, 4, 4, 3, 2, 1};
        std::vector<int> expected{1, 4, 2, 3, 3, 2, 4, 1};
        REQUIRE(solution.shuffle(nums, 4) == expected);
    }

    SECTION("Example 3: nums = [1, 1, 2, 2], n = 2")
    {
        std::vector<int> nums{1, 1, 2, 2};
        std::vector<int> expected{1, 2, 1, 2};
        REQUIRE(solution.shuffle(nums, 2) == expected);
    }

    SECTION("Minimum length: n = 1, nums = [10, 20]")
    {
        std::vector<int> nums{10, 20};
        std::vector<int> expected{10, 20};
        REQUIRE(solution.shuffle(nums, 1) == expected);
    }

    SECTION("All identical elements: nums = [5, 5, 5, 5, 5, 5], n = 3")
    {
        std::vector<int> nums{5, 5, 5, 5, 5, 5};
        std::vector<int> expected{5, 5, 5, 5, 5, 5};
        REQUIRE(solution.shuffle(nums, 3) == expected);
    }

    SECTION("Distinct block values: nums = [1, 2, 3, 10, 20, 30], n = 3")
    {
        std::vector<int> nums{1, 2, 3, 10, 20, 30};
        std::vector<int> expected{1, 10, 2, 20, 3, 30};
        REQUIRE(solution.shuffle(nums, 3) == expected);
    }
}


