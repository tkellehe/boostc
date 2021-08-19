//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CHRONO__DURATION_H
#define BOOSTC__CHRONO__DURATION_H


#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/ratio.h>
#include <boostc/stdint.h>


/** Constructs a compile time representation of the duration type.
 * \param rep An arithmetic type representing the number of ticks.
 * \param per A \c bstc_ratio representing the tick period (i.e. the number of seconds per tick).
 */
/// \{
#ifndef bstc_chrono_dur_traits
# if defined(BSTC_HAS_VARIADIC_MACROS)
#  define bstc_dtl_chrono_dur_traits_append2(...) bstc_dtl_chrono_dur_traits_wrap bstc_ctuple(__VA_ARGS__)
#  define bstc_dtl_chrono_dur_traits_append1(L, R) BSTC_EXPAND(bstc_dtl_chrono_dur_traits_append2(L, R))
#  define bstc_dtl_chrono_dur_traits_append(tpl) BSTC_EXPAND(bstc_dtl_chrono_dur_traits_append1(bstc_ctuple_layout tpl, bstc_ratio(1, 1)))
#  define bstc_dtl_chrono_dur_traits_no(tpl) bstc_dtl_chrono_dur_traits_wrap tpl
#  define bstc_dtl_chrono_dur_traits_select(tpl) bstc_ctuple_hasN(tpl, 2, bstc_dtl_chrono_dur_traits_no, bstc_dtl_chrono_dur_traits_append)
#  define bstc_dtl_chrono_dur_traits(tpl) bstc_dtl_chrono_dur_traits_select(tpl) (tpl)
#  define bstc_dtl_chrono_dur_traits_wrap(rep, per) BSTC_CTUPLE2(rep, per)
#  define bstc_chrono_dur_traits(...) bstc_dtl_chrono_dur_traits(bstc_ctuple(__VA_ARGS__))
# else
#  define bstc_chrono_dur_traits(rep, per) BSTC_CTUPLE2(rep, per)
# endif
#endif
/// \}


/** Get the type representing the duration object. */
/// \{
#ifndef bstc_chrono_dur_t
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_chrono_dur_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_chrono_dur_t(rep, per) rep
#  define bstc_chrono_dur_t(tpl) BSTC_EXPAND(bstc_dtl_chrono_dur_t tpl)
# endif
#endif
/// \}


/** Get the symbol stored as the representation. */
/// \{
#ifndef bstc_chrono_dur_rep
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_chrono_dur_rep(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_chrono_dur_rep(rep, per) rep
#  define bstc_chrono_dur_rep(tpl) BSTC_EXPAND(bstc_dtl_chrono_dur_t tpl)
# endif
#endif
/// \}


/** Get the symbol stored as the period. */
/// \{
#ifndef bstc_chrono_dur_per
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_chrono_dur_per(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
# else
#  define bstc_dtl_chrono_dur_per(rep, per) per
#  define bstc_chrono_dur_per(tpl) BSTC_EXPAND(bstc_dtl_chrono_dur_per tpl)
# endif
#endif
/// \}


/** Get the current count in the type specified. */
/// \{
#ifndef bstc_chrono_dur_cnt
# define bstc_chrono_dur_cnt(tpl, dur) dur
#endif
/// \}


/** Converts a duration type into a different duration type.
 * \param to_dur_tpl The duration type to convert to.
 * \param dur_tpl The current duration type provided.
 * \param dur The duration object to be converted.
 * \return Returns the duration ticks converted to the new duration type.
 */
/// \{
#ifndef bstc_chrono_dur_cast
# define bstc_chrono_dur_cast(to_dur_tpl, dur_tpl, dur) \
    ((bstc_chrono_dur_rep(to_dur_tpl))(\
        (\
            (dur) * \
            ((bstc_chrono_dur_rep(to_dur_tpl))((bstc_ratio_num(bstc_chrono_dur_per(dur_tpl))) * (bstc_ratio_den(bstc_chrono_dur_per(to_dur_tpl)))))\
        ) / \
        ((bstc_ratio_den(bstc_chrono_dur_per(dur_tpl))) * (bstc_ratio_num(bstc_chrono_dur_per(to_dur_tpl))))\
    ))
#endif
/// \}


/** Duration helper types.
 * Note: each of the predefined duration types up to hours covers a range of at least ±292 years. 
 * Each of the predefined duration types days, weeks, months and years covers a range of at least ±40000 years.
 * Years is equal to 365.2425 days (the average length of a Gregorian year).
 * Months is equal to 30.436875 days (exactly 1/12 of years).
 */
/// \{
#ifndef bstc_chrono_ns
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_nano)
#  define bstc_chrono_ns BSTC_CTUPLE2(bstc_int_least64_t, bstc_nano)
# endif
#endif


#ifndef bstc_chrono_us
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_micro)
#  define bstc_chrono_us BSTC_CTUPLE2(bstc_int_least64_t, bstc_micro)
# endif
#endif


