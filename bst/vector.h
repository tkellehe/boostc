//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__VECTOR_H
#define BST__VECTOR_H


#include <bst/config.h>
#include <bst/assert.h>
#include <bst/ppack.h>
#include <bst/stdint.h>
#include <bst/template.h>

// This will need to be updated.
#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif


/* Provide interface without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define vect_tmplt_t bst_vect_tmplt_t
#define vect_t bst_vect_t
#define vect_init bst_vect_init
#define vect_destroy bst_vect_destroy
#define vect_len bst_vect_len
#define vect_cap bst_vect_cap
#define vect_rsz bst_vect_rsz
#define vect_rsv bst_vect_rsv
#define vect_empty bst_vect_empty
#define vect_front bst_vect_front
#define vect_back bst_vect_back
#define vect_push bst_vect_push

#define vect_begin bst_vect_begin
#define vect_end bst_vect_end

#define vect_rbegin bst_vect_rbegin
#define vect_rend bst_vect_rend

#define vect_iter_t bst_vect_iter_t
#define vect_iter_nxt bst_vect_iter_nxt
#define vect_iter_eq bst_vect_iter_eq
#define vect_iter_val bst_vect_iter_val
#define vect_iter_set bst_vect_iter_set


#define vect_riter_t bst_vect_riter_t
#define vect_riter_nxt bst_vect_riter_nxt
#define vect_riter_eq bst_vect_riter_eq
#define vect_riter_val bst_vect_riter_val
#define vect_riter_set bst_vect_riter_set
#endif
/// \}


/** Declares the vector template type.
 * \param T The type of the data in the vector.
 * \param alloc An optional argument which is the allocator for the template type.
 */
#define bst_vect_tmplt_t(T, ...) bst_dtl_vect_tmplt_t(T, __VA_ARGS__)


/** Declares the vector type.
 * \param T The template type of the vector or the type of the vector.
 */
#define bst_vect_t(T) bst_tmplt_isa(T, bst_tmplt_type(T), T*)


/** Initializes the vector structure.
 * \param vect Reference to the vector.
 */
#define bst_vect_init(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_init(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_init(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Destroys and frees any memory allocated for the vector.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_destroy(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_destroy(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_destroy(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Gets the number of items that have been added or resized to.
 * \param vect Reference to the vector.
 * \return Returns the number of items.
 */
#define bst_vect_len(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_len(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_len(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Gets the capacity that the vector has been allocated for.
 * \param vect Reference to the vector.
 * \return Returns the capacity for the vector.
 */
#define bst_vect_cap(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_cap(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_cap(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Resizes the vector to be able to hold the new size.
 * \param vect Reference to the vector.
 * \param nsz The new size for the vector.
 * \return Returns the new size.
 */
#define bst_vect_rsz(vect, nsz, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_rsz(vect)(vect, nsz, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_rsz(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect, nsz)\
    )


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Reference to the vector.
 * \param ncap The new capacity for the vector.
 * \return Returns the new capacity.
 */
#define bst_vect_rsv(vect, ncap, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_rsv(vect)(vect, ncap, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_rsv(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect, ncap)\
    )


/** Assert at the index provided then read the value in the array.
 * \param vect Reference to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
#define bst_vect_at(vect, i, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_at(vect)(vect, i, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_at(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect, i)\
    )


/** Checks to see if the vector is empty.
 * \param vect Reference to the vector.
 * \return Returns one if empty and zero otherwise.
 */
#define bst_vect_empty(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_empty(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_empty(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Get the front value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the first index.
 */
#define bst_vect_front(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_front(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_front(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Get the back value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the last index.
 */
#define bst_vect_back(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_back(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_back(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Reference to the vector.
 * \param val The value to push on.
 * \return Returns the new value pushed on.
 */
#define bst_vect_push(vect, val, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_push(vect)(vect, val, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_push(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect, val)\
    )


#define bst_vect_begin(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_begin(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_begin(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )
#define bst_vect_end(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_end(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_end(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


#define bst_vect_rbegin(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_rbegin(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_rbegin(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )
#define bst_vect_rend(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_get_vect_rend(vect)(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_tmplt_vect_rend(bst_tmplt_ppack_alloc(bst_alloc_stdlib), vect)\
    )


#define bst_vect_iter_t(tmplt) bst_iter_t(bst_tmplt_iter(tmplt))
#define bst_vect_iter_nxt(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_nxt(bst_tmplt_iter(iter))(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_nxt(iter)\
    )
#define bst_vect_iter_eq(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_eq(bst_tmplt_iter(left))(right, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_eq(left, right)\
    )
#define bst_vect_iter_val(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_val(bst_tmplt_iter(iter))(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_val(iter)\
    )
#define bst_vect_iter_set(iter, val, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_set(bst_tmplt_iter(iter))(val, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_set(iter, val)\
    )
#define bst_vect_iter_swap(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_swap(bst_tmplt_iter(left))(right, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_swap(left, right)\
    )


#define bst_vect_riter_t(tmplt) bst_iter_t(bst_tmplt_riter(tmplt))
#define bst_vect_riter_nxt(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_nxt(bst_tmplt_riter(iter))(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_nxt(iter)\
    )
#define bst_vect_riter_eq(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_eq(bst_tmplt_riter(left))(right, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_eq(left, right)\
    )
#define bst_vect_riter_val(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_val(bst_tmplt_riter(iter))(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_val(iter)\
    )
#define bst_vect_riter_set(iter, val, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_set(bst_tmplt_riter(iter))(val, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_set(iter, val)\
    )
#define bst_vect_riter_swap(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_swap(bst_tmplt_riter(left))(right, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_swap(left, right)\
    )

/* Packs the iterator defaults */
#define bst_dtl_vect_iter_defaults(T) bst_ppack(bst_dtl_vect_iter_t(T), bst_dtl_vect_iter_nxt, bst_dtl_vect_iter_eq, bst_dtl_vect_iter_val, bst_dtl_vect_iter_set, bst_dtl_vect_iter_swap)


#define bst_dtl_vect_iter_t(T) T*
#define bst_dtl_vect_iter_nxt(iter) (++iter)
#define bst_dtl_vect_iter_eq(left, right) (left == right)
#define bst_dtl_vect_iter_val(iter) *(iter)
#define bst_dtl_vect_iter_set(iter, val) (*(iter) = val)
#define bst_dtl_vect_iter_swap(left, right) \
    ({\
        char __bst_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bst_dtl_swap, (void*)(left), sizeof(*(left)));\
        memcpy((void*)(left), (void*)(right), sizeof(*(left)));\
        memcpy((void*)(right), (void*)__bst_dtl_swap, sizeof(*(left)));\
    })


/* Packs the iterator defaults */
#define bst_dtl_vect_riter_defaults(T) bst_ppack(bst_dtl_vect_riter_t(T), bst_dtl_vect_riter_nxt, bst_dtl_vect_riter_eq, bst_dtl_vect_riter_val, bst_dtl_vect_riter_set, bst_dtl_vect_riter_swap)


#define bst_dtl_vect_riter_t(T) T*
#define bst_dtl_vect_riter_nxt(riter) (--riter)
#define bst_dtl_vect_riter_eq(left, right) (left == right)
#define bst_dtl_vect_riter_val(riter) *((riter)-1)
#define bst_dtl_vect_riter_set(riter, val) (*((riter)-1) = val)
#define bst_dtl_vect_riter_swap(left, right) \
    ({\
        char __bst_dtl_swap[sizeof(*(left))];\
        memcpy((void*)__bst_dtl_swap, (void*)(left), sizeof(*(left)));\
        memcpy((void*)(left), (void*)(right), sizeof(*(left)));\
        memcpy((void*)(right), (void*)__bst_dtl_swap, sizeof(*(left)));\
    })


/* Detail code */
/// \{
#define bst_dtl_vect_tmplt_t(T, ...) \
    bst_tmplt_ppack(\
        T*,\
        (T),\
        bst_dtl_vect_default_fns,\
        bst_dtl_vect_iter_defaults(T),\
        bst_dtl_vect_riter_defaults(T),\
        bst_ppack_empty(bst_ppack(__VA_ARGS__),\
            bst_alloc_stdlib,\
            bst_alloc_isa(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0),\
                bst_ppack_getI(bst_ppack(__VA_ARGS__), 0),\
                bst_alloc_stdlib\
            )\
        )\
    )

// Preparing for potential specialization concept.
#define bst_dtl_vect_default_fns \
    bst_ppack(\
        bst_dtl_tmplt_vect_init,\
        bst_dtl_tmplt_vect_destroy,\
        bst_dtl_tmplt_vect_len,\
        bst_dtl_tmplt_vect_cap,\
        bst_dtl_tmplt_vect_rsz,\
        bst_dtl_tmplt_vect_rsv,\
        bst_dtl_tmplt_vect_at,\
        bst_dtl_tmplt_vect_empty,\
        bst_dtl_tmplt_vect_front,\
        bst_dtl_tmplt_vect_back,\
        bst_dtl_tmplt_vect_push,\
        bst_dtl_tmplt_vect_begin,\
        bst_dtl_tmplt_vect_end,\
        bst_dtl_tmplt_vect_rbegin,\
        bst_dtl_tmplt_vect_rend\
    )

