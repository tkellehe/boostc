//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>


#ifdef __cplusplus
# include <climits>
#else
# include <limits.h>
#endif


#ifdef BSTC_HAS_LONG_LONG
# ifndef bstc_llong_max
#  ifdef LLONG_MAX
#   define bstc_llong_max LLONG_MAX
#  else
#   error "BOOSTC LLONG_MAX is not provided for this system."
#  endif
# endif


# ifndef bstc_llong_min
#  ifdef LLONG_MIN
#   define bstc_llong_min LLONG_MIN
#  else
#   error "BOOSTC LLONG_MIN is not provided for this system."
#  endif
# endif


# ifndef bstc_ullong_max
#  ifdef ULLONG_MAX
#   define bstc_ullong_max ULLONG_MAX
#  else
#   error "BOOSTC ULLONG_MAX is not provided for this system."
#  endif
# endif
#endif


#ifndef bstc_char_bit
# ifdef CHAR_BIT
#  define bstc_char_bit CHAR_BIT
# else
#  error "BOOSTC CHAR_BIT is not provided for this system."
# endif
#endif


#ifndef bstc_mb_len_max
# ifdef MB_LEN_MAX
#  define bstc_mb_len_max MB_LEN_MAX
# else
#  error "BOOSTC MB_LEN_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_char_min
# ifdef CHAR_MIN
#  define bstc_char_min CHAR_MIN
# else
#  error "BOOSTC CHAR_MIN is not provided for this system."
# endif
#endif


#ifndef bstc_char_max
# ifdef CHAR_MAX
#  define bstc_char_max CHAR_MAX
# else
#  error "BOOSTC CHAR_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_schar_min
# ifdef SCHAR_MIN
#  define bstc_schar_min SCHAR_MIN
# else
#  error "BOOSTC SCHAR_MIN is not provided for this system."
# endif
#endif


#ifndef bstc_shrt_min
# ifdef SHRT_MIN
#  define bstc_shrt_min SHRT_MIN
# else
#  error "BOOSTC SHRT_MIN is not provided for this system."
# endif
#endif


#ifndef bstc_int_min
# ifdef INT_MIN
#  define bstc_int_min INT_MIN
# else
#  error "BOOSTC INT_MIN is not provided for this system."
# endif
#endif


#ifndef bstc_long_min
# ifdef LONG_MIN
#  define bstc_long_min LONG_MIN
# else
#  error "BOOSTC LONG_MIN is not provided for this system."
# endif
#endif


#ifndef bstc_schar_max
# ifdef SCHAR_MAX
#  define bstc_schar_max SCHAR_MAX
# else
#  error "BOOSTC SCHAR_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_shrt_max
# ifdef SHRT_MAX
#  define bstc_shrt_max SHRT_MAX
# else
#  error "BOOSTC SHRT_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_int_max
# ifdef INT_MAX
#  define bstc_int_max INT_MAX
# else
#  error "BOOSTC INT_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_long_max
# ifdef LONG_MAX
#  define bstc_long_max LONG_MAX
# else
#  error "BOOSTC LONG_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_uchar_max
# ifdef UCHAR_MAX
#  define bstc_uchar_max UCHAR_MAX
# else
#  error "BOOSTC UCHAR_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_ushrt_max
# ifdef USHRT_MAX
#  define bstc_ushrt_max USHRT_MAX
# else
#  error "BOOSTC USHRT_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_uint_max
# ifdef UINT_MAX
#  define bstc_uint_max UINT_MAX
# else
#  error "BOOSTC UINT_MAX is not provided for this system."
# endif
#endif


#ifndef bstc_ulong_max
# ifdef ULONG_MAX
#  define bstc_ulong_max ULONG_MAX
# else
#  error "BOOSTC ULONG_MAX is not provided for this system."
# endif
#endif

