#include "l1q1.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Can Make Arithmetic Progression From Sequence", "[LeetCode][quest][maths][q1]")
{
    Solution solution;

    SECTION("Example 1: arr = [3, 5, 1]")
    {
        std::vector<int> arr{3, 5, 1};
        REQUIRE(solution.canMakeArithmeticProgression(arr));
    }

    SECTION("Example 2: arr = [1, 2, 4]")
    {
        std::vector<int> arr{1, 2, 4};
        REQUIRE_FALSE(solution.canMakeArithmeticProgression(arr));
    }

    SECTION("Length 2 array is always an arithmetic progression")
    {
        std::vector<int> arr{1, 2};
        REQUIRE(solution.canMakeArithmeticProgression(arr));
    }

    SECTION("Array with constant elements")
    {
        std::vector<int> arr{5, 5, 5, 5};
        REQUIRE(solution.canMakeArithmeticProgression(arr));
    }

    SECTION("Array with negative numbers that forms an AP")
    {
        std::vector<int> arr{1, -1, 3, -3, -5};
        REQUIRE(solution.canMakeArithmeticProgression(arr));
    }

    SECTION("Array with negative numbers that does not form an AP")
    {
        std::vector<int> arr{-2, -4, -7, -10};
        REQUIRE_FALSE(solution.canMakeArithmeticProgression(arr));
    }
}
