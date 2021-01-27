![boostc icon](images/boostc-icon.png)

# boostc
A library like [Boost _C++_](https://github.com/boostorg), but for C.
Provides compile time decisions similar to templating in a simple API.
Also has polyfills for C standards.

## Why Make This?
I began to write my own variation of _Boost C++_ to get better at _C++_.
I was able to write a lot of parts that competed well with Boost, but overall useless.
Therein, I began to wonder if I could take this and get it into a _C_ library.

So, this library is my attempt to make a _C_ version without copying _Boost C++_ directly for my own learning experience.

### Compile Time Requirement
Currently, the goal is to write all of the library as compile time insertions of the code.
This allows more flexibility and makes it closer to _Boost C++_.
Another benefit is that you do not need to build this library.

### Insertion Code Bloat
Since most interfaces are inlined code, this can cause binaries to be quite large.
A simple solution is to instantiate your own function to wrap the _boostc_ functions.
Then the compiler will treat it as a function and potentially reducing the size of binaries.

# vector
Provides compile time decisions to create a _C++_ like vector in _C_. Uses the _template_ interface.

```c
#include <boostc/vector.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    // Note: It is recommended to do as typedef because there is no guarantee that the types will be the same.
    //       This problem is more relevant when the underlying structure is a more complex data structure.
    bstc_vect_t(int) vect;
    
    // Initialize the state of the vector.
    bstc_vect_init(vect);
    
    // Default is to use stdlib allocator.
    bstc_vect_push(vect, 11);
    bstc_vect_push(vect, 12);
    
    // Can use basic array operator on the data.
    vect[0] += 10;
    
    // Can loop over the contents.
    {
        int i;
        for(i = 0; i < bstc_vect_len(vect); ++i)
            printf("%i\n", vect[i]);
    }
    
    // Deallocate any memory.
    bstc_vect_destroy(vect);
    
    return 0;
}
```

## Changing Templates

The basic implementation works by taking the default template if the first parameter does not syntactically appear as a template.
A template is basically a tuple of symbols that follows a particular pattern.
The default layout of this pattern can be generated using the template vector macro.
Then you can do things like changing the default allocator.

```c
#include <boostc/vector.h>
#include <stdio.h>

// This is a simple allocator that is not the best, but provides as a simple example.
int _memory[1024];
int _pos = 0;
void* my_malloc(int sz)
{
    int* res = &_memory[_pos];
    _pos += sz / sizeof(int);
    return (void*)res;
}
void* my_realloc(void* mem, int sz)
{
    (void)mem;
    int* res = &_memory[_pos];
    _pos += sz / sizeof(int);
    return (void*)res;
}


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    // It is recommended to create a definition for the macro type to make it more readable.
    // The type provided first is the underlying type of the vector.
    // The symbol tuple is merely indicated by parentheses and the three symbols provided.
    // They must be provided in the following order: free, malloc, realloc.
    #define vect_int bstc_vect_tmplt_t(int, (bstc_alloc_nofree, my_malloc, my_realloc))

    // You can print out what was actually encoded into the symbol tuple:
    printf("vect_int: %s\n", BSTC_TOSTRING(vect_int));

    // Passing it into a vector function will cause it to extract the symbol representing the type.
    bstc_vect_t(vect_int) vect;
    
    // Initializes the state by extracting the symbol encoded representing the init function.
    // It is not required to use the template here since the default behavior does not change when changing the allocators.
    // But, it is recommended for consistency.
    bstc_vect_init(vect_int, vect);
    
    // Uses the allocator encoded into the template to realloc and malloc the memory.
    bstc_vect_push(vect_int, vect, 11);
    bstc_vect_push(vect_int, vect, 12);
    
    // Can still use basic array operator on the data.
    vect[0] += 10;
    
    // Can loop over the contents where the template is not necessary, but recommended for consistency.
    {
        int i;
        for(i = 0; i < bstc_vect_len(vect_int, vect); ++i)
            printf("%i\n", vect[i]);
    }
    
    // Deallocates any memory allocated using what is encoded in the template.
    bstc_vect_destroy(vect_int, vect);
    
    return 0;
}
```
