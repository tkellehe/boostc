#include <bst/template.h>
#include <stdio.h>

// #define fooT_int(x, y) (x + y)
// #define fooT_int tmplt_specialize(fooT, fooT_int) // hmmm...

// #define fooT(T, x, y) 
//     tmplt_if((fooT, T),
//         tmplt_type(tmplt_id(fooT, T))(x, y),
//         BST_TMPLT_NOT_IMPLEMENTED
//     )

// static short fooT_short(short x, short y)
// {
//     return x * y;
// }
// #define fooT_short tmplt_ctuple(fooT_short)

int main()
{
    // int i = fooT(int, 2, 5);
    // short s = fooT(short, 2, 5);
    // printf("fooT_int(2, 5) = %i\n", i);
    // printf("fooT_short(2, 5) = %i\n", s);
    return 0;
}