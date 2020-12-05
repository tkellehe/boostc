//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__VECTOR_H
#define BST__VECTOR_H


#include <bst/config.h>
#include <bst/assert.h>
#include <bst/ctuple.h>
#include <bst/stdint.h>
#include <bst/string.h>
#include <bst/template.h>
#include <bst/detail/vector.h>


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
/// \{
#ifdef BST_NO_NAMESPACE
# define bst_vect_tmplt_t(T, ...) \
    bst_tmplt_isa(bst_vect_tmplt_ ## T,\
        bst_vect_tmplt_ ## T,\
        bst_tmplt_isa(vect_tmplt_ ## T,\
            vect_tmplt_ ## T,\
            bst_dtl_vect_tmplt_t(T, __VA_ARGS__)\
        )\
    )
#else
# define bst_vect_tmplt_t(T, ...)  \
    bst_tmplt_isa(bst_vect_tmplt_ ## T,\
        bst_vect_tmplt_ ## T,\
        bst_dtl_vect_tmplt_t(T, __VA_ARGS__)\
    )
#endif
/// \}


/** Declares the vector type.
 * \param T The template type of the vector or the type of the vector.
 */
#define bst_vect_t(T) bst_tmplt_isa(T, bst_tmplt_type(T), T*)


/** Initializes the vector structure.
 * \param vect Reference to the vector.
 */
#define bst_vect_init(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_init(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_init(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Destroys and frees any memory allocated for the vector.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_destroy(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_destroy(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_destroy(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Gets the number of items that have been added or resized to.
 * \param vect Reference to the vector.
 * \return Returns the number of items.
 */
#define bst_vect_len(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_len(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_len(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Gets the capacity that the vector has been allocated for.
 * \param vect Reference to the vector.
 * \return Returns the capacity for the vector.
 */
#define bst_vect_cap(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_cap(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_cap(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Resizes the vector to be able to hold the new size.
 * \param vect Reference to the vector.
 * \param nsz The new size for the vector.
 * \return Returns the new size.
 */
#define bst_vect_rsz(vect, nsz, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_rsz(vect)(vect, nsz, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_rsz(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect, nsz)\
    )


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Reference to the vector.
 * \param ncap The new capacity for the vector.
 * \return Returns the new capacity.
 */
#define bst_vect_rsv(vect, ncap, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_rsv(vect)(vect, ncap, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_rsv(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect, ncap)\
    )


/** Assert at the index provided then read the value in the array.
 * \param vect Reference to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
#define bst_vect_at(vect, i, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_at(vect)(vect, i, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_at(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect, i)\
    )


/** Checks to see if the vector is empty.
 * \param vect Reference to the vector.
 * \return Returns one if empty and zero otherwise.
 */
#define bst_vect_empty(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_empty(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_empty(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Get the front value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the first index.
 */
#define bst_vect_front(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_front(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_front(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Get the back value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the last index.
 */
#define bst_vect_back(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_back(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_back(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Reference to the vector.
 * \param val The value to push on.
 * \return Returns the new value pushed on.
 */
#define bst_vect_push(vect, val, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_push(vect)(vect, val, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_push(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect, val)\
    )


#define bst_vect_begin(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_begin(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_begin(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )
#define bst_vect_end(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_end(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_end(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


#define bst_vect_rbegin(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_rbegin(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_rbegin(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )
#define bst_vect_rend(vect, ...) \
    bst_tmplt_isa(vect,\
        bst_dtl_vect_get_rend(vect)(vect, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_rend(bst_tmplt_ctuple_alloc(bst_alloc_stdlib), vect)\
    )


#define bst_vect_iter_t(tmplt) bst_iter_t(bst_tmplt_iter(tmplt))
#define bst_vect_iter_nxt(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_nxt(bst_tmplt_iter(iter))(bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_nxt(iter)\
    )
#define bst_vect_iter_eq(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_eq(bst_tmplt_iter(left))(right, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_eq(left, right)\
    )
#define bst_vect_iter_val(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_val(bst_tmplt_iter(iter))(bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_val(iter)\
    )
#define bst_vect_iter_set(iter, val, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_set(bst_tmplt_iter(iter))(val, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_set(iter, val)\
    )
#define bst_vect_iter_swap(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_swap(bst_tmplt_iter(left))(right, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_iter_swap(left, right)\
    )


#define bst_vect_riter_t(tmplt) bst_iter_t(bst_tmplt_riter(tmplt))
#define bst_vect_riter_nxt(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_nxt(bst_tmplt_riter(iter))(bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_nxt(iter)\
    )
#define bst_vect_riter_eq(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_eq(bst_tmplt_riter(left))(right, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_eq(left, right)\
    )
#define bst_vect_riter_val(iter, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_val(bst_tmplt_riter(iter))(bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_val(iter)\
    )
#define bst_vect_riter_set(iter, val, ...) \
    bst_tmplt_isa(iter,\
        bst_iter_set(bst_tmplt_riter(iter))(val, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_set(iter, val)\
    )
#define bst_vect_riter_swap(left, right, ...) \
    bst_tmplt_isa(left,\
        bst_iter_swap(bst_tmplt_riter(left))(right, bst_ctuple_getI(bst_ctuple(__VA_ARGS__), 0)),\
        bst_dtl_vect_riter_swap(left, right)\
    )


#endif // BST__VECTOR_H
