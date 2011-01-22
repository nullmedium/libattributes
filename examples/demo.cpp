#include "attributes.hpp"

#include <iostream>

enum Value {
    One = 1,
    Two,
    Three
};

namespace string2type {

template <>
Value convert<Value>(const std::string &value) {
    std::cout << "special convert function... " << std::endl;

    if (value == "One") {
        return One;
    } else if (value == "Two") {
        return Two;
    } else if (value == "Three") {
        return Three;
    }
}
    
}

struct foo : attributes {
    foo() {
        REGISTER_ATTRIBUTE(int, x);
        REGISTER_ATTRIBUTE(Value, y);
    }

    int x;
    Value y;
};
    
int main(int argc, char *argv) {
    foo f;
    f.set_attribute("x", "42");
    f.set_attribute("y", "One");

    std::cout << f.x << std::endl;
    std::cout << f.y << std::endl;

    return 0;
}
