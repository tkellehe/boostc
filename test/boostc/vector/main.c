//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/algorithm/find.h>
#include <boostc/stdlib.h>
#include <boostc/vector.h>
#include <stdio.h>

void my_free(void *mem)
{
    bstc_free(mem);
}

void *my_malloc(int size)
{
    return bstc_malloc(size);
}

void *my_realloc(void *mem, int size)
{
    return bstc_realloc(mem, size);
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #define vtmplt1 bstc_vect_tmplt_t(int)
    #define vtmplt2 bstc_vect_tmplt_t(float, bstc_alloc_defaults)
    #define vtmplt3 bstc_vect_tmplt_t(float, bstc_ctuple(my_free, my_malloc, my_realloc))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_vect_tmplt_t(int): %s\n", bstc_ctuple_tostring(vtmplt1));
    bstc_tmplt_isa(vtmplt1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_vect_tmplt_t(float, bstc_alloc_defaults): %s\n", bstc_ctuple_tostring(vtmplt2));
    bstc_tmplt_isa(vtmplt2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_vect_tmplt_t(float, %s): %s\n", bstc_ctuple_tostring(bstc_ctuple(my_free, my_malloc, my_realloc)), bstc_ctuple_tostring(vtmplt3));
    bstc_tmplt_isa(vtmplt3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(float) vect;
        bstc_vect_init(vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(float) vect;
        bstc_vect_init(vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vect));
        if(bstc_vect_len(vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_push(vect, 0.0f);
        printf("bstc_vect_t(float) & bstc_vect_push(vect): %p\n", (void*)vect);
        if(vect != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("vect[0]: %f\n", vect[0]);
        if(vect[0] == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vect));
        if(bstc_vect_len(vect) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtmplt3) vect;
        bstc_vect_init(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtmplt3) vect;
        bstc_vect_init(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtmplt3, vect));
        if(bstc_vect_len(vtmplt3, vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_push(vtmplt3, vect, 0.0f);
        printf("bstc_vect_t(float) & bstc_vect_push(vect): %p\n", (void*)vect);
        if(vect != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("vect[0]: %f\n", vect[0]);
        if(vect[0] == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtmplt3, vect));
        if(bstc_vect_len(vtmplt3, vect) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtmplt3) vect;
        bstc_vect_init(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtmplt3, vect));
        if(bstc_vect_len(vtmplt3, vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsz(vtmplt3, vect, 10);
        printf("bstc_vect_t(float) & bstc_vect_rsz(vect, 10): %p\n", (void*)vect);
        if(vect != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtmplt3, vect));
        if(bstc_vect_len(vtmplt3, vect) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtmplt3) vect;
        bstc_vect_init(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_cap(vect): %i\n", (int)bstc_vect_cap(vtmplt3, vect));
        if(bstc_vect_cap(vtmplt3, vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsv(vtmplt3, vect, 100);
        printf("bstc_vect_t(float) & bstc_vect_rsv(vect, 100): %p\n", (void*)vect);
        if(vect != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_cap(vect): %i\n", (int)bstc_vect_cap(vtmplt3, vect));
        if(bstc_vect_cap(vtmplt3, vect) == 100) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtmplt3) vect;
        bstc_vect_init(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_empty(vect): %i\n", (int)bstc_vect_empty(vtmplt3, vect));
        if(bstc_vect_empty(vtmplt3, vect)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsz(vtmplt3, vect, 10);
        printf("bstc_vect_t(float) & bstc_vect_rsz(vect, 10): %p\n", (void*)vect);
        if(vect != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtmplt3, vect));
        if(bstc_vect_len(vtmplt3, vect) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        vect[1] = 0.0f;
        printf("bstc_vect_at(vect, 1): %f\n", bstc_vect_at(vect, 1));
        if(bstc_vect_at(vect, 1) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_front(vect) = 0.0f;
        printf("bstc_vect_front(vect): %f\n", bstc_vect_front(vect));
        if(bstc_vect_front(vect) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_back(vect) = 0.0f;
        printf("bstc_vect_back(vect): %f\n", bstc_vect_back(vect));
        if(bstc_vect_back(vect) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtmplt3, vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)vect);
        if(vect == bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(int) vect;
        bstc_vect_iter_t(int) iter;
        bstc_vect_riter_t(int) riter;
        
        bstc_vect_init(vect);
        bstc_vect_rsz(vect, 4);

        vect[0] = 0;
        vect[1] = 1;
        vect[2] = 2;
        vect[3] = 3;

        iter = bstc_vect_end(vect);
        printf("bstc_vect_end(vect): %p\n", (void*)bstc_vect_end(vect));
        if(iter != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        riter = bstc_vect_rend(vect);
        printf("bstc_vect_rend(vect): %p\n", (void*)bstc_vect_rend(vect));
        if(riter != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");



        iter = bstc_vect_begin(vect);
        printf("bstc_vect_begin(vect): %p\n", (void*)bstc_vect_begin(vect));
        if(iter != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        printf("bstc_vect_iter_val(iter): %i\n", bstc_vect_iter_val(iter));
        if(bstc_vect_iter_val(iter) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_iter_nxt(iter);
        printf("bstc_vect_iter_val(iter): %i\n", bstc_vect_iter_val(iter));
        if(bstc_vect_iter_val(iter) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_iter_set(iter, 10);
        printf("bstc_vect_iter_set(iter, 10): %i\n", bstc_vect_iter_val(iter));
        if(bstc_vect_iter_val(iter) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        printf("bstc_vect_iter_eq(iter, end)\n");
        if(!bstc_vect_iter_eq(iter, bstc_vect_end(vect))) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_iter_swap(iter, bstc_vect_begin(vect));
        printf("bstc_vect_iter_swap(iter, begin): {%i, %i, %i, %i}\n", vect[0], vect[1], vect[2], vect[3]);
        if(vect[0] == 10 && vect[1] == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");



        riter = bstc_vect_rbegin(vect);
        printf("bstc_vect_rbegin(vect): %p\n", (void*)bstc_vect_rbegin(vect));
        if(riter != bstc_null) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        printf("bstc_vect_riter_val(iter): %i\n", bstc_vect_riter_val(riter));
        if(bstc_vect_riter_val(riter) == 3) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_riter_nxt(riter);
        printf("bstc_vect_riter_val(riter): %i\n", bstc_vect_riter_val(riter));
        if(bstc_vect_riter_val(riter) == 2) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_riter_set(riter, 11);
        printf("bstc_vect_riter_set(riter, 11): %i\n", bstc_vect_riter_val(riter));
        if(bstc_vect_riter_val(riter) == 11) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        printf("bstc_vect_riter_eq(riter, rend)\n");
        if(!bstc_vect_riter_eq(riter, bstc_vect_rend(vect))) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_riter_swap(riter, bstc_vect_rbegin(vect));
        printf("bstc_vect_riter_swap(riter, rbegin): {%i, %i, %i, %i}\n", vect[0], vect[1], vect[2], vect[3]);
        if(vect[3] == 11 && vect[2] == 3) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");


        bstc_vect_destroy(vect);
    }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
