#include "3115.maximum_prime_difference.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC3115;

TEST_CASE("LeetCode 3115 - Maximum Prime Difference",
          "[LeetCode][3115][array][math][number-theory][primality-test]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [4, 2, 9, 5, 3]")
    {
        std::vector<int> nums = {4, 2, 9, 5, 3};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 3);
    }

    SECTION("Example 2: nums = [4, 8, 2, 8]")
    {
        std::vector<int> nums = {4, 8, 2, 8};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 0);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum length single prime element")
    {
        std::vector<int> nums = {2};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 0);
    }

    SECTION("Value 1 is not prime")
    {
        std::vector<int> nums = {1, 4, 7, 1, 1};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 0);
    }

    SECTION("Tricky odd composites surrounding primes")
    {
        // Only indices 4 (11) and 8 (13) are prime; 9, 25, 49, 51, 57, 77, 87, 91, 99 are composite
        std::vector<int> nums = {1, 9, 49, 91, 11, 51, 57, 87, 13, 25, 77, 99, 100};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 4);
    }

    SECTION("Repeated identical prime at different indices")
    {
        std::vector<int> nums = {100, 97, 4, 97, 1};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 2);
    }

    SECTION("All 25 primes within constraint range [1, 100]")
    {
        std::vector<int> nums = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                                 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        REQUIRE(Solution::maximumPrimeDifference(nums) == 24);
    }

    SECTION("Maximum length constraint with primes near both ends")
    {
        std::vector<int> nums(300000, 4);
        nums[5] = 2;
        nums[299994] = 97;
        REQUIRE(Solution::maximumPrimeDifference(nums) == 299989);
    }
}
