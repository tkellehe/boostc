//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/ratio.h>
#include <boostc/inttypes.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

    #define one_half bstc_ratio(1, 2)
    #ifdef BSTC_HAS_VARIADIC_MACROS
    # define two bstc_ratio(2)
    #else
    # define two bstc_ratio(2, 1)
    #endif
    #define one_third bstc_ratio(1, 3)
    #define two_thirds bstc_ratio(2, 3)
    #define one_sixth bstc_ratio(1, 6)

    #define add bstc_ratio_reduce4(bstc_ratio_add(one_sixth, one_half))
    #define div bstc_ratio_reduce4(bstc_ratio_div(two_thirds, two))
    #define mul bstc_ratio_reduce4(bstc_ratio_mul(two_thirds, one_half))
    #define sub bstc_ratio_reduce4(bstc_ratio_sub(two_thirds, one_sixth))

    #define centi bstc_ratio_reduce4(bstc_centi)
    
    //--------------------------------------------------------------------------------------------------------
    printf("one_half   => %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(one_half), bstc_ratio_den(one_half));
    printf("two        => %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(two), bstc_ratio_den(two));
    printf("one_third  => %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(one_third), bstc_ratio_den(one_third));
    printf("two_thirds => %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(two_thirds), bstc_ratio_den(two_thirds));
    printf("one_sixth  => %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(one_sixth), bstc_ratio_den(one_sixth));

    //--------------------------------------------------------------------------------------------------------
    printf("one_half: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(one_half), bstc_ratio_den(one_half));
    #if (bstc_ratio_t(1) == bstc_ratio_num(one_half) && bstc_ratio_t(2) == bstc_ratio_den(one_half))
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("two: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(two), bstc_ratio_den(two));
    #if (bstc_ratio_t(2) == bstc_ratio_num(two) && bstc_ratio_t(1) == bstc_ratio_den(two))
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("one_half == one_half:\n");
    #if bstc_ratio_eq(one_half, one_half)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("one_half != two:\n");
    #if bstc_ratio_neq(one_half, two)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("one_half != two:\n");
    #if bstc_ratio_neq(one_half, two)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("add: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(add), bstc_ratio_den(add));
    #if bstc_ratio_eq(add, two_thirds)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif

    //--------------------------------------------------------------------------------------------------------
    printf("div: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(div), bstc_ratio_den(div));
    #if bstc_ratio_eq(div, one_third)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("mul: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(mul), bstc_ratio_den(mul));
    #if bstc_ratio_eq(mul, one_third)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("sub: %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(sub), bstc_ratio_den(sub));
    #if bstc_ratio_eq(sub, one_half)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif
    
    //--------------------------------------------------------------------------------------------------------
    printf("bstc_ratio_reduce4(bstc_centi): %" bstc_priratio "/%" bstc_priratio "\n", bstc_ratio_num(centi), bstc_ratio_den(centi));
    #if bstc_ratio_eq(centi, bstc_centi)
    {
        ++num_pass;
        printf("    passed\n");
    }
    #else
    {
        ++num_fail;
        printf("    failed\n");
    }
    #endif

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
