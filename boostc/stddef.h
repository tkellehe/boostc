//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__STDDEF_H
#define BOOSTC__STDDEF_H


#include <boostc/config.h>


#ifdef __cplusplus
# include <cstddef>
#else
# include <stddef.h>
#endif


/* Add namespaced version. */
/// \{
#if defined(BSTC_LEAST_C11) || defined(BSTC_LEAST_CPP11)
# ifndef bstc_max_align_t
#  define bstc_max_align_t max_align_t
# endif
#endif


#ifndef bstc_size_t
# define bstc_size_t size_t
#endif


#ifndef bstc_ptrdiff_t
# define bstc_ptrdiff_t ptrdiff_t
#endif


#ifndef bstc_offsetof
# ifdef offsetof
#  define bstc_offsetof offsetof
# endif
#endif
/// \}


#endif // BOOSTC__STDDEF_H
