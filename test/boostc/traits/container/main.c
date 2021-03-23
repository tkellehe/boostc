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
    bstc_unused_param(argc);
    bstc_unused_param(argv);
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_container_isa
    //--------------------------------------------------------------------------------------------------------
    #define container1 bstc_container_pack_t(A)
    #define container2 bstc_container_pack_info((B))
    #define container3 bstc_container_pack_subtraits(bstc_ctuple(C, CC, CCC))
    #define container4 bstc_container_pack_obj(bstc_obj_pack_t(D))
    #define container5 bstc_container_pack_alloc(bstc_alloc_pack_free(E))
    #define containerN bstc_ctuple(1, 2, 3, 4)

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
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(containerN));
    bstc_container_isa(containerN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_container_isa(%s)\n", bstc_ctuple_tostring(bstc_container_defaults));
    bstc_container_isa(bstc_container_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define containerA bstc_container_traits((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerB bstc_container_traits((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerC bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define containerD bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define containerE bstc_container_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_container_t(tpl):\n");
    bstc_container_t(containerA);
    printf("bstc_container_info(tpl):\n");
    bstc_container_info(containerB);
    printf("bstc_container_subtraits(tpl):\n");
    bstc_container_subtraits(containerC);
    printf("bstc_container_obj(tpl):\n");
    bstc_container_obj(containerD);
    printf("bstc_container_alloc(tpl):\n");
    bstc_container_alloc(containerE);

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
