#include "compare_the_triplets.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(tc1)
{
    std::vector<int> expected{1, 1};
    std::vector<int> result = triplets::compute({5, 6, 7}, {3, 6, 10});
    BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(), expected.end(), result.begin(), result.end());
}
