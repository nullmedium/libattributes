//! \file attribute.hpp
//! \brief C++ Library (header-only).

//  attribute.hpp  ----------------------------------------------------------//

// 
// Copyright Jens Luedicke 2010
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//----------------------------------------------------------------------------// 

#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include "abstract_attribute.hpp"
#include "string2type.hpp"

#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

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

#endif /* ATTRIBUTE_HPP */
