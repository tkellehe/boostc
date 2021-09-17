//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CHRONO__STEADY_CLOCK_H
#define BOOSTC__CHRONO__STEADY_CLOCK_H


#include <boostc/chrono/duration.h>
#include <boostc/config.h>
#include <boostc/stdbool.h>
#include <boostc/time.h>


#ifdef BSTC_OSAPI_WINDOWS
# include <windows.h>
#elif defined(BSTC_OSAPI_POSIX)
#endif


// If we do not have bstc_clock_monotonic, we cannot build the POSIX version.
#if !defined(BSTC_OSAPI_POSIX) || defined(bstc_clock_monotonic)

/// The duration type for the steady clock.
/// Instead of having a time_point type, it was simpler to just have it be the same as the duration type.
/// \{
#ifndef bstc_chrono_stdyclk_dur
# define bstc_chrono_stdyclk_dur bstc_chrono_ns
#endif


#ifndef bstc_chrono_stdyclk_dur_t
# define bstc_chrono_stdyclk_dur_t bstc_chrono_dur_t(bstc_chrono_ns)
#endif


#ifndef bstc_chrono_stdyclk_dur_cnt
# define bstc_chrono_stdyclk_dur_cnt(dur) bstc_chrono_dur_cnt(bstc_chrono_stdyclk_dur, dur)
#endif
/// \}


/// A constant for indicating if the steady clock is steady.
/// \{
#ifndef bstc_chrono_stdyclk_isstdy
# define bstc_chrono_stdyclk_isstdy bstc_true
#endif
/// \}


/// Gets the current steady time.
/// 
/// Logic pulled from:
///       boost/chrono/detail/inlined/mac/chrono.hpp (currently not implemented)
///       boost/chrono/detail/inlined/posix/chrono.hpp
///       boost/chrono/detail/inlined/win/chrono.hpp
/// 
/// \return Returns a steady clock duration representing the current time.
/// \{
#ifndef bstc_chrono_stdyclk_now
# ifdef BSTC_OSAPI_WINDOWS
static bstc_inline double _bstc_get_ns_per_tic()
{
    LARGE_INTEGER frequency;
    if(!QueryPerformanceFrequency(&frequency)) return 0.0L;
    return (double)(1000000000.0L / frequency.QuadPart);
}
# endif

static bstc_inline bstc_chrono_stdyclk_dur_t _bstc_chrono_stdyclk_now()
{
# ifdef BSTC_OSAPI_WINDOWS
    LARGE_INTEGER performance_counter;
    double ns_per_tic = _bstc_get_ns_per_tic();
    unsigned count = 0;

    if(ns_per_tic <= 0.0L)
    {
        return 0;
    }

    while(!QueryPerformanceCounter(&performance_counter))
    {
        if(++count > 3)
        {
            return 0;
        }
    }

    return (bstc_chrono_stdyclk_dur_t)((ns_per_tic) * performance_counter.QuadPart);

# elif defined(BSTC_OSAPI_POSIX)
    struct bstc_timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 0;
#  if defined(BSTC_PLATFORM_CYGWIN)
    // From Boost C++:
    //   lack of thread safety in high resolution timer initialization
    //   can lead to a timespec of zero without an error; was reported
    //   to the cygwin mailing list and can be removed once fixed
    do {
#  endif
        if(clock_gettime(bstc_clock_monotonic, &ts))
        {
            break;
        }
#  if defined(BSTC_PLATFORM_CYGWIN)
    } while(ts.tv_sec == 0 && ts.tv_nsec == 0);
#  endif
    return (((bstc_int_least64_t)ts.tv_sec) * 1000000000) + ((bstc_int_least64_t)(ts.tv_nsec));
# endif
}
# define bstc_chrono_stdyclk_now _bstc_chrono_stdyclk_now
#endif
/// \}


#endif // Has Steady Clock


#endif // BOOSTC__CHRONO__STEADY_CLOCK_H
