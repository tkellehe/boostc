//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/time.h>
#include <boostc/inttypes.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    {
        struct bstc_timespec ts;
        int r = bstc_timespec_get(&ts, bstc_time_utc);
        printf("bstc_timespec_get(&ts, %i): {.tv_sec=%" bstc_priimax ", .tv_nsec=%" bstc_priimax "}\n", (int)bstc_time_utc, (bstc_intmax_t)ts.tv_sec, (bstc_intmax_t)ts.tv_nsec);
        if(r == bstc_time_utc)
        {
            ++num_pass;
            printf("    passed\n");
        }
        else
        {
            ++num_fail;
            printf("    failed\n");
        }
    }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
