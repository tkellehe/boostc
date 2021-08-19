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
        bstc_chrono_hrs_t hrs = 100;
        bstc_chrono_ms_t ms;
    
        printf("bstc_chrono_hrs_cnt(hrs): %" bstc_priimax "\n", (bstc_intmax_t)bstc_chrono_hrs_cnt(hrs));
        if(bstc_chrono_hrs_cnt(hrs) == 100)
        {
            ++num_pass;
            printf("    passed\n");
        }
        else
        {
            ++num_fail;
            printf("    failed\n");
        }
    
        ms = bstc_chrono_dur_cast(bstc_chrono_ms, bstc_chrono_hrs, hrs);
        printf("bstc_chrono_ms_cnt(ms): %" bstc_priimax "\n", (bstc_intmax_t)bstc_chrono_ms_cnt(ms));
        if(bstc_chrono_ms_cnt(ms) == 360000000)
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
    {
        #define hrsf bstc_chrono_dur_traits(double, bstc_ratio(3600))
        bstc_chrono_ms_t ms = 100;
        bstc_chrono_dur_rep(hrsf) hrs;
    
        printf("bstc_chrono_ms_cnt(ms): %" bstc_priimax "\n", (bstc_intmax_t)bstc_chrono_ms_cnt(ms));
        if(bstc_chrono_ms_cnt(ms) == 100)
        {
            ++num_pass;
            printf("    passed\n");
        }
        else
        {
            ++num_fail;
            printf("    failed\n");
        }
    
        hrs = bstc_chrono_dur_cast(hrsf, bstc_chrono_ms, ms);
        printf("bstc_chrono_hrs_cnt(hrs): %f\n", (float)bstc_chrono_dur_cnt(hrsf, hrs));
        if((0.000028 - 0.000001) <= bstc_chrono_dur_cnt(hrsf, hrs) || bstc_chrono_dur_cnt(hrsf, hrs) <= (0.000028 + 0.000001))
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
