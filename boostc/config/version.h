//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__VERSION_H
#define BOOSTC__CONFIG__VERSION_H


/* Determine the C++ standard version provided by the compiler. */
/// \{
#if defined(__cplusplus)
# if __cplusplus >= 199711L
#  define BSTC_LEAST_CPP98
# endif
# if __cplusplus >= 201103L
#  define BSTC_LEAST_CPP11
# endif
# if __cplusplus >= 201402L
#  define BSTC_LEAST_CPP14
# endif
# if __cplusplus >= 201703L
#  define BSTC_LEAST_CPP17
# endif
# if __cplusplus >= 202002L
#  define BSTC_LEAST_CPP20
# endif
#endif
/// \}


/* Determine the C standard version provided by the compiler. */
/// \{
#if !defined(__cplusplus) && ((defined(__STDC__) && __STDC__ == 1) || defined(__STDC_VERSION__)) 
# define BSTC_LEAST_C89
#endif
#if !defined(__cplusplus) && defined(__STDC_VERSION__)
# if __STDC_VERSION__ >= 199409L
#  define BSTC_LEAST_C95
# endif
# if __STDC_VERSION__ >= 199901L
#  define BSTC_LEAST_C99
# endif
# if __STDC_VERSION__ >= 201112L
#  define BSTC_LEAST_C11
# endif
# if __STDC_VERSION__ >= 201710L
#  define BSTC_LEAST_C17
# endif
#endif
/// \}


#endif // BOOSTC__CONFIG__VERSION_H
