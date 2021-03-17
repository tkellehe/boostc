//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__DETAIL__VECTOR_H
#define BOOSTC__DETAIL__VECTOR_H


/* Details for vector */
/// \{
#define bstc_dtl_vect_tmplt_t_select(tpl) bstc_ctuple_hasN(tpl, 1, bstc_dtl_vect_tmplt_t1, bstc_dtl_vect_tmplt_t2)

#define bstc_dtl_vect_tmplt_t1(T) \
    bstc_ctuple(\
        T*,\
        bstc_ctuple(T),\
        bstc_dtl_vect_default_fns,\
        bstc_dtl_vect_iter_defaults(T),\
        bstc_dtl_vect_riter_defaults(T),\
        bstc_alloc_stdlib\
    )

#define bstc_dtl_vect_tmplt_t2(T, alloc) \
    bstc_ctuple(\
        T*,\
        bstc_ctuple(T),\
        bstc_dtl_vect_default_fns,\
        bstc_dtl_vect_iter_defaults(T),\
        bstc_dtl_vect_riter_defaults(T),\
        bstc_alloc_isa(alloc,\
            alloc,\
            BSTC_VECT_BAD_ALLOC_PROVIDED\
        )\
    )


#define bstc_dtl_vect_add_tmplt(tpl) bstc_tmplt_isa(bstc_ctuple_getI(tpl, 0), tpl, bstc_ctuple_prepend(tpl, bstc_dtl_vect_tmplt_t1(void)))


#define bstc_dtl_vect_init(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_init(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_init(tmplt, vect) (*((void**)&(vect)) = bstc_nullptr)


#define bstc_dtl_vect_destroy(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_destroy(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_destroy(tmplt, vect) ((vect) ? bstc_alloc_free(bstc_tmplt_alloc(tmplt))(bstc_dtl_vect_raw_(vect)),*((void**)&(vect))=bstc_nullptr : bstc_nullptr)


#define bstc_dtl_vect_len(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_len(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_len(tmplt, vect) ((vect) ? (bstc_size_t)bstc_dtl_vect_len_(vect) : 0)

#define bstc_dtl_vect_cap(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_cap(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_cap(tmplt, vect) ((vect) ? (bstc_size_t)bstc_dtl_vect_cap_(vect) : 0)

#define bstc_dtl_vect_rsz(tmplt, vect, nsz) BSTC_CALL(bstc_dtl_vect_get_rsz(tmplt), tmplt, vect, nsz)
#define bstc_dtl_vect_default_rsz(tmplt, vect, nsz) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new size already fits. */\
    (bstc_dtl_vect_cap_(vect) < (nsz) ?\
        /* Since it does not fit, check to see if twice the current size will hold the new size. */\
        (bstc_dtl_vect_cap_(vect)*2 > (nsz) ?\
            (\
                *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_tmplt_alloc(tmplt))(\
                    bstc_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*(bstc_dtl_vect_cap_(vect)*2) + 2*sizeof(bstc_intptr_t)\
                ) + 2),\
                bstc_dtl_vect_cap_(vect) = (bstc_dtl_vect_cap_(vect)*2),\
                (bstc_dtl_vect_len_(vect) = (bstc_intptr_t)(nsz))\
            )\
        :\
            (\
                *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_tmplt_alloc(tmplt))(\
                    bstc_dtl_vect_raw_(vect),\
                    sizeof(*(vect))*(nsz) + 2*sizeof(bstc_intptr_t)\
                ) + 2),\
                bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)(nsz),\
                (bstc_dtl_vect_len_(vect) = bstc_dtl_vect_cap_(vect))\
            )\
        )\
    :\
        (bstc_dtl_vect_len_(vect) = (bstc_intptr_t)(nsz))\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_malloc(bstc_tmplt_alloc(tmplt))(sizeof(*(vect))*(nsz) + 2*sizeof(bstc_intptr_t)) + 2),\
        bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)(nsz),\
        (bstc_dtl_vect_len_(vect) = bstc_dtl_vect_cap_(vect))\
    )\
)

