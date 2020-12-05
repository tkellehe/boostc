#include <bst/template.h>
#include <stdio.h>

#define fooT_int(x, y) (x + y)
#define fooT_tmplt_int tmplt_ctuple_fn(fooT_int)

#define fooT(T, x, y) \
    tmplt_isa(fooT_tmplt_ ## T,\
        tmplt_fn(fooT_tmplt_ ## T)(x, y),\
        (y - x)\
    )

static short fooT_short(short x, short y)
{
    return x * y;
}
#define fooT_tmplt_short tmplt_ctuple_fn(fooT_short)

int main()
{
    int i = fooT(int, 2, 5);
    short s = fooT(short, 2, 5);
    unsigned u = fooT(unsigned, 2, 5);
    printf("fooT_int(2, 5) = %i\n", i);
    printf("fooT_short(2, 5) = %i\n", s);
    printf("fooT_unsigned(2, 5) = %i\n", u);
    return 0;
}