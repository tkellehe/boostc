![boostc icon](images/boostc-icon.png)

# [boostc](https://tkellehe.github.io/boostc/)
A library like [Boost _C++_](https://github.com/boostorg), but for C.
Provides compile time decisions similar to templating in a simple API.
Also has polyfills for C standards. Documentation can be viewed [here](https://tkellehe.github.io/boostc/docs/).

### Compile Time Requirement
Currently, the goal is to write all of the library as compile time insertions of the code.
This allows more flexibility and makes it closer to _Boost C++_.
Another benefit is that you do not need to build this library.

### Insertion Code Bloat
Since most interfaces are inlined code, this can cause binaries to be quite large.
A simple solution is to instantiate your own function to wrap the _boostc_ functions.
Then the compiler will treat it as a single function and potentially reducing the size of binaries.

# ratio

This interface provides a compile time `std::ratio` like interface but in _C_.
The fractions do not naturally reduce.
However, there are compile time GCD calls where the amount to recurse must be specified.
Note that some compilers cannot support these calls because of the heap requirements or some compilers may take several minutes just to compile.

```c
#include <boostc/ratio.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    
    // Since they are compile time, they must be declared as a macro.
    #define one_half bstc_ratio(1, 2)
    #define two bstc_ratio(2)
    #define one bstc_ratio(1)

    // The values can be accessed and printed using similar "pri" string macros.
    printf("one_half => %" bstc_priratio "/%" bstc_priimax "\n", bstc_ratio_num(one_half), bstc_ratio_den(one_half));
    printf("two      => %" bstc_priratio "/%" bstc_priimax "\n", bstc_ratio_num(two), bstc_ratio_den(two));
    printf("one      => %" bstc_priratio "/%" bstc_priimax "\n", bstc_ratio_num(one), bstc_ratio_den(one));
    
    // Can be used in a macro if-statement or a regular if-statement.
    // Also, the reduce call has a general form `bstc_ratio_reduce` which uses way more steps than what is needed here.
    #if bstc_ratio_eq(one, bstc_ratio_reduce2(bstc_ratio_mul(one_half, two)))
    printf("(two * one_half) == one\n");
    #else
    printf("(two * one_half) != one\n");
    #endif

    // Note that it is not required to reduce in order to check if two ratios are equal.
    if(bstc_ratio_eq(one, bstc_ratio_mul(one_half, two)))
        printf("(two * one_half) == one\n");
    else
        printf("(two * one_half) != one\n");

    return bstc_exit_success;
}
```
