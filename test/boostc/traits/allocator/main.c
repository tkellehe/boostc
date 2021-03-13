//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/traits/allocator.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_alloc_isa
    //--------------------------------------------------------------------------------------------------------
    #define alloc1 bstc_alloc_pack_free(bstc_free)
    #define alloc2 bstc_alloc_pack_malloc(bstc_malloc)
    #define alloc3 bstc_alloc_pack_realloc(bstc_realloc)
    #define alloc4 bstc_ctuple(1, 2, 3, 4)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(alloc1));
    bstc_alloc_isa(alloc1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(alloc2));
    bstc_alloc_isa(alloc2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(alloc3));
    bstc_alloc_isa(alloc3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(alloc4));
    bstc_alloc_isa(alloc4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(bstc_alloc_defaults));
    bstc_alloc_isa(bstc_alloc_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_alloc_isa(%s):\n", BSTC_TOSTRING(bstc_alloc_stdlib));
    bstc_alloc_isa(bstc_alloc_stdlib, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define alloc5 bstc_alloc((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define alloc6 bstc_alloc((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define alloc7 bstc_alloc((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_alloc_free(tpl):\n");
    bstc_alloc_free(alloc5);
    printf("bstc_alloc_malloc(tpl):\n");
    bstc_alloc_malloc(alloc6);
    printf("bstc_alloc_realloc(tpl):\n");
    bstc_alloc_realloc(alloc7);

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
