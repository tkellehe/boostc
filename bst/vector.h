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
#define bst_vect_tmplt_t(T, ...) \
    bst_tmplt_ppack(\
        T*,\
        (T),\
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


/** Declares the vector type.
 * \param T The template type of the vector or the type of the vector.
 */
#define bst_vect_t(T) bst_tmplt_isa(T, bst_tmplt_type(T), T*)


/** Initializes the vector structure.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_init(vect, ...) (*((void**)&(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))) = bst_null, 1)


/** Destroys and frees any memory allocated for the vector.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_destroy(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_destroy(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect),\
        bst_dtl_vect_destroy(vect, bst_tmplt_ppack_alloc(bst_alloc_stdlib))\
    )


/** Gets the number of items that have been added or resized to.
 * \param vect Reference to the vector.
 * \return Returns the number of items.
 */
#define bst_vect_len(vect, ...) ((bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)) ?\
    (int)bst_dtl_vect_len(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)) : 0)


/** Gets the capacity that the vector has been allocated for.
 * \param vect Reference to the vector.
 * \return Returns the capacity for the vector.
 */
#define bst_vect_cap(vect, ...) ((bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)) ?\
    (int)bst_dtl_vect_cap(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)) : 0)


/** Resizes the vector to be able to hold the new size.
 * \param vect Reference to the vector.
 * \param nsz The new size for the vector.
 * \return Returns the new size.
 */
#define bst_vect_rsz(vect, nsz, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_rsz(nsz, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect),\
        bst_dtl_vect_rsz(vect, nsz, bst_tmplt_ppack_alloc(bst_alloc_stdlib))\
    )


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Reference to the vector.
 * \param ncap The new capacity for the vector.
 * \return Returns the new capacity.
 */
#define bst_vect_rsv(vect, ncap, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_rsv(ncap, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect),\
        bst_dtl_vect_rsv(vect, ncap, bst_tmplt_ppack_alloc(bst_alloc_stdlib))\
    )


/** Assert at the index provided then read the value in the array.
 * \param vect Reference to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
#define bst_vect_at(vect, i, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_at(i, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect),\
        bst_dtl_vect_at(vect, i, bst_tmplt_ppack_alloc(bst_alloc_stdlib))\
    )


/** Checks to see if the vector is empty.
 * \param vect Reference to the vector.
 * \return Returns one if empty and zero otherwise.
 */
#define bst_vect_empty(vect, ...) (bst_vect_len(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)) == 0)


/** Get the front value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the first index.
 */
#define bst_vect_front(vect, ...) (bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))[0]


/** Get the back value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the last index.
 */
#define bst_vect_back(vect, ...) \
    bst_tmplt_isa(vect,\
        (bst_ppack_getI(bst_ppack(__VA_ARGS__), 0))[bst_dtl_vect_len(bst_ppack_getI(bst_ppack(__VA_ARGS__), 0))-1],\
        (vect)[bst_dtl_vect_len(vect)-1]\
    )


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Reference to the vector.
 * \param val The value to push on.
 * \return Returns the new value pushed on.
 */
#define bst_vect_push(vect, val, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_push(val, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect),\
        bst_dtl_vect_push(vect, val, bst_tmplt_ppack_alloc(bst_alloc_stdlib))\
    )


#define bst_vect_begin(vect, ...) (bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))
#define bst_vect_end(vect, ...) ((bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))+bst_vect_len(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)))


#define bst_vect_rbegin(vect, ...) ((bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))+bst_vect_len(bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect)))
#define bst_vect_rend(vect, ...) ((bst_tmplt_isa(vect, bst_ppack_getI(bst_ppack(__VA_ARGS__), 0), vect))+1)


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

/* Packs the iterator defaults */
#define bst_dtl_vect_iter_defaults(T) bst_ppack(bst_dtl_vect_iter_t(T), bst_dtl_vect_iter_nxt, bst_dtl_vect_iter_eq, bst_dtl_vect_iter_val, bst_dtl_vect_iter_set)


#define bst_dtl_vect_iter_t(T) T*
#define bst_dtl_vect_iter_nxt(iter) (++iter)
#define bst_dtl_vect_iter_eq(left, right) (left == right)
#define bst_dtl_vect_iter_val(iter) *(iter)
#define bst_dtl_vect_iter_set(iter, val) (*(iter) = val)


