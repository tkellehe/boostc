#ifndef BST__CONFIG_H
#define BST__CONFIG_H


#include <bst/config/version.h>


#if !defined(BST_COMPILER_CONFIG) && !defined(BST_NO_COMPILER_CONFIG) && !defined(BST_NO_CONFIG)
# include <bst/config/select_compiler.h>
#endif
#ifdef BST_COMPILER_CONFIG
# include BST_COMPILER_CONFIG
#endif


#if !defined(BST_PLATFORM_CONFIG) && !defined(BST_NO_PLATFORM_CONFIG) && !defined(BST_NO_CONFIG)
# include <bst/config/select_platform.h>
#endif
#ifdef BST_PLATFORM_CONFIG
# include BST_PLATFORM_CONFIG
#endif


/* Ensure macros are defined */
/// \{
// Note that the processors typically handle branch prediction better for the likely case.
// Therein, the best time to use these is when you are dealing with the unlikely case.
// https://medium.com/software-design/likely-unlikely-directives-802c09bd5232
// Note that it is faster to merely write the code such that the most common case is always first.
// It is only better in the case where the most common case is not first.
// https://stackoverflow.com/questions/35938249/optimizing-a-branch-for-a-known-more-common-path/35940041#35940041
#ifndef BST_LIKELY
# define BST_LIKELY(x) x
#endif
#ifndef BST_UNLIKELY
# define BST_UNLIKELY(x) x
#endif


#if !(defined(BST_NO_STDATOMICS) || defined(BST_HAS_STDATOMICS))
# if (defined(__STDC_NO_ATOMICS__) && (__STDC_NO_ATOMICS__ == 1)) || !defined(BST_LEAST_C11)
#  define BST_NO_STDATOMICS
# else
#  define BST_HAS_STDATOMICS
# endif
#endif


#if !defined(BST_INTPTR_NBITS)
# if defined(__alpha__) || defined(__ia64__) || defined(__x86_64__) || defined(_WIN64) || defined(__ppc64__)
#  define BST_INTPTR_NBITS 64
# elif defined(__WATCOMC__) || defined(__TURBOC__)
#  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#    define BST_INTPTR_NBITS 16
#  else
#    define BST_INTPTR_NBITS 32
#  endif
# elif defined(__i386__) || defined(_WIN32) || defined(WIN32) || defined(__ppc64__)
#  define BST_INTPTR_NBITS 32
# elif defined(BST_COMPILER_INTEL)
// If made it this far, it typically is a 32 bit system.
# define BST_INTPTR_NBITS 32
# else
#  error "Could not determine BST_INTPTR_NBITS."
# endif
#endif


#if !defined(BST_HAS_LONG_LONG) && !defined(BST_NO_LONG_LONG) && !defined(BST_MSVC) && !defined(__BORLANDC__)
# include <limits.h>
# if (defined(ULLONG_MAX) || defined(ULONG_LONG_MAX) || defined(ULONGLONG_MAX))
#   define BST_HAS_LONG_LONG
# else
#   define BST_NO_LONG_LONG
# endif
#endif
/// \}


#endif // BST__CONFIG_H
