//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/assert.h>
#include <boostc/ctuple.h>
#include <boostc/stdint.h>
#include <boostc/string.h>
#include <boostc/template.h>
#include <boostc/detail/vector.h>


/** Declares the vector template type.
 * \param T The type of the data in the vector.
 * \param alloc An optional argument which is the allocator for the template type.
 */
/// \{
#ifndef bstc_vect_tmplt_t
# define bstc_vect_tmplt_t(...) BSTC_EXPAND(bstc_ctuple_call(bstc_dtl_vect_tmplt_t_select(bstc_ctuple(__VA_ARGS__)), bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Declares the vector type.
 * \param T The template type of the vector or the type of the vector.
 */
/// \{
#ifndef bstc_vect_t
# define bstc_vect_t(T) bstc_tmplt_isa(T, bstc_tmplt_t(T), T*)
#endif
/// \}


/** Initializes the vector structure.
 * \param vect Reference to the vector.
 */
/// \{
#ifndef bstc_vect_init
# define bstc_vect_init(...) bstc_ctuple_call(bstc_dtl_vect_init, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Destroys and frees any memory allocated for the vector.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
/// \{
#ifndef bstc_vect_destroy
# define bstc_vect_destroy(...) bstc_ctuple_call(bstc_dtl_vect_destroy, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Gets the number of items that have been added or resized to.
 * \param vect Reference to the vector.
 * \return Returns the number of items.
 */
/// \{
#ifndef bstc_vect_len
# define bstc_vect_len(...) bstc_ctuple_call(bstc_dtl_vect_len, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Gets the capacity that the vector has been allocated for.
 * \param vect Reference to the vector.
 * \return Returns the capacity for the vector.
 */
/// \{
#ifndef bstc_vect_cap
# define bstc_vect_cap(...) bstc_ctuple_call(bstc_dtl_vect_cap, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Resizes the vector to be able to hold the new size.
 * \param vect Reference to the vector.
 * \param nsz The new size for the vector.
 * \return Returns the new size.
 */
/// \{
#ifndef bstc_vect_rsz
# define bstc_vect_rsz(...) bstc_ctuple_call(bstc_dtl_vect_rsz, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Reference to the vector.
 * \param ncap The new capacity for the vector.
 * \return Returns the new capacity.
 */
/// \{
#ifndef bstc_vect_rsv
# define bstc_vect_rsv(...) bstc_ctuple_call(bstc_dtl_vect_rsv, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Assert at the index provided then read the value in the array.
 * \param vect Reference to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
/// \{
#ifndef bstc_vect_at
# define bstc_vect_at(...) bstc_ctuple_call(bstc_dtl_vect_at, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Checks to see if the vector is empty.
 * \param vect Reference to the vector.
 * \return Returns one if empty and zero otherwise.
 */
/// \{
#ifndef bstc_vect_empty
# define bstc_vect_empty(...) bstc_ctuple_call(bstc_dtl_vect_empty, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get the front value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the first index.
 */
/// \{
#ifndef bstc_vect_front
# define bstc_vect_front(...) bstc_ctuple_call(bstc_dtl_vect_front, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get the back value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the last index.
 */
/// \{
#ifndef bstc_vect_back
# define bstc_vect_back(...) bstc_ctuple_call(bstc_dtl_vect_back, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Reference to the vector.
 * \param val The value to push on.
 * \return Returns the new value pushed on.
 */
/// \{
#ifndef bstc_vect_push
# define bstc_vect_push(...) bstc_ctuple_call(bstc_dtl_vect_push, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get a forward iterator referencing the first item.
 * \param vect Reference to the vector.
 * \return Returns the forward iterator to the first item.
 */
/// \{
#ifndef bstc_vect_begin
# define bstc_vect_begin(...) bstc_ctuple_call(bstc_dtl_vect_begin, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get a forward iterator referencing the end of the vector.
 * \param vect Reference to the vector.
 * \return Returns the forward iterator to the end of the vector.
 */
