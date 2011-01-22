#include "attributes.hpp"

#include <iostream>

struct foo : attributes {
    foo() {
        REGISTER_ATTRIBUTE(int, x);
    }

    int x;
};

int main(int argc, char *argv) {
    foo f;
    f.set_attribute("x", "42");

    std::cout << f.x << std::endl;

    return 0;
}
