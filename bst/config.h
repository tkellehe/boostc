#ifndef BST__CONFIG_H
#define BST__CONFIG_H


#include <bst/config/version.h>


/* Default is to provide BST with no namespaces and namespaced */
/// \{
#if !defined(BST_NAMESPACE_ONLY) && !defined(BST_NO_NAMESPACE)
#define BST_NO_NAMESPACE
#endif
/// \}


/* Provide a helper that joins two symbols */
/// \{
#define BST_DTL_DTL_JOIN(L, R) L ## R
#define BST_DTL_JOIN(L, R) BST_DTL_DTL_JOIN(L, R)
#define BST_JOIN(L, R) BST_DTL_JOIN(L, R)
/// \}


/* Provide a helper that assist with variadic parameter default values */
/// \{
#define BST_X1ARGS1(x, a, ...) a
#define BST_X1ARGS2(x, a, b, ...) a, b
#define BST_X1ARGS3(x, a, b, c, ...) a, b, c
#define BST_X1ARGS4(x, a, b, c, d, ...) a, b, c, d
#define BST_X1ARGS5(x, a, b, c, d, e, ...) a, b, c, d, e
#define BST_X1ARGS6(x, a, b, c, d, e, f, ...) a, b, c, d, e, f
#define BST_ARGS1(a, ...) a
#define BST_ARGS2(a, b, ...) a, b
#define BST_ARGS3(a, b, c, ...) a, b, c
#define BST_ARGS4(a, b, c, d, ...) a, b, c, d
#define BST_ARGS5(a, b, c, d, e, ...) a, b, c, d, e
#define BST_ARGS6(a, b, c, d, e, f, ...) a, b, c, d, e, f
/// \}


/* Provide a helper that allows for counting the number of parameters passed to a variadic macro */
/// \{
#define BST_NARG(...) \
         BST_DTL_NARG(__VA_ARGS__, BST_DTL_SEQ())
#define BST_DTL_NARG(...) \
         BST_DTL_ARGN(__VA_ARGS__)
#define BST_DTL_ARGN( \
         _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
        _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
        _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
        _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
        _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
        _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, \
        _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, \
        _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, \
        _91, _92, _93, _94, _95, _96, _97, _98, _99,  N, ...) N
#define BST_DTL_SEQ() \
        99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
        89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
        79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
        69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
         9,  8,  7,  6,  5,  4,  3,  2,  1,  0
/// \}


/* Configure the compiler */
/// \{
#if !defined(BST_COMPILER_CONFIG) && !defined(BST_NO_COMPILER_CONFIG) && !defined(BST_NO_CONFIG)
# include <bst/config/select_compiler.h>
#endif
#ifdef BST_COMPILER_CONFIG
# include BST_COMPILER_CONFIG
#endif
/// \}


/* Configure the platform */
/// \{
#if !defined(BST_PLATFORM_CONFIG) && !defined(BST_NO_PLATFORM_CONFIG) && !defined(BST_NO_CONFIG)
# include <bst/config/select_platform.h>
#endif
#ifdef BST_PLATFORM_CONFIG
# include BST_PLATFORM_CONFIG
#endif
/// \}


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


/* Provide a null type */
/// \{
#ifndef bst_null
# ifdef BST_LEAST_CPP11
#  define bst_null nullptr
# else
#  define bst_null 0
# endif
#endif
/// \}


#endif // BST__CONFIG_H
