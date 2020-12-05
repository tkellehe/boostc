# bst
A library like [**B**oo**st** _C++_](https://github.com/boostorg), but for C.
Provides compile time decisions similar to templating in a simple API.
Also has polyfills for C standards.

## Why Make This?
I had began to write my own variation of _Boost C++_ to get better at _C++_.
I was able to write a lot of parts that competed well with Boost, but overall useless.
Therein, I began to wonder if I could take this and get it into a _C_ library.

So, this library is my attempt to make a _C_ version without copying _Boost C++_ directly for my own learning experience.

The name comes from taking _Object Oriented_ out of _Boost C++_.
At least that is what I say now.
It really is just an abbreviation of _Boost_, by removing the vowels...

# Components
 * [allocator](#allocator)
 * [assert](#assert)
 * [config](#config)
 * [errno](#errno)
 * [iterator](#iterator)
 * [ctuple](#ctuple)
 * [stdint](#stdint)
 * [template](#template)
 * [vector](#vector)

### Interface Namespaces
The current interface is to prefix everything with `bst_`.
Also, to provide an interface without this prefix.
This may cause problems in your library if you have something with a similar name.
To avoid this, you can define `BST_NAMESPACE_ONLY` and it will remove the other non-stdc interfaces without the `bst_`.

### Compile Time Requirement
Currently, the goal is to write all of the library as compile time insertions of the code.
This allows more flexibility and makes it closer to _Boost C++_.
Another benefit is that you do not need to build this library.

### Insertion Code Bloat
Since most interfaces are inlined code, this can cause binaries to be quite large.
A simple solution is to instantiate your own function calling the inlining _bst_ functions.
Then the compiler will treat it as a function and potentially reducing the size of binaries.

# allocator
Provides compile time decisions for creating allocators.
The allocator paradigm is that only the functions `free`, `malloc`, and `realloc` are needed.
Each are then packed into a [ctuple](#ctuple) that can be passed to types that require an allocator.
This allows for the code desired for allocators to be inlined into the functions that use them.

```c
#include <bst/allocator.h>

// A helper is provided to reference the ctuple of the stdlib calls.
#define stdlib alloc_stdlib

// The actual implemenation of the mk_array function. Need the variadic portion to make the other parts easier.
#define mk_array_dtl(T, N, alloc, ...) (T*)alloc_malloc(alloc)(sizeof(T) * N)
// Optional allocator operation where default uses stdlib.
#define mk_array(T, N, ...) \
    /* Select the default argument if nothing is provided. */\
    mk_array_dtl(T, N, ctuple_defargs(ctuple(__VA_ARGS__), ctuple(stdlib)))

#define rm_array_dtl(array, alloc, ...) alloc_free(alloc)((void*)(array))
#define rm_array(array, ...) rm_array_dtl(array, ctuple_defargs(ctuple(__VA_ARGS__), ctuple(stdlib)))

int _pos = 0;
char _memory[1024] = {0,};
void *mymalloc(int size) { int pos = _pos; _pos += size; return (void*)(_memory + pos); }

// The allocator interface provides calls to be able to ensure that the std order is always packed correctly.
// Also, the default free and realloc calls are set to do-nothings.
#define myalloc alloc_ctuple_malloc(mymalloc)

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
Provides compile time decisions to create [ctuples](#ctuple) for iterators similar to that of [allocators](#allocator).

```c
#include <bst/iterator.h>
```

# ctuple
Provides compile time decisions to create ctuple macros.
The ctuples work by taking parameters and describing them as a single compile time symbol.
This is done by placing parentheses around the parameters (ie `(1, 'a', var)`).
Then using macros to apply operations to these ctuples.

```c
#include <bst/ctuple.h>
#include <stdio.h>

// The actual final call made.
#define myprints5(a, b, c, d, e, ...) printf("%i %i %i %i %i\n", a, b, c, d, e)
// This unpacks the ctuple provided.
#define myprints_tpl(tpl) myprints5 tpl
// Takes in an optional list of integers and prepends a value.
#define myprints(...) myprints_tpl(ctuple_prepend(ctuple_defaults(ctuple(__VA_ARGS__), ctuple(1, 2, 3, 4)), 0))

int main()
{
    myprints();
    myprints(1);
    myprints(2, 1);
    myprints(3, 2, 1);
    myprints(4, 3, 2, 1);
    myprints(5, 4, 3, 2, 1);

    #define mytpl ctuple('a', 'b', 'c', 'd')

    // Can get sizes of ctuples.
    printf("mytpl size = %i\n", ctuple_size(mytpl));

    // Can get constant access to ctuples.
    printf("mytpl[0] = %c\n", ctuple_getI(mytpl, 0));
    printf("mytpl[1] = %c\n", ctuple_getI(mytpl, 1));
    printf("mytpl[2] = %c\n", ctuple_getI(mytpl, 2));
    printf("mytpl[3] = %c\n", ctuple_getI(mytpl, 3));

    // Can set constant access to ctuples.
    #define smytpl ctuple_setI(mytpl, 1, 'x')
    printf("smytpl[0] = %c\n", ctuple_getI(smytpl, 0));
    printf("smytpl[1] = %c\n", ctuple_getI(smytpl, 1));
    printf("smytpl[2] = %c\n", ctuple_getI(smytpl, 2));
    printf("smytpl[3] = %c\n", ctuple_getI(smytpl, 3));

    // Can get reverse ctuples.
    #define rmytpl ctuple_reverse(mytpl)
    printf("rmytpl[0] = %c\n", ctuple_getI(rmytpl, 0));
    printf("rmytpl[1] = %c\n", ctuple_getI(rmytpl, 1));
    printf("rmytpl[2] = %c\n", ctuple_getI(rmytpl, 2));
    printf("rmytpl[3] = %c\n", ctuple_getI(rmytpl, 3));
    printf("rmytpl size = %i\n", ctuple_size(rmytpl));

    // Can get trim ctuples.
    #define ltmytpl ctuple_ltrim(mytpl, 2)
    printf("ltmytpl[0] = %c\n", ctuple_getI(ltmytpl, 0));
    printf("ltmytpl[1] = %c\n", ctuple_getI(ltmytpl, 1));
    printf("ltmytpl size = %i\n", ctuple_size(ltmytpl));
    #define rtmytpl ctuple_rtrim(mytpl, 2)
    printf("rtmytpl[0] = %c\n", ctuple_getI(rtmytpl, 0));
    printf("rtmytpl[1] = %c\n", ctuple_getI(rtmytpl, 1));
    printf("rtmytpl size = %i\n", ctuple_size(rtmytpl));
    
    // Can fill with default values by position.
    #define dmytpl ctuple_defaults(rtmytpl, ('x', 'y', 'e', 'f'))
    printf("dmytpl[0] = %c\n", ctuple_getI(dmytpl, 0));
    printf("dmytpl[1] = %c\n", ctuple_getI(dmytpl, 1));
    printf("dmytpl[2] = %c\n", ctuple_getI(dmytpl, 2));
    printf("dmytpl[3] = %c\n", ctuple_getI(dmytpl, 3));
    printf("dmytpl size = %i\n", ctuple_size(dmytpl));

    // Can unpack directly as default arguments.
    printf("%c %c %c %c\n", ctuple_defargs(rtmytpl, ('x', 'y', 'e', 'f')));
    printf("%c %c %c %c\n", ctuple_defargs(ctuple(), ('x', 'y', 'e', 'f')));

    // Can create if-statements and check if has minimum size.
    printf("mytpl %s\n", ctuple_hasLT(mytpl, 5, "size < 5", "size >= 5"));
    printf("mytpl %s\n", ctuple_if(ctuple_ltrim(mytpl, 4), "size > 4", "size < 5"));
    printf("mytpl %s\n", ctuple_if(ctuple_ltrim(mytpl, 0), "size > 3", "size < 4"));
    printf("mytpl %s\n", ctuple_hasN(mytpl, 4, "size == 4", "size != 4"));
    printf("mytpl %s\n", ctuple_hasN(mytpl, 40, "size == 40", "size != 40"));

    // Define symbols in a ctuple to be called.
    #define myf0() a
    #define myf1(a) a
    #define myf2(a, b) a + b
    #define mytplf ctuple(myf0, myf1, myf2)

    #define params ctuple(100, 101)

    printf(
        "invoke %s = %i\n",
        BST_TOSTRING(ctuple_getI(mytplf, ctuple_size(params))),
        ctuple_call(ctuple_getI(mytplf, ctuple_size(params)), params)
    );

    // Can detect if is a ctuple or not.
    printf("is mytpl ctuple? %s\n", ctuple_isa(mytpl, "yes", "no"));
    printf("is int ctuple? %s\n", ctuple_isa(int, "yes", "no"));

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
It is a ctuples of a standard order such that the type, type info, iterator calls, reverse iterator calls, and allocator calls can be accessed.
This allows for more complex structures with a simpler interface.

```c
#include <bst/algorithm/find.h>
#include <bst/vector.h>
#include <stdio.h>

int main()
{
    // This creates a ctuple in the form of a template that contains compile time information about the vector type.
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

        // Get the iterator ctuple from the template to then search.
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
