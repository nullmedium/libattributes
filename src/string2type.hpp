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

#include <boost/lexical_cast.hpp>

namespace string2type {

template<typename T>
T convert(const std::string &value) {
    return boost::lexical_cast<T>(value);
}

}

#endif /* STRING2TYPE_HPP */
