//! \file settable.hpp
//! \brief C++ Library (header-only).

//  settable.hpp  ------------------------------------------------------------//

// 
// Copyright Jens Luedicke 2010
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//----------------------------------------------------------------------------// 

#ifndef SETTABLE_HPP
#define SETTABLE_HPP

#include <map>
#include <string>

#include <boost/assert.hpp>
#include <boost/shared_ptr.hpp>

namespace string2type {

template<typename T>
T convert(const std::string &value);

}

namespace settable {

class abstract_setter {
public:
    virtual void set_value(const std::string &value) = 0;
};

template<typename T>
class setter: public abstract_setter {
public:
    setter(void *p)
        : ptr(p) {
        BOOST_ASSERT(ptr != 0);
    }

    virtual void set_value(const std::string &value) {
        T *ptrT = static_cast<T*>(ptr);
        BOOST_ASSERT(ptrT != 0);

        *ptrT = string2type::convert<T>(value);
    }

    void *ptr;
};

#define REGISTER_MEMBER(Type, Attribute) \
    this->register_setter<Type>(#Attribute, &Attribute);

class settable {
public:
    void set_attribute(const std::string &attr, const std::string &value) {
        setters_map::iterator it = setters.find(attr);

        if (it != setters.end()) {
            it->second->set_value(value);
        }
    }

    template<typename T>
    void register_setter(const std::string &name, T *ptr) {
        typedef setter<T> specific_setter;

        setter_ptr setter(new specific_setter(ptr));

        setters.insert(std::make_pair(name, setter));
    }

private:
    typedef boost::shared_ptr<abstract_setter> setter_ptr;
    typedef std::map<std::string, setter_ptr> setters_map;

    setters_map setters;
};

}

#endif /* SETTABLE_HPP */

