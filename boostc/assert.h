//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__ASSERT_H
#define BOOSTC__ASSERT_H


#include <boostc/config.h>


#if defined(NDEBUG) && !defined(bstc_ndebug)
# define bstc_ndebug
#endif


#if defined(bstc_ndebug) && !defined(NDEBUG)
# define NDEBUG
#endif


#ifdef __cplusplus
# include <cassert>
#else
# include <assert.h>
#endif


/* Add namespaced version. */
/// \{
#ifndef bstc_assert
# define bstc_assert assert
#endif
/// \}


/* Add namespaced static assert. */
/// \{
#ifndef bstc_static_assert
# if defined(BSTC_LEAST_CPP11)
#  define bstc_static_assert(expr, msg) static_assert((expr), msg)
# elif defined(BSTC_LEAST_C11)
#  define bstc_static_assert(expr, msg) _Static_assert((expr), msg)
# else
// Fallback for older standards; msg is unused but kept for API parity.
#  define bstc_static_assert(expr, msg) typedef char bstc_static_assert_failed[(expr) ? 1 : -1]
# endif
#endif
/// \}


/* Create a simple assert that has a message in it. */
/// \{
#ifndef bstc_assert_msg
# define bstc_assert_msg(expr, msg) bstc_assert((expr)&&(msg))
#endif
/// \}


#endif // BOOSTC__ASSERT_H