/// \{
#ifndef bstc_vect_end
# define bstc_vect_end(...) bstc_ctuple_call(bstc_dtl_vect_end, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get a reverse iterator referencing the first item.
 * \param vect Reference to the vector.
 * \return Returns the reverse iterator to the first item.
 */
/// \{
#ifndef bstc_vect_rbegin
# define bstc_vect_rbegin(...) bstc_ctuple_call(bstc_dtl_vect_rbegin, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Get a reverse iterator referencing the end of the vector.
 * \param vect Reference to the vector.
 * \return Returns the reverse iterator to the end of the vector.
 */
/// \{
#ifndef bstc_vect_rend
# define bstc_vect_rend(...) bstc_ctuple_call(bstc_dtl_vect_rend, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


/** Declares the forward iterator type.
 * \param T The base type of the vector or the template.
 */
/// \{
#ifndef bstc_vect_iter_t
# define bstc_vect_iter_t(T) bstc_tmplt_isa(T, bstc_iter_t(bstc_tmplt_iter(T)), bstc_dtl_vect_default_iter_t(T))
#endif
/// \}


#define bstc_vect_iter_nxt(iter, ...) \
    bstc_tmplt_isa(iter,\
        bstc_iter_nxt(bstc_tmplt_iter(iter))(bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_iter_nxt(iter)\
    )
#define bstc_vect_iter_eq(left, right, ...) \
    bstc_tmplt_isa(left,\
        bstc_iter_eq(bstc_tmplt_iter(left))(right, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_iter_eq(left, right)\
    )


/** Declares the forward iterator type.
 * \param iter Reference to the vector.
 */
/// \{
#ifndef bstc_vect_iter_val
# define bstc_vect_iter_val(...) bstc_ctuple_call(bstc_dtl_vect_iter_val, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


#define bstc_vect_iter_set(iter, val, ...) \
    bstc_tmplt_isa(iter,\
        bstc_iter_set(bstc_tmplt_iter(iter))(val, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_iter_set(iter, val)\
    )
#define bstc_vect_iter_swap(left, right, ...) \
    bstc_tmplt_isa(left,\
        bstc_iter_swap(bstc_tmplt_iter(left))(right, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_iter_swap(left, right)\
    )



/** Declares the reverse iterator type.
 * \param T The base type of the vector or the template.
 */
/// \{
#ifndef bstc_vect_riter_t
# define bstc_vect_riter_t(T) bstc_tmplt_isa(T, bstc_iter_t(bstc_tmplt_riter(T)), bstc_dtl_vect_default_riter_t(T))
#endif
/// \}


#define bstc_vect_riter_nxt(iter, ...) \
    bstc_tmplt_isa(iter,\
        bstc_iter_nxt(bstc_tmplt_riter(iter))(bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_riter_nxt(iter)\
    )
#define bstc_vect_riter_eq(left, right, ...) \
    bstc_tmplt_isa(left,\
        bstc_iter_eq(bstc_tmplt_riter(left))(right, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_riter_eq(left, right)\
    )


/** Declares the reverse iterator type.
 * \param iter Reference to the vector.
 */
/// \{
#ifndef bstc_vect_riter_val
# define bstc_vect_riter_val(...) bstc_ctuple_call(bstc_dtl_vect_riter_val, bstc_dtl_vect_add_tmplt(bstc_ctuple(__VA_ARGS__)))
#endif
/// \}


#define bstc_vect_riter_set(iter, val, ...) \
    bstc_tmplt_isa(iter,\
        bstc_iter_set(bstc_tmplt_riter(iter))(val, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_riter_set(iter, val)\
    )
#define bstc_vect_riter_swap(left, right, ...) \
    bstc_tmplt_isa(left,\
        bstc_iter_swap(bstc_tmplt_riter(left))(right, bstc_ctuple_getI(bstc_ctuple(__VA_ARGS__), 0)),\
        bstc_dtl_vect_riter_swap(left, right)\
    )
