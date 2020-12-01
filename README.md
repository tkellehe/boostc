# bst
 Boost C++ like library for C.

## Why Make This?
I had began to write my own variation of _Boost C++_ to get better at _C++_.
I was able to write a lot of parts that competed well with Boost, but overall useless.
Therein, I began to wonder if I could take this and get it into a _C_ library.

So, this library is my attempt to make a _C_ version without copying _Boost C++_ directly for my own learning experience.

# Components
 * [allocator](#allocator)
 * [assert](#assert)
 * [config](#config)
 * [errno](#errno)
 * [ppack](#ppack)
 * [stdint](#stdint)
 * [vector](#vector)

## Interface Namespaces

## Compile Time Requirement

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
        ppack_prepend(\
            /* Select the default argument if nothing is provided. */\
            BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), T, N\
        )\
    )

#define rm_array_dtl(array, free, malloc, realloc, ...) free((void*)(array))
#define rm_array_dtl_pkd(pkd) rm_array_dtl pkd
#define rm_array(array, ...) rm_array_dtl_pkd(ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), array))

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
        // This evaluates to a do-nothing statement.
        rm_array(array, myalloc);
    }
    return 0;
}
```

# assert
Provides the std `assert` call.

```c
#include <bst/assert.h>

int main()
{
    int x = 100;
    assert(x < 100);
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

# ppack
Provides compile time decisions to create _parameter packed_ macros.
Parameter packing is the idea of taking parameters and describing them as a single compile time symbol.
This is done by placing parantheses around the parameters (ie `(1, 'a', var)`).
Then using macros to apply operations to these parameter packs.

```c
#include <bst/ppack.h>
#include <stdio.h>

// The actual final call made.
#define prints5(a, b, c, d, e, ...) printf("%i %i %i %i %i\n", a, b, c, d, e)
// This unpacks the ppack provided.
#define prints_pkd(pkd) prints5 pkd
// Takes in an optional parameter pack of integers and prepends a value.
#define prints(...) prints_pkd(ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, (1, 2, 3, 4)), 0))

int main()
{
    prints();
    prints(4, 3, 2, 1);
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

# vector
Provides compile time decisions to create a _C++_ like vector in _C_.

```c
#include <bst/allocator.h>
#include <bst/vector.h>
#include <stdio.h>

int main()
{
    // It is recommended to do as `typedef vector_t(int) myvect_t` because there is no guarantee that `vector_t(int) == vector_t(int)`.
    // This problem is more relavant when the underlying structure is a more complex data structure.
    vector_t(int) vect;
    
    vect_init(vect);
    // Default is to use stdlib allocator.
    vect_push(vect, 11);
    vect_push(vect, 12);
    vect_destroy(vect);
    
    // Can specify own allocator and create macro.
    #define vect_int_push(vect, val) vect_push(vect, val, alloc_stdlib)
    
    // Initialize call is not needed since the destroy leaves the vector in a good state.
    // Just have it as good practice.
    vect_init(vect);
    vect_int_push(vect, 101);
    vect_int_push(vect, 102);
    
    // Can use basic array operator on the data.
    vect[0] += 10;
    
    // Can loop over the contents.
    {
        int i;
        for(i = 0; i < vect_cnt(vect); ++i) printf("%i\n", vect[i]);
    }
    
    // Make sure that all calls that can take an allocator have the same allocator.
    vect_destroy(vect, alloc_stdlib);
    
    return 0;
}
```
