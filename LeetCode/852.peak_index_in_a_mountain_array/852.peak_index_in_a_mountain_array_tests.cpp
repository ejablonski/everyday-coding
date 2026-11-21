#include "852.peak_index_in_a_mountain_array.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace LC852;

TEST_CASE("LeetCode 852 - Peak Index in a Mountain Array",
          "[LeetCode][852][array][binary-search][ternary-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: arr = [0,1,0]")
    {
        std::vector<int> arr = {0, 1, 0};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 1);
    }

    SECTION("Example 2: arr = [0,2,1,0]")
    {
        std::vector<int> arr = {0, 2, 1, 0};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 1);
    }

    SECTION("Example 3: arr = [0,10,5,2]")
    {
        std::vector<int> arr = {0, 10, 5, 2};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 1);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Peak near right end (index n - 2)")
    {
        std::vector<int> arr = {1, 2, 3, 4, 5, 6, 0};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 5);
    }

    SECTION("Peak near left end (index 1) in longer array")
    {
        std::vector<int> arr = {0, 100, 90, 80, 70, 60, 50};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 1);
    }

    SECTION("Symmetric mountain with peak at exact middle")
    {
        std::vector<int> arr = {0, 10, 20, 30, 20, 10, 0};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 3);
    }

    SECTION("Boundary constraint values (0 and 10^6)")
    {
        std::vector<int> arr = {0, 500000, 1000000, 999999, 0};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 2);
    }

    SECTION("Even-length mountain array")
    {
        std::vector<int> arr = {2, 5, 9, 14, 11, 3};
        REQUIRE(Solution::peakIndexInMountainArray(arr) == 3);
    }
}
