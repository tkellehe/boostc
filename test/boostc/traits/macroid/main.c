//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/traits/macroid.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #define id 0
    #define nxt bstc_macroid_nxt(id)

    printf("bstc_macroid_nxt == 1:\n");
    if(nxt == 1)
        (++num_pass, printf("    passed\n"));
    else
        (++num_fail, printf("    failed\n"));

    //--------------------------------------------------------------------------------------------------------
    int bstc_macroid_var(var, nxt) = 1;
    num_pass += bstc_macroid_var(var, nxt);
    printf("bstc_macroid_var(var, 1) == %s:\n", BSTC_TOSTRING(bstc_macroid_var(var, nxt)));
    printf("    passed\n");


    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
