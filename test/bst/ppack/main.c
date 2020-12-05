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

    // Force ppacks to resolve and print as a string even if they have symbols.
    printf("dmypkd tostring = %s\n", ppack_tostring(dmypkd));

    return 0;
}
