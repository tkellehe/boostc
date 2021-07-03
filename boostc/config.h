//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG_H
#define BOOSTC__CONFIG_H


/* The current version of the boostc library. */
/// \{
#define BSTC 0L
/// \}


#include <boostc/config/version.h>


/* Make sure that macros are available for stdint. */
/// \{
#if !defined(BSTC_HAS_FORMAT_MACROS) && !defined(BSTC_NO_FORMAT_MACROS)
# define BSTC_HAS_FORMAT_MACROS
#endif
#ifdef BSTC_HAS_FORMAT_MACROS
# ifdef __STDC_FORMAT_MACROS
#  undef __STDC_FORMAT_MACROS
# endif
# define __STDC_FORMAT_MACROS 1
#endif
/// \}


/* Configure the compiler */
/// \{
#if !defined(BSTC_COMPILER_CONFIG) && !defined(BSTC_NO_COMPILER_CONFIG) && !defined(BSTC_NO_CONFIG)
# include <boostc/config/select_compiler.h>
#endif
/// \}


/* Configure the platform */
/// \{
#if !defined(BSTC_PLATFORM_CONFIG) && !defined(BSTC_NO_PLATFORM_CONFIG) && !defined(BSTC_NO_CONFIG)
# include <boostc/config/select_platform.h>
#endif
/// \}


/* Ensure macros are defined */
/// \{
#if !defined(BSTC_HAS_VARIADIC_MACROS) && !defined(BSTC_NO_VARIADIC_MACROS)
# if defined(BSTC_LEAST_C99) || defined(BSTC_LEAST_CPP98)
#  define BSTC_HAS_VARIADIC_MACROS
# else
#  define BSTC_NO_VARIADIC_MACROS
# endif
#endif


#if !defined(BSTC_HAS_VA_ARGS_PASTE) && !defined(BSTC_NO_VA_ARGS_PASTE)
# define BSTC_NO_VA_ARGS_PASTE
#endif


#if !defined(BSTC_HAS_STRING_PASTE) && !defined(BSTC_NO_STRING_PASTE)
# define BSTC_NO_STRING_PASTE
#endif


#include <boostc/config/macros.h>


// Note that the processors typically handle branch prediction better for the likely case.
// Therein, the best time to use these is when you are dealing with the unlikely case.
// https://medium.com/software-design/likely-unlikely-directives-802c09bd5232
// Note that it is faster to merely write the code such that the most common case is always first.
// It is only better in the case where the most common case is not first.
// https://stackoverflow.com/questions/35938249/optimizing-a-branch-for-a-known-more-common-path/35940041#35940041
#ifndef BSTC_LIKELY
# define BSTC_LIKELY(x) (x)
#endif
#ifndef BSTC_UNLIKELY
# define BSTC_UNLIKELY(x) (x)
#endif


#if !(defined(BSTC_NO_STDATOMICS) || defined(BSTC_HAS_STDATOMICS))
# if (defined(__STDC_NO_ATOMICS__) && (__STDC_NO_ATOMICS__ == 1)) || !defined(BSTC_LEAST_C11)
#  define BSTC_NO_STDATOMICS
# else
#  define BSTC_HAS_STDATOMICS
# endif
#endif


#if !(defined(BSTC_NO_STDTHREADS) || defined(BSTC_HAS_STDTHREADS))
# if (defined(__STDC_NO_THREADS__) && (__STDC_NO_THREADS__ == 1)) || !defined(BSTC_LEAST_C11)
#  define BSTC_NO_STDTHREADS
# else
#  define BSTC_HAS_STDTHREADS
# endif
#endif


#if !defined(BSTC_INTPTR_NBITS)
# if defined(__alpha__) || defined(__ia64__) || defined(__x86_64__) || defined(_WIN64) || defined(__ppc64__)
#  define BSTC_INTPTR_NBITS 64
# elif defined(__WATCOMC__) || defined(__TURBOC__)
#  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#    define BSTC_INTPTR_NBITS 16
#  else
#    define BSTC_INTPTR_NBITS 32
#  endif
# elif defined(__i386__) || defined(_WIN32) || defined(WIN32) || defined(__ppc64__)
#  define BSTC_INTPTR_NBITS 32
# elif defined(BSTC_COMPILER_INTEL)
// If made it this far, it typically is a 32 bit system.
#  define BSTC_INTPTR_NBITS 32
# else
#  error "BOOSTC could not determine BSTC_INTPTR_NBITS."
# endif
#endif


