//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
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


/* Create a simple assert that has a message in it. */
/// \{
#ifndef bstc_assert_msg
# define bstc_assert_msg(expr, msg) bstc_assert((expr)&&(msg))
#endif
/// \}
