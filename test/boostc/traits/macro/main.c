//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/traits/macro.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_macro_isa
    //--------------------------------------------------------------------------------------------------------
    #define macro1 bstc_macro_pack(A)
    #define macroN bstc_ctuple(1, 2, 3)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_macro_isa(%s)\n", bstc_ctuple_tostring(macro1));
    bstc_macro_isa(macro1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_macro_isa(%s)\n", bstc_ctuple_tostring(macroN));
    bstc_macro_isa(macroN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_macro_isa(%s)\n", bstc_ctuple_tostring(bstc_macro_defaults));
    bstc_macro_isa(bstc_macro_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define macroA bstc_macro_traits((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define macroB bstc_macro_traits((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_macro_id(tpl):\n");
    bstc_macro_id(macroA);
    printf("bstc_macro(tpl):\n");
    bstc_macro(macroB);

    //--------------------------------------------------------------------------------------------------------
    #define F(id, cmp) if(id == cmp) (++num_pass, printf("    passed\n")); else (++num_fail, printf("    failed\n"));
    #define macro bstc_macro_pack(F)

    printf("bstc_macro_id == 0:\n");
    bstc_macro(macro) (bstc_macro_id(macro), 0);

    #define next bstc_macro_next(macro)

    printf("bstc_macro_next == 1:\n");
    bstc_macro(next) (bstc_macro_id(next), 1);

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