#if !defined(BSTC_HAS_64BIT) && !defined(BSTC_NO_64BIT)
# ifdef BSTC_LEAST_C99
#  define BSTC_HAS_64BIT
# elif defined(BSTC_LEAST_CPP98)
#  define BSTC_HAS_64BIT
# endif
#endif


#if !defined(BSTC_HAS_LONG_LONG) && !defined(BSTC_NO_LONG_LONG)
# ifdef __cplusplus
#  include <climits>
# else
#  include <limits.h>
# endif
# if (defined(ULLONG_MAX) || defined(ULONG_LONG_MAX) || defined(ULONGLONG_MAX))
#   define BSTC_HAS_LONG_LONG
# else
#   define BSTC_NO_LONG_LONG
# endif
#endif
/// \}


/* Provide an inline specific to C style */
/// \{
#ifndef bstc_inline
# if defined(BSTC_LEAST_C99) || defined(__cplusplus)
#  define bstc_inline inline
# elif defined(BSTC_COMPILER_GCC) || defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_CLANG)
#  define bstc_inline __inline__
# elif defined(BSTC_COMPILER_VISUALC)
#  define bstc_inline __inline
# else
#  define bstc_inline
# endif
#endif
/// \}


/* Provide a way to mark a parameter as unused */
/// \{
#ifndef bstc_unused
# define bstc_unused(P) (void)(P);
#endif
/// \}


/* Provide a null type */
/// \{
#ifndef bstc_nullptr
# ifdef BSTC_LEAST_CPP11
#  define bstc_nullptr nullptr
# else
#  ifdef __cplusplus
#   include <cstddef>
#  else
#   include <stddef.h>
#  endif
#  ifdef NULL
#   define bstc_nullptr NULL
#  else
#   define bstc_nullptr 0
#  endif
# endif
#endif
/// \}


/* Provide a way to unpack tuples */
/// \{
#ifdef BSTC_HAS_VARIADIC_MACROS
# ifndef BSTC_UNPACK
#  define BSTC_UNPACK(...) __VA_ARGS__
# endif
#endif
/// \}


/* Provide a way to detect if a tuple */
/// \{
#if defined(BSTC_HAS_VARIADIC_MACROS) && defined(BSTC_ARGCNT)
# ifndef BSTC_ISA_TUPLE
#  define BSTC_ISA_TUPLE(tpl, _t, _f) BSTC_DTL_ISA_TUPLE_CALL(BSTC_DTL_ISA_TUPLE_SELECT(tpl,unused), _t, _f)
#  define BSTC_DTL_ISA_TUPLE_CALL(F, _t, _f) F(_t, _f)
#  define BSTC_DTL_ISA_TUPLE_SELECT(tpl,U) BSTC_JOIN2(BSTC_DTL_ISA_TUPLE, BSTC_DTL_ISA_TUPLE_SELECT_(tpl, unused))
#  define BSTC_DTL_ISA_TUPLE_SELECT_(tpl,U) BSTC_ARGCNT(0, BSTC_DTL_ISA_TUPLE_EXPAND tpl)
#  define BSTC_DTL_ISA_TUPLE2(_t, _f) _f
#  define BSTC_DTL_ISA_TUPLE3(_t, _f) _t
#  define BSTC_DTL_ISA_TUPLE_EXPAND(...) 0, 0
# endif
#endif
/// \}


