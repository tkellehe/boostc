//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/limits.h>
#include <boostc/signal.h>
#include <boostc/stddef.h>


#ifdef BSTC_LEAST_CPP11
# define __STDC_LIMIT_MACROS
# define __STDC_CONSTANT_MACROS
# include <cstdint>
#elif defined(BSTC_LEAST_C99)
# include <stdint.h>
#endif


// The standard states that if FIXEDTYPE_MAX is not defined,
// then the typedef for the fixed type is not defined.


//------------------------------------------------------------------------------------------------------------
//                                               [u]int8
//------------------------------------------------------------------------------------------------------------
#ifndef bstc_uint8_c
# ifdef UINT8_C
#  define bstc_uint8_c UINT8_C
# else
#  define bstc_uint8_c(v) ((bstc_uint8_t) v)
# endif
#endif
#ifndef bstc_uint8_max
# ifdef UINT8_MAX
#  define bstc_uint8_max UINT8_MAX
#  ifndef bstc_uint8_t
#   define bstc_uint8_t uint8_t
#  endif
# else
#  define bstc_uint8_max 0xff
# endif
#endif
#if !defined(bstc_uint8_t) && defined(bstc_uint8_max)
# define bstc_uint8_t unsigned char
#endif


#ifndef bstc_int8_c
# ifdef INT8_C
#  define bstc_int8_c INT8_C
# else
#  define bstc_int8_c(v) ((bstc_int8_t) v)
# endif
#endif
#ifndef bstc_int8_min
# ifdef INT8_MIN
#  define bstc_int8_min INT8_MIN
# else
#  define bstc_int8_min bstc_int8_c(0x80)
# endif
#endif
#ifndef bstc_int8_max
# ifdef INT8_MAX
#  define bstc_int8_max INT8_MAX
#  ifndef bstc_int8_t
#   define bstc_int8_t int8_t
#  endif
# else
#  define bstc_int8_max 0xff
# endif
#endif
#if !defined(bstc_int8_t) && defined(bstc_int8_max)
# define bstc_int8_t char
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int16
//------------------------------------------------------------------------------------------------------------
#ifndef bstc_uint16_c
# ifdef UINT16_C
#  define bstc_uint16_c UINT16_C
# else
#  define bstc_uint16_c(v) ((bstc_uint16_t) v)
# endif
#endif
#ifndef bstc_uint16_max
# ifdef UINT16_MAX
#  define bstc_uint16_max UINT16_MAX
#  ifndef bstc_uint16_t
#   define bstc_uint16_t uint16_t
#  endif
# else
#  define bstc_uint16_max 0xffff
# endif
#endif
#if !defined(bstc_uint16_t) && defined(bstc_uint16_max)
# if bstc_uint16_max == bstc_uint_max
#  define bstc_uint16_t unsigned int
# elif bstc_uint16_max == bstc_ushrt_max
#  define bstc_uint16_t unsigned short
# else
#  error "BOOSTC could not determine bstc_uint16_t."
# endif
#endif


#ifndef bstc_int16_c
# ifdef INT16_C
#  define bstc_int16_c INT16_C
# else
#  define bstc_int16_c(v) ((bstc_int16_t) v)
# endif
#endif
#ifndef bstc_int16_min
# ifdef INT16_MIN
#  define bstc_int16_min INT16_MIN
# else
#  define bstc_int16_min bstc_int16_c(0x8000)
# endif
#endif
#ifndef bstc_int16_max
# ifdef INT16_MAX
#  define bstc_int16_max INT16_MAX
#  ifndef bstc_int16_t
#   define bstc_int16_t int16_t
#  endif
# else
#  define bstc_int16_max 0x7fff
# endif
#endif
#if !defined(bstc_int16_t) && defined(bstc_int16_max)
# if bstc_int16_max == bstc_int_max
#  define bstc_int16_t int
# elif bstc_int16_max == bstc_shrt_max
#  define bstc_int16_t short
# else
#  error "BOOSTC could not determine bstc_int16_t."
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int32
//------------------------------------------------------------------------------------------------------------
#ifndef bstc_uint32_c
# ifdef UINT32_C
#  define bstc_uint32_c UINT32_C
# else
#  define bstc_uint32_c(v) ((bstc_uint32_t) v)
# endif
#endif
#ifndef bstc_uint32_max
# ifdef UINT32_MAX
#  define bstc_uint32_max UINT32_MAX
#  ifndef bstc_uint32_t
#   define bstc_uint32_t uint32_t
#  endif
# else
#  define bstc_uint32_max (0xffffffffUL)
# endif
#endif
#if !defined(bstc_uint32_t) && defined(bstc_uint32_max)
# if bstc_uint32_max == bstc_ulong_max
#  define bstc_uint32_t unsigned long
# elif bstc_uint32_max == bstc_uint_max
#  define bstc_uint32_t unsigned int
# elif bstc_uint32_max == bstc_ushrt_max
#  define bstc_uint32_t unsigned short
# else
#  error "BOOSTC could not determine bstc_uint32_t."
# endif
#endif


