//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__COMPILER__VISUALC_H
#define BST__CONFIG__COMPILER__VISUALC_H


/* Provide a way to detect the version of VISUALC */
/// \{
#if _MSC_FULL_VER > 100000000
# define BST_VISUALC_VER _MSC_FULL_VER
#else
# define BST_VISUALC_VER (_MSC_FULL_VER * 10)
#endif
/// \}


/* Add branch predictors */
/// \{
#define BST_LIKELY(x) __builtin_expect(x, 1)
#define BST_UNLIKELY(x) __builtin_expect(x, 0)
/// \}


/* Pulled from Boost <boost/config/compiler/visualc.hpp> */
/// \{
#if defined(_MSC_EXTENSIONS) || (_MSC_VER >= 1400)
# define BOOST_HAS_LONG_LONG
#else
# define BOOST_NO_LONG_LONG
#endif
/// \}


/* Indicate visualc allows pasting symbols to strings */
/// \{
#define BST_HAS_STRING_PASTE
/// \}


#endif // BST__CONFIG__COMPILER__VISUALC_H
