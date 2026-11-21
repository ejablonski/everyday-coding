#include "952.largest_component_size_by_common_factor.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC952;

TEST_CASE("LeetCode 952 - Largest Component Size by Common Factor",
          "[LeetCode][952][array][hash-table][math][union-find][number-theory]"
          "[prime-factorization]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: nums = [4,6,15,35]")
    {
        std::vector<int> nums = {4, 6, 15, 35};
        REQUIRE(Solution::largestComponentSize(nums) == 4);
    }

    SECTION("Example 2: nums = [20,50,9,63]")
    {
        std::vector<int> nums = {20, 50, 9, 63};
        REQUIRE(Solution::largestComponentSize(nums) == 2);
    }

    SECTION("Example 3: nums = [2,3,6,7,4,12,21,39]")
    {
        std::vector<int> nums = {2, 3, 6, 7, 4, 12, 21, 39};
        REQUIRE(Solution::largestComponentSize(nums) == 8);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint single element 1: nums = [1]")
    {
        std::vector<int> nums = {1};
        REQUIRE(Solution::largestComponentSize(nums) == 1);
    }

    SECTION("Value 1 stays isolated from even component: nums = [1,2,4,8]")
    {
        std::vector<int> nums = {1, 2, 4, 8};
        REQUIRE(Solution::largestComponentSize(nums) == 3);
    }

    SECTION("Pairwise coprime primes form only singleton components")
    {
        std::vector<int> nums = {2, 3, 5, 7, 11, 13};
        REQUIRE(Solution::largestComponentSize(nums) == 1);
    }

    SECTION("Bridge composite connects two disjoint prime-power chains")
    {
        std::vector<int> nums = {2, 4, 8, 3, 9, 27, 6};
        REQUIRE(Solution::largestComponentSize(nums) == 7);
    }

    SECTION("Multiple disjoint components of unequal sizes")
    {
        std::vector<int> nums = {10, 15, 25, 7, 49, 77, 121, 13};
        REQUIRE(Solution::largestComponentSize(nums) == 4);
    }

    SECTION("Upper value boundary up to 10^5 with isolated large prime")
    {
        std::vector<int> nums = {99991, 100000, 50000, 99995, 99998};
        REQUIRE(Solution::largestComponentSize(nums) == 4);
    }
}
