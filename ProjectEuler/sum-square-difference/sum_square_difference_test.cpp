#include "sum_square_difference.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(170, difference_of_squares::difference(5));
}

BOOST_AUTO_TEST_CASE(test_2)
{
    BOOST_REQUIRE_EQUAL(2640, difference_of_squares::difference(10));
}

BOOST_AUTO_TEST_CASE(test_3)
{
    BOOST_REQUIRE_EQUAL(25164150, difference_of_squares::difference(100));
}
