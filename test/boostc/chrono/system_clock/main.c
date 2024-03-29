//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/chrono/system_clock.h>
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
        printf("bstc_chrono_sysclk_isstdy: %s\n", bstc_chrono_sysclk_isstdy ? "true" : "false");
        if(!bstc_chrono_sysclk_isstdy)
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
        bstc_chrono_sysclk_dur_t tp;
        bstc_chrono_ns_t ns;
        bstc_chrono_sec_t sec;
        bstc_time_t tt;

        tp = bstc_chrono_sysclk_now();
        ns = bstc_chrono_dur_cast(bstc_chrono_ns, bstc_chrono_sysclk_dur, tp);

        printf(
            "bstc_chrono_dur_cast(tp) == bstc_chrono_ns_cnt(ns): %" bstc_priimax ", %" bstc_priimax "\n",
            (bstc_intmax_t)bstc_chrono_sysclk_dur_cnt(tp),
            (bstc_intmax_t)bstc_chrono_ns_cnt(ns)
        );
        if(bstc_chrono_ns_cnt(ns) == bstc_chrono_sysclk_dur_cnt(tp))
        {
            ++num_pass;
            printf("    passed\n");
        }
        else
        {
            ++num_fail;
            printf("    failed\n");
        }

        sec = bstc_chrono_dur_cast(bstc_chrono_sec, bstc_chrono_sysclk_dur, tp);
        tt = bstc_chrono_sysclk_to_time_t(tp);
        tp = bstc_chrono_sysclk_from_time_t(tt);
        ns = bstc_chrono_dur_cast(bstc_chrono_ns, bstc_chrono_sec, sec);

        printf(
            "bstc_chrono_sysclk_from_time_t(tt) == bstc_chrono_ns_cnt(ns): %" bstc_priimax ", %" bstc_priimax "\n",
            (bstc_intmax_t)bstc_chrono_sysclk_dur_cnt(tp),
            (bstc_intmax_t)bstc_chrono_ns_cnt(ns)
        );
        if(tp == ns)
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
