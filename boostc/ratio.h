//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__RATIO_H
#define BOOSTC__RATIO_H


#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stdint.h>


/** Declares the ratio tuple.
 * \param numerator The numerator for the constant ratio.
 * \param denominator The denominator for the constant ratio.
 */
/// \{
#ifndef bstc_ratio
# if defined(BSTC_HAS_VARIADIC_MACROS)
#  define bstc_dtl_ratio_append2(...) bstc_dtl_ratio_wrap bstc_ctuple(__VA_ARGS__)
#  define bstc_dtl_ratio_append1(L, R) BSTC_EXPAND(bstc_dtl_ratio_append2(L, R))
#  define bstc_dtl_ratio_append(tpl) BSTC_EXPAND(bstc_dtl_ratio_append1(bstc_ctuple_layout tpl, 1))
#  define bstc_dtl_ratio_no(tpl) bstc_dtl_ratio_wrap tpl
#  define bstc_dtl_ratio_select(tpl) bstc_ctuple_hasN(tpl, 2, bstc_dtl_ratio_no, bstc_dtl_ratio_append)
#  define bstc_dtl_ratio(tpl) bstc_dtl_ratio_select(tpl) (tpl)
#  define bstc_dtl_ratio_wrap(numerator, denominator) BSTC_CTUPLE2(bstc_ratio_c(numerator), bstc_ratio_c(denominator))
#  define bstc_ratio(...) bstc_dtl_ratio(bstc_ctuple(__VA_ARGS__))
# else
#  define bstc_ratio(numerator, denominator) BSTC_CTUPLE2(bstc_ratio_c(numerator), bstc_ratio_c(denominator))
# endif
#endif
/// \}


/** Declares a constant into the proper integer type. */
/// \{
#ifndef bstc_ratio_c
# define bstc_ratio_c(N) (bstc_intmax_c(N))
#endif
/// \}


/** The integer type for ratio numerator and denominator. */
/// \{
#ifndef bstc_ratio_t
# define bstc_ratio_t bstc_intmax_t
#endif
/// \}


/** A macro string for encoding a ratio numerator or denominator into a string. */
/// \{
#ifndef bstc_priratio
# define bstc_priratio bstc_priimax
#endif
/// \}


/** Access the numerator or denominator at compile time. */
/// \{
#ifndef bstc_ratio_num
# define bstc_dtl_ratio_num(num, den) num
# define bstc_ratio_num(ratio) BSTC_EXPAND(bstc_dtl_ratio_num ratio)
#endif
#ifndef bstc_ratio_den
# define bstc_dtl_ratio_den(num, den) den
# define bstc_ratio_den(ratio) BSTC_EXPAND(bstc_dtl_ratio_den ratio)
#endif
/// \}


/** Arithmetic operations at compile time. */
/// \{
#ifndef bstc_ratio_mul
# define bstc_ratio_mul(r1, r2) BSTC_CTUPLE2(((bstc_ratio_num(r1)) * (bstc_ratio_num(r2))), ((bstc_ratio_den(r1)) * (bstc_ratio_den(r2))))
#endif
#ifndef bstc_ratio_div
# define bstc_ratio_div(r1, r2) BSTC_CTUPLE2(((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))), ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_add
# define bstc_ratio_add(r1, r2) BSTC_CTUPLE2(((bstc_ratio_num(r1)) * (bstc_ratio_den(r2)) + ((bstc_ratio_num(r2)) * (bstc_ratio_den(r1)))), ((bstc_ratio_den(r1)) * (bstc_ratio_den(r2))))
#endif
#ifndef bstc_ratio_sub
# define bstc_ratio_sub(r1, r2) BSTC_CTUPLE2(((bstc_ratio_num(r1)) * (bstc_ratio_den(r2)) - ((bstc_ratio_num(r2)) * (bstc_ratio_den(r1)))), ((bstc_ratio_den(r1)) * (bstc_ratio_den(r2))))
#endif
/// \}


