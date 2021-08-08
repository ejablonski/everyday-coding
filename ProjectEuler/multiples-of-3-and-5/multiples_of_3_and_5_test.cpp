#include "multiples_of_3_and_5.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiples_to_10)
{
    BOOST_REQUIRE_EQUAL(23, task::sum_multiples(10));
}

BOOST_AUTO_TEST_CASE(multiples_to_100)
{
    BOOST_REQUIRE_EQUAL(2318, task::sum_multiples(100));
}

BOOST_AUTO_TEST_CASE(multiples_to_1000)
{
    BOOST_REQUIRE_EQUAL(233168, task::sum_multiples(1000));
}