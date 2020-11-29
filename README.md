# bst
 Boost C++ like library for C.

## Why Make This?
I had began to write my own variation of Boost C++ to get better at C++. I was able to write a lot of parts that competed well with Boost, but overall useless. Therein, I began to wonder if I could take this and get it into a C library.

So, this library is my attempt to make a C version without copying Boost C++ directly for my own learning experience.

# Components

## config
Provides compile time decisions to create macros based on the platform and compiler.

```c
#include <bst/config.h>
```

## errno
Provides compile time decisions to add missing `errno` values and some `errno` functions.

```c
#include <bst/errno.h>

int main()
{
    // Get the errno value guranteed to be best for the platform/compiler.
    int val = get_errno();
    // Can also read the value which is best for the std, but not best for the platform/compiler.
    val = errno;
    // Set the errno value guranteed to be best for the platform/compiler.
    set_errno(val);
    // Can also write the value which is best for the std, but not best for the platform/compiler.
    errno = val;
    return 0;
}
```

## stdint
Provides the compile time decisions to ensure the `stdint.h` types and macros are provided. This currently uses `pstdint.h` which can be found [here](http://www.azillionmonkeys.com/qed/pstdint.h). I have created my own variant prior to finding this one, but `pstdint.h` provides a full implementation of what the std specifies.

```c
#include <bst/stdint.h>
```