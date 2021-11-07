//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/endian.h>
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
        bstc_uint8_t x = 0x8;
        bstc_uint8_t y;
        y = bstc_endian_rev_uint8(x);
        printf("bstc_endian_rev_uint8(%i):\n", (int)x);
        if(x == y)
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
        bstc_uint16_t x = bstc_uint16_c(0x0880);
        bstc_uint16_t y;
        y = bstc_endian_rev_uint16(x);
        printf("bstc_endian_rev_uint16(%i):\n", (int)x);
        if(y == bstc_uint16_c(0x8008))
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
        bstc_uint32_t x = bstc_uint32_c(0x08800550);
        bstc_uint32_t y;
        y = bstc_endian_rev_uint32(x);
        printf("bstc_endian_rev_uint32(%i):\n", (int)x);
        if(y == bstc_uint32_c(0x50058008))
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
#ifdef bstc_uint64_t
    {
        bstc_uint64_t x = bstc_uint64_c(0x0880055001100330);
        bstc_uint64_t y;
        y = bstc_endian_rev_uint64(x);
        printf("bstc_endian_rev_uint64(%i):\n", (int)x);
        if(y == bstc_uint64_c(0x3003100150058008))
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
#endif

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
