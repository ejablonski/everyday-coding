#include "1365.how_many_numbers_are_smaller_than_the_current_number.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number", "[LeetCode][1365][array][hash-table][sorting][counting]")
{
    Solution solution;

    SECTION("Example 1: nums = [8, 1, 2, 2, 3]")
    {
        std::vector<int> nums{8, 1, 2, 2, 3};
        std::vector<int> expected{4, 0, 1, 1, 3};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Example 2: nums = [6, 5, 4, 8]")
    {
        std::vector<int> nums{6, 5, 4, 8};
        std::vector<int> expected{2, 1, 0, 3};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Example 3: nums = [7, 7, 7, 7]")
    {
        std::vector<int> nums{7, 7, 7, 7};
        std::vector<int> expected{0, 0, 0, 0};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Minimum length distinct: nums = [1, 2]")
    {
        std::vector<int> nums{1, 2};
        std::vector<int> expected{0, 1};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Minimum length identical: nums = [5, 5]")
    {
        std::vector<int> nums{5, 5};
        std::vector<int> expected{0, 0};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Sorted descending: nums = [5, 4, 3, 2, 1]")
    {
        std::vector<int> nums{5, 4, 3, 2, 1};
        std::vector<int> expected{4, 3, 2, 1, 0};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Sorted ascending: nums = [1, 2, 3, 4, 5]")
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        std::vector<int> expected{0, 1, 2, 3, 4};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Array with zeros: nums = [0, 0, 1, 2]")
    {
        std::vector<int> nums{0, 0, 1, 2};
        std::vector<int> expected{0, 0, 2, 3};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }

    SECTION("Larger input with boundary values: nums = [100, 50, 100, 0, 50]")
    {
        std::vector<int> nums{100, 50, 100, 0, 50};
        std::vector<int> expected{3, 1, 3, 0, 1};
        REQUIRE(solution.smallerNumbersThanCurrent(nums) == expected);
    }
}
