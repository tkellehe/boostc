//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__STDBOOL_H
#define BOOSTC__STDBOOL_H


#include <boostc/config.h>


// https://stackoverflow.com/a/30875579/5407843
// The `stdbool.h` was added in C99 before C++11 which is when it was added to C++.
#ifdef BSTC_LEAST_CPP11
# include <cstdbool>
#elif defined(BSTC_LEAST_C99)
# include <stdbool.h>
#endif


/* Make sure that the symbols are provided. */
/// \{
#ifdef __cplusplus
# if !(defined(__bool_true_false_are_defined) && __bool_true_false_are_defined == 1)
#  define _Bool bool
#  define bool bool
#  define false false
#  define true true
#  ifdef __bool_true_false_are_defined
#   undef __bool_true_false_are_defined
#  endif
#  define __bool_true_false_are_defined 1
# endif
#else
# ifdef _Bool
#  if !(defined(__bool_true_false_are_defined) && __bool_true_false_are_defined == 1)
#   define bool _Bool
#   define false 0
#   define true 1
#   ifdef __bool_true_false_are_defined
#    undef __bool_true_false_are_defined
#   endif
#   define __bool_true_false_are_defined 1
#  endif
# elif !(defined(__bool_true_false_are_defined) && __bool_true_false_are_defined == 1)
// This most likely will need to be resolved in the config area.
#  ifdef BSTC_COMPILER_VISUALC
#   define bool char
#   define false 0
#   define true 1
#   define __bool_true_false_are_defined 1
#  else
#   error "BOOSTC system does not support bool."
#  endif
# endif
#endif
/// \}


/* Add namespaced version. */
/// \{
#ifndef bstc_Bool
# define bstc_Bool _Bool
#endif

#ifndef bstc_bool
# define bstc_bool bool
#endif

#ifndef bstc_true
# define bstc_true true
#endif

#ifndef bstc_false
# define bstc_false false
#endif
/// \}


#endif // BOOSTC__STDBOOL_H
