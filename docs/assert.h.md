![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/assert.h

Provides a polyfill of `assert.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_assert`

Standard and description overview can be found here: https://en.cppreference.com/w/c/error/assert

## `bstc_ndebug`

This can be defined instead of `NDEBUG` and it will ensure that the proper `bstc_assert` is set.
