//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/stdnoreturn.h>
#include <stdio.h>

int num_pass = 0;
int num_fail = 0;

bstc_noreturn void stop_now()
{
    num_pass += 1;
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");
    bstc_exit(num_fail ? bstc_exit_failure : bstc_exit_success);
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    //--------------------------------------------------------------------------------------------------------
    stop_now();

    num_fail += 1;
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");
    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
