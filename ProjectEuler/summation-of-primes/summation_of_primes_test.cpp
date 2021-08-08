#include "summation_of_primes.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(142913828922, sum_of_primes(2000000));
}
