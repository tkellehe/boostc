#include <bst/template.h>
#include <stdio.h>

// The function that gets inserted is merely the symbol, therein does not matter when it is defined.
#define fooT_int(x, y) (x + y)

// Can use the template API to create a default template with only a single function packed in.
#define fooT_tmplt_int tmplt_ctuple_fn(fooT_int)

// This is the actual function that is templated.
#define fooT(T, x, y) \
    /* Detect if the symbol created exists when used and make sure to use `##`. */\
    tmplt_isa(fooT_tmplt_ ## T,\
        /* Since we could find the symbol as a template, we can extract the function from it. */\
        tmplt_fn(fooT_tmplt_ ## T)(x, y),\
        /* If we could not find a specialization, we can insert the default implementation. */\
        (y - x)\
    )

// This function can be declared here and will be inserted when the specialization is interpreted.
static short fooT_short(short x, short y)
{
    return x * y;
}

// Since everything is a macro, we just need to define this (like real templates) before it is used.
#define fooT_tmplt_short tmplt_ctuple_fn(fooT_short)

int main()
{
    int i = fooT(int, 2, 5);
    short s = fooT(short, 2, 5);
    unsigned u = fooT(unsigned, 2, 5);
    printf("fooT_int(2, 5) = %i\n", i);
    printf("fooT_short(2, 5) = %i\n", s);
    printf("fooT_unsigned(2, 5) = %i\n", u);

    // Here is what the specialization resolves to:
    printf("fooT_tmplt_int = %s\n", ctuple_tostring(fooT_tmplt_int));
    printf("fooT_tmplt_short = %s\n", ctuple_tostring(fooT_tmplt_short));

    return 0;
}