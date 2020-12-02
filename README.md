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

### Interface Namespaces
The current interface is to prefix everything with `bst_`.
Also, to provide an interface without this prefix.
This may cause problems in your library if you have something with a similar name.
To avoid this, you can define `BST_NAMESPACE_ONLY` and it will remove the other non-stdc intefaces without the `bst_`.

### Compile Time Requirement
Currently, the goal is to write all of the library as compile time insertions of the code.
This allows more flexibility and makes it closer to _Boost C++_.
Another benfit is that you do not need to build this library.

### Insertion Code Bloat
Since most interfaces are inlined code, this can cause binaries to be quite large.
A simple solution is to instantiate your own function calling the inlining _bst_ functions.
Then the compiler will treat it as a function and potentially reducing the size of binaries.

# allocator
Provides compile time decisions for creating allocators.
The allocator paradigm is that only the functions `free`, `malloc`, and `realloc` are needed.
Each are then [parameter packed](#ppack) into a single symbol that can be passed to types that require an allocator.
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
void *mymalloc(int size) { int pos = _pos; _pos += size; return (void*)(_memory + pos); }

// The allocator interface provides calls to be able to ensure that the std order is always packed correctly.
// Also, the default free and realloc calls are set to do-nothings.
#define myalloc alloc_ppack_malloc(mymalloc)

int main()
{
    {
        // Use the stdlib memory management calls.
        int *array = mk_array(int, 10);
        rm_array(array);
    }
    {
        // Use the user defined memory management calls.
        int *array = mk_array(int, 10, myalloc);
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
#define myprints5(a, b, c, d, e, ...) printf("%i %i %i %i %i\n", a, b, c, d, e)
// This unpacks the ppack provided.
#define myprints_pkd(pkd) myprints5 pkd
// Takes in an optional list of integers and prepends a value.
#define myprints(...) myprints_pkd(ppack_prepend(ppack(BST_X1ARGS4(0, ##__VA_ARGS__, 1, 2, 3, 4)), 0))

int main()
{
    myprints();
    myprints(1);
    myprints(2, 1);
    myprints(3, 2, 1);
    myprints(4, 3, 2, 1);
    myprints(5, 4, 3, 2, 1);

    #define mypkd ppack('a', 'b', 'c', 'd')

    // Can get sizes of ppacks.
    printf("mypkd size = %i\n", ppack_size(mypkd));

    // Can get constant access to ppacks.
    printf("mypkd[0] = %c\n", ppack_argI(mypkd, 0));
    printf("mypkd[1] = %c\n", ppack_argI(mypkd, 1));
    printf("mypkd[2] = %c\n", ppack_argI(mypkd, 2));
    printf("mypkd[3] = %c\n", ppack_argI(mypkd, 3));

    // Can get reverse ppacks.
    #define rmypkd ppack_reverse(mypkd)
    printf("rmypkd[0] = %c\n", ppack_argI(rmypkd, 0));
    printf("rmypkd[1] = %c\n", ppack_argI(rmypkd, 1));
    printf("rmypkd[2] = %c\n", ppack_argI(rmypkd, 2));
    printf("rmypkd[3] = %c\n", ppack_argI(rmypkd, 3));
    printf("rmypkd size = %i\n", ppack_size(rmypkd));

    // Can get trim ppacks.
    #define ltmypkd ppack_ltrim(mypkd, 2)
    printf("ltmypkd[0] = %c\n", ppack_argI(ltmypkd, 0));
    printf("ltmypkd[1] = %c\n", ppack_argI(ltmypkd, 1));
    printf("ltmypkd size = %i\n", ppack_size(ltmypkd));
    #define rtmypkd ppack_rtrim(mypkd, 2)
    printf("rtmypkd[0] = %c\n", ppack_argI(rtmypkd, 0));
    printf("rtmypkd[1] = %c\n", ppack_argI(rtmypkd, 1));
    printf("rtmypkd size = %i\n", ppack_size(rtmypkd));
    
    // Can fill with default values by position.
    #define dmypkd ppack_defaults(rtmypkd, ('x', 'y', 'e', 'f'))
    printf("dmypkd[0] = %c\n", ppack_argI(dmypkd, 0));
    printf("dmypkd[1] = %c\n", ppack_argI(dmypkd, 1));
    printf("dmypkd[2] = %c\n", ppack_argI(dmypkd, 2));
    printf("dmypkd[3] = %c\n", ppack_argI(dmypkd, 3));
    printf("dmypkd size = %i\n", ppack_size(dmypkd));

    // Can create if-statements and check if has minimum size.
    printf("mypkd %s\n", ppack_if(ppack_ltrim(mypkd, 4), "size < 5", "size > 4"));
    printf("mypkd %s\n", ppack_if(ppack_ltrim(mypkd, 2), "size < 3", "size > 2"));

    // Define symbols in a ppack to be called.
    #define myf0() a
    #define myf1(a) a
    #define myf2(a, b) a + b
    #define mypkdf ppack(myf0, myf1, myf2)

    #define params ppack(100, 101)

    printf(
        "invoke %s = %i\n",
        BST_TOSTRING(ppack_argI(mypkdf, ppack_size(params))),
        ppack_call(ppack_argI(mypkdf, ppack_size(params)), params)
    );

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
Provides compile time decisions to create a _C++_ like vector in _C_. Uses the [template](#template) interface.

```c
#include <bst/allocator.h>
#include <bst/vector.h>
#include <stdio.h>

int main()
{
    // Note: It is recommended to do as typedef because there is no guarantee that the types will be the same.
    //       This problem is more relavant when the underlying structure is a more complex data structure.
    //       Also, it is recommended to define a macro of the template for similar reasons.

    // Define a macro of the template type.
    #define vect_tmplt_int_t vect_tmplt_t(int)

    // Declare a vector by accessing the type from the template.
    vect_t(vect_tmplt_int_t) vect;
    
    vect_init(vect);
    // Default is to use stdlib allocator.
    vect_push(vect, 11);
    // Can explicitly provide the template type to ensure using the same allocator and types.
    vect_push(vect, 12, vect_tmplt_int_t);
    
    // Can use basic array operator on the data.
    vect[0] += 10;
    
    // Can loop over the contents.
    {
        int i;
        for(i = 0; i < vect_cnt(vect); ++i) printf("%i\n", vect[i]);
    }
    
    // It is optional for all vector functions to provide the template argument if using the defaults.
    vect_destroy(vect, vect_tmplt_int_t);
    
    return 0;
}
```
