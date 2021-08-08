#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "LargeNumber.h"

BOOST_AUTO_TEST_CASE(myTestCase0)
{
    ln::LargeNumber a("1235");
    ln::LargeNumber b("4289");

    BOOST_TEST("5524" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase1)
{
    ln::LargeNumber a("23478965");
    ln::LargeNumber b("892376498");

    BOOST_TEST("915855463" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase2)
{
    ln::LargeNumber a("915855463");
    ln::LargeNumber b("74474");

    BOOST_TEST("915929937" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase3)
{
    ln::LargeNumber a("999999");
    ln::LargeNumber b("111111");

    BOOST_TEST("1111110" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase4)
{
    ln::LargeNumber a("2238948924591383");
    ln::LargeNumber b("2238948924591383");

    BOOST_TEST("4477897849182766" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase5)
{
    ln::LargeNumber a("4477897849182766");
    ln::LargeNumber b("1");

    BOOST_TEST("4477897849182767" == ln::LargeNumber::add(a, b));
}

BOOST_AUTO_TEST_CASE(myTestCase6)
{
    ln::LargeNumber a("5");
    ln::LargeNumber b("10");

    BOOST_TEST("15" == ln::LargeNumber::add(a, b));
}