/* Packs the iterator defaults */
#define bst_dtl_vect_riter_defaults(T) bst_ppack(bst_dtl_vect_riter_t(T), bst_dtl_vect_riter_nxt, bst_dtl_vect_riter_eq, bst_dtl_vect_riter_val, bst_dtl_vect_riter_set)


#define bst_dtl_vect_riter_t(T) T*
#define bst_dtl_vect_riter_nxt(riter) (--riter)
#define bst_dtl_vect_riter_eq(left, right) (left == right)
#define bst_dtl_vect_riter_val(riter) *((riter)-1)
#define bst_dtl_vect_riter_set(riter, val) (*((riter)-1) = val)


/* Detail code */
/// \{
// The type intptr_t is used because the memory may need to be word aligned.
// This does assume that intptr_t causes the memory to be word aligned.
#define bst_dtl_vect_raw(vect) ((intptr_t*)(void*)(vect) - 2)
#define bst_dtl_vect_cap(vect) (bst_dtl_vect_raw(vect)[0])
#define bst_dtl_vect_len(vect) (bst_dtl_vect_raw(vect)[1])
#define bst_dtl_vect_push(vect, val, tmplt) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    (bst_dtl_vect_cap(vect) < (bst_dtl_vect_len(vect)+1) ?\
        (\
            *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(bst_dtl_vect_cap(vect)*2) + 2*sizeof(intptr_t)\
            ) + 2),\
            bst_dtl_vect_cap(vect) *= 2,\
            (vect[bst_dtl_vect_len(vect)++] = val)\
        )\
    :\
        (vect[bst_dtl_vect_len(vect)++] = val)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*4 + 2*sizeof(intptr_t)) + 2),\
        bst_dtl_vect_len(vect) = (intptr_t)(1),\
        bst_dtl_vect_cap(vect) = (intptr_t)(4),\
        (vect[0] = val)\
    )\
)
#define bst_dtl_vect_destroy(vect, tmplt) \
    ((vect) ? bst_alloc_free(bst_tmplt_alloc(tmplt))(bst_dtl_vect_raw(vect)),*((void**)&(vect))=bst_null,1 : 0)
#define bst_dtl_vect_rsz(vect, nsz, tmplt) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new size already fits. */\
    (bst_dtl_vect_cap(vect) < (nsz) ?\
        /* Since it does not fit, check to see if twice the current size will hold the new size. */\
        (bst_dtl_vect_cap(vect)*2 > (nsz) ?\
            (\
                *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw(vect),\
                    sizeof(*(vect))*(bst_dtl_vect_cap(vect)*2) + 2*sizeof(intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap(vect) = (bst_dtl_vect_cap(vect)*2),\
                (bst_dtl_vect_len(vect) = (intptr_t)(nsz))\
            )\
        :\
            (\
                *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                    bst_dtl_vect_raw(vect),\
                    sizeof(*(vect))*(nsz) + 2*sizeof(intptr_t)\
                ) + 2),\
                bst_dtl_vect_cap(vect) = (intptr_t)(nsz),\
                (bst_dtl_vect_len(vect) = bst_dtl_vect_cap(vect))\
            )\
        )\
    :\
        (bst_dtl_vect_len(vect) = (intptr_t)(nsz))\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(nsz) + 2*sizeof(intptr_t)) + 2),\
        bst_dtl_vect_cap(vect) = (intptr_t)(nsz),\
        (bst_dtl_vect_len(vect) = bst_dtl_vect_cap(vect))\
    )\
)
#define bst_dtl_vect_rsv(vect, ncap, tmplt) \
/* Check to see if the vector has anything allocated yet. */\
((vect) ?\
    /* Check to see if the new capacity already fits. */\
    (bst_dtl_vect_cap(vect) < (ncap) ?\
        (\
            *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_realloc(bst_tmplt_alloc(tmplt))(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(ncap) + 2*sizeof(intptr_t)\
            ) + 2),\
            (bst_dtl_vect_cap(vect) = (intptr_t)(ncap))\
        )\
    :\
        (intptr_t)(ncap)\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((intptr_t*)bst_alloc_malloc(bst_tmplt_alloc(tmplt))(sizeof(*(vect))*(ncap) + 2*sizeof(intptr_t)) + 2),\
        bst_dtl_vect_len(vect) = 0,\
        (bst_dtl_vect_cap(vect) = (intptr_t)(ncap))\
    )\
)
#define bst_dtl_vect_at(vect, i, ...) (bst_assert((i) < bst_vect_len(vect)), (vect)[(i)])
/// \}


#endif // BST__VECTOR_H
