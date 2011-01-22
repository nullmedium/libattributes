#include "attributes.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE attributes_test

#include <boost/test/unit_test.hpp>

#include <iostream>

struct test : attributes {
    test() : x(0) {
        REGISTER_ATTRIBUTE(int, x);
    }

    int x;
};

struct test_fixture {
    test_fixture() : object() {
        BOOST_TEST_MESSAGE( "setup fixture" );
    }

    ~test_fixture() {
        BOOST_TEST_MESSAGE( "teardown fixture" );
    }
    
    test object;
};

BOOST_FIXTURE_TEST_SUITE( test_suite, test_fixture )

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE( test2 )
{
    BOOST_CHECK( object.x == 0 );

    object.set_attribute("x", "42");

    BOOST_CHECK( object.x == 42 );

    object.set_attribute("x", "0");

    BOOST_CHECK( object.x == 0 );
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()
