#include "smallest_multiple.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(232792560, smallest_multiple());
}
