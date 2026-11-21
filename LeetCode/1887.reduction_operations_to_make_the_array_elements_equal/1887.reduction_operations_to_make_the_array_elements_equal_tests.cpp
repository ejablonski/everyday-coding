#include "1887.reduction_operations_to_make_the_array_elements_equal.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1887;

TEST_CASE("LeetCode 1887 - Reduction Operations to Make the Array Elements Equal",
          "[LeetCode][1887][array][sorting]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [5, 1, 3]")
    {
        std::vector<int> nums = {5, 1, 3};
        REQUIRE(Solution::reductionOperations(nums) == 3);
    }

    SECTION("Example 2: nums = [1, 1, 1]")
    {
        std::vector<int> nums = {1, 1, 1};
        REQUIRE(Solution::reductionOperations(nums) == 0);
    }

    SECTION("Example 3: nums = [1, 1, 2, 2, 3]")
    {
        std::vector<int> nums = {1, 1, 2, 2, 3};
        REQUIRE(Solution::reductionOperations(nums) == 4);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single element (minimum length)")
    {
        std::vector<int> nums = {42};
        REQUIRE(Solution::reductionOperations(nums) == 0);
    }

    SECTION("Two distinct boundary values (1 and 50000)")
    {
        std::vector<int> nums = {1, 50000};
        REQUIRE(Solution::reductionOperations(nums) == 1);
    }

    SECTION("Strictly increasing elements")
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        REQUIRE(Solution::reductionOperations(nums) == 10);
    }

    SECTION("Strictly decreasing elements")
    {
        std::vector<int> nums = {5, 4, 3, 2, 1};
        REQUIRE(Solution::reductionOperations(nums) == 10);
    }

    SECTION("Duplicates separated by large value gaps")
    {
        std::vector<int> nums = {10, 10, 50000, 50000, 100, 100};
        REQUIRE(Solution::reductionOperations(nums) == 6);
    }

    SECTION("All elements equal at maximum constraint value")
    {
        std::vector<int> nums = {50000, 50000, 50000};
        REQUIRE(Solution::reductionOperations(nums) == 0);
    }
}
