![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/stdnoreturn.h

Provides a polyfill of `stdnoreturn.h` described below.
Note that the interface is setup as macros.
So, the interface can be checked if it could not be resolved.


## `bstc_noreturn`

Defined per the compiler and language support.
In C11 it prefers `_Noreturn`, and in C++11 it prefers `[[noreturn]]` when the `noreturn` macro is not defined.
Otherwise it falls back to compiler-specific attributes.
Standard and description overview can be found here: https://en.cppreference.com/w/c/language/_Noreturn

```c
#include <boostc/stdlib.h>
#include <boostc/stdnoreturn.h>

bstc_noreturn void stop_now(void)
{
    bstc_exit(bstc_exit_success);
}

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);

    stop_now();

    return bstc_exit_failure;
}
```