#define bstc_dtl_vect_rsv(tmplt, vect, ncap) BSTC_CALL(bstc_dtl_vect_get_rsv(tmplt), tmplt, vect, ncap)
#define bstc_dtl_vect_default_rsv(tmplt, vect, ncap) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new capacity already fits. */\
    (bstc_dtl_vect_cap_(vect) < (ncap) ?\
        (\
            *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_tmplt_alloc(tmplt))(\
                bstc_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(ncap) + 2*sizeof(bstc_intptr_t)\
            ) + 2),\
            (bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)(ncap))\
        )\
    :\
        (bstc_intptr_t)(ncap)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_malloc(bstc_tmplt_alloc(tmplt))(sizeof(*(vect))*(ncap) + 2*sizeof(bstc_intptr_t)) + 2),\
        bstc_dtl_vect_len_(vect) = 0,\
        (bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)(ncap))\
    )\
)

#define bstc_dtl_vect_at(tmplt, vect, i) BSTC_CALL(bstc_dtl_vect_get_at(tmplt), tmplt, vect, i)
#define bstc_dtl_vect_default_at(tmplt, vect, i) (bstc_assert((i) < bstc_dtl_vect_default_len(tmplt, vect)), (vect)[(i)])

#define bstc_dtl_vect_empty(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_empty(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_empty(tmplt, vect) (bstc_dtl_vect_default_len(tmplt, vect) == 0)

#define bstc_dtl_vect_front(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_front(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_front(tmplt, vect) (vect)[0]

#define bstc_dtl_vect_back(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_back(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_back(tmplt, vect) (vect)[bstc_dtl_vect_len_(vect)-1]

#define bstc_dtl_vect_pushb(tmplt, vect, val) BSTC_CALL(bstc_dtl_vect_get_pushb(tmplt), tmplt, vect, val)
#define bstc_dtl_vect_default_pushb(tmplt, vect, val) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    (bstc_dtl_vect_cap_(vect) < (bstc_dtl_vect_len_(vect)+1) ?\
        (\
            *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_realloc(bstc_tmplt_alloc(tmplt))(\
                bstc_dtl_vect_raw_(vect),\
                sizeof(*(vect))*(bstc_dtl_vect_cap_(vect)*2) + 2*sizeof(bstc_intptr_t)\
            ) + 2),\
            bstc_dtl_vect_cap_(vect) *= 2,\
            (vect[bstc_dtl_vect_len_(vect)++] = val)\
        )\
    :\
        (vect[bstc_dtl_vect_len_(vect)++] = val)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bstc_intptr_t*)bstc_alloc_malloc(bstc_tmplt_alloc(tmplt))(sizeof(*(vect))*4 + 2*sizeof(bstc_intptr_t)) + 2),\
        bstc_dtl_vect_len_(vect) = (bstc_intptr_t)(1),\
        bstc_dtl_vect_cap_(vect) = (bstc_intptr_t)(4),\
        (vect[0] = val)\
    )\
)

#define bstc_dtl_vect_begin(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_begin(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_begin(tmplt, vect) (vect)

#define bstc_dtl_vect_end(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_end(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_end(tmplt, vect) ((vect)+bstc_dtl_vect_default_len(tmplt, vect))

#define bstc_dtl_vect_rbegin(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_rbegin(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_rbegin(tmplt, vect) ((vect)+bstc_dtl_vect_default_len(tmplt, vect))

#define bstc_dtl_vect_rend(tmplt, vect) BSTC_CALL(bstc_dtl_vect_get_rend(tmplt), tmplt, vect)
#define bstc_dtl_vect_default_rend(tmplt, vect) (vect)

#define bstc_dtl_vect_get_init(tmplt) BSTC_GET_ARG0 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_destroy(tmplt) BSTC_GET_ARG1 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_len(tmplt) BSTC_GET_ARG2 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_cap(tmplt) BSTC_GET_ARG3 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_rsz(tmplt) BSTC_GET_ARG4 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_rsv(tmplt) BSTC_GET_ARG5 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_at(tmplt) BSTC_GET_ARG6 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_empty(tmplt) BSTC_GET_ARG7 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_front(tmplt) BSTC_GET_ARG8 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_back(tmplt) BSTC_GET_ARG9 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_pushb(tmplt) BSTC_GET_ARG10 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_begin(tmplt) BSTC_GET_ARG11 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_end(tmplt) BSTC_GET_ARG12 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_rbegin(tmplt) BSTC_GET_ARG13 bstc_tmplt_fns(tmplt)
#define bstc_dtl_vect_get_rend(tmplt) BSTC_GET_ARG14 bstc_tmplt_fns(tmplt)