#ifndef bstc_int32_c
# ifdef INT32_C
#  define bstc_int32_c INT32_C
# else
#  define bstc_int32_c(v) ((bstc_int32_t) v)
# endif
#endif
#ifndef bstc_int32_min
# ifdef INT32_MIN
#  define bstc_int32_min INT32_MIN
# else
#  define bstc_int32_min bstc_int32_c(0x80000000)
# endif
#endif
#ifndef bstc_int32_max
# ifdef INT32_MAX
#  define bstc_int32_max INT32_MAX
#  ifndef bstc_int32_t
#   define bstc_int32_t int32_t
#  endif
# else
#  define bstc_int32_max (0x7fffffffL)
# endif
#endif
#if !defined(bstc_int32_t) && defined(bstc_int32_max)
# if bstc_int32_max == bstc_long_max
#  define bstc_int32_t long
# elif bstc_int32_max == bstc_int_max
#  define bstc_int32_t int
# elif bstc_int32_max == bstc_shrt_max
#  define bstc_int32_t short
# else
#  error "BOOSTC could not determine bstc_int32_t."
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int64
//------------------------------------------------------------------------------------------------------------
#ifdef BSTC_HAS_64BIT
# ifndef bstc_uint64_c
#  ifdef UINT64_C
#   define bstc_uint64_c UINT64_C
#  elif BSTC_HAS_LONG_LONG
#   define bstc_uint64_c(v) v ## ULL
#  else
#   define bstc_uint64_c(v) ((bstc_uint64_t) v)
#  endif
# endif
# ifndef bstc_uint64_max
#  ifdef UINT64_MAX
#   define bstc_uint64_max UINT64_MAX
#   ifndef bstc_uint64_t
#    define bstc_uint64_t uint64_t
#   endif
#  else
#   define bstc_uint64_max (0xffffffffUL)
#  endif
# endif
# if !defined(bstc_uint64_t) && defined(bstc_uint64_max)
#  if defined(bstc_ullong_max) && bstc_uint64_max == bstc_ullong_max
#   define bstc_uint64_t unsigned long long
#  elif bstc_uint64_max == bstc_ulong_max
#   define bstc_uint64_t unsigned long
#  elif bstc_uint64_max == bstc_uint_max
#   define bstc_uint64_t unsigned int
#  elif bstc_uint64_max == bstc_ushrt_max
#   define bstc_uint64_t unsigned short
#  else
#   error "BOOSTC could not determine bstc_uint64_t."
#  endif
# endif


