//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <bst/config.h>


#ifdef __cplusplus
# include <cstdlib>
#else
# include <stdlib.h>
#endif


/* Add namespaced version. */
/// \{
#if defined(BST_LEAST_C11) || defined(BST_LEAST_CPP11)
# ifndef bst_aligned_alloc
#  define bst_aligned_alloc aligned_alloc
# endif

# ifndef bst_quick_exit
#  define bst_quick_exit quick_exit
# endif

# ifndef bst_at_quick_exit
#  define bst_at_quick_exit at_quick_exit
# endif

# ifndef bst_getenv_s
#  define bst_getenv_s getenv_s
# endif

# ifndef bst_wctomb_s
#  define bst_wctomb_s wctomb_s
# endif

# ifndef bst_mbstowcs_s
#  define bst_mbstowcs_s mbstowcs_s
# endif

# ifndef bst_wcstombs_s
#  define bst_wcstombs_s wcstombs_s
# endif

#ifndef bst_qsort_s
# define bst_qsort_s qsort_s
#endif

#ifndef bst_bsearch_s
# define bst_bsearch_s bsearch_s
#endif
#endif

#if defined(BST_LEAST_C99) || defined(BST_LEAST_CPP11)
# ifndef bst_Exit
#  define bst_Exit _Exit
# endif

# ifndef bst_atoll
#  define bst_atoll atoll
# endif

# ifndef bst_strtoll
#  define bst_strtoll strtoll
# endif

# ifndef bst_strtoull
#  define bst_strtoull strtoull
# endif

# ifndef bst_strtof
#  define bst_strtof strtof
# endif

# ifndef bst_strtold
#  define bst_strtold strtold
# endif
#endif

#ifndef bst_malloc 
# define bst_malloc malloc
#endif

#ifndef bst_calloc 
# define bst_calloc calloc
#endif

#ifndef bst_realloc 
# define bst_realloc realloc
#endif

#ifndef bst_free 
# define bst_free free
#endif

#ifndef bst_abort 
# define bst_abort abort
#endif

#ifndef bst_exit 
# define bst_exit exit
#endif

#ifndef bst_atexit 
# define bst_atexit atexit
#endif

#ifndef bst_exit_success 
# define bst_exit_success EXIT_SUCCESS
#endif

#ifndef bst_exit_failure 
# define bst_exit_failure EXIT_FAILURE
#endif

#ifndef bst_system 
# define bst_system system
#endif

#ifndef bst_getenv 
# define bst_getenv getenv
#endif

#ifndef bst_atof 
# define bst_atof atof
#endif

#ifndef bst_atoi 
# define bst_atoi atoi
#endif

#ifndef bst_atol 
# define bst_atol atol
#endif

#ifndef bst_strtol 
# define bst_strtol strtol
#endif

#ifndef bst_strtoul 
# define bst_strtoul strtoul
#endif

#ifndef bst_strtod 
# define bst_strtod strtod
#endif

#ifndef bst_mblen 
# define bst_mblen mblen
#endif

#ifndef bst_mbtowc 
# define bst_mbtowc mbtowc
#endif

#ifndef bst_wctomb 
# define bst_wctomb wctomb
#endif

#ifndef bst_mbstowcs 
# define bst_mbstowcs mbstowcs
#endif

#ifndef bst_wcstombs 
# define bst_wcstombs wcstombs
#endif

#ifndef bst_mb_len_max 
# define bst_mb_len_max MB_LEN_MAX
#endif

#ifndef bst_wchar_t 
# define bst_wchar_t wchar_t
#endif

#ifndef bst_rand
# define bst_rand rand
#endif

#ifndef bst_srand
# define bst_srand srand
#endif

#ifndef bst_rand_max
# define bst_rand_max RAND_MAX
#endif

#ifndef bst_qsort
# define bst_qsort qsort
#endif

#ifndef bst_bsearch
# define bst_bsearch bsearch
#endif
/// \}
