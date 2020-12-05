# bst
 __B__oo__st__ C++ like library for C.

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
 * [iterator](#iterator)
 * [ppack](#ppack)
 * [stdint](#stdint)
 * [template](#template)
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
#define mk_array_dtl(T, N, alloc, ...) (T*)alloc_malloc(alloc)(sizeof(T) * N)
// Optional allocator operation where default uses stdlib.
#define mk_array(T, N, ...) \
    /* Select the default argument if nothing is provided. */\
    mk_array_dtl(T, N, ppack_defargs(ppack(__VA_ARGS__), ppack(stdlib)))

#define rm_array_dtl(array, alloc, ...) alloc_free(alloc)((void*)(array))
#define rm_array(array, ...) rm_array_dtl(array, ppack_defargs(ppack(__VA_ARGS__), ppack(stdlib)))

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

# iterator
Provides compile time decisions to create parameter packs for iterators similar to that of [allocators](#allocator).

```c
#include <bst/iterator.h>
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
#define myprints(...) myprints_pkd(ppack_prepend(ppack_defaults(ppack(__VA_ARGS__), ppack(1, 2, 3, 4)), 0))

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
    printf("mypkd[0] = %c\n", ppack_getI(mypkd, 0));
    printf("mypkd[1] = %c\n", ppack_getI(mypkd, 1));
    printf("mypkd[2] = %c\n", ppack_getI(mypkd, 2));
    printf("mypkd[3] = %c\n", ppack_getI(mypkd, 3));

    // Can set constant access to ppacks.
    #define smypkd ppack_setI(mypkd, 1, 'x')
    printf("smypkd[0] = %c\n", ppack_getI(smypkd, 0));
    printf("smypkd[1] = %c\n", ppack_getI(smypkd, 1));
    printf("smypkd[2] = %c\n", ppack_getI(smypkd, 2));
    printf("smypkd[3] = %c\n", ppack_getI(smypkd, 3));

    // Can get reverse ppacks.
    #define rmypkd ppack_reverse(mypkd)
    printf("rmypkd[0] = %c\n", ppack_getI(rmypkd, 0));
    printf("rmypkd[1] = %c\n", ppack_getI(rmypkd, 1));
    printf("rmypkd[2] = %c\n", ppack_getI(rmypkd, 2));
    printf("rmypkd[3] = %c\n", ppack_getI(rmypkd, 3));
    printf("rmypkd size = %i\n", ppack_size(rmypkd));

    // Can get trim ppacks.
    #define ltmypkd ppack_ltrim(mypkd, 2)
    printf("ltmypkd[0] = %c\n", ppack_getI(ltmypkd, 0));
    printf("ltmypkd[1] = %c\n", ppack_getI(ltmypkd, 1));
    printf("ltmypkd size = %i\n", ppack_size(ltmypkd));
    #define rtmypkd ppack_rtrim(mypkd, 2)
    printf("rtmypkd[0] = %c\n", ppack_getI(rtmypkd, 0));
    printf("rtmypkd[1] = %c\n", ppack_getI(rtmypkd, 1));
    printf("rtmypkd size = %i\n", ppack_size(rtmypkd));
    
    // Can fill with default values by position.
    #define dmypkd ppack_defaults(rtmypkd, ('x', 'y', 'e', 'f'))
    printf("dmypkd[0] = %c\n", ppack_getI(dmypkd, 0));
    printf("dmypkd[1] = %c\n", ppack_getI(dmypkd, 1));
    printf("dmypkd[2] = %c\n", ppack_getI(dmypkd, 2));
    printf("dmypkd[3] = %c\n", ppack_getI(dmypkd, 3));
    printf("dmypkd size = %i\n", ppack_size(dmypkd));

    // Can unpack directly as default arguments.
    printf("%c %c %c %c\n", ppack_defargs(rtmypkd, ('x', 'y', 'e', 'f')));
    printf("%c %c %c %c\n", ppack_defargs(ppack(), ('x', 'y', 'e', 'f')));

    // Can create if-statements and check if has minimum size.
    printf("mypkd %s\n", ppack_hasLT(mypkd, 5, "size < 5", "size >= 5"));
    printf("mypkd %s\n", ppack_if(ppack_ltrim(mypkd, 4), "size > 4", "size < 5"));
    printf("mypkd %s\n", ppack_if(ppack_ltrim(mypkd, 0), "size > 3", "size < 4"));
    printf("mypkd %s\n", ppack_hasN(mypkd, 4, "size == 4", "size != 4"));
    printf("mypkd %s\n", ppack_hasN(mypkd, 40, "size == 40", "size != 40"));

    // Define symbols in a ppack to be called.
    #define myf0() a
    #define myf1(a) a
    #define myf2(a, b) a + b
    #define mypkdf ppack(myf0, myf1, myf2)

    #define params ppack(100, 101)

    printf(
        "invoke %s = %i\n",
        BST_TOSTRING(ppack_getI(mypkdf, ppack_size(params))),
        ppack_call(ppack_getI(mypkdf, ppack_size(params)), params)
    );

    // Can detect if is a ppack or not.
    printf("is mypkd ppack? %s\n", ppack_isa(mypkd, "yes", "no"));
    printf("is int ppack? %s\n", ppack_isa(int, "yes", "no"));

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

# template
Provides compile time decisions to create _C++_ like std template structures.
It is a parameter pack of a standard order such that the type, type info, iterator calls, reverse iterator calls, and allocator calls can be accessed.
This allows for more complex structures with a simpler interface.

```c
#include <bst/algorithm/find.h>
#include <bst/vector.h>
#include <stdio.h>

int main()
{
    // This creates a ppack in the form of a template that contains compile time information about the vector type.
    // The default is already the stdlib for the allocator, but can specify your own.
    #define vect_tmplt_int_t vect_tmplt_t(int, alloc_stdlib)

    // Get the vector type out of the template and use a typedef for good practice.
    typedef vect_t(vect_tmplt_int_t) vect_int_t;

    // Can use the type just like `vect_t(int)` works.
    vect_int_t vect;

    // All the same functions can be used in the normal vector, just provide the template first to not use the default template.
    vect_init(vect_tmplt_int_t, vect);

    vect_push(vect_tmplt_int_t, vect, 1);
    vect_push(vect_tmplt_int_t, vect, 2);
    vect_push(vect_tmplt_int_t, vect, -1);
    vect_push(vect_tmplt_int_t, vect, 4);
    vect_push(vect_tmplt_int_t, vect, -1);

    // We can now do iterators since we have the template.
    {
        // Get the iterator type from the template.
        vect_iter_t(vect_tmplt_int_t) iter = vect_begin(vect_tmplt_int_t, vect);

        // Get the iterator ppack from the template to then search.
        alg_find(tmplt_iter(vect_tmplt_int_t), iter, vect_end(vect_tmplt_int_t, vect), -1);

        // If we find it, then we can change the value.
        if(iter != vect_end(vect_tmplt_int_t, vect))
        {
            vect_iter_set(vect_tmplt_int_t, iter, 3);
        }
    }

    // We can even do reverse iterators since we have the template.
    {
        vect_riter_t(vect_tmplt_int_t) riter = vect_rbegin(vect_tmplt_int_t, vect);

        alg_find(tmplt_riter(vect_tmplt_int_t), riter, vect_rend(vect_tmplt_int_t, vect), -1);

        if(riter != vect_rend(vect_tmplt_int_t, vect))
        {
            vect_riter_set(vect_tmplt_int_t, riter, 5);
        }
    }

    // We can use iterators to loop over the contents.
    {
        // Get the iterator type from the template.
        vect_iter_t(vect_tmplt_int_t) iter;
        
        // For the vector, the template is not actually needed for most calls.
        for(iter = vect_begin(vect); iter != vect_end(vect); vect_iter_nxt(iter))
            printf("*iter = %i\n", vect_iter_val(iter));
    }

    vect_destroy(vect_tmplt_int_t, vect);
}
```

# vector
Provides compile time decisions to create a _C++_ like vector in _C_. Uses the [template](#template) interface.

```c
#include <bst/vector.h>
#include <stdio.h>

int main()
{
    // Note: It is recommended to do as typedef because there is no guarantee that the types will be the same.
    //       This problem is more relavant when the underlying structure is a more complex data structure.
    vect_t(int) vect;
    
    vect_init(vect);
    // Default is to use stdlib allocator.
    vect_push(vect, 11);
    vect_push(vect, 12);
    
    // Can use basic array operator on the data.
    vect[0] += 10;
    
    // Can loop over the contents.
    {
        int i;
        for(i = 0; i < vect_len(vect); ++i) printf("%i\n", vect[i]);
    }
    
    vect_destroy(vect);
    
    return 0;
}
```
