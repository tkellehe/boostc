//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONTAINER__DETAIL__VECTOR_H
#define BOOSTC__CONTAINER__DETAIL__VECTOR_H


#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stddef.h>
#include <boostc/stdint.h>
#include <boostc/string.h>
#include <boostc/traits/container.h>


/* Details for vector */
/// \{
#define bstc_dtl_vect_traits_select(tpl) \
    bstc_ctuple_hasN(tpl, 1,\
        bstc_dtl_vect_traits1,\
        bstc_ctuple_hasN(tpl, 2,\
            bstc_dtl_vect_traits2,\
            bstc_ctuple_hasN(tpl, 3,\
                bstc_dtl_vect_traits3,\
                bstc_dtl_vect_traits4\
            )\
        )\
    )

#define bstc_dtl_vect_traits1(T) \
    (\
        T*,\
        bstc_container_pack_t(T),\
        bstc_dtl_vect_default_fns,\
        bstc_dtl_vect_iter_defaults(T),\
        bstc_dtl_vect_riter_defaults(T),\
        bstc_alloc_stdlib\
    )

#define bstc_dtl_vect_traits2(T, alloc) \
    (\
        T*,\
        bstc_container_pack_t(T),\
        bstc_dtl_vect_default_fns,\
        bstc_dtl_vect_iter_defaults(T),\
        bstc_dtl_vect_riter_defaults(T),\
        alloc\
    )

#define bstc_dtl_vect_traits3(T, alloc, subtraits) \
    (\
        T*,\
        subtraits,\
        bstc_dtl_vect_default_fns,\
        bstc_dtl_vect_iter_defaults(T),\
        bstc_dtl_vect_riter_defaults(T),\
        alloc\
    )

#define bstc_dtl_vect_default_fns \
    bstc_ctuple(\
        bstc_dtl_vect_default_init,\
        bstc_dtl_vect_default_destroy\
    )

#define bstc_dtl_vect_add_traits(tpl) bstc_container_isa(bstc_ctuple_getI(tpl, 0), tpl, bstc_ctuple_prepend(tpl, bstc_dtl_vect_traits1(void)))


#define bstc_dtl_vect_init(traits, vect) \
    do {\
        *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_malloc(bstc_container_alloc(traits))(sizeof(*(vect))*(2) + 2*sizeof(bstc_intptr_t)) + 2);\
        bstc_dtl_vect_len_((vect)) = 0;\
        bstc_dtl_vect_cap_((vect)) = 2;\
    } while(0)


#define bstc_dtl_vect_destroy(traits, vect) \
    do {\
        bstc_intptr_t __bstc_dtl_i;\
        for(__bstc_dtl_i = bstc_dtl_vect_len_(vect); __bstc_dtl_i--;)\
            bstc_container_dtor(bstc_container_subtraits(traits))(bstc_container_subtraits(traits), vect[i]);\
        bstc_alloc_free(bstc_container_alloc(traits))(bstc_dtl_vect_raw_(vect));\
        *((void**)&(vect)) = bstc_nullptr;\
    } while(0)


#define bstc_dtl_vect_len(traits, vect) (bstc_size_t)bstc_dtl_vect_len_(vect)
#define bstc_dtl_vect_cap(traits, vect) (bstc_size_t)bstc_dtl_vect_cap_(vect)
#define bstc_dtl_vect_empty(traits, vect) (bstc_dtl_vect_len(traits, vect) == 0)
#define bstc_dtl_vect_at(traits, vect, i) ((vect)[(i)])
#define bstc_dtl_vect_front(traits, vect) (vect)[0]
#define bstc_dtl_vect_back(traits, vect) (vect)[bstc_dtl_vect_len_(vect)-1]

#define bstc_dtl_vect_rsz(traits, vect, nsz) \
    do {\
        bstc_intptr_t __bstc_dtl_nsz = (bstc_intptr_t)(nsz);\
        /* Check to see if the new size already fits. */\
        if(bstc_dtl_vect_cap_(vect) < __bstc_dtl_nsz) {\
            /* Since it does not fit, check to see if twice the current size will hold the new size. */\
            if(bstc_dtl_vect_cap_(vect)*2 > __bstc_dtl_nsz) {\
                *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_container_alloc(traits))(\
                    bstc_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*(bstc_dtl_vect_cap_(vect)*2) + 2*sizeof(bstc_intptr_t)\
                ) + 2);\
                bstc_dtl_vect_cap_(vect) = (bstc_dtl_vect_cap_(vect)*2);\
                bstc_dtl_vect_len_(vect) = __bstc_dtl_nsz;\
            }else{\
                *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_container_alloc(traits))(\
                    bstc_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*__bstc_dtl_nsz + 2*sizeof(bstc_intptr_t)\
                ) + 2);\
                bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)__bstc_dtl_nsz;\
                bstc_dtl_vect_len_(vect) = bstc_dtl_vect_cap_(vect);\
            }\
        }else{\
            bstc_dtl_vect_len_(vect) = __bstc_dtl_nsz;\
        }\
    } while(0)

#define bstc_dtl_vect_rsv(traits, vect, ncap) \
/* Check to see if the vector has anything allocated yet. */\
    do {\
        /* Check to see if the new capacity already fits. */\
        bstc_intptr_t __bstc_dtl_ncap = (bstc_intptr_t)(ncap);\
        if(bstc_dtl_vect_cap_(vect) < __bstc_dtl_ncap) {\
            *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_container_alloc(traits))(\
                bstc_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(__bstc_dtl_ncap) + 2*sizeof(bstc_intptr_t)\
            ) + 2);\
            bstc_dtl_vect_cap_(vect) = __bstc_dtl_ncap;\
        }\
    } while(0)

