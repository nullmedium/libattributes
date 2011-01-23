#include "attribute.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE attribute_test

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( test_suite )

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE( test1 )
{
    int x = 0;
    attribute<int> a(x);

    BOOST_CHECK( a.get_value() == 0 );

    a.set_value("1");

    BOOST_CHECK( a.get_value() == 1 );

    a.set_value("0");

    BOOST_CHECK( a.get_value() == 0 );
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()