#define bst_dtl_tmplt_vect_init(tmplt, vect) (*((void**)&(vect)) = bst_null)
#define bst_dtl_tmplt_vect_destroy(tmplt, vect) ((vect) ? bst_alloc_free(bst_tmplt_alloc(tmplt))(bst_dtl_vect_raw(vect)),*((void**)&(vect))=bst_null,1 : 0)
#define bst_dtl_tmplt_vect_len(tmplt, vect) ((vect) ? (int)bst_dtl_vect_len(vect) : 0)
#define bst_dtl_tmplt_vect_cap(tmplt, vect) ((vect) ? (int)bst_dtl_vect_cap(vect) : 0)
#define bst_dtl_tmplt_vect_rsz(tmplt, vect, nsz) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new size already fits. */\
    (bst_dtl_vect_cap(vect) < (nsz) ?\
        /* Since it does not fit, check to see if twice the current size will hold the new size. */\
        (bst_dtl_vect_cap(vect)*2 > (nsz) ?\
            (\
                *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw(vect),\
                    sizeof(*(vect))*(bst_dtl_vect_cap(vect)*2) + 2*sizeof(bst_intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap(vect) = (bst_dtl_vect_cap(vect)*2),\
                (bst_dtl_vect_len(vect) = (bst_intptr_t)(nsz))\
            )\
        :\
            (\
                *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw(vect),\
                    sizeof(*(vect))*(nsz) + 2*sizeof(bst_intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap(vect) = (bst_intptr_t)(nsz),\
                (bst_dtl_vect_len(vect) = bst_dtl_vect_cap(vect))\
            )\
        )\
    :\
        (bst_dtl_vect_len(vect) = (bst_intptr_t)(nsz))\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(nsz) + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_cap(vect) = (bst_intptr_t)(nsz),\
        (bst_dtl_vect_len(vect) = bst_dtl_vect_cap(vect))\
    )\
)
#define bst_dtl_tmplt_vect_rsv(tmplt, vect, ncap) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new capacity already fits. */\
    (bst_dtl_vect_cap(vect) < (ncap) ?\
        (\
            *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(ncap) + 2*sizeof(bst_intptr_t)\
            ) + 2),\
            (bst_dtl_vect_cap(vect) = (bst_intptr_t)(ncap))\
        )\
    :\
        (bst_intptr_t)(ncap)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(ncap) + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_len(vect) = 0,\
        (bst_dtl_vect_cap(vect) = (bst_intptr_t)(ncap))\
    )\
)
#define bst_dtl_tmplt_vect_at(tmplt, vect, i) (bst_assert((i) < bst_vect_len(vect)), (vect)[(i)])
#define bst_dtl_tmplt_vect_empty(tmplt, vect) (bst_vect_len(vect) == 0)
#define bst_dtl_tmplt_vect_front(tmplt, vect) (vect)[0]
#define bst_dtl_tmplt_vect_back(tmplt, vect) (vect)[bst_dtl_vect_len(vect)-1]
#define bst_dtl_tmplt_vect_push(tmplt, vect, val) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    (bst_dtl_vect_cap(vect) < (bst_dtl_vect_len(vect)+1) ?\
        (\
            *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(bst_dtl_vect_cap(vect)*2) + 2*sizeof(bst_intptr_t)\
            ) + 2),\
            bst_dtl_vect_cap(vect) *= 2,\
            (vect[bst_dtl_vect_len(vect)++] = val)\
        )\
    :\
        (vect[bst_dtl_vect_len(vect)++] = val)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((bst_intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*4 + 2*sizeof(bst_intptr_t)) + 2),\
        bst_dtl_vect_len(vect) = (bst_intptr_t)(1),\
        bst_dtl_vect_cap(vect) = (bst_intptr_t)(4),\
        (vect[0] = val)\
    )\
)
#define bst_dtl_tmplt_vect_begin(tmplt, vect) (vect)
#define bst_dtl_tmplt_vect_end(tmplt, vect) ((vect)+bst_vect_len(vect))
#define bst_dtl_tmplt_vect_rbegin(tmplt, vect) ((vect)+bst_vect_len(vect))
#define bst_dtl_tmplt_vect_rend(tmplt, vect) ((vect)+1)

#define bst_dtl_get_vect_init(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 0)
#define bst_dtl_get_vect_destroy(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 1)
#define bst_dtl_get_vect_len(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 2)
#define bst_dtl_get_vect_cap(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 3)
#define bst_dtl_get_vect_rsz(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 4)
#define bst_dtl_get_vect_rsv(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 5)
#define bst_dtl_get_vect_at(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 6)
#define bst_dtl_get_vect_empty(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 7)
#define bst_dtl_get_vect_front(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 8)
#define bst_dtl_get_vect_back(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 9)
#define bst_dtl_get_vect_push(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 10)
#define bst_dtl_get_vect_begin(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 11)
#define bst_dtl_get_vect_end(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 12)
#define bst_dtl_get_vect_rbegin(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 13)
#define bst_dtl_get_vect_rend(tmplt) bst_ppack_getI(bst_tmplt_fns(tmplt), 14)


// The type bst_intptr_t is used because the memory may need to be word aligned.
// This does assume that bst_intptr_t causes the memory to be word aligned.
#define bst_dtl_vect_raw(vect) ((bst_intptr_t*)(void*)(vect) - 2)
#define bst_dtl_vect_cap(vect) (bst_dtl_vect_raw(vect)[0])
#define bst_dtl_vect_len(vect) (bst_dtl_vect_raw(vect)[1])
/// \}


#endif // BST__VECTOR_H
