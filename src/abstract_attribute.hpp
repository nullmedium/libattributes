//! \file abstract_attribute.hpp
//! \brief C++ Library (header-only).

//  abstract_attribute.hpp  ----------------------------------------------------------//

// 
// Copyright Jens Luedicke 2010
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//----------------------------------------------------------------------------// 

#ifndef ABSTRACT_ATTRIBUTE_HPP
#define ABSTRACT_ATTRIBUTE_HPP

#include <string>

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

#endif /* ABSTRACT_ATTRIBUTE_HPP */

