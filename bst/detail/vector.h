//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__DETAIL__VECTOR_H
#define BST__DETAIL__VECTOR_H


/* Packs the iterator defaults */
#define bst_dtl_vect_iter_defaults(T) bst_ctuple(bst_dtl_vect_iter_t(T), bst_dtl_vect_iter_nxt, bst_dtl_vect_iter_eq, bst_dtl_vect_iter_val, bst_dtl_vect_iter_set, bst_dtl_vect_iter_swap)


#define bst_dtl_vect_iter_t(T) T*
#define bst_dtl_vect_iter_nxt(iter) (++iter)
#define bst_dtl_vect_iter_eq(left, right) (left == right)
#define bst_dtl_vect_iter_val(iter) *(iter)
#define bst_dtl_vect_iter_set(iter, val) (*(iter) = val)
#define bst_dtl_vect_iter_swap(left, right) \
    {\
        char __bst_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bst_dtl_swap, (void*)(left), sizeof(*(left)));\
        memcpy((void*)(left), (void*)(right), sizeof(*(left)));\
        memcpy((void*)(right), (void*)__bst_dtl_swap, sizeof(*(left)));\
    }


/* Packs the iterator defaults */
#define bst_dtl_vect_riter_defaults(T) bst_ctuple(bst_dtl_vect_riter_t(T), bst_dtl_vect_riter_nxt, bst_dtl_vect_riter_eq, bst_dtl_vect_riter_val, bst_dtl_vect_riter_set, bst_dtl_vect_riter_swap)


#define bst_dtl_vect_riter_t(T) T*
#define bst_dtl_vect_riter_nxt(riter) (--riter)
#define bst_dtl_vect_riter_eq(left, right) (left == right)
#define bst_dtl_vect_riter_val(riter) *((riter)-1)
#define bst_dtl_vect_riter_set(riter, val) (*((riter)-1) = val)
#define bst_dtl_vect_riter_swap(left, right) \
    {\
        char __bst_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bst_dtl_swap, (void*)(left), sizeof(*(left)));\
        memcpy((void*)(left), (void*)(right), sizeof(*(left)));\
        memcpy((void*)(right), (void*)__bst_dtl_swap, sizeof(*(left)));\
    }


/* Detail code */
/// \{
#define bst_dtl_vect_tmplt_t(T, ...) \
    bst_tmplt_ctuple(\
        T*,\
        (T),\
        bst_dtl_vect_default_fns,\
        bst_dtl_vect_iter_defaults(T),\
        bst_dtl_vect_riter_defaults(T),\
        bst_ctuple_empty(bst_ctuple(__VA_ARGS__),\
            bst_alloc_stdlib,\
            bst_alloc_isa(bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0),\
                bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0),\
                bst_alloc_stdlib\
            )\
        )\
    )

// Preparing for potential specialization concept.
#define bst_dtl_vect_default_fns \
    bst_ctuple(\
        bst_dtl_vect_init,\
        bst_dtl_vect_destroy,\
        bst_dtl_vect_len,\
        bst_dtl_vect_cap,\
        bst_dtl_vect_rsz,\
        bst_dtl_vect_rsv,\
        bst_dtl_vect_at,\
        bst_dtl_vect_empty,\
        bst_dtl_vect_front,\
        bst_dtl_vect_back,\
        bst_dtl_vect_push,\
        bst_dtl_vect_begin,\
        bst_dtl_vect_end,\
        bst_dtl_vect_rbegin,\
        bst_dtl_vect_rend\
    )

