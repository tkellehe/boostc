![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/assert.h

Provides a polyfill of `assert.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_assert`

Standard and description overview can be found here: https://en.cppreference.com/w/c/error/assert

## `bstc_ndebug`

Defining this will also define `NDEBUG` (and vice versa), keeping `bstc_assert` aligned with the standard assert behavior.


## `bstc_assert_msg`

A convenience macro that asserts `(expr && msg)` so a string literal can be included with the expression.
