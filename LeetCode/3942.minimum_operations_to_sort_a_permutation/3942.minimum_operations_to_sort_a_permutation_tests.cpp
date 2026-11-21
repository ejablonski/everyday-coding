#include "3942.minimum_operations_to_sort_a_permutation.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC3942;

TEST_CASE("LeetCode 3942 - Minimum Operations to Sort a Permutation",
          "[LeetCode][3942][array][math][greedy]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [0, 2, 1]")
    {
        std::vector<int> nums{0, 2, 1};
        REQUIRE(Solution::minOperations(nums) == 2);
    }

    SECTION("Example 2: nums = [1, 0, 2]")
    {
        std::vector<int> nums{1, 0, 2};
        REQUIRE(Solution::minOperations(nums) == 2);
    }

    SECTION("Example 3: nums = [2, 0, 1, 3]")
    {
        std::vector<int> nums{2, 0, 1, 3};
        REQUIRE(Solution::minOperations(nums) == -1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element permutation is already sorted: nums = [0]")
    {
        std::vector<int> nums{0};
        REQUIRE(Solution::minOperations(nums) == 0);
    }

    SECTION("Two elements already sorted: nums = [0, 1]")
    {
        std::vector<int> nums{0, 1};
        REQUIRE(Solution::minOperations(nums) == 0);
    }

    SECTION("Two elements reversed sorted: nums = [1, 0]")
    {
        std::vector<int> nums{1, 0};
        REQUIRE(Solution::minOperations(nums) == 1);
    }

    SECTION("Already sorted array: nums = [0, 1, 2, 3]")
    {
        std::vector<int> nums{0, 1, 2, 3};
        REQUIRE(Solution::minOperations(nums) == 0);
    }

    SECTION("Single reverse operation on reverse-sorted array: nums = [3, 2, 1, 0]")
    {
        std::vector<int> nums{3, 2, 1, 0};
        REQUIRE(Solution::minOperations(nums) == 1);
    }

    SECTION("Single left rotation: nums = [3, 0, 1, 2]")
    {
        std::vector<int> nums{3, 0, 1, 2};
        REQUIRE(Solution::minOperations(nums) == 1);
    }

    SECTION("Two left rotations: nums = [2, 3, 0, 1]")
    {
        std::vector<int> nums{2, 3, 0, 1};
        REQUIRE(Solution::minOperations(nums) == 2);
    }

    SECTION("Right rotation via reverse-rotate-reverse: nums = [1, 2, 3, 0]")
    {
        std::vector<int> nums{1, 2, 3, 0};
        REQUIRE(Solution::minOperations(nums) == 3);
    }

    SECTION("Unreachable permutation: nums = [1, 3, 0, 2]")
    {
        std::vector<int> nums{1, 3, 0, 2};
        REQUIRE(Solution::minOperations(nums) == -1);
    }

    SECTION("Unreachable permutation of length 5: nums = [0, 2, 1, 3, 4]")
    {
        std::vector<int> nums{0, 2, 1, 3, 4};
        REQUIRE(Solution::minOperations(nums) == -1);
    }
}
