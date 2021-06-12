//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/traits/object.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_obj_isa
    //--------------------------------------------------------------------------------------------------------
    #define obj1 bstc_obj_pack_t(A)
    #define obj2 bstc_obj_pack_init(B)
    #define obj3 bstc_obj_pack_destroy(C)
    #define obj4 bstc_obj_pack_clone(D)
    #define obj5 bstc_obj_pack_copy(E)
    #define obj6 bstc_obj_pack_move(F)
    #define obj7 bstc_obj_pack_assign(G)
    #define obj8 bstc_obj_pack_extend(H)
    #define objN bstc_ctuple(1, 2, 3)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj1));
    bstc_obj_isa(obj1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj2));
    bstc_obj_isa(obj2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj3));
    bstc_obj_isa(obj3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj4));
    bstc_obj_isa(obj4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj5));
    bstc_obj_isa(obj5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj6));
    bstc_obj_isa(obj6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj7));
    bstc_obj_isa(obj7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(obj8));
    bstc_obj_isa(obj8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(objN));
    bstc_obj_isa(objN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_obj_isa(%s)\n", bstc_ctuple_tostring(bstc_obj_defaults));
    bstc_obj_isa(bstc_obj_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define objA bstc_obj_traits((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objB bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objC bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objD bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objE bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objF bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define objG bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define objH bstc_obj_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_obj_t(tpl):\n");
    bstc_obj_t(objA);
    printf("bstc_obj_init(tpl):\n");
    bstc_obj_init(objB);
    printf("bstc_obj_destroy(tpl):\n");
    bstc_obj_destroy(objC);
    printf("bstc_obj_clone(tpl):\n");
    bstc_obj_clone(objD);
    printf("bstc_obj_copy(tpl):\n");
    bstc_obj_copy(objE);
    printf("bstc_obj_move(tpl):\n");
    bstc_obj_move(objF);
    printf("bstc_obj_assign(tpl):\n");
    bstc_obj_assign(objG);
    printf("bstc_obj_extend(tpl):\n");
    bstc_obj_extend(objH);

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
