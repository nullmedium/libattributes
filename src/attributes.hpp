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

#include "string2type.hpp"

#include <map>
#include <string>

#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

//!
//! \class abstract_attribute
//! \brief Abstract base class for attributes.
//!
//! The class can't be instantiated.
//!
class abstract_attribute {
public:

    //!
    //! \brief Constructor.
    //!
    abstract_attribute() {}

    //!
    //! \brief Destructor.
    //!
    virtual ~abstract_attribute() {}

    //!
    //! \brief Pure virtual method. 
    //! 
    //! This method needs to be implemented in classes derived from
    //! \e abstract_attribute.
    //!
    //!
    virtual void set_value(const std::string &value) = 0;
};

//!
//! \class attribute
//! \brief attribute class.
//!
//! Wraps a reference to an object of type T.
//!
//! \tparam T Assignable type.
//!
template<typename T>
class attribute : public abstract_attribute {
public:
    //!
    //! \brief Constructor
    //!
    //! Constructs an attribute object for \e object. \e object needs to
    //! be an Assignable type.
    //!
    //! \param object Reference to object of type T.
    //!
    explicit attribute(T &object)
        : abstract_attribute()
        , reference(object) {
            BOOST_CONCEPT_ASSERT((boost::Assignable<T>));
    }

    //!
    //! \brief Destructor
    //!
    virtual ~attribute() {
    }

    //!
    //! \brief Implementation of set_value method.
    //!
    //! This method assigns \e value to \e this.
    //!
    //! \param value String
    //!
    virtual void set_value(const std::string &value) {
        reference = string2type::convert<T>(value);
    }

    //!
    //! \brief Implementation of get_value method.
    //!
    virtual T& get_value() const {
        return reference;
    }

private:
    T &reference; //!< Reference to T object.
};

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

