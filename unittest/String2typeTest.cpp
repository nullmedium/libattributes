#include "string2type.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE attributes_test

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(string2type_test)

BOOST_AUTO_TEST_CASE( test1 )
{
    int x = string2type::convert<int>("42");

    BOOST_CHECK( x == 42 );
}

BOOST_AUTO_TEST_CASE( test2 )
{
    double x = string2type::convert<double>("3.14");

    BOOST_CHECK( x >= 3.14 );
}

BOOST_AUTO_TEST_SUITE_END()