// The type bstc_intptr_t is used because the memory may need to be word aligned.
// This does assume that bstc_intptr_t causes the memory to be word aligned.
#define bstc_dtl_vect_raw_(vect) ((bstc_intptr_t*)(void*)(vect) - 2)
#define bstc_dtl_vect_cap_(vect) (bstc_dtl_vect_raw_(vect)[0])
#define bstc_dtl_vect_len_(vect) (bstc_dtl_vect_raw_(vect)[1])


// Preparing for potential specialization concept.
#define bstc_dtl_vect_default_fns \
    bstc_ctuple(\
        bstc_dtl_vect_default_init,\
        bstc_dtl_vect_default_destroy,\
        bstc_dtl_vect_default_len,\
        bstc_dtl_vect_default_cap,\
        bstc_dtl_vect_default_rsz,\
        bstc_dtl_vect_default_rsv,\
        bstc_dtl_vect_default_at,\
        bstc_dtl_vect_default_empty,\
        bstc_dtl_vect_default_front,\
        bstc_dtl_vect_default_back,\
        bstc_dtl_vect_default_pushb,\
        bstc_dtl_vect_default_begin,\
        bstc_dtl_vect_default_end,\
        bstc_dtl_vect_default_rbegin,\
        bstc_dtl_vect_default_rend\
    )


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

#define bstc_dtl_vect_iter_nxt(tmplt, iter) BSTC_CALL(bstc_iter_nxt(bstc_tmplt_iter(tmplt)), iter)
#define bstc_dtl_vect_default_iter_nxt(iter) (++iter)

#define bstc_dtl_vect_iter_eq(tmplt, left, right) BSTC_CALL(bstc_iter_eq(bstc_tmplt_iter(tmplt)), left, right)
#define bstc_dtl_vect_default_iter_eq(left, right) (left == right)

#define bstc_dtl_vect_iter_val(tmplt, iter) BSTC_CALL(bstc_iter_val(bstc_tmplt_iter(tmplt)), iter)
#define bstc_dtl_vect_default_iter_val(iter) *(iter)

#define bstc_dtl_vect_iter_put(tmplt, iter, val) BSTC_CALL(bstc_iter_put(bstc_tmplt_iter(tmplt)), iter, val)
#define bstc_dtl_vect_default_iter_put(iter, val) (*(iter) = val)

#define bstc_dtl_vect_iter_swap(tmplt, left, right) BSTC_CALL(bstc_iter_swap(bstc_tmplt_iter(tmplt)), left, right)
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

#define bstc_dtl_vect_riter_nxt(tmplt, riter) BSTC_CALL(bstc_iter_nxt(bstc_tmplt_riter(tmplt)), riter)
#define bstc_dtl_vect_default_riter_nxt(riter) (--riter)

#define bstc_dtl_vect_riter_eq(tmplt, left, right) BSTC_CALL(bstc_iter_eq(bstc_tmplt_riter(tmplt)), left, right)
#define bstc_dtl_vect_default_riter_eq(left, right) (left == right)

#define bstc_dtl_vect_riter_val(tmplt, riter) BSTC_CALL(bstc_iter_val(bstc_tmplt_riter(tmplt)), riter)
#define bstc_dtl_vect_default_riter_val(riter) *((riter)-1)

#define bstc_dtl_vect_riter_put(tmplt, riter, val) BSTC_CALL(bstc_iter_put(bstc_tmplt_riter(tmplt)), riter, val)
#define bstc_dtl_vect_default_riter_put(riter, val) (*((riter)-1) = val)

#define bstc_dtl_vect_riter_swap(tmplt, left, right) BSTC_CALL(bstc_iter_swap(bstc_tmplt_riter(tmplt)), left, right)
#define bstc_dtl_vect_default_riter_swap(left, right) \
    {\
        char __bstc_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bstc_dtl_swap, (void*)((left)-1), sizeof(*(left)));\
        memcpy((void*)((left)-1), (void*)((right)-1), sizeof(*(left)));\
        memcpy((void*)((right)-1), (void*)__bstc_dtl_swap, sizeof(*(left)));\
    }
/// \}


#endif // BOOSTC__DETAIL__VECTOR_H
