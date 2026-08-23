#include "l1q3.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Palindrome Number", "[LeetCode][quest][maths][q3]")
{
    Solution solution;

    SECTION("Example 1: x = 121") { REQUIRE(solution.isPalindrome(121)); }
    SECTION("Example 2: x = -121") { REQUIRE_FALSE(solution.isPalindrome(-121)); }
    SECTION("Example 3: x = 10") { REQUIRE_FALSE(solution.isPalindrome(10)); }
    SECTION("Single digit is a palindrome: x = 0") { REQUIRE(solution.isPalindrome(0)); }
    SECTION("Even length palindrome: x = 1221") { REQUIRE(solution.isPalindrome(1221)); }
    SECTION("Non-palindrome: x = 123456") { REQUIRE_FALSE(solution.isPalindrome(123456)); }
}