#define bst_dtl_vect_init(tmplt, vect) (*((void**)&(vect)) = bst_null)
#define bst_dtl_vect_destroy(tmplt, vect) ((vect) ? bst_alloc_free(bst_tmplt_alloc(tmplt))(bst_dtl_vect_raw_(vect)),*((void**)&(vect))=bst_null,1 : 0)
#define bst_dtl_vect_len(tmplt, vect) ((vect) ? (int)bst_dtl_vect_len_(vect) : 0)
#define bst_dtl_vect_cap(tmplt, vect) ((vect) ? (int)bst_dtl_vect_cap_(vect) : 0)
#define bst_dtl_vect_rsz(tmplt, vect, nsz) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new size already fits. */\
    (bst_dtl_vect_cap_(vect) < (nsz) ?\
        /* Since it does not fit, check to see if twice the current size will hold the new size. */\
        (bst_dtl_vect_cap_(vect)*2 > (nsz) ?\
            (\
                *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*(bst_dtl_vect_cap_(vect)*2) + 2*sizeof(bst_intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap_(vect) = (bst_dtl_vect_cap_(vect)*2),\
                (bst_dtl_vect_len_(vect) = (bst_intptr_t)(nsz))\
            )\
        :\
            (\
                *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*(nsz) + 2*sizeof(bst_intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap_(vect) = (bst_intptr_t)(nsz),\
                (bst_dtl_vect_len_(vect) = bst_dtl_vect_cap_(vect))\
            )\
        )\
    :\
        (bst_dtl_vect_len_(vect) = (bst_intptr_t)(nsz))\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(nsz) + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_cap_(vect) = (bst_intptr_t)(nsz),\
        (bst_dtl_vect_len_(vect) = bst_dtl_vect_cap_(vect))\
    )\
)
#define bst_dtl_vect_rsv(tmplt, vect, ncap) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new capacity already fits. */\
    (bst_dtl_vect_cap_(vect) < (ncap) ?\
        (\
            *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(ncap) + 2*sizeof(bst_intptr_t)\
            ) + 2),\
            (bst_dtl_vect_cap_(vect) = (bst_intptr_t)(ncap))\
        )\
    :\
        (bst_intptr_t)(ncap)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(ncap) + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_len_(vect) = 0,\
        (bst_dtl_vect_cap_(vect) = (bst_intptr_t)(ncap))\
    )\
)
#define bst_dtl_vect_at(tmplt, vect, i) (bst_assert((i) < bst_vect_len(vect)), (vect)[(i)])
#define bst_dtl_vect_empty(tmplt, vect) (bst_vect_len(vect) == 0)
#define bst_dtl_vect_front(tmplt, vect) (vect)[0]
#define bst_dtl_vect_back(tmplt, vect) (vect)[bst_dtl_vect_len_(vect)-1]
#define bst_dtl_vect_push(tmplt, vect, val) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    (bst_dtl_vect_cap_(vect) < (bst_dtl_vect_len_(vect)+1) ?\
        (\
            *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(bst_dtl_vect_cap_(vect)*2) + 2*sizeof(bst_intptr_t)\
            ) + 2),\
            bst_dtl_vect_cap_(vect) *= 2,\
            (vect[bst_dtl_vect_len_(vect)++] = val)\
        )\
    :\
        (vect[bst_dtl_vect_len_(vect)++] = val)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*4 + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_len_(vect) = (bst_intptr_t)(1),\
        bst_dtl_vect_cap_(vect) = (bst_intptr_t)(4),\
        (vect[0] = val)\
    )\
)
#define bst_dtl_vect_begin(tmplt, vect) (vect)
#define bst_dtl_vect_end(tmplt, vect) ((vect)+bst_vect_len(vect))
#define bst_dtl_vect_rbegin(tmplt, vect) ((vect)+bst_vect_len(vect))
#define bst_dtl_vect_rend(tmplt, vect) ((vect)+1)

#define bst_dtl_vect_get_init(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 0)
#define bst_dtl_vect_get_destroy(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 1)
#define bst_dtl_vect_get_len(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 2)
#define bst_dtl_vect_get_cap(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 3)
#define bst_dtl_vect_get_rsz(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 4)
#define bst_dtl_vect_get_rsv(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 5)
#define bst_dtl_vect_get_at(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 6)
#define bst_dtl_vect_get_empty(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 7)
#define bst_dtl_vect_get_front(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 8)
#define bst_dtl_vect_get_back(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 9)
#define bst_dtl_vect_get_push(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 10)
#define bst_dtl_vect_get_begin(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 11)
#define bst_dtl_vect_get_end(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 12)
#define bst_dtl_vect_get_rbegin(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 13)
#define bst_dtl_vect_get_rend(tmplt) bst_ctuple_getI(bst_tmplt_fns(tmplt), 14)


// The type bst_intptr_t is used because the memory may need to be word aligned.
// This does assume that bst_intptr_t causes the memory to be word aligned.
#define bst_dtl_vect_raw_(vect) ((bst_intptr_t*)(void*)(vect) - 2)
#define bst_dtl_vect_cap_(vect) (bst_dtl_vect_raw_(vect)[0])
#define bst_dtl_vect_len_(vect) (bst_dtl_vect_raw_(vect)[1])
/// \}


#endif // BST__DETAIL__VECTOR_H