# ifndef bstc_int64_c
#  ifdef INT64_C
#   define bstc_int64_c INT64_C
#  elif BSTC_HAS_LONG_LONG
#   define bstc_uint64_c(v) v ## LL
#  else
#   define bstc_int64_c(v) ((bstc_int64_t) v)
#  endif
# endif
# ifndef bstc_int64_min
#  ifdef INT64_MIN
#   define bstc_int64_min INT64_MIN
#  else
#   define bstc_int64_min bstc_int64_c(0x80000000)
#  endif
# endif
# ifndef bstc_int64_max
#  ifdef INT64_MAX
#   define bstc_int64_max INT64_MAX
#   ifndef bstc_int64_t
#    define bstc_int64_t int64_t
#   endif
#  else
#   define bstc_int64_max (0x7fffffffL)
#  endif
# endif
# if !defined(bstc_int64_t) && defined(bstc_int64_max)
#  if defined(bstc_llong_max) && bstc_int64_max == bstc_llong_max
#   define bstc_int64_t long long
#  elif bstc_int64_max == bstc_long_max
#   define bstc_int64_t long
#  elif bstc_int64_max == bstc_int_max
#   define bstc_int64_t int
#  elif bstc_int64_max == bstc_shrt_max
#   define bstc_int64_t short
#  else
#   error "BOOSTC could not determine bstc_int64_t."
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]intptr
//------------------------------------------------------------------------------------------------------------
#ifndef bstc_intptr_c
# ifdef INTPTR_C
#  define bstc_intptr_c INTPTR_C
# endif
#endif
#ifndef bstc_intptr_min
# ifdef INTPTR_MIN
#  define bstc_intptr_min INTPTR_MIN
# endif
#endif
#ifndef bstc_intptr_max
# ifdef INTPTR_MAX
#  define bstc_intptr_max INTPTR_MAX
#  ifndef bstc_intptr_t
#   define bstc_intptr_t intptr_t
#  endif
# endif
#endif
#ifndef bstc_uintptr_c
# ifdef UINTPTR_C
#  define bstc_uintptr_c UINTPTR_C
# endif
#endif
#ifndef bstc_uintptr_max
# ifdef UINTPTR_MAX
#  define bstc_uintptr_max UINTPTR_MAX
#  ifndef bstc_uintptr_t
#   define bstc_uintptr_t uintptr_t
#  endif
# endif
#endif
#ifdef BSTC_INTPTR_NBITS
# if BSTC_INTPTR_NBITS == 64
#  ifndef bstc_uintptr_t
#   define bstc_uintptr_t bstc_uint64_t
#  endif
#  ifndef bstc_intptr_t
#   define bstc_intptr_t bstc_int64_t
#  endif
#  ifndef bstc_uintptr_c
#   define bstc_uintptr_c bstc_uint64_c
#  endif
#  ifndef bstc_intptr_c
#   define bstc_intptr_c bstc_int64_c
#  endif
#  ifndef bstc_uintptr_max
#   define bstc_uintptr_max bstc_uint64_max
#  endif
#  ifndef bstc_intptr_max
#   define bstc_intptr_max bstc_int64_max
#  endif
#  ifndef bstc_intptr_min
#   define bstc_intptr_min bstc_int64_min
#  endif
# elif BSTC_INTPTR_NBITS == 32
#  ifndef bstc_uintptr_t
#   define bstc_uintptr_t bstc_uint32_t
#  endif
#  ifndef bstc_intptr_t
#   define bstc_intptr_t bstc_int32_t
#  endif
#  ifndef bstc_uintptr_c
#   define bstc_uintptr_c bstc_uint32_c
#  endif
#  ifndef bstc_intptr_c
#   define bstc_intptr_c bstc_int32_c
#  endif
#  ifndef bstc_uintptr_max
#   define bstc_uintptr_max bstc_uint32_max
#  endif
#  ifndef bstc_intptr_max
#   define bstc_intptr_max bstc_int32_max
#  endif
#  ifndef bstc_intptr_min
#   define bstc_intptr_min bstc_int32_min
#  endif
# elif BSTC_INTPTR_NBITS == 16
#  ifndef bstc_uintptr_t
#   define bstc_uintptr_t bstc_uint16_t
#  endif
#  ifndef bstc_intptr_t
#   define bstc_intptr_t bstc_int16_t
#  endif
#  ifndef bstc_uintptr_c
#   define bstc_uintptr_c bstc_uint16_c
#  endif
#  ifndef bstc_intptr_c
#   define bstc_intptr_c bstc_int16_c
#  endif
#  ifndef bstc_uintptr_max
#   define bstc_uintptr_max bstc_uint16_max
#  endif
#  ifndef bstc_intptr_max
#   define bstc_intptr_max bstc_int16_max
#  endif
#  ifndef bstc_intptr_min
#   define bstc_intptr_min bstc_int16_min
#  endif
# elif BSTC_INTPTR_NBITS == 8
#  ifndef bstc_uintptr_t
#   define bstc_uintptr_t bstc_uint8_t
#  endif
#  ifndef bstc_intptr_t
#   define bstc_intptr_t bstc_int8_t
#  endif
#  ifndef bstc_uintptr_c
#   define bstc_uintptr_c bstc_uint8_c
#  endif
#  ifndef bstc_intptr_c
#   define bstc_intptr_c bstc_int8_c
#  endif
#  ifndef bstc_uintptr_max
#   define bstc_uintptr_max bstc_uint8_max
#  endif
#  ifndef bstc_intptr_max
#   define bstc_intptr_max bstc_int8_max
#  endif
#  ifndef bstc_intptr_min
#   define bstc_intptr_min bstc_int8_min
#  endif
# else
#  error "BOOSTC cannot define bstc_intptr_t or bstc_uintptr_t."
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]intmax
//------------------------------------------------------------------------------------------------------------
#ifndef bstc_uintmax_c
# ifdef UINTMAX_C
#  define bstc_uintmax_c UINTMAX_C
# endif
#endif
#ifndef bstc_uintmax_max
# ifdef UINTMAX_MAX
#  define bstc_uintmax_max UINTMAX_MAX
#  ifndef bstc_uintmax_t
#   define bstc_uintmax_t uintmax_t
#  endif
# elif defined(bstc_uint64_max)
#  define bstc_uintmax_max bstc_uint64_max
# elif defined(bstc_uint32_max)
#  define bstc_uintmax_max bstc_uint32_max
# elif defined(bstc_uint16_max)
#  define bstc_uintmax_max bstc_uint16_max
# elif defined(bstc_uint8_max)
#  define bstc_uintmax_max bstc_uint8_max
# endif
#endif
#if !defined(bstc_uintmax_t) && defined(bstc_uintmax_max)
# if bstc_uintmax_max == bstc_uint64_max
#  define bstc_uintmax_t bstc_uint64_t
# elif bstc_uintmax_max == bstc_uint32_max
#  define bstc_uintmax_t bstc_uint32_t
# elif bstc_uintmax_max == bstc_uint16_max
#  define bstc_uintmax_t bstc_uint16_t
# elif bstc_uintmax_max == bstc_uint8_max
#  define bstc_uintmax_t bstc_uint8_t
# else
#  error "BOOSTC could not determine bstc_uintmax_t."
# endif
#endif
#if !defined(bstc_uintmax_c) && defined(bstc_uintmax_max)
# if bstc_uintmax_max == bstc_uint64_max
#  define bstc_uintmax_c bstc_uint64_c
# elif bstc_uintmax_max == bstc_uint32_max
#  define bstc_uintmax_c bstc_uint32_c
# elif bstc_uintmax_max == bstc_uint16_max
#  define bstc_uintmax_c bstc_uint16_c
# elif bstc_uintmax_max == bstc_uint8_max
#  define bstc_uintmax_c bstc_uint8_c
# else
#  error "BOOSTC could not determine bstc_uintmax_c."
# endif
#endif