#ifndef bstc_chrono_ms
# if bstc_intmax_max >= bstc_int16_max && defined(bstc_milli)
#  define bstc_chrono_ms BSTC_CTUPLE2(bstc_int_least64_t, bstc_milli)
# endif
#endif


#ifndef bstc_chrono_sec
# if defined(bstc_int_least64_t)
#  define bstc_chrono_sec BSTC_CTUPLE2(bstc_int_least64_t, BSTC_CTUPLE2(bstc_ratio_c(1), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_min
# if defined(bstc_int_least32_t)
#  define bstc_chrono_min BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(60), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_hrs
# if defined(bstc_int_least32_t)
#  define bstc_chrono_hrs BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(3600), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_days
# if defined(bstc_int_least32_t)
#  define bstc_chrono_days BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(86400), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_weeks
# if defined(bstc_int_least32_t)
#  define bstc_chrono_weeks BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(604800), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_months
# if defined(bstc_int_least32_t)
#  define bstc_chrono_months BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(2629746), bstc_ratio_c(1)))
# endif
#endif


#ifndef bstc_chrono_years
# if defined(bstc_int_least32_t)
#  define bstc_chrono_years BSTC_CTUPLE2(bstc_int_least32_t, BSTC_CTUPLE2(bstc_ratio_c(31556952), bstc_ratio_c(1)))
# endif
#endif
/// \}


/** Convenience types for the duration helpers. */
/// \{
#ifndef bstc_chrono_ns_t
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_nano)
#  define bstc_chrono_ns_t bstc_chrono_dur_t(bstc_chrono_ns)
# endif
#endif


#ifndef bstc_chrono_us_t
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_micro)
#  define bstc_chrono_us_t bstc_chrono_dur_t(bstc_chrono_us)
# endif
#endif


#ifndef bstc_chrono_ms_t
# if bstc_intmax_max >= bstc_int16_max && defined(bstc_milli)
#  define bstc_chrono_ms_t bstc_chrono_dur_t(bstc_chrono_ms)
# endif
#endif


#ifndef bstc_chrono_sec_t
# if defined(bstc_int_least64_t)
#  define bstc_chrono_sec_t bstc_chrono_dur_t(bstc_chrono_sec)
# endif
#endif


#ifndef bstc_chrono_min_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_min_t bstc_chrono_dur_t(bstc_chrono_min)
# endif
#endif


#ifndef bstc_chrono_hrs_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_hrs_t bstc_chrono_dur_t(bstc_chrono_hrs)
# endif
#endif


#ifndef bstc_chrono_days_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_days_t bstc_chrono_dur_t(bstc_chrono_days)
# endif
#endif


#ifndef bstc_chrono_weeks_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_weeks_t bstc_chrono_dur_t(bstc_chrono_weeks)
# endif
#endif


#ifndef bstc_chrono_months_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_months_t bstc_chrono_dur_t(bstc_chrono_months)
# endif
#endif


#ifndef bstc_chrono_years_t
# if defined(bstc_int_least32_t)
#  define bstc_chrono_years_t bstc_chrono_dur_t(bstc_chrono_years)
# endif
#endif
/// \}


/** Convenience function to get the count for the duration helpers. */
/// \{
#ifndef bstc_chrono_ns_cnt
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_nano)
#  define bstc_chrono_ns_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_ns, dur)
# endif
#endif


#ifndef bstc_chrono_us_cnt
# if bstc_intmax_max >= bstc_int32_max && defined(bstc_micro)
#  define bstc_chrono_us_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_us, dur)
# endif
#endif


#ifndef bstc_chrono_ms_cnt
# if bstc_intmax_max >= bstc_int16_max && defined(bstc_milli)
#  define bstc_chrono_ms_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_ms, dur)
# endif
#endif


#ifndef bstc_chrono_sec_cnt
# if defined(bstc_int_least64_t)
#  define bstc_chrono_sec_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_sec, dur)
# endif
#endif


#ifndef bstc_chrono_min_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_min_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_min, dur)
# endif
#endif


#ifndef bstc_chrono_hrs_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_hrs_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_hrs, dur)
# endif
#endif


#ifndef bstc_chrono_days_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_days_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_days, dur)
# endif
#endif


#ifndef bstc_chrono_weeks_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_weeks_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_weeks, dur)
# endif
#endif


#ifndef bstc_chrono_months_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_months_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_months, dur)
# endif
#endif


#ifndef bstc_chrono_years_cnt
# if defined(bstc_int_least32_t)
#  define bstc_chrono_years_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_years, dur)
# endif
#endif
/// \}


#endif // BOOSTC__CHRONO__DURATION_H
