#include "largest_prime_factor.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(largest_prime_of_10)
{
    BOOST_REQUIRE_EQUAL(5, primes::largest_prime(10));
}

BOOST_AUTO_TEST_CASE(largest_prime_of_17)
{
    BOOST_REQUIRE_EQUAL(17, primes::largest_prime(17));
}

BOOST_AUTO_TEST_CASE(primes_to_10)
{
    std::vector<unsigned long long> expected{ 2, 3, 5, 7 };
    std::vector<unsigned long long> result = primes::eratosthenes_sieve(10);
    BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(), expected.end(), result.begin(), result.end());
}

BOOST_AUTO_TEST_CASE(primes_to_100)
{
    std::vector<unsigned long long> expected{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    std::vector<unsigned long long> result = primes::eratosthenes_sieve(100);
    BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(), expected.end(), result.begin(), result.end());
}

BOOST_AUTO_TEST_CASE(largest_prime_factor_of_56)
{
    BOOST_REQUIRE_EQUAL(7, primes::largest_prime_factor(56));
}

BOOST_AUTO_TEST_CASE(largest_prime_factor_of_13195)
{
    BOOST_REQUIRE_EQUAL(29, primes::largest_prime_factor(13195));
}

BOOST_AUTO_TEST_CASE(largest_prime_factor_of_600851475143)
{
    BOOST_REQUIRE_EQUAL(6857, primes::largest_prime_factor(600851475143));
}