#include "l1q3.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Max Consecutive Ones", "[LeetCode][quest][data structures and algorithms][l1q3]")
{
    Solution solution;

    SECTION("Example 1: nums = [1, 1, 0, 1, 1, 1]")
    {
        std::vector<int> nums{1, 1, 0, 1, 1, 1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 3);
    }

    SECTION("Example 2: nums = [1, 0, 1, 1, 0, 1]")
    {
        std::vector<int> nums{1, 0, 1, 1, 0, 1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 2);
    }

    SECTION("Single element: 1")
    {
        std::vector<int> nums{1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 1);
    }

    SECTION("Single element: 0")
    {
        std::vector<int> nums{0};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 0);
    }

    SECTION("All zeros: nums = [0, 0, 0, 0]")
    {
        std::vector<int> nums{0, 0, 0, 0};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 0);
    }

    SECTION("All ones: nums = [1, 1, 1, 1]")
    {
        std::vector<int> nums{1, 1, 1, 1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 4);
    }

    SECTION("Consecutive ones at the end: nums = [0, 0, 1, 1, 1]")
    {
        std::vector<int> nums{0, 0, 1, 1, 1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 3);
    }

    SECTION("Alternating: nums = [1, 0, 1, 0, 1]")
    {
        std::vector<int> nums{1, 0, 1, 0, 1};
        REQUIRE(solution.findMaxConsecutiveOnes(nums) == 1);
    }
}



