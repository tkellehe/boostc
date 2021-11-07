//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__ENDIAN__REVERSE_H
#define BOOSTC__ENDIAN__REVERSE_H


#include <boostc/config.h>
#include <boostc/stdint.h>


/* Simplfied for BOOSTC and main logic pulled from Boost <boost/endian/detail/intrinsic.hpp>. */
/// \{
#ifndef BSTC_NO_ENDIAN_REV_INTRINSICS

# if defined(_MSC_VER) && ( !defined(BSTC_COMPILER_CLANG) || defined(__c2__) )
#  include <boostc/stdlib.h>
#  define BSTC_ENDIAN_REV_INTRINSIC_16(x) _byteswap_ushort(x)
#  define BSTC_ENDIAN_REV_INTRINSIC_32(x) _byteswap_ulong(x)
#  define BSTC_ENDIAN_REV_INTRINSIC_64(x) _byteswap_uint64(x)

# elif (defined(BSTC_CLANG_HAS_BUILTIN) && BSTC_CLANG_HAS_BUILTIN(__builtin_bswap32) && BSTC_CLANG_HAS_BUILTIN(__builtin_bswap64)) ||\
       (defined(BSTC_COMPILER_GCC) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)))
#  if (defined(BSTC_CLANG_HAS_BUILTIN) && BSTC_CLANG_HAS_BUILTIN(__builtin_bswap16)) ||\
      (defined(BSTC_COMPILER_GCC) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)))
#   define BSTC_ENDIAN_REV_INTRINSIC_16(x) __builtin_bswap16(x)
#  else
#   define BSTC_ENDIAN_REV_INTRINSIC_16(x) __builtin_bswap32((x) << 16)
#  endif

#  define BSTC_ENDIAN_REV_INTRINSIC_32(x) __builtin_bswap32(x)
#  define BSTC_ENDIAN_REV_INTRINSIC_64(x) __builtin_bswap64(x)

# elif defined(__linux__)

#  include <byteswap.h>
#  define BSTC_ENDIAN_REV_INTRINSIC_16(x) bswap_16(x)
#  define BSTC_ENDIAN_REV_INTRINSIC_32(x) bswap_32(x)
#  define BSTC_ENDIAN_REV_INTRINSIC_64(x) bswap_64(x)

# else
#  define BSTC_NO_ENDIAN_REV_INTRINSICS
# endif

# if !defined(BSTC_NO_ENDIAN_REV_INTRINSICS) && !defined(BSTC_HAS_ENDIAN_REV_INTRINSICS)
#  define BSTC_HAS_ENDIAN_REV_INTRINSICS
# endif

#endif
/// \}


/** Applies byte swapping to 1 byte. */
/// \{
#if defined(bstc_uint8_t) && !defined(bstc_endian_rev_uint8)
# define bstc_endian_rev_uint8(x) (x)
#endif
/// \}


/** Applies byte swapping to 2 bytes. */
/// \{
#if defined(bstc_uint16_t) && !defined(bstc_endian_rev_uint16)
    static bstc_inline bstc_uint16_t _bstc_endian_rev_uint16(bstc_uint16_t x)
    {
# ifdef BSTC_HAS_ENDIAN_REV_INTRINSICS
        return BSTC_ENDIAN_REV_INTRINSIC_16(x);
# else
        return (x << 8) | (x >> 8);
# endif
    }
# define bstc_endian_rev_uint16 _bstc_endian_rev_uint16
#endif
/// \}


/** Applies byte swapping to 4 bytes. */
/// \{
#if defined(bstc_uint32_t) && !defined(bstc_endian_rev_uint32)
    static bstc_inline bstc_uint32_t _bstc_endian_rev_uint32(bstc_uint32_t x)
    {
# ifdef BSTC_HAS_ENDIAN_REV_INTRINSICS
        return BSTC_ENDIAN_REV_INTRINSIC_32(x);
# else
        bstc_uint32_t temp = (x << 16) | (x >> 16);
        return ((temp << 8) & 0xFF00FF00) | ((temp >> 8) & 0x00FF00FF);
# endif
    }
# define bstc_endian_rev_uint32 _bstc_endian_rev_uint32
#endif
/// \}


/** Applies byte swapping to 8 bytes. */
/// \{
#if defined(bstc_uint64_t) && !defined(bstc_endian_rev_uint64)
    static bstc_inline bstc_uint64_t _bstc_endian_rev_uint64(bstc_uint64_t x)
    {
# ifdef BSTC_HAS_ENDIAN_REV_INTRINSICS
        return BSTC_ENDIAN_REV_INTRINSIC_64(x);
# else
        bstc_uint64_t temp1 = x << 32 | x >> 32;
        bstc_uint64_t temp2 = ((temp1 & 0x0000FFFF0000FFFFULL) << 16) | ((temp1 & 0xFFFF0000FFFF0000ULL) >> 16);
        return (temp2 & 0x00FF00FF00FF00FFULL) << 8 | (temp2 & 0xFF00FF00FF00FF00ULL) >> 8;
# endif
    }
# define bstc_endian_rev_uint64 _bstc_endian_rev_uint64
#endif
/// \}


#endif // BOOSTC__ENDIAN__REVERSE_H
