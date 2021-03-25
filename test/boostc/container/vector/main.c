//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/stdlib.h>
#include <boostc/container/vector.h>
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
    bstc_unused_param(argc);
    bstc_unused_param(argv);
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #define vtraits1 bstc_vect_traits(int)
    #define vtraits2 bstc_vect_traits(float, bstc_alloc_defaults)
    #define vtraits3 bstc_vect_traits(float, bstc_alloc_traits(my_free, my_malloc, my_realloc))

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_vect_traits(int): %s\n", bstc_ctuple_tostring(vtraits1));
    bstc_container_isa(vtraits1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_vect_traits(float, bstc_alloc_defaults): %s\n", bstc_ctuple_tostring(vtraits2));
    bstc_container_isa(vtraits2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_vect_traits(float, %s): %s\n", bstc_ctuple_tostring(bstc_ctuple(my_free, my_malloc, my_realloc)), bstc_ctuple_tostring(vtraits3));
    bstc_container_isa(vtraits3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(float) vect;
        bstc_vect_init(&vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(&vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(float) vect;
        bstc_vect_init(&vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(&vect));
        if(bstc_vect_len(&vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_pushb(&vect, 0.0f);
        printf("bstc_vect_t(float) & bstc_vect_pushb(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("vect[0]: %f\n", vect[0]);
        if(vect[0] == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(&vect));
        if(bstc_vect_len(&vect) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(&vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtraits3) vect;
        bstc_vect_init(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtraits3) vect;
        bstc_vect_init(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtraits3, &vect));
        if(bstc_vect_len(vtraits3, &vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_pushb(vtraits3, &vect, 0.0f);
        printf("bstc_vect_t(float) & bstc_vect_pushb(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("vect[0]: %f\n", bstc_vect_at(vtraits3, &vect, 0));
        if(bstc_vect_at(vtraits3, &vect, 0) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtraits3, &vect));
        if(bstc_vect_len(vtraits3, &vect) == 1) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtraits3) vect;
        bstc_vect_init(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtraits3, &vect));
        if(bstc_vect_len(vtraits3, &vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsz(vtraits3, &vect, 10);
        printf("bstc_vect_t(float) & bstc_vect_rsz(vect, 10): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtraits3, &vect));
        if(bstc_vect_len(vtraits3, &vect) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtraits3) vect;
        bstc_vect_init(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_cap(vect): %i\n", (int)bstc_vect_cap(vtraits3, &vect));
        if(bstc_vect_cap(vtraits3, &vect) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsv(vtraits3, &vect, 100);
        printf("bstc_vect_t(float) & bstc_vect_rsv(vect, 100): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_cap(vect): %i\n", (int)bstc_vect_cap(vtraits3, &vect));
        if(bstc_vect_cap(vtraits3, &vect) == 100) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(bstc_vect_data(vtraits3, &vect) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(vtraits3) vect;
        bstc_vect_init(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_init(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_empty(vect): %i\n", (int)bstc_vect_empty(vtraits3, &vect));
        if(bstc_vect_empty(vtraits3, &vect)) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_rsz(vtraits3, &vect, 10);
        printf("bstc_vect_t(float) & bstc_vect_rsz(vect, 10): %p\n", (void*)bstc_vect_data(&vect));
        if(vect != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        printf("bstc_vect_len(vect): %i\n", (int)bstc_vect_len(vtraits3, &vect));
        if(bstc_vect_len(vtraits3, &vect) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        vect[1] = 0.0f;
        printf("bstc_vect_at(vect, 1): %f\n", bstc_vect_at(&vect, 1));
        if(bstc_vect_at(&vect, 1) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_front(&vect) = 0.0f;
        printf("bstc_vect_front(vect): %f\n", bstc_vect_front(&vect));
        if(bstc_vect_front(&vect) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_back(&vect) = 0.0f;
        printf("bstc_vect_back(vect): %f\n", bstc_vect_back(&vect));
        if(bstc_vect_back(&vect) == 0.0f) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
        bstc_vect_destroy(vtraits3, &vect);
        printf("bstc_vect_t(float) & bstc_vect_destroy(vect): %p\n", (void*)bstc_vect_data(&vect));
        if(vect == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    {
        bstc_vect_t(double) vect1;
        bstc_vect_t(double) vect2;
        bstc_vect_init(&vect1);

        bstc_vect_clone(&vect2, &vect1);
        printf("bstc_vect_clone(%p, %p):\n", (void*)bstc_vect_data(&vect1), (void*)bstc_vect_data(&vect2));
        if(vect2 == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_destroy(&vect2);

        bstc_vect_pushb(&vect1, 1.2);

        bstc_vect_clone(&vect2, &vect1);
        printf("bstc_vect_clone(%p, %p):\n", (void*)bstc_vect_data(&vect1), (void*)bstc_vect_data(&vect2));
        if(vect2 != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        printf("vect1[0] == vect2[0]: %f %f\n", vect1[0], vect2[0]);
        if(vect1[0] == vect2[0]) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        bstc_vect_destroy(&vect1);
    }

    //--------------------------------------------------------------------------------------------------------
    {
        #define vect_vect_int bstc_vect_traits(bstc_vect_t(int), bstc_vect_traits(int))
        bstc_vect_t(vect_vect_int) vects;

        bstc_vect_init(vect_vect_int, &vects);

        printf("bstc_vect_cap(vects): %i\n", (int)bstc_vect_cap(vect_vect_int, &vects));
        if(bstc_vect_cap(vect_vect_int, &vects) == 0) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

        {
            bstc_size_t i;
            bstc_vect_rsz(vect_vect_int, &vects, 3);

            printf("bstc_vect_cap(vects): %i\n", (int)bstc_vect_cap(vect_vect_int, &vects));
            if(bstc_vect_cap(vect_vect_int, &vects) >= 3) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

            printf("bstc_vect_len(vects): %i\n", (int)bstc_vect_len(vect_vect_int, &vects));
            if(bstc_vect_len(vect_vect_int, &vects) == 3) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

            for(i = 0; i < bstc_vect_len(vect_vect_int, &vects); ++i)
            {
                bstc_vect_init(vect_vect_int, vects + i);
                printf("bstc_vect_init(vects[%i]): %p\n", (int)i, (void*)bstc_vect_data(vects + i));
                if(bstc_vect_data(vects + i) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
            }

            for(i = 0; i < bstc_vect_len(vect_vect_int, &vects); ++i)
            {
                bstc_vect_rsz(vect_vect_int, vects + i, 10);
                printf("bstc_vect_rsz(vects[%i]): %p\n", (int)i, (void*)bstc_vect_data(vects + i));
                if(bstc_vect_data(vects + i) != bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
                printf("bstc_vect_cap(vects[%i]): %i\n", (int)i, (int)bstc_vect_cap(vect_vect_int, vects + i));
                if(bstc_vect_cap(vect_vect_int, vects + i) >= 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");

                printf("bstc_vect_len(vects[%i]): %i\n", (int)i, (int)bstc_vect_len(vect_vect_int, vects + i));
                if(bstc_vect_len(vect_vect_int, vects + i) == 10) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
            }

            for(i = 0; i < bstc_vect_len(vect_vect_int, &vects); ++i)
            {
                bstc_vect_destroy(vect_vect_int, vects + i);
                printf("bstc_vect_destroy(vects[%i]): %p\n", (int)i, (void*)bstc_vect_data(vects + i));
                if(bstc_vect_data(vects + i) == bstc_nullptr) ++num_pass, printf("    passed\n"); else ++num_fail, printf("    failed\n");
            }
        }

        bstc_vect_destroy(vect_vect_int, &vects);
    }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
