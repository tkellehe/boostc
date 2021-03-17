//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/traits/iterator.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused_param(argc);;
    bstc_unused_param(argv);;
    int num_pass = 0;
    int num_fail = 0;

#ifdef bstc_iter_isa
    //--------------------------------------------------------------------------------------------------------
    #define iter1 bstc_iter_pack_t(A)
    #define iter2 bstc_iter_pack_nxt(B)
    #define iter3 bstc_iter_pack_eq(C)
    #define iter4 bstc_iter_pack_val(D)
    #define iter5 bstc_iter_pack_put(E)
    #define iter6 bstc_iter_pack_swap(F)
    #define iterN bstc_ctuple(1, 2, 3, 4)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter1));
    bstc_iter_isa(iter1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter2));
    bstc_iter_isa(iter2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter3));
    bstc_iter_isa(iter3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter4));
    bstc_iter_isa(iter4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter5));
    bstc_iter_isa(iter5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iter6));
    bstc_iter_isa(iter6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(iterN));
    bstc_iter_isa(iterN, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bstc_iter_isa(%s):\n", bstc_ctuple_tostring(bstc_iter_defaults));
    bstc_iter_isa(bstc_iter_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
#endif

    //--------------------------------------------------------------------------------------------------------
    #define iterA bstc_iter_traits((++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define iterB bstc_iter_traits((++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define iterC bstc_iter_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define iterD bstc_iter_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")))
    #define iterE bstc_iter_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")))
    #define iterF bstc_iter_traits((++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_iter_t(tpl):\n");
    bstc_iter_t(iterA);
    printf("bstc_iter_nxt(tpl):\n");
    bstc_iter_nxt(iterB);
    printf("bstc_iter_eq(tpl):\n");
    bstc_iter_eq(iterC);
    printf("bstc_iter_val(tpl):\n");
    bstc_iter_val(iterD);
    printf("bstc_iter_put(tpl):\n");
    bstc_iter_put(iterE);
    printf("bstc_iter_swap(tpl):\n");
    bstc_iter_swap(iterF);

    //--------------------------------------------------------------------------------------------------------
    {
        #define int_iter_nxt(iter) (++iter)
        #define int_iter_eq(l, r) (l == r)
        #define int_iter bstc_iter_traits(int*, int_iter_nxt, int_iter_eq, bstc_iter_noval, bstc_iter_noput, bstc_iter_noswap)
        int array[5] = {1, 2, 3, 4, 5};
        int* iter = (int*)array;
        int* end = (int*)(array + 5);
        int cnt = 0;
        bstc_iter_foreach(int_iter, iter, end)
        {
            printf("iterator array[%i] = %i:\n", cnt++, *iter);
            if(*iter == cnt)
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
    }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
