//! \file string2type.hpp
//! \brief C++ Library (header-only).

//  settable.hpp  ------------------------------------------------------------//

// 
// Copyright Jens Luedicke 2010
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//----------------------------------------------------------------------------// 

#ifndef STRING2TYPE_HPP
#define STRING2TYPE_HPP

#include <string>

#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>
#include <boost/lexical_cast.hpp>

//!
//! \namespace string2type
//! \brief String conversion functions.
//!
//! Default namespace for string to type conversion functions.
//!
namespace string2type {

//!
//! \brief string-to-type conversion function.
//!
//! Converts input string \e value into type T of template argument. Internally
//! the function calls boost::lexical_cast<T>. If you need a specialiized convert function
//! for your given type, you need to implement a specialized convert function.
//!
//! \tparam T return type of function.
//!
//! \param value Input string for function.
//!
//! \returns Converted value.
//!
//!
template<typename T>
T convert(const std::string &value) {
    BOOST_CONCEPT_ASSERT((boost::Assignable<T>));

    return boost::lexical_cast<T>(value);
}

}

#endif /* STRING2TYPE_HPP */
