//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__STDBOOL_H
#define BST__STDBOOL_H


#include <bst/config.h>


// https://stackoverflow.com/a/30875579/5407843
// The `stdbool.h` was added in C99 before C++11 which is when it was added to C++.
#ifdef BST_LEAST_CPP11
# include <cstdbool>
#elif BST_LEAST_C99
# include <stdbool.h>
#endif


/* Make sure that the symbols are provided */
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
# else
// This most likely will need to be resolved in the config area.
#  error "System does not support bool."
# endif
#endif
/// \}


/* Add namespaced version */
/// \{
#define bst_Bool _Bool
#define bst_bool bool
#define bst_true true
#define bst_false false
/// \}


#endif // BST__STDBOOL_H
