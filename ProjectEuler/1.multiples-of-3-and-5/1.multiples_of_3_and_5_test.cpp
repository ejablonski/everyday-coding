#include "1.multiples_of_3_and_5.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Project Euler 1 - Multiples of 3 and 5", "[euler][1]")
{
    SECTION("Multiples below 10") { REQUIRE(Solution::sum_multiples(10) == 23); }

    SECTION("Multiples below 100") { REQUIRE(Solution::sum_multiples(100) == 2318); }

    SECTION("Multiples below 1000") { REQUIRE(Solution::sum_multiples(1000) == 233168); }
}
