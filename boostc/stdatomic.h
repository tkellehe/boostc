//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CTYPE_H
#define BOOSTC__CTYPE_H


#include <boostc/config.h>


/** Detect if compile times constant values indicate particular lock-free properties. */
/// \{
#define bstc_atomic_is_lockfree_never 0
#define bstc_atomic_is_lockfree_sometimes 1
#define bstc_atomic_is_lockfree_always 2
/// \}


#if (defined(BSTC_LEAST_C11) || defined(BSTC_LEAST_CPP11)) && !defined(__STDC_NO_ATOMICS__)

# ifdef __cplusplus
#  include <cstdint>
# else
#  include <stdint.h>
# endif

/* Add namespaced version. */
/// \{
# ifndef bstc_memory_order
#  define bstc_memory_order memory_order
# endif

# ifndef bstc_atomic_flag
#  define bstc_atomic_flag atomic_flag
# endif
/// \}

#else // Else must provide own implementation.


#endif




#endif // BOOSTC__CTYPE_H
