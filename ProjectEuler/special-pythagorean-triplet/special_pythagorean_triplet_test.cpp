#include "special_pythagorean_triplet.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(31875000, abc_product(1000));
}
