//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__GCC_H
#define BOOSTC__CONFIG__COMPILER__GCC_H


/* Provide a way to detect the version of GCC. */
/// \{
#ifndef BSTC_GCC_VER
# define BSTC_GCC_VER (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif
/// \}


/* Add branch predictors. */
/// \{
#ifndef BSTC_LIKELY
# define BSTC_LIKELY(x) __builtin_expect(x, 1)
#endif
#ifndef BSTC_UNLIKELY
# define BSTC_UNLIKELY(x) __builtin_expect(x, 0)
#endif
/// \}


/* Pulled from Boost <boost/config/compiler/gcc.hpp>. */
/// \{
#if !defined(BSTC_HAS_LONG_LONG) && !defined(BSTC_NO_LONG_LONG)
# if !defined(__DARWIN_NO_LONG_LONG)
#  define BSTC_HAS_LONG_LONG
# endif
#endif
/// \}


/* Indicate that null concat with __VA_ARGS__ works. */
/// \{
#if !defined(BSTC_HAS_VA_ARGS_PASTE) && !defined(BSTC_NO_VA_ARGS_PASTE)
# define BSTC_HAS_VA_ARGS_PASTE
#endif
/// \}


#endif // BOOSTC__CONFIG__COMPILER__GCC_H
