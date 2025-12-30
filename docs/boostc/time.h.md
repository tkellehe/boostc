![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/time.h

Provides a polyfill of `time.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_difftime`

Computes the difference between times: https://en.cppreference.com/w/c/chrono/difftime

## `bstc_time`

Returns the current calendar time of the system as time since epoch: https://en.cppreference.com/w/c/chrono/time

## `bstc_clock`

Returns raw processor clock time since the program is started: https://en.cppreference.com/w/c/chrono/clock

## `bstc_time_utc`

Time base constant for `bstc_timespec_get` (maps to `TIME_UTC` when available).

## `bstc_timespec_get`

Returns the calendar time based on a given time base: https://en.cppreference.com/w/c/chrono/timespec_get

 > A polyfill implementation is provided where `bstc_time_utc` is also ensured.

## `bstc_clock_monotonic`

POSIX clock id exposed when `CLOCK_MONOTONIC` is available.

## `bstc_clock_process_cputime_id`

POSIX clock id exposed when `CLOCK_PROCESS_CPUTIME_ID` is available.

## `bstc_clock_realtime`

POSIX clock id exposed when `CLOCK_REALTIME` is available.

## `bstc_clock_thread_cputime_id`

POSIX clock id exposed when `CLOCK_THREAD_CPUTIME_ID` is available.

## `bstc_asctime`

Converts a tm object to a textual representation: https://en.cppreference.com/w/c/chrono/asctime

## `bstc_ctime`

Converts a time_t object to a textual representation: https://en.cppreference.com/w/c/chrono/ctime

## `bstc_strftime`

Converts a tm object to custom textual representation: https://en.cppreference.com/w/c/chrono/strftime

## `bstc_gmtime`

Converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC): https://en.cppreference.com/w/c/chrono/gmtime

## `bstc_localtime`

Converts time since epoch to calendar time expressed as local time: https://en.cppreference.com/w/c/chrono/localtime

## `bstc_mktime`

Converts calendar time to time since epoch: https://en.cppreference.com/w/c/chrono/mktime

## `bstc_clocks_per_sec`

Number of processor clock ticks per second: https://en.cppreference.com/w/c/chrono/CLOCKS_PER_SEC

## `bstc_tm`

Calendar time type: https://en.cppreference.com/w/c/chrono/tm

## `bstc_time_t`

Calendar time since epoch type: https://en.cppreference.com/w/c/chrono/time_t

## `bstc_clock_t`

Processor time since era type: https://en.cppreference.com/w/c/chrono/clock_t

## `bstc_timespec`

Time in seconds and nanoseconds: https://en.cppreference.com/w/c/chrono/timespec

 > A polyfill is provided along with the `bstc_timespec_get` function.
