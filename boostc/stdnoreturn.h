//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__STDNORETURN_H
#define BOOSTC__STDNORETURN_H


#include <boostc/config.h>


#if defined(BSTC_LEAST_C11)
# include <stdnoreturn.h>
#endif

#if defined(BSTC_LEAST_CPP11)
# ifndef bstc_noreturn
#  if !defined(noreturn)
#   define bstc_noreturn [[noreturn]]
#  endif
# endif
#elif defined(BSTC_LEAST_C11)
# ifndef bstc_noreturn
#  define bstc_noreturn _Noreturn
# endif
#endif


/* Add namespaced version. */
/// \{
#ifndef bstc_noreturn
# if defined(BSTC_COMPILER_GCC) || defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_CLANG)
#  define bstc_noreturn __attribute__((__noreturn__))
# elif defined(BSTC_COMPILER_VISUALC)
#  define bstc_noreturn __declspec(noreturn)
# else
#  define bstc_noreturn
# endif
#endif
/// \}


#endif // BOOSTC__STDNORETURN_H
