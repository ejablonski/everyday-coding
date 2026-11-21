#include "1545.find_kth_bit_in_nth_binary_string.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace LC1545;

TEST_CASE("LeetCode 1545 - Find Kth Bit in Nth Binary String",
          "[LeetCode][1545][string][recursion][simulation]")
{
    // --- Official Markdown Examples ---
    SECTION("Example 1: n = 3, k = 1")
    {
        REQUIRE(Solution::findKthBit(3, 1) == '0');
    }

    SECTION("Example 2: n = 4, k = 11")
    {
        REQUIRE(Solution::findKthBit(4, 11) == '1');
    }

    // --- Lean Edge Cases & Tricky Scenarios (Constraint-Aware) ---
    SECTION("Minimum constraints: n = 1, k = 1")
    {
        REQUIRE(Solution::findKthBit(1, 1) == '0');
    }

    SECTION("Middle index: n = 5, k = 16")
    {
        REQUIRE(Solution::findKthBit(5, 16) == '1');
    }

    SECTION("Last bit in S_4: n = 4, k = 15")
    {
        REQUIRE(Solution::findKthBit(4, 15) == '1');
    }

    SECTION("Right-half index: n = 4, k = 12")
    {
        REQUIRE(Solution::findKthBit(4, 12) == '0');
    }

    SECTION("Maximum n = 20 at exact middle and last positions")
    {
        REQUIRE(Solution::findKthBit(20, 524288) == '1');
        REQUIRE(Solution::findKthBit(20, 1048575) == '1');
    }

    SECTION("Maximum n = 20 with deep right-half recursion: k = 1000000 and k = 786432")
    {
        REQUIRE(Solution::findKthBit(20, 1000000) == '1');
        REQUIRE(Solution::findKthBit(20, 786432) == '0');
    }
}
