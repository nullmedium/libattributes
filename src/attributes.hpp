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

#include "string2type.hpp"

#include <map>
#include <string>

#include <boost/shared_ptr.hpp>

class abstract_attribute {
public:
    virtual void set_value(const std::string &value) = 0;
};

template<typename T>
class attribute : public abstract_attribute {
public:
    explicit attribute(T &object)
        : reference(object) {
    }

    virtual void set_value(const std::string &value) {
        reference = string2type::convert<T>(value);
    }

    virtual T& get_value() const {
        return reference;
    }

private:
    T &reference;
};

#define REGISTER_ATTRIBUTE(Type, Attribute) \
    this->register_attribute<Type>(#Attribute, this->Attribute);

class attributes {
public:
    void set_attribute(const std::string &attr, const std::string &value) {
        attributes_map::iterator it = attributes.find(attr);

        if (it != attributes.end()) {
            it->second->set_value(value);
        }
    }

    template<typename T>
    void register_attribute(const std::string &name, T &object) {
        typedef attribute<T> specific_attribute;

        attribute_ptr attribute(new specific_attribute(object));

        attributes.insert(std::make_pair(name, attribute));
    }

private:
    typedef boost::shared_ptr<abstract_attribute> attribute_ptr;
    typedef std::map<std::string, attribute_ptr> attributes_map;

    attributes_map attributes;
};

#endif /* SETTABLE_HPP */