/* Provide a way to detect if-empty character is first */
/// \{
#ifdef BSTC_HAS_VARIADIC_MACROS
# ifndef BSTC_IF_ARG0_EMPTY
#  ifdef BSTC_HAS_VA_ARGS_PASTE
#   define BSTC_IF_ARG0_EMPTY(tpl, _t, _f) BSTC_EXPAND(BSTC_IFEQ(BSTC_DTL_IF_ARG0_EMPTY1(tpl), BSTC_DTL_IF_ARG0_EMPTY2(tpl), _f, _t))
#   define BSTC_DTL_IF_ARG0_EMPTY1(tpl) BSTC_EXPAND(BSTC_DTL_IF_ARG0_EMPTY1_ tpl)
#   define BSTC_DTL_IF_ARG0_EMPTY1_(...) BSTC_DTL_IF_ARG0_EMPTY1__(__VA_ARGS__)
#   define BSTC_DTL_IF_ARG0_EMPTY1__(A, ...) BSTC_DTL_IF_ARG0_EMPTY1___(A)
#   define BSTC_DTL_IF_ARG0_EMPTY1___(...) BSTC_ARGCNT(0, __VA_ARGS__)
#   define BSTC_DTL_IF_ARG0_EMPTY2(tpl) BSTC_EXPAND(BSTC_DTL_IF_ARG0_EMPTY2_ tpl)
#   define BSTC_DTL_IF_ARG0_EMPTY2_(...) BSTC_DTL_IF_ARG0_EMPTY2__(__VA_ARGS__)
#   define BSTC_DTL_IF_ARG0_EMPTY2__(A, ...) BSTC_DTL_IF_ARG0_EMPTY2___(A)
#   define BSTC_DTL_IF_ARG0_EMPTY2___(...) BSTC_ARGCNT(0, ##__VA_ARGS__)
#  else
#   define BSTC_IF_ARG0_EMPTY(tpl, _t, _f) BSTC_EXPAND(BSTC_DTL_IF_ARG0_EMPTY(_t, _f, BSTC_DTL_IF_ARG0_EMPTY_DETECT(tpl)))
#   define BSTC_DTL_IF_ARG0_EMPTY(_t, _f, tpl) BSTC_EXPAND(BSTC_IFEQ(BSTC_ARGCNT tpl, 2, _t, _f))
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT(tpl) BSTC_EXPAND(BSTC_DTL_IF_ARG0_EMPTY_DETECT1(unused, BSTC_UNPACK tpl, unused))
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT1(U,...) BSTC_EXPAND(BSTC_DTL_IF_ARG0_EMPTY_DETECT2(__VA_ARGS__))
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT2(A,...) (BSTC_CALL(BSTC_DTL_IF_ARG0_EMPTY_DETECT3(A, unused), A, unused))
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT3(A, U) BSTC_ISA_TUPLE(A, BSTC_DTL_IF_ARG0_EMPTY_DETECT4, BSTC_DTL_IF_ARG0_EMPTY_DETECT5)
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT4(A, U) A
#   define BSTC_DTL_IF_ARG0_EMPTY_DETECT5(A, U) BSTC_DTL_IF_ARG0_EMPTY_DETECT6(A, U) ()

// If does not have symbol string pasting, then we need to potentially mess up string literals.
#   ifdef BSTC_HAS_STRING_PASTE
#    define BSTC_DTL_IF_ARG0_EMPTY_PREFIX() 0, 0
#    define BSTC_DTL_IF_ARG0_EMPTY_DETECT6(A, U) BSTC_DTL_IF_ARG0_EMPTY_PREFIX ## A
#   else
#    define L() 0, 0
#    define BSTC_DTL_IF_ARG0_EMPTY_DETECT6(A, U) L ## A
#   endif

#  endif
# endif
#endif
/// \}


/** Compile time GCD and LCM.
 * Based on: https://stackoverflow.com/a/76746/5407843
 * 32bit numbers could require up to 45 steps.
 * VISUALC runs out of heap around 8. In order to get 13 steps, the macro is already embedded in itself.
 * 
 * # define BSTC_GCD(a, b) (((a) >= (b)) * BSTC_DTL_GCD_1(a, b) + ((a) < (b)) * BSTC_DTL_GCD_1(b, a))
 * # define BSTC_DTL_GCD_1(a, b) (((((b) == 0))*(a)) + ((b) != 0) * BSTC_DTL_GCD_2((b), (a) % ((b) + ((b) == 0))))
 * # define BSTC_DTL_GCD_2(a, b) (((((b) == 0))*(a)) + ((b) != 0) * BSTC_DTL_GCD_N((b), (a) % ((b) + ((b) == 0))))
 * # define BSTC_DTL_GCD_N(a, b) (a)
 */
/// \{
#ifndef BSTC_GCD
# define BSTC_GCD(a, b) (((a) >= (b)) * BSTC_DTL_GCD_1(a, b) + ((a) < (b)) * BSTC_DTL_GCD_1(b, a))
# define BSTC_DTL_GCD_1(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_2(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_2(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_3(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_3(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_4(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_4(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_5(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_5(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_6(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_6(a, b) (\
    ((((b) == 0))*(a)) + ((b) != 0) * \
    ((((((a) % ((b) + ((b) == 0))) == 0))*(b)) + (((a) % ((b) + ((b) == 0))) != 0) * BSTC_DTL_GCD_7(((a) % ((b) + ((b) == 0))), ((b) % (((a) % ((b) + ((b) == 0))) + (((a) % ((b) + ((b) == 0))) == 0)))))\
    )
# define BSTC_DTL_GCD_7(a, b) (a)
#endif


#ifndef BSTC_LCM
# define BSTC_LCM(a,b) (((a)*(b))/BSTC_GCD(a,b))
#endif
/// \}


#endif // BOOSTC__CONFIG_H
