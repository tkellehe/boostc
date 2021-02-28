//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>


#if defined(BSTC_LEAST_C11) || defined(BSTC_LEAST_CPP11)
# include <stdnoreturn.h>

# ifndef bstc_noreturn
#  ifdef __cplusplus
#   define bstc_noreturn [[noreturn]]
#  else
#   define bstc_noreturn _Noreturn
#  endif
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
