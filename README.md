# bst
 Boost C++ like library for C.

## Why Make This?
I had began to write my own variation of Boost C++ to get better at C++.
I was able to write a lot of parts that competed well with Boost, but overall useless.
Therein, I began to wonder if I could take this and get it into a C library.

So, this library is my attempt to make a C version without copying Boost C++ directly for my own learning experience.

# Components
 * [allocator](#allocator)
 * [assert](#assert)
 * [config](#config)
 * [errno](#errno)
 * [ppack](#ppack)
 * [stdint](#stdint)
 * [vector](#vector)

## Interface Namespaces


# allocator
Provides compile time decisions for creating allocators.
The allocator paradigm is that only the functions `free`, `malloc`, and `realloc` are needed.
Each they are then [parameter packed](#ppack) into a single symbol that can be passed to types that require an allocator.
This allows for the code desired for allocators to be inlined into the functions that use them.

```c
#include <bst/allocator.h>

// A helper is provided to reference the ppack of the stdlib calls.
#define stdlib alloc_stdlib

// The actual implemenation of the mk_array function. Need the variadic portion to make the other parts easier.
#define mk_array_dtl(T, N, free, malloc, realloc, ...) (T*)malloc(sizeof(T) * N)
// Unpacks the parameters to call the actual implementation.
#define mk_array_dtl_pkd(pkd) mk_array_dtl pkd
// Optional allocator operation where default uses stdlib.
#define mk_array(T, N, ...) \
    mk_array_dtl_pkd(\
        /* Build up the ppack to be decompressed. */\
        bst_ppack_prepend(\
            /* Select the default argument if nothing is provided. */\
            BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), T, N\
        )\
    )

#define rm_array_dtl(array, free, malloc, realloc, ...) free((void*)(array))
#define rm_array_dtl_pkd(pkd) rm_array_dtl pkd
#define rm_array(array, ...) rm_array_dtl_pkd(bst_ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), array))

int _pos = 0;
char _memory[1024] = {0,};
void* mymalloc(int size) { int pos = _pos; _pos += size; return (void*)(_memory + pos); }

// The allocator interface provides calls to be able to ensure that the std order is always packed correctly.
// Also, the default free and realloc calls are set to do-nothings.
#define myalloc alloc_pack_m(mymalloc)

int main()
{
    {
        // Use the stdlib memory management calls.
        int* array = mk_array(int, 10);
        rm_array(array);
    }
    {
        // Use the user defined memory management calls.
        int* array = mk_array(int, 10, myalloc);
        rm_array(array, myalloc);
    }
    return 0;
}
```

# config
Provides compile time decisions to create macros based on the platform and compiler.

```c
#include <bst/config.h>
```

# errno
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

# stdint
Provides the compile time decisions to ensure the `stdint.h` types and macros are provided.
This currently uses `pstdint.h` which can be found [here](http://www.azillionmonkeys.com/qed/pstdint.h).
I have created my own variant prior to finding this one, but `pstdint.h` provides a full implementation of what the std specifies.

```c
#include <bst/stdint.h>
```
