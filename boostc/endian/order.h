//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__ENDIAN__ORDER_H
#define BOOSTC__ENDIAN__ORDER_H


#include <boostc/config.h>


#define BSTC_ENDIAN_ORDER_LITTLE 0
#define BSTC_ENDIAN_ORDER_BIG 1
#define BSTC_ENDIAN_ORDER_PDP 2


#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_LITTLE
#elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_BIG
#elif defined(__BYTE_ORDER__) && defined(__ORDER_PDP_ENDIAN__) && __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_PDP
#elif defined(__LITTLE_ENDIAN__)
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_LITTLE
#elif defined(__BIG_ENDIAN__)
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_BIG
#elif defined(_MSC_VER) || defined(__i386__) || defined(__x86_64__)
# define BSTC_ENDIAN_ORDER_NATIVE BSTC_ENDIAN_ORDER_LITTLE
#else
/// Else \c BSTC_ENDIAN_ORDER_NATIVE is not defined.
#endif


/* An enumeration type representing the different endianness that are supported. */
/// \{
#ifndef bstc_endian_order
enum _bstc_endian_order
{
    _bstc_endian_order_little = BSTC_ENDIAN_ORDER_LITTLE,
    _bstc_endian_order_big = BSTC_ENDIAN_ORDER_BIG,
    _bstc_endian_order_pdp = BSTC_ENDIAN_ORDER_PDP
# ifdef BSTC_ENDIAN_ORDER_NATIVE
    , _bstc_endian_order_native = BSTC_ENDIAN_ORDER_NATIVE
#  define bstc_endian_order_native _bstc_endian_order_native
# endif
};
# define bstc_endian_order_t enum _bstc_endian_order
# define bstc_endian_order_little _bstc_endian_order_little
# define bstc_endian_order_big _bstc_endian_order_big
# define bstc_endian_order_pdp _bstc_endian_order_pdp
#endif
/// \}


#endif // BOOSTC__ENDIAN__ORDER_H
