#include "60.permutation_sequence.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("LeetCode 60 - Permutation Sequence", "[LeetCode][60][math][recursion]")
{
    Solution solution;

    SECTION("Example 1: n = 3, k = 3") { REQUIRE(solution.getPermutation(3, 3) == "213"); }

    SECTION("Example 2: n = 4, k = 9") { REQUIRE(solution.getPermutation(4, 9) == "2314"); }

    SECTION("Example 3: n = 3, k = 1") { REQUIRE(solution.getPermutation(3, 1) == "123"); }

    SECTION("Minimum constraints: n = 1, k = 1") { REQUIRE(solution.getPermutation(1, 1) == "1"); }

    SECTION("Maximum n, first permutation: n = 9, k = 1")
    {
        REQUIRE(solution.getPermutation(9, 1) == "123456789");
    }

    SECTION("Maximum constraints: n = 9, k = 362880 (9!)")
    {
        REQUIRE(solution.getPermutation(9, 362880) == "987654321");
    }
}
