//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/chrono/duration.h>
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
        bstc_chrono_hrs_t hrs = 1000;
    
        printf("bstc_chrono_hrs_cnt(hrs): %" bstc_priimax "\n", (bstc_intmax_t)bstc_chrono_hrs_cnt(hrs));
        if(bstc_chrono_hrs_cnt(hrs) == 1000)
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
