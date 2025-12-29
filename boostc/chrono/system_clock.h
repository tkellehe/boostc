//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CHRONO__SYSTEM_CLOCK_H
#define BOOSTC__CHRONO__SYSTEM_CLOCK_H


#include <boostc/chrono/duration.h>
#include <boostc/config.h>
#include <boostc/stdbool.h>
#include <boostc/time.h>


/// The duration type for the system clock.
/// Instead of having a time_point type, it was simpler to just have it be the same as the duration type.
/// \{
#ifndef bstc_chrono_sysclk_dur
# define bstc_chrono_sysclk_dur bstc_chrono_ns
#endif


#ifndef bstc_chrono_sysclk_dur_t
# define bstc_chrono_sysclk_dur_t bstc_chrono_dur_t(bstc_chrono_ns)
#endif


#ifndef bstc_chrono_sysclk_dur_cnt
# define bstc_chrono_sysclk_dur_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_sysclk_dur, dur)
#endif
/// \}


/// A constant for indicating if the system clock is steady.
/// \{
#ifndef bstc_chrono_sysclk_isstdy
# define bstc_chrono_sysclk_isstdy bstc_false
#endif
/// \}


/// Converts a system clock duration to a \c time_t.
/// 
/// \param dur The system clock duration to be converted.
/// \return Returns the \c time_t representing the system clock duration.
/// \{
#ifndef bstc_chrono_sysclk_to_time_t
static bstc_inline bstc_time_t _bstc_chrono_sysclk_to_time_t(bstc_chrono_sysclk_dur_t dur)
{
# ifdef BSTC_OSAPI_WINDOWS
    __int64 temp = (__int64)bstc_chrono_sysclk_dur_cnt(dur);
    temp /= 1000000000;
    return (bstc_time_t)temp;
# elif defined BSTC_OSAPI_POSIX
    return (bstc_time_t)(bstc_chrono_sysclk_dur_cnt(dur) / 1000000000);
# endif
}
# define bstc_chrono_sysclk_to_time_t _bstc_chrono_sysclk_to_time_t
#endif
/// \}


/// Converts a \c time_t to a system clock duration.
/// 
/// \param tt The \c time_t to be converted.
/// \return Returns the system clock duration representing the \c time_t.
/// \{
#ifndef bstc_chrono_sysclk_from_time_t
static bstc_inline bstc_chrono_sysclk_dur_t _bstc_chrono_sysclk_from_time_t(bstc_time_t tt)
{
# ifdef BSTC_OSAPI_WINDOWS
    return (bstc_chrono_sysclk_dur_t)(((__int64)tt) * 1000000000);
# elif defined BSTC_OSAPI_POSIX
    return ((bstc_chrono_sysclk_dur_t)tt) * 1000000000;
# endif
}
# define bstc_chrono_sysclk_from_time_t _bstc_chrono_sysclk_from_time_t
#endif
/// \}


/// Gets the current system time.
/// 
/// \return Returns a system clock duration representing the current time.
/// \{
#ifndef bstc_chrono_sysclk_now
static bstc_inline bstc_chrono_sysclk_dur_t _bstc_chrono_sysclk_now(void)
{
# if defined(BSTC_OSAPI_WINDOWS) || (defined(BSTC_OSAPI_POSIX) && !defined(BSTC_PLATFORM_MACOS))
    struct bstc_timespec ts;
    bstc_timespec_get(&ts, bstc_time_utc);
    return ((bstc_int_least64_t)ts.tv_sec) * 1000000000 + (bstc_int_least64_t)ts.tv_nsec;
# else
    timeval tv;
    gettimeofday(&tv, 0);
    return (((bstc_int_least64_t)tv.tv_sec) * 1000000000) + ((bstc_int_least64_t)(tv.tv_usec) * 1000);
# endif
}
# define bstc_chrono_sysclk_now _bstc_chrono_sysclk_now
#endif
/// \}


#endif // BOOSTC__CHRONO__SYSTEM_CLOCK_H
