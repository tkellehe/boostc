//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__VISUALC_H
#define BOOSTC__CONFIG__COMPILER__VISUALC_H


/* Provide a way to detect the version of VISUALC. */
/// \{
#if _MSC_FULL_VER > 100000000
# define BSTC_VISUALC_VER _MSC_FULL_VER
#else
# define BSTC_VISUALC_VER (_MSC_FULL_VER * 10)
#endif
/// \}


/* Add branch predictors. */
/// \{
#define BSTC_LIKELY(x) __builtin_expect(x, 1)
#define BSTC_UNLIKELY(x) __builtin_expect(x, 0)
/// \}


/* Pulled from Boost <boost/config/compiler/visualc.hpp>. */
/// \{
#if defined(_MSC_EXTENSIONS) || (_MSC_VER >= 1400)
# define BOOST_HAS_LONG_LONG
#else
# define BOOST_NO_LONG_LONG
#endif
/// \}


/* Indicate visualc allows pasting symbols to strings. */
/// \{
#define BSTC_HAS_STRING_PASTE
/// \}


/* Make sure that the main libraries are linked in. */
/// \{
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
/// \}


#endif // BOOSTC__CONFIG__COMPILER__VISUALC_H