#ifndef bstc_intmax_c
# ifdef INTMAX_C
#  define bstc_intmax_c INTMAX_C
# endif
#endif
#ifndef bstc_intmax_min
# ifdef INTMAX_MIN
#  define bstc_intmax_min INTMAX_MIN
# endif
#endif
#ifndef bstc_intmax_max
# ifdef INTMAX_MAX
#  define bstc_intmax_max INTMAX_MAX
#  ifndef bstc_intmax_t
#   define bstc_intmax_t intmax_t
#  endif
# elif defined(bstc_int64_max)
#  define bstc_intmax_max bstc_int64_max
# elif defined(bstc_int32_max)
#  define bstc_intmax_max bstc_int32_max
# elif defined(bstc_int16_max)
#  define bstc_intmax_max bstc_int16_max
# elif defined(bstc_int8_max)
#  define bstc_intmax_max bstc_int8_max
# endif
#endif
#if !defined(bstc_intmax_t) && defined(bstc_intmax_max)
# if bstc_intmax_max == bstc_int64_max
#  define bstc_intmax_t bstc_int64_t
# elif bstc_intmax_max == bstc_int32_max
#  define bstc_intmax_t bstc_int32_t
# elif bstc_intmax_max == bstc_int16_max
#  define bstc_intmax_t bstc_int16_t
# elif bstc_intmax_max == bstc_int8_max
#  define bstc_intmax_t bstc_int8_t
# else
#  error "BOOSTC could not determine bstc_intmax_t."
# endif
#endif
#if !defined(bstc_intmax_c) && defined(bstc_intmax_max)
# if bstc_intmax_max == bstc_int64_max
#  define bstc_intmax_c bstc_int64_c
# elif bstc_intmax_max == bstc_int32_max
#  define bstc_intmax_c bstc_int32_c
# elif bstc_intmax_max == bstc_int16_max
#  define bstc_intmax_c bstc_int16_c
# elif bstc_intmax_max == bstc_int8_max
#  define bstc_intmax_c bstc_int8_c
# else
#  error "BOOSTC could not determine bstc_intmax_c."
# endif
#endif
#if !defined(bstc_intmax_min) && defined(bstc_intmax_max)
# if bstc_intmax_max == bstc_int64_max
#  define bstc_intmax_min bstc_int64_min
# elif bstc_intmax_max == bstc_int32_max
#  define bstc_intmax_min bstc_int32_min
# elif bstc_intmax_max == bstc_int16_max
#  define bstc_intmax_min bstc_int16_min
# elif bstc_intmax_max == bstc_int8_max
#  define bstc_intmax_min bstc_int8_min
# else
#  error "BOOSTC could not determine bstc_intmax_min."
# endif
#endif
