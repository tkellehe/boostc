//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/traits/template.h>
#include <stdio.h>

// The function that gets inserted is merely the symbol, therein does not matter when it is defined.
#define fooT_int(x, y) (x + y)

// Can use the template API to create a default template with only a single function packed in.
#define fooT_tmplt_int bstc_tmplt_pack_fn(fooT_int)

// This is the actual function that is templated.
#define fooT(T, x, y) \
    /* Detect if the symbol created exists when used and make sure to use `##`. */\
    bstc_tmplt_isa(fooT_tmplt_ ## T,\
        /* Since we could find the symbol as a template, we can extract the function from it. */\
        bstc_tmplt_fn(fooT_tmplt_ ## T)(x, y),\
        /* If we could not find a specialization, we can insert the default implementation. */\
        (y - x)\
    )

// This function can be declared here and will be inserted when the specialization is interpreted.
static short fooT_short(short x, short y)
{
    return x * y;
}

// Since everything is a macro, we just need to define this (like real templates) before it is used.
#define fooT_tmplt_short bstc_tmplt_pack_fn(fooT_short)

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    // Here is what the specialization resolves to:
    printf("fooT_tmplt_int = %s\n", bstc_ctuple_tostring(fooT_tmplt_int));
    printf("fooT_tmplt_short = %s\n", bstc_ctuple_tostring(fooT_tmplt_short));

    //--------------------------------------------------------------------------------------------------------
    int i = fooT(int, 2, 5);
    short s = fooT(short, 2, 5);
    unsigned u = fooT(unsigned, 2, 5);
    printf("fooT_int(2, 5) = %i\n", i);
    if(i == 7) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    printf("fooT_short(2, 5) = %i\n", s);
    if(s == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    printf("fooT_unsigned(2, 5) = %i\n", u);
    if(u == 3) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

    //--------------------------------------------------------------------------------------------------------
    #define tmplt1 bstc_tmplt_pack_t(A)
    #define tmplt2 bstc_tmplt_pack_info(bstc_ctuple(B, BB, BBB))
    #define tmplt3 bstc_tmplt_pack_fns(bstc_ctuple(C, CC, CCC))
    #define tmplt4 bstc_tmplt_pack_iter(bstc_iter_pack_t(D))
    #define tmplt5 bstc_tmplt_pack_riter(bstc_iter_pack_t(E))
    #define tmplt6 bstc_tmplt_pack_alloc(bstc_alloc_pack_free(F))
    #define tmpltN bstc_ctuple(1, 2, 3, 4, 5, 6)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt1));
    bstc_tmplt_isa(tmplt1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt2));
    bstc_tmplt_isa(tmplt2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt3));
    bstc_tmplt_isa(tmplt3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt4));
    bstc_tmplt_isa(tmplt4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt5));
    bstc_tmplt_isa(tmplt5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmplt6));
    bstc_tmplt_isa(tmplt6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(tmpltN));
    bstc_tmplt_isa(tmpltN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_tmplt_isa(%s)\n", bstc_ctuple_tostring(bstc_tmplt_defaults));
    bstc_tmplt_isa(bstc_tmplt_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
