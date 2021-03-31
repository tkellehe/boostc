//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdint.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint8_t
        printf("sizeof(bstc_uint8_t): %i\n", (int)sizeof(bstc_uint8_t));
        if((int)sizeof(bstc_uint8_t) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int8_t
        printf("sizeof(bstc_int8_t): %i\n", (int)sizeof(bstc_int8_t));
        if((int)sizeof(bstc_int8_t) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint16_t
        printf("sizeof(bstc_uint16_t): %i\n", (int)sizeof(bstc_uint16_t));
        if((int)sizeof(bstc_uint16_t) == 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int16_t
        printf("sizeof(bstc_int16_t): %i\n", (int)sizeof(bstc_int16_t));
        if((int)sizeof(bstc_int16_t) == 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint32_t
        printf("sizeof(bstc_uint32_t): %i\n", (int)sizeof(bstc_uint32_t));
        if((int)sizeof(bstc_uint32_t) == 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int32_t
        printf("sizeof(bstc_int32_t): %i\n", (int)sizeof(bstc_int32_t));
        if((int)sizeof(bstc_int32_t) == 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint64_t
        printf("sizeof(bstc_uint64_t): %i\n", (int)sizeof(bstc_uint64_t));
        if((int)sizeof(bstc_uint64_t) == 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int64_t
        printf("sizeof(bstc_int64_t): %i\n", (int)sizeof(bstc_int64_t));
        if((int)sizeof(bstc_int64_t) == 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uintptr_t
        printf("sizeof(bstc_uintptr_t): %i\n", (int)sizeof(bstc_uintptr_t));
        if((int)sizeof(bstc_uintptr_t) == (BSTC_INTPTR_NBITS>>3)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_intptr_t
        printf("sizeof(bstc_intptr_t): %i\n", (int)sizeof(bstc_intptr_t));
        if((int)sizeof(bstc_intptr_t) == (BSTC_INTPTR_NBITS>>3)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uintmax_t
        printf("sizeof(bstc_uintmax_t): %i\n", (int)sizeof(bstc_uintmax_t));
        # if bstc_uintmax_max == bstc_uint64_max
        if(sizeof(bstc_uintmax_t) == sizeof(bstc_uint64_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_uintmax_max == bstc_uint32_max
        if(sizeof(bstc_uintmax_t) == sizeof(bstc_uint32_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_uintmax_max == bstc_uint16_max
        if(sizeof(bstc_uintmax_t) == sizeof(bstc_uint16_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_uintmax_max == bstc_uint8_max
        if(sizeof(bstc_uintmax_t) == sizeof(bstc_uint8_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # endif
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_intmax_t
        printf("sizeof(bstc_intmax_t): %i\n", (int)sizeof(bstc_intmax_t));
        # if bstc_intmax_max == bstc_int64_max
        if(sizeof(bstc_intmax_t) == sizeof(bstc_int64_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_intmax_max == bstc_int32_max
        if(sizeof(bstc_intmax_t) == sizeof(bstc_int32_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_intmax_max == bstc_int16_max
        if(sizeof(bstc_intmax_t) == sizeof(bstc_int16_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # elif bstc_intmax_max == bstc_int8_max
        if(sizeof(bstc_intmax_t) == sizeof(bstc_int8_t)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        # endif
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_least8_t
        printf("sizeof(bstc_uint_least8_t): %i\n", (int)sizeof(bstc_uint_least8_t));
        if((int)sizeof(bstc_uint_least8_t) >= 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_least8_t
        printf("sizeof(bstc_int_least8_t): %i\n", (int)sizeof(bstc_int_least8_t));
        if((int)sizeof(bstc_int_least8_t) >= 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_least16_t
        printf("sizeof(bstc_uint_least16_t): %i\n", (int)sizeof(bstc_uint_least16_t));
        if((int)sizeof(bstc_uint_least16_t) >= 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_least16_t
        printf("sizeof(bstc_int_least16_t): %i\n", (int)sizeof(bstc_int_least16_t));
        if((int)sizeof(bstc_int_least16_t) >= 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_least32_t
        printf("sizeof(bstc_uint_least32_t): %i\n", (int)sizeof(bstc_uint_least32_t));
        if((int)sizeof(bstc_uint_least32_t) >= 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_least32_t
        printf("sizeof(bstc_int_least32_t): %i\n", (int)sizeof(bstc_int_least32_t));
        if((int)sizeof(bstc_int_least32_t) >= 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_least64_t
        printf("sizeof(bstc_uint_least64_t): %i\n", (int)sizeof(bstc_uint_least64_t));
        if((int)sizeof(bstc_uint_least64_t) >= 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_least64_t
        printf("sizeof(bstc_int_least64_t): %i\n", (int)sizeof(bstc_int_least64_t));
        if((int)sizeof(bstc_int_least64_t) >= 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_fast8_t
        printf("sizeof(bstc_uint_fast8_t): %i\n", (int)sizeof(bstc_uint_fast8_t));
        if((int)sizeof(bstc_uint_fast8_t) >= 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_fast8_t
        printf("sizeof(bstc_int_fast8_t): %i\n", (int)sizeof(bstc_int_fast8_t));
        if((int)sizeof(bstc_int_fast8_t) >= 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_fast16_t
        printf("sizeof(bstc_uint_fast16_t): %i\n", (int)sizeof(bstc_uint_fast16_t));
        if((int)sizeof(bstc_uint_fast16_t) >= 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_fast16_t
        printf("sizeof(bstc_int_fast16_t): %i\n", (int)sizeof(bstc_int_fast16_t));
        if((int)sizeof(bstc_int_fast16_t) >= 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_fast32_t
        printf("sizeof(bstc_uint_fast32_t): %i\n", (int)sizeof(bstc_uint_fast32_t));
        if((int)sizeof(bstc_uint_fast32_t) >= 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_fast32_t
        printf("sizeof(bstc_int_fast32_t): %i\n", (int)sizeof(bstc_int_fast32_t));
        if((int)sizeof(bstc_int_fast32_t) >= 4) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_uint_fast64_t
        printf("sizeof(bstc_uint_fast64_t): %i\n", (int)sizeof(bstc_uint_fast64_t));
        if((int)sizeof(bstc_uint_fast64_t) >= 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    #ifdef bstc_int_fast64_t
        printf("sizeof(bstc_int_fast64_t): %i\n", (int)sizeof(bstc_int_fast64_t));
        if((int)sizeof(bstc_int_fast64_t) >= 8) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    #endif

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
