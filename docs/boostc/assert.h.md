![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/assert.h

Provides a polyfill of `assert.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_assert`

Standard and description overview can be found here: https://en.cppreference.com/w/c/error/assert

## `bstc_static_assert`

Compile-time assertion that maps to `static_assert` in C++11 or `_Static_assert` in C11.
Falls back to a typedef-based check on older standards.

## `bstc_ndebug`

Defining this will also define `NDEBUG` (and vice versa), keeping `bstc_assert` aligned with the standard assert behavior.


## `bstc_assert_msg`

Uses the common C idiom `bstc_assert((expr) && (msg))` so a string literal can appear in assertion output.