#define bstc_dtl_vect_pushb(traits, vect, val) \
    do {\
        if(bstc_dtl_vect_cap_(vect) < (bstc_dtl_vect_len_(vect)+1))\
        {\
            *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_container_alloc(traits))(\
                bstc_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(bstc_dtl_vect_cap_(vect)*2) + 2*sizeof(bstc_intptr_t)\
            ) + 2);\
            bstc_dtl_vect_cap_(vect) *= 2;\
            (vect)[bstc_dtl_vect_len_(vect)++] = (val);\
        }else{\
            (vect)[bstc_dtl_vect_len_(vect)++] = (val);\
        }\
    } while(0)


#define bstc_dtl_vect_begin(traits, vect) (vect)
#define bstc_dtl_vect_end(traits, vect) ((vect)+bstc_dtl_vect_len(traits, vect))
#define bstc_dtl_vect_rbegin(traits, vect) ((vect)+bstc_dtl_vect_len(traits, vect))
#define bstc_dtl_vect_rend(traits, vect) (vect)


// The type bstc_intptr_t is used because the memory may need to be word aligned.
// This does assume that bstc_intptr_t causes the memory to be word aligned.
#define bstc_dtl_vect_raw_(vect) ((bstc_intptr_t*)(void*)(vect) - 2)
#define bstc_dtl_vect_cap_(vect) (bstc_dtl_vect_raw_(vect)[0])
#define bstc_dtl_vect_len_(vect) (bstc_dtl_vect_raw_(vect)[1])

#define bstc_dtl_vect_iter_defaults(T) \
    bstc_ctuple(\
        bstc_dtl_vect_default_iter_t(T),\
        bstc_dtl_vect_default_iter_nxt,\
        bstc_dtl_vect_default_iter_eq,\
        bstc_dtl_vect_default_iter_val,\
        bstc_dtl_vect_default_iter_put,\
        bstc_dtl_vect_default_iter_swap\
    )


#define bstc_dtl_vect_default_iter_t(T) T*

#define bstc_dtl_vect_iter_nxt(traits, iter) BSTC_CALL(bstc_iter_nxt(bstc_container_iter(traits)), iter)
#define bstc_dtl_vect_default_iter_nxt(iter) (++iter)

#define bstc_dtl_vect_iter_eq(traits, left, right) BSTC_CALL(bstc_iter_eq(bstc_container_iter(traits)), left, right)
#define bstc_dtl_vect_default_iter_eq(left, right) (left == right)

#define bstc_dtl_vect_iter_val(traits, iter) BSTC_CALL(bstc_iter_val(bstc_container_iter(traits)), iter)
#define bstc_dtl_vect_default_iter_val(iter) *(iter)

#define bstc_dtl_vect_iter_put(traits, iter, val) BSTC_CALL(bstc_iter_put(bstc_container_iter(traits)), iter, val)
#define bstc_dtl_vect_default_iter_put(iter, val) (*(iter) = val)

#define bstc_dtl_vect_iter_swap(traits, left, right) BSTC_CALL(bstc_iter_swap(bstc_container_iter(traits)), left, right)
#define bstc_dtl_vect_default_iter_swap(left, right) \
    {\
        char __bstc_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bstc_dtl_swap, (void*)(left), sizeof(*(left)));\
        memcpy((void*)(left), (void*)(right), sizeof(*(left)));\
        memcpy((void*)(right), (void*)__bstc_dtl_swap, sizeof(*(left)));\
    }

#define bstc_dtl_vect_riter_defaults(T) \
    bstc_ctuple(\
        bstc_dtl_vect_default_riter_t(T),\
        bstc_dtl_vect_default_riter_nxt,\
        bstc_dtl_vect_default_riter_eq,\
        bstc_dtl_vect_default_riter_val,\
        bstc_dtl_vect_default_riter_put,\
        bstc_dtl_vect_default_riter_swap\
    )


#define bstc_dtl_vect_default_riter_t(T) T*

#define bstc_dtl_vect_riter_nxt(traits, riter) BSTC_CALL(bstc_iter_nxt(bstc_container_riter(traits)), riter)
#define bstc_dtl_vect_default_riter_nxt(riter) (--riter)

#define bstc_dtl_vect_riter_eq(traits, left, right) BSTC_CALL(bstc_iter_eq(bstc_container_riter(traits)), left, right)
#define bstc_dtl_vect_default_riter_eq(left, right) (left == right)

#define bstc_dtl_vect_riter_val(traits, riter) BSTC_CALL(bstc_iter_val(bstc_container_riter(traits)), riter)
#define bstc_dtl_vect_default_riter_val(riter) *((riter)-1)

#define bstc_dtl_vect_riter_put(traits, riter, val) BSTC_CALL(bstc_iter_put(bstc_container_riter(traits)), riter, val)
#define bstc_dtl_vect_default_riter_put(riter, val) (*((riter)-1) = val)

#define bstc_dtl_vect_riter_swap(traits, left, right) BSTC_CALL(bstc_iter_swap(bstc_container_riter(traits)), left, right)
#define bstc_dtl_vect_default_riter_swap(left, right) \
    {\
        char __bstc_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bstc_dtl_swap, (void*)((left)-1), sizeof(*(left)));\
        memcpy((void*)((left)-1), (void*)((right)-1), sizeof(*(left)));\
        memcpy((void*)((right)-1), (void*)__bstc_dtl_swap, sizeof(*(left)));\
    }
/// \}


#endif // BOOSTC__CONTAINER__DETAIL__VECTOR_H
