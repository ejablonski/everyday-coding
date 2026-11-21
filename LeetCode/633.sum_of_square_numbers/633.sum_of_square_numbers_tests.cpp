#include "633.sum_of_square_numbers.hpp"

#include <catch2/catch_test_macros.hpp>
#include <limits>

using namespace LC633;

TEST_CASE("LeetCode 633 - Sum of Square Numbers", "[LeetCode][633][math][two-pointers][binary-search]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: c = 5")
    {
        REQUIRE(Solution::judgeSquareSum(5) == true);
    }

    SECTION("Example 2: c = 3")
    {
        REQUIRE(Solution::judgeSquareSum(3) == false);
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraint value: c = 0 (0^2 + 0^2)")
    {
        REQUIRE(Solution::judgeSquareSum(0) == true);
    }

    SECTION("Sum of two equal non-zero squares: c = 2 (1^2 + 1^2)")
    {
        REQUIRE(Solution::judgeSquareSum(2) == true);
    }

    SECTION("Perfect square with zero addend: c = 4 (0^2 + 2^2)")
    {
        REQUIRE(Solution::judgeSquareSum(4) == true);
    }

    SECTION("Small impossible value congruent to 3 mod 4: c = 7")
    {
        REQUIRE(Solution::judgeSquareSum(7) == false);
    }

    SECTION("Composite with 3-mod-4 prime factor to even power: c = 45 (3^2 + 6^2)")
    {
        REQUIRE(Solution::judgeSquareSum(45) == true);
    }

    SECTION("Large valid value near 2^31 - 1: c = 2147395601")
    {
        REQUIRE(Solution::judgeSquareSum(2147395601) == true);
    }

    SECTION("Maximum constraint value: c = 2^31 - 1 (Mersenne prime, 3 mod 4)")
    {
        REQUIRE(Solution::judgeSquareSum(std::numeric_limits<int>::max()) == false);
    }
}
