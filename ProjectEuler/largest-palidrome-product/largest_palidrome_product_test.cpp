#include "largest_palidrome_product.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(101101, palidrome::largestPalidromeProduct(101110));
}

BOOST_AUTO_TEST_CASE(test_2)
{
    BOOST_REQUIRE_EQUAL(793397, palidrome::largestPalidromeProduct(800000));
}

BOOST_AUTO_TEST_CASE(test_3)
{
    BOOST_REQUIRE_EQUAL(906609, palidrome::largestPalidromeProduct(999999));
}
