//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CHRONO__HIGH_RESOLUTION_CLOCK_H
#define BOOSTC__CHRONO__HIGH_RESOLUTION_CLOCK_H


#include <boostc/chrono/duration.h>
#include <boostc/chrono/steady_clock.h>
#include <boostc/chrono/system_clock.h>
#include <boostc/config.h>


/// The duration type for the high-resolution clock.
/// Instead of having a time_point type, it was simpler to just have it be the same as the duration type.
/// \{
#ifndef bstc_chrono_hiresclk_dur
# ifdef bstc_chrono_stdyclk_dur
#  define bstc_chrono_hiresclk_dur bstc_chrono_stdyclk_dur
# else
#  define bstc_chrono_hiresclk_dur bstc_chrono_sysclk_dur
# endif
#endif


#ifndef bstc_chrono_hiresclk_dur_t
# ifdef bstc_chrono_stdyclk_dur_t
#  define bstc_chrono_hiresclk_dur_t bstc_chrono_stdyclk_dur_t
# else
#  define bstc_chrono_hiresclk_dur_t bstc_chrono_sysclk_dur_t
# endif
#endif


#ifndef bstc_chrono_hiresclk_dur_cnt
# ifdef bstc_chrono_stdyclk_dur_cnt
#  define bstc_chrono_hiresclk_dur_cnt bstc_chrono_stdyclk_dur_cnt
# else
#  define bstc_chrono_hiresclk_dur_cnt bstc_chrono_sysclk_dur_cnt
# endif
#endif
/// \}


/// A constant for indicating if the steady clock is steady.
/// \{
#ifndef bstc_chrono_hiresclk_isstdy
# ifdef bstc_chrono_stdyclk_isstdy
#  define bstc_chrono_hiresclk_isstdy bstc_chrono_stdyclk_isstdy
# else
#  define bstc_chrono_hiresclk_isstdy bstc_chrono_sysclk_isstdy
# endif
#endif
/// \}


/// Gets the current time.
/// 
/// \return Returns a high-resolution clock duration representing the current time.
/// \{
#ifndef bstc_chrono_hiresclk_now
# ifdef bstc_chrono_stdyclk_now
#  define bstc_chrono_hiresclk_now bstc_chrono_stdyclk_now
# else
#  define bstc_chrono_hiresclk_now bstc_chrono_sysclk_now
# endif
#endif
/// \}


#endif // BOOSTC__CHRONO__HIGH_RESOLUTION_CLOCK_H
