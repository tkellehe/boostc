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

    return 0;
}
