#include "solve_me_first.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_1)
{
    BOOST_REQUIRE_EQUAL(5, solveMeFirst(2, 3));
}
