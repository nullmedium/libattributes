//! \file attributes.hpp
//! \brief C++ Library (header-only).

//  attributes.hpp  ----------------------------------------------------------//

// 
// Copyright Jens Luedicke 2010
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//----------------------------------------------------------------------------// 

#ifndef SETTABLE_HPP
#define SETTABLE_HPP

#include "attribute.hpp"

#include <map>
#include <string>

#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

//!
//! \brief Convenience macro for attribute registration.
//!
#define REGISTER_ATTRIBUTE(Type, Attribute) \
    this->register_attribute<Type>(#Attribute, this->Attribute);

//!
//! \class attributes
//! \brief Provides attribute registration facility.
//!
class attributes {
public:
    //!
    //! Sets named attribute \e attr to value \e value.
    //!
    //! Calling this method with an registered attribute \e attr has no effect.
    //!
    void set_attribute(const std::string &attr, const std::string &value) {
        attributes_map::iterator it = attributes.find(attr);

        if (it != attributes.end()) {
            it->second->set_value(value);
        }
    }

    //!
    //! Registers attribute \e object with name \e name.
    //!
    template<typename T>
    void register_attribute(const std::string &name, T &object) {
        typedef attribute<T> specific_attribute;

        attribute_ptr attribute(new specific_attribute(object));

        attributes.insert(std::make_pair(name, attribute));
    }

private:
    typedef boost::shared_ptr<abstract_attribute> attribute_ptr;
    typedef std::map<std::string, attribute_ptr> attributes_map;

    attributes_map attributes; //!< internal attributes map.
};

#endif /* SETTABLE_HPP */

