![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/signal.h

Provides a polyfill of `signal.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.

## `bstc_signal`

Installs a signal handler: https://en.cppreference.com/w/c/program/signal

## `bstc_raise`

Raises a signal: https://en.cppreference.com/w/c/program/raise

## `bstc_sig_atomic_t`

Integer type that can be accessed as an atomic entity from a signal handler: https://en.cppreference.com/w/c/program/sig_atomic_t

## `bstc_sig_dfl`

Default signal handling: https://en.cppreference.com/w/c/program/signal

## `bstc_sig_ign`

Ignore signal handling: https://en.cppreference.com/w/c/program/signal

## `bstc_sig_err`

Signal handler error value: https://en.cppreference.com/w/c/program/signal

## `bstc_sigabrt`

Abnormal termination signal: https://en.cppreference.com/w/c/program/SIGABRT

## `bstc_sigfpe`

Floating-point exception signal: https://en.cppreference.com/w/c/program/SIGFPE

## `bstc_sigill`

Illegal instruction signal: https://en.cppreference.com/w/c/program/SIGILL

## `bstc_sigint`

Interrupt signal: https://en.cppreference.com/w/c/program/SIGINT

## `bstc_sigsegv`

Invalid memory access signal: https://en.cppreference.com/w/c/program/SIGSEGV

## `bstc_sigterm`

Termination request signal: https://en.cppreference.com/w/c/program/SIGTERM
