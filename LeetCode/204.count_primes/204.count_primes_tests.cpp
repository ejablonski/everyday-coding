#include "204.count_primes.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LeetCode 204 - Count Primes", "[LeetCode][204][array][math][number-theory]")
{
    Solution solution;

    SECTION("Example 1: n = 10") { REQUIRE(solution.countPrimes(10) == 4); }

    SECTION("Example 2: n = 0") { REQUIRE(solution.countPrimes(0) == 0); }

    SECTION("Example 3: n = 1") { REQUIRE(solution.countPrimes(1) == 0); }

    SECTION("Boundary: n = 2") { REQUIRE(solution.countPrimes(2) == 0); }

    SECTION("Boundary: n = 3") { REQUIRE(solution.countPrimes(3) == 1); }

    SECTION("Boundary: n = 5") { REQUIRE(solution.countPrimes(5) == 2); }

    SECTION("Boundary: n = 3772497") { REQUIRE(solution.countPrimes(3772497) == 268166); }
}
