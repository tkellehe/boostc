//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__ENDIAN__SWAP_H
#define BOOSTC__ENDIAN__SWAP_H


#include <boostc/config.h>
#include <boostc/endian/order.h>
#include <boostc/endian/reverse.h>
#include <boostc/stdint.h>


/**  Converts big endian to the native order for 1 byte. */
/// \{
#ifndef bstc_endian_swap_uint8_big_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint8_big_to_native(x) (x)
# else
#  define bstc_endian_swap_uint8_big_to_native bstc_endian_rev_uint8
# endif
#endif
/// }


/**  Converts big endian to the native order for 2 bytes. */
/// \{
#ifndef bstc_endian_swap_uint16_big_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint16_big_to_native(x) (x)
# else
#  define bstc_endian_swap_uint16_big_to_native bstc_endian_rev_uint16
# endif
#endif
/// }


/**  Converts big endian to the native order for 4 bytes. */
/// \{
#ifndef bstc_endian_swap_uint32_big_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint32_big_to_native(x) (x)
# else
#  define bstc_endian_swap_uint32_big_to_native bstc_endian_rev_uint32
# endif
#endif
/// }


/**  Converts big endian to the native order for 8 bytes. */
/// \{
#ifdef bstc_uint64_t
# ifndef bstc_endian_swap_uint64_big_to_native
#  if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#   define bstc_endian_swap_uint64_big_to_native(x) (x)
#  else
#   define bstc_endian_swap_uint64_big_to_native bstc_endian_rev_uint64
#  endif
# endif
#endif
/// }


/**  Converts native order to big endian for 1 byte. */
/// \{
#ifndef bstc_endian_swap_uint8_native_to_big
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint8_native_to_big(x) (x)
# else
#  define bstc_endian_swap_uint8_native_to_big bstc_endian_rev_uint8
# endif
#endif
/// }


/**  Converts native order to big endian for 2 bytes. */
/// \{
#ifndef bstc_endian_swap_uint16_native_to_big
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint16_native_to_big(x) (x)
# else
#  define bstc_endian_swap_uint16_native_to_big bstc_endian_rev_uint16
# endif
#endif
/// }


/**  Converts native order to big endian for 4 bytes. */
/// \{
#ifndef bstc_endian_swap_uint32_native_to_big
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#  define bstc_endian_swap_uint32_native_to_big(x) (x)
# else
#  define bstc_endian_swap_uint32_native_to_big bstc_endian_rev_uint32
# endif
#endif
/// }


/**  Converts native order to big endian for 8 bytes. */
/// \{
#ifdef bstc_uint64_t
# ifndef bstc_endian_swap_uint64_native_to_big
#  if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_BIG
#   define bstc_endian_swap_uint64_native_to_big(x) (x)
#  else
#   define bstc_endian_swap_uint64_native_to_big bstc_endian_rev_uint64
#  endif
# endif
#endif
/// }


/**  Converts little endian to the native order for 1 byte. */
/// \{
#ifndef bstc_endian_swap_uint8_little_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint8_little_to_native(x) (x)
# else
#  define bstc_endian_swap_uint8_little_to_native bstc_endian_rev_uint8
# endif
#endif
/// }


/**  Converts little endian to the native order for 2 bytes. */
/// \{
#ifndef bstc_endian_swap_uint16_little_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint16_little_to_native(x) (x)
# else
#  define bstc_endian_swap_uint16_little_to_native bstc_endian_rev_uint16
# endif
#endif
/// }


/**  Converts little endian to the native order for 4 bytes. */
/// \{
#ifndef bstc_endian_swap_uint32_little_to_native
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint32_little_to_native(x) (x)
# else
#  define bstc_endian_swap_uint32_little_to_native bstc_endian_rev_uint32
# endif
#endif
/// }


/**  Converts little endian to the native order for 8 bytes. */
/// \{
#ifdef bstc_uint64_t
# ifndef bstc_endian_swap_uint64_little_to_native
#  if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#   define bstc_endian_swap_uint64_little_to_native(x) (x)
#  else
#   define bstc_endian_swap_uint64_little_to_native bstc_endian_rev_uint64
#  endif
# endif
#endif
/// }


/**  Converts native order to little endian for 1 byte. */
/// \{
#ifndef bstc_endian_swap_uint8_native_to_little
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint8_native_to_little(x) (x)
# else
#  define bstc_endian_swap_uint8_native_to_little bstc_endian_rev_uint8
# endif
#endif
/// }


/**  Converts native order to little endian for 2 bytes. */
/// \{
#ifndef bstc_endian_swap_uint16_native_to_little
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint16_native_to_little(x) (x)
# else
#  define bstc_endian_swap_uint16_native_to_little bstc_endian_rev_uint16
# endif
#endif
/// }


/**  Converts native order to little endian for 4 bytes. */
/// \{
#ifndef bstc_endian_swap_uint32_native_to_little
# if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#  define bstc_endian_swap_uint32_native_to_little(x) (x)
# else
#  define bstc_endian_swap_uint32_native_to_little bstc_endian_rev_uint32
# endif
#endif
/// }


/**  Converts native order to little endian for 8 bytes. */
/// \{
#ifdef bstc_uint64_t
# ifndef bstc_endian_swap_uint64_native_to_little
#  if defined(BSTC_ENDIAN_ORDER_NATIVE) && BSTC_ENDIAN_ORDER_NATIVE == BSTC_ENDIAN_ORDER_LITTLE
#   define bstc_endian_swap_uint64_native_to_little(x) (x)
#  else
#   define bstc_endian_swap_uint64_native_to_little bstc_endian_rev_uint64
#  endif
# endif
#endif
/// }


#endif // BOOSTC__ENDIAN__SWAP_H
