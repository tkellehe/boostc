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
    return 0;
}
