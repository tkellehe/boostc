//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/traits/iterator.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #define iter1 bstc_iter_pack_t(A)
    #define iter2 bstc_iter_pack_nxt(B)
    #define iter3 bstc_iter_pack_eq(C)
    #define iter4 bstc_iter_pack_val(D)
    #define iter5 bstc_iter_pack_put(E)
    #define iter6 bstc_iter_pack_swap(F)
    #define iterN bstc_ctuple(1, 2, 3, 4)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter1));
    bstc_iter_isa(iter1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter2));
    bstc_iter_isa(iter2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter3));
    bstc_iter_isa(iter3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter4));
    bstc_iter_isa(iter4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter5));
    bstc_iter_isa(iter5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iter6));
    bstc_iter_isa(iter6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(iterN));
    bstc_iter_isa(iterN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_iter_isa(%s)\n", bstc_ctuple_tostring(bstc_iter_defaults));
    bstc_iter_isa(bstc_iter_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
