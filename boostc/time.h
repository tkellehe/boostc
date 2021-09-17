//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__TIME_H
#define BOOSTC__TIME_H


#include <boostc/config.h>
#include <boostc/stddef.h>


#if defined(BSTC_OSAPI_POSIX)
# undef _FEATURES_H
# if !defined(_GNU_SOURCE)
#  define _GNU_SOURCE
# endif
# if !defined(_POSIX_C_SOURCE) || ((_POSIX_C_SOURCE - 0) < 199309L)
#  undef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif
# if !defined(_XOPEN_SOURCE) || ((_XOPEN_SOURCE - 0) < 500)
#  undef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 500
# endif
# define _XPG6
#endif


#ifdef __cplusplus
# include <ctime>
#else
# include <time.h>
#endif


#if defined(BSTC_OSAPI_POSIX) && defined(BSTC_PLATFORM_MACOS)
# include <sys/time.h>
#endif


#if defined(CLOCK_MONOTONIC) && !defined(bstc_clock_monotonic)
# define bstc_clock_monotonic CLOCK_MONOTONIC
#endif
#if defined(CLOCK_PROCESS_CPUTIME_ID) && !defined(bstc_clock_process_cputime_id)
# define bstc_clock_process_cputime_id CLOCK_PROCESS_CPUTIME_ID
#endif
#if defined(CLOCK_REALTIME) && !defined(bstc_clock_realtime)
# define bstc_clock_realtime CLOCK_REALTIME
#endif
#if defined(CLOCK_THREAD_CPUTIME_ID) && !defined(bstc_clock_thread_cputime_id)
# define bstc_clock_thread_cputime_id CLOCK_THREAD_CPUTIME_ID
#endif


#ifndef bstc_time_t
# define bstc_time_t time_t
#endif


#ifndef bstc_tm
# define bstc_tm tm
#endif


#ifndef bstc_clock_t
# define bstc_clock_t clock_t
#endif


#ifndef bstc_time_utc
# ifdef TIME_UTC
#  define bstc_time_utc TIME_UTC
# else
#  define bstc_time_utc 1
# endif
#endif


#ifndef bstc_timespec
# if defined(BSTC_OSAPI_WINDOWS) && !defined(TIME_UTC)
struct _bstc_timespec
{
    bstc_time_t tv_sec;
    long        tv_nsec;
};
#  define bstc_timespec _bstc_timespec
# else
#  define bstc_timespec timespec
# endif
#endif


#ifndef bstc_timespec_get
# ifndef TIME_UTC
#  ifdef BSTC_OSAPI_WINDOWS
    static bstc_inline int _bstc_timespec_get(struct bstc_timespec *ts, int base)
    {
        struct _timeb tb;

        if(base != bstc_time_utc) return 0;

        _ftime_s(&tb);
        ts->tv_sec = (bstc_time_t)tb.time;
        ts->tv_nsec = 1000000L * (long)tb.millitm;

        return base;
    }
#   define bstc_timespec_get _bstc_timespec_get
#  elif defined(BSTC_OSAPI_POSIX)
    static bstc_inline int _bstc_timespec_get(struct bstc_timespec *ts, int base)
    {
    #if !defined(bstc_clock_realtime)
        struct timeval tv;
    #endif

        if(base != bstc_time_utc) return 0;

    #if defined(bstc_clock_realtime)
        base = (clock_gettime(bstc_clock_realtime, ts) == 0) ? base : 0;
    #else
        gettimeofday(&tv, bstc_nullptr);
        ts->tv_sec = (bstc_time_t)tv.tv_sec;
        ts->tv_nsec = 1000L * (long)tv.tv_usec;
    #endif

      return base;
    }
#   define bstc_timespec_get _bstc_timespec_get
#  else
#   error "BOOSTC could not determine bstc_timespec_get."
#  endif
# else
#  define bstc_timespec_get timespec_get
# endif
#endif


#ifndef bstc_difftime
# define bstc_difftime difftime
#endif


#ifndef bstc_time
# define bstc_time time
#endif


#ifndef bstc_clock
# define bstc_clock clock
#endif


#ifndef bstc_asctime
# define bstc_asctime asctime
#endif


#ifndef bstc_ctime
# define bstc_ctime ctime
#endif


#ifndef bstc_strftime
# define bstc_strftime strftime
#endif


#ifndef bstc_gmtime
# define bstc_gmtime gmtime
#endif


#ifndef bstc_localtime
# define bstc_localtime localtime
#endif


#ifndef bstc_mktime
# define bstc_mktime mktime
#endif


#ifdef CLOCKS_PER_SEC
# ifndef bstc_clocks_per_sec
#  define bstc_clocks_per_sec CLOCKS_PER_SEC
# endif
#endif


#endif // BOOSTC__TIME_H
