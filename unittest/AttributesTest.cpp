#include "attributes.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE attributes_test

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <stdexcept>

enum Value {
    One = 1,
    Two,
    Three
};

namespace string2type {

template <>
Value convert<Value>(const std::string &value) {
    if (value == "One") {
        return One;
    } else if (value == "Two") {
        return Two;
    } else if (value == "Three") {
        return Three;
    } else {
        throw std::invalid_argument("unknown string");
    }
}
    
}

struct test : attributes {
    test() : x(0), y(One) {
        REGISTER_ATTRIBUTE(int, x);
        REGISTER_ATTRIBUTE(Value, y);
    }

    int x;
    Value y;
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

BOOST_AUTO_TEST_CASE( test3 )
{
    BOOST_CHECK( object.y == One );

    object.set_attribute("y", "Two");

    BOOST_CHECK( object.y == Two );

    BOOST_CHECK_THROW(object.set_attribute("y", "xxx"), std::invalid_argument);
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()