/** Comparison operations at compile time. */
/// \{
#ifndef bstc_ratio_eq
# define bstc_ratio_eq(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) == ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_neq
# define bstc_ratio_neq(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) != ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_lt
# define bstc_ratio_lt(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) < ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_lte
# define bstc_ratio_lte(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) <= ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_gt
# define bstc_ratio_gt(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) > ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
#ifndef bstc_ratio_gte
# define bstc_ratio_gte(r1, r2) (((bstc_ratio_num(r1)) * (bstc_ratio_den(r2))) >= ((bstc_ratio_den(r1)) * (bstc_ratio_num(r2))))
#endif
/// \}


/** Constant ratio values. */
/// \{
#ifndef bstc_nano
# if bstc_intmax_max >= bstc_uint32_max
#  define bstc_nano BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(1000000000))
# endif
#endif


#ifndef bstc_micro
# if bstc_intmax_max >= bstc_uint32_max
#  define bstc_micro BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(1000000))
# endif
#endif


#ifndef bstc_milli
# if bstc_intmax_max >= bstc_uint16_max
#  define bstc_milli BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(1000))
# endif
#endif


#ifndef bstc_centi
# if bstc_intmax_max >= bstc_uint8_max
#  define bstc_centi BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(100))
# endif
#endif

#ifndef bstc_deci
# if bstc_intmax_max >= bstc_uint8_max
#  define bstc_deci BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(10))
# endif
#endif


#ifndef bstc_deca
# if bstc_intmax_max >= bstc_uint8_max
#  define bstc_deca BSTC_CTUPLE2(bstc_ratio_c(10), bstc_ratio_c(1))
# endif
#endif


#ifndef bstc_hecto
# if bstc_intmax_max >= bstc_uint8_max
#  define bstc_hecto BSTC_CTUPLE2(bstc_ratio_c(100), bstc_ratio_c(1))
# endif
#endif


#ifndef bstc_killo
# if bstc_intmax_max >= bstc_uint16_max
#  define bstc_killo BSTC_CTUPLE2(bstc_ratio_c(1000), bstc_ratio_c(1))
# endif
#endif


#ifndef bstc_mega
# if bstc_intmax_max >= bstc_uint32_max
#  define bstc_mega BSTC_CTUPLE2(bstc_ratio_c(1000000), bstc_ratio_c(1))
# endif
#endif


#ifndef bstc_giga
# if bstc_intmax_max >= bstc_uint32_max
#  define bstc_giga BSTC_CTUPLE2(bstc_ratio_c(1000000000), bstc_ratio_c(1))
# endif
#endif
/// \}


/** Reduce the ratio such that it is a fully reduced fraction. */
/// \{
#ifndef bstc_ratio_reduce
# define bstc_ratio_reduce(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce2) && defined(BSTC_GCD_X2)
# define bstc_ratio_reduce2(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X2(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X2(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce4) && defined(BSTC_GCD_X4)
# define bstc_ratio_reduce4(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X4(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X4(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce6) && defined(BSTC_GCD_X6)
# define bstc_ratio_reduce6(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X6(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X6(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce8) && defined(BSTC_GCD_X8)
# define bstc_ratio_reduce8(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X8(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X8(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce10) && defined(BSTC_GCD_X10)
# define bstc_ratio_reduce10(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X10(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X10(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce12) && defined(BSTC_GCD_X12)
# define bstc_ratio_reduce12(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X12(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X12(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce14) && defined(BSTC_GCD_X14)
# define bstc_ratio_reduce14(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X14(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X14(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
#if !defined(bstc_ratio_reduce16) && defined(BSTC_GCD_X16)
# define bstc_ratio_reduce16(r) BSTC_CTUPLE2((bstc_ratio_num(r) / BSTC_GCD_X16(bstc_ratio_num(r), bstc_ratio_den(r))), (bstc_ratio_den(r) / BSTC_GCD_X16(bstc_ratio_num(r), bstc_ratio_den(r))))
#endif
/// \}


#endif // BOOSTC__RATIO_H
