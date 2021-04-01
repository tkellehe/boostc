![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/errno.h

Provides a polyfill of `errno.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_errno`

Standard and description overview can be found here: https://en.cppreference.com/w/c/error/errno

## `EDOM`, `EILSEQ`, `ERANGE`, ...

The _errno_ values are not placed into the `bstc_` namespace.
This is because there are a lot of these and ensuring they are all there under that namespace (at this time) appears too large of a task.
Instead, _boostc_ provides the common missing error values defined with some default value.
These are all defined as macro constants.
Standard and description overview can be found here: https://en.cppreference.com/w/c/error/errno_macros

## `bstc_get_errno()`

On some systems, there are special _get_ and _set_ operations that are not connected to `errno`.
To support these, _boostc_ provides a macro function that calls to the underlying error function that is best for that system.
The `bstc_get_errno` function inserts code that gets the error on that system.
To ensure consistency, this call should be paired with `bstc_set_errno`.

## `bstc_set_errno(error)`

On some systems, there are special _get_ and _set_ operations that are not connected to `errno`.
To support these, _boostc_ provides a macro function that calls to the underlying error function that is best for that system.
The `bstc_set_errno` function inserts code that sets the error on that system.
To ensure consistency, this call should be paired with `bstc_get_errno`.
