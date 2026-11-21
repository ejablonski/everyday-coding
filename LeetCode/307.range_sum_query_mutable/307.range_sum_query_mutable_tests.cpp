#include "307.range_sum_query_mutable.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC307;

TEST_CASE("LeetCode 307 - Range Sum Query - Mutable",
          "[LeetCode][307][array][divide-and-conquer][design][binary-indexed-tree][segment-tree]"
          "[sqrt-decomposition]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [1, 3, 5] with sumRange and update")
    {
        std::vector<int> nums{1, 3, 5};
        NumArray numArray(nums);

        REQUIRE(numArray.sumRange(0, 2) == 9);
        numArray.update(1, 2);
        REQUIRE(numArray.sumRange(0, 2) == 8);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Single-element array with boundary updates")
    {
        std::vector<int> nums{42};
        NumArray numArray(nums);

        REQUIRE(numArray.sumRange(0, 0) == 42);
        numArray.update(0, -100);
        REQUIRE(numArray.sumRange(0, 0) == -100);
        numArray.update(0, 100);
        REQUIRE(numArray.sumRange(0, 0) == 100);
    }

    SECTION("Negative numbers and alternating constraint bounds (-100 and 100)")
    {
        std::vector<int> nums{-100, 100, -100, 100};
        NumArray numArray(nums);

        REQUIRE(numArray.sumRange(0, 3) == 0);
        REQUIRE(numArray.sumRange(0, 0) == -100);
        REQUIRE(numArray.sumRange(1, 2) == 0);

        numArray.update(0, 100);
        REQUIRE(numArray.sumRange(0, 3) == 200);

        numArray.update(2, 100);
        REQUIRE(numArray.sumRange(0, 3) == 400);
        REQUIRE(numArray.sumRange(1, 3) == 300);
    }

    SECTION("Repeated updates to the same index including no-op update")
    {
        std::vector<int> nums{2, 4, 6, 8};
        NumArray numArray(nums);

        numArray.update(2, 10);
        REQUIRE(numArray.sumRange(0, 3) == 24);

        numArray.update(2, 10);
        REQUIRE(numArray.sumRange(0, 3) == 24);

        numArray.update(2, -6);
        REQUIRE(numArray.sumRange(1, 3) == 6);
        REQUIRE(numArray.sumRange(2, 2) == -6);
    }

    SECTION("Non-power-of-two length with prefix, middle, and suffix queries")
    {
        std::vector<int> nums{7, -3, 5, 0, -2, 8, 1};
        NumArray numArray(nums);

        REQUIRE(numArray.sumRange(0, 6) == 16);
        REQUIRE(numArray.sumRange(1, 4) == 0);

        numArray.update(0, -7);
        REQUIRE(numArray.sumRange(0, 2) == -5);

        numArray.update(6, 10);
        REQUIRE(numArray.sumRange(4, 6) == 16);
        REQUIRE(numArray.sumRange(0, 6) == 11);
    }

    SECTION("Multi-block array (64 elements) with endpoint and midpoint updates")
    {
        std::vector<int> nums(64, 100);
        NumArray numArray(nums);

        REQUIRE(numArray.sumRange(0, 63) == 6400);
        REQUIRE(numArray.sumRange(16, 47) == 3200);

        numArray.update(0, -100);
        numArray.update(31, -100);
        numArray.update(63, -100);

        REQUIRE(numArray.sumRange(0, 63) == 5800);
        REQUIRE(numArray.sumRange(1, 62) == 6000);
        REQUIRE(numArray.sumRange(31, 31) == -100);
    }
}
