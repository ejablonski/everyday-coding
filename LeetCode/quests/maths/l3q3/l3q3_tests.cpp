#include "l3q3.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Number of Ways to Rearrange Sticks With K Sticks Visible", "[LeetCode][quest][maths][l3q3]")
{
    Solution solution;

    SECTION("Example 1: n = 3, k = 2")
    {
        REQUIRE(solution.rearrangeSticks(3, 2) == 3);
    }
    
    SECTION("Example 2: n = 5, k = 5")
    {
        REQUIRE(solution.rearrangeSticks(5, 5) == 1);
    }
    
    SECTION("Example 3: n = 20, k = 11")
    {
        REQUIRE(solution.rearrangeSticks(20, 11) == 647427950);
    }
    
    SECTION("All sticks visible: n = 10, k = 10")
    {
        REQUIRE(solution.rearrangeSticks(10, 10) == 1);
    }
    
    SECTION("Minimum constraints: n = 1, k = 1")
    {
        REQUIRE(solution.rearrangeSticks(1, 1) == 1);
    }
}
