#include "1191.k_concatenation_maximum_sum.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC1191;

TEST_CASE(
    "LeetCode 1191 - K-Concatenation Maximum Sum",
    "[LeetCode][1191][array][dynamic-programming]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: arr = [1,2], k = 3")
    {
        std::vector<int> arr = {1, 2};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 3) == 9);
    }

    SECTION("Example 2: arr = [1,-2,1], k = 5")
    {
        std::vector<int> arr = {1, -2, 1};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 5) == 2);
    }

    SECTION("Example 3: arr = [-1,-2], k = 7")
    {
        std::vector<int> arr = {-1, -2};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 7) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum k = 1: single copy")
    {
        std::vector<int> arr = {-5, 4, -1, 7, -8};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 1) == 10);
    }

    SECTION("Minimum k = 1: must not wrap around boundary")
    {
        std::vector<int> arr = {5, -10, 5};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 1) == 5);
    }

    SECTION("Negative total sum where optimal subarray stays inside a single copy")
    {
        std::vector<int> arr = {-10, 8, -10};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 5) == 8);
    }

    SECTION("Positive total sum with negative endpoints: suffix + (k - 2) * total + prefix")
    {
        std::vector<int> arr = {-2, 4, -1, 3, -2};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 4) == 12);
    }

    SECTION("Single element at maximum value and maximum k (just under modulo)")
    {
        std::vector<int> arr = {10000};
        REQUIRE(Solution::kConcatenationMaxSum(arr, 100000) == 1000000000);
    }

    SECTION("Large sum across many repetitions")
    {
        std::vector<int> arr(100, 10000);
        REQUIRE(Solution::kConcatenationMaxSum(arr, 100000) == 999999307);
    }
}
