//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/traits/container.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused_param(argc);;
    bstc_unused_param(argv);;
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_container_isa
    //--------------------------------------------------------------------------------------------------------
    #define container1 bstc_container_pack_t(A)
    #define container2 bstc_container_pack_subtraits(bstc_ctuple(B, BB, BBB))
    #define container3 bstc_container_pack_fns(bstc_ctuple(C, CC, CCC))
    #define container4 bstc_container_pack_iter(bstc_iter_pack_t(D))
    #define container5 bstc_container_pack_riter(bstc_iter_pack_t(E))
    #define container6 bstc_container_pack_alloc(bstc_alloc_pack_free(F))
    #define containerN bstc_container_traits(1, 2, 3, 4, 5, 6)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container1));
    bstc_container_isa(container1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container2));
    bstc_container_isa(container2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container3));
    bstc_container_isa(container3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container4));
    bstc_container_isa(container4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container5));
    bstc_container_isa(container5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(container6));
    bstc_container_isa(container6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(containerN));
    bstc_container_isa(containerN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(bstc_container_defaults));
    bstc_container_isa(bstc_container_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define containerA bstc_container_traits((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerB bstc_container_traits((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerC bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerD bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerE bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define containerF bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_container_t(tpl):\n");
    bstc_container_t(containerA);
    printf("bstc_container_subtraits(tpl):\n");
    bstc_container_subtraits(containerB);
    printf("bstc_container_fns(tpl):\n");
    bstc_container_fns(containerC);
    printf("bstc_container_iter(tpl):\n");
    bstc_container_iter(containerD);
    printf("bstc_container_riter(tpl):\n");
    bstc_container_riter(containerE);
    printf("bstc_container_alloc(tpl):\n");
    bstc_container_alloc(containerF);

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
