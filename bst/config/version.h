//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__VERSION_H
#define BST__CONFIG__VERSION_H


/* Determine the C++ standard version provided by the compiler */
/// \{
#if defined(__cplusplus)
# if __cplusplus >= 199711L
#  define BST_LEAST_CPP98
# else
#  error "Compiler does not support at least C++98 features."
# endif
# if __cplusplus >= 201103L
#  define BST_LEAST_CPP11
# endif
# if __cplusplus >= 201402L
#  define BST_LEAST_CPP14
# endif
# if __cplusplus >= 201703L
#  define BST_LEAST_CPP17
# endif
# if __cplusplus >= 202002L
#  define BST_LEAST_CPP20
# endif
#endif
/// \}


/* Determine the C standard version provided by the compiler */
/// \{
#if !defined(__cplusplus) && defined(__STDC_VERSION__)
# if __STDC_VERSION__ >= 199901L
#  define BST_LEAST_C99
# else
#  error "Compiler does not support at least C99 features."
# endif
# if __STDC_VERSION__ >= 201112L
#  define BST_LEAST_C11
# endif
# if __STDC_VERSION__ >= 201710L
#  define BST_LEAST_C18
# endif
#endif
/// \}


#endif // BST__CONFIG__VERSION_H
