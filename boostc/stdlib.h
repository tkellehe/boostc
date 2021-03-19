//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__STDLIB_H
#define BOOSTC__STDLIB_H


#include <boostc/config.h>


#ifdef __cplusplus
# include <cstdlib>
#else
# include <stdlib.h>
#endif


/* Add namespaced version. */
/// \{
#if defined(BSTC_LEAST_C11) || defined(BSTC_LEAST_CPP11)
# ifndef bstc_aligned_alloc
#  define bstc_aligned_alloc aligned_alloc
# endif

# ifndef bstc_quick_exit
#  define bstc_quick_exit quick_exit
# endif

# ifndef bstc_at_quick_exit
#  define bstc_at_quick_exit at_quick_exit
# endif

# ifndef bstc_getenv_s
#  define bstc_getenv_s getenv_s
# endif

# ifndef bstc_wctomb_s
#  define bstc_wctomb_s wctomb_s
# endif

# ifndef bstc_mbstcowcs_s
#  define bstc_mbstcowcs_s mbstcowcs_s
# endif

# ifndef bstc_wcstombs_s
#  define bstc_wcstombs_s wcstombs_s
# endif

#ifndef bstc_qsort_s
# define bstc_qsort_s qsort_s
#endif

#ifndef bstc_bsearch_s
# define bstc_bsearch_s bsearch_s
#endif
#endif

#if defined(BSTC_LEAST_C99) || defined(BSTC_LEAST_CPP11)
# ifndef bstc_Exit
#  define bstc_Exit _Exit
# endif

# ifndef bstc_atoll
#  define bstc_atoll atoll
# endif

# ifndef bstc_strtoll
#  define bstc_strtoll strtoll
# endif

# ifndef bstc_strtoull
#  define bstc_strtoull strtoull
# endif

# ifndef bstc_strtof
#  define bstc_strtof strtof
# endif

# ifndef bstc_strtold
#  define bstc_strtold strtold
# endif
#endif

#ifndef bstc_malloc 
# define bstc_malloc malloc
#endif

#ifndef bstc_calloc 
# define bstc_calloc calloc
#endif

#ifndef bstc_realloc 
# define bstc_realloc realloc
#endif

#ifndef bstc_free 
# define bstc_free free
#endif

#ifndef bstc_abort 
# define bstc_abort abort
#endif

#ifndef bstc_exit 
# define bstc_exit exit
#endif

#ifndef bstc_atexit 
# define bstc_atexit atexit
#endif

#ifndef bstc_exit_success 
# define bstc_exit_success EXIT_SUCCESS
#endif

#ifndef bstc_exit_failure 
# define bstc_exit_failure EXIT_FAILURE
#endif

#ifndef bstc_system 
# define bstc_system system
#endif

#ifndef bstc_getenv 
# define bstc_getenv getenv
#endif

#ifndef bstc_atof 
# define bstc_atof atof
#endif

#ifndef bstc_atoi 
# define bstc_atoi atoi
#endif

#ifndef bstc_atol 
# define bstc_atol atol
#endif

#ifndef bstc_strtol 
# define bstc_strtol strtol
#endif

#ifndef bstc_strtoul 
# define bstc_strtoul strtoul
#endif

#ifndef bstc_strtod 
# define bstc_strtod strtod
#endif

#ifndef bstc_mblen 
# define bstc_mblen mblen
#endif

#ifndef bstc_mbtowc 
# define bstc_mbtowc mbtowc
#endif

#ifndef bstc_wctomb 
# define bstc_wctomb wctomb
#endif

#ifndef bstc_mbstcowcs 
# define bstc_mbstcowcs mbstcowcs
#endif

#ifndef bstc_wcstombs 
# define bstc_wcstombs wcstombs
#endif

#ifndef bstc_mb_len_max 
# define bstc_mb_len_max MB_LEN_MAX
#endif

#ifndef bstc_wchar_t 
# define bstc_wchar_t wchar_t
#endif

#ifndef bstc_rand
# define bstc_rand rand
#endif

#ifndef bstc_srand
# define bstc_srand srand
#endif

#ifndef bstc_rand_max
# define bstc_rand_max RAND_MAX
#endif

#ifndef bstc_qsort
# define bstc_qsort qsort
#endif

#ifndef bstc_bsearch
# define bstc_bsearch bsearch
#endif
/// \}


#endif // BOOSTC__STDLIB_H
