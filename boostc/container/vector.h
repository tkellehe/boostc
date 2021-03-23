//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONTAINER__VECTOR_H
#define BOOSTC__CONTAINER__VECTOR_H


#include <boostc/container/detail/vector.h>


/** Declares the vector vector traits.
 * \param T The type of the data in the vector.
 * \param alloc An optional argument which is the allocator for the vector traits.
 * \param subtraits An optional argument which is the subtraits for the type provided.
 */
/// \{
#ifndef bstc_vect_traits
# if defined(BSTC_HAS_VARIADIC_MACROS)
#  define bstc_vect_traits(...) BSTC_EXPAND(bstc_ctuple_call(bstc_dtl_vect_traits_select(bstc_ctuple(__VA_ARGS__)), bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_traits(T, alloc, subtraits) bstc_dtl_vect_traits3(T, alloc, subtraits)
# endif
#endif
/// \}


/** Declares the vector type.
 * \param T The vector traits or the template type of the vector.
 */
/// \{
#ifndef bstc_vect_t
# ifdef bstc_container_isa
#  define bstc_vect_t(T) bstc_container_isa(T, bstc_container_t(T), T*)
# else
#  define bstc_vect_t(traits) bstc_container_t(traits)
# endif
#endif
/// \}


/** Initializes the vector structure.
 * \param vect Pointer to the vector.
 */
/// \{
#ifndef bstc_vect_init
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_init(...) bstc_ctuple_call(bstc_dtl_vect_init, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_init(traits, vect) bstc_dtl_vect_init(traits, vect)
# endif
#endif
/// \}


/** Destroys and frees any memory allocated for the vector.
 * \param vect Pointer to the vector.
 */
/// \{
#ifndef bstc_vect_destroy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_destroy(...) bstc_ctuple_call(bstc_dtl_vect_destroy, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_destroy(traits, vect) bstc_dtl_vect_destroy(traits, vect)
# endif
#endif
/// \}


/** Gets the number of items that have been added or resized to.
 * \param vect Pointer to the vector.
 * \return Returns the number of items.
 */
/// \{
#ifndef bstc_vect_len
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_len(...) bstc_ctuple_call(bstc_dtl_vect_len, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_len(traits, vect) bstc_dtl_vect_len(traits, vect)
# endif
#endif
/// \}


/** Gets the capacity that the vector has been allocated for.
 * \param vect Pointer to the vector.
 * \return Returns the capacity for the vector.
 */
/// \{
#ifndef bstc_vect_cap
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_cap(...) bstc_ctuple_call(bstc_dtl_vect_cap, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_cap(traits, vect) bstc_dtl_vect_cap(traits, vect)
# endif
#endif
/// \}


/** Gets the data array that the vector has been allocated with.
 * \param vect Pointer to the vector.
 * \return Returns the data array for the vector.
 */
/// \{
#ifndef bstc_vect_data
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_data(...) bstc_ctuple_call(bstc_dtl_vect_data, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_data(traits, vect) bstc_dtl_vect_data(traits, vect)
# endif
#endif
/// \}


/** Resizes the vector to be able to hold the new size.
 * \param vect Pointer to the vector.
 * \param nsz The new size for the vector.
 */
/// \{
#ifndef bstc_vect_rsz
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_rsz(...) bstc_ctuple_call(bstc_dtl_vect_rsz, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_rsz(traits, vect, nsz) bstc_dtl_vect_rsz(traits, vect, nsz)
# endif
#endif
/// \}


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Pointer to the vector.
 * \param ncap The new capacity for the vector.
 */
/// \{
#ifndef bstc_vect_rsv
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_rsv(...) bstc_ctuple_call(bstc_dtl_vect_rsv, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_rsv(traits, vect, ncap) bstc_dtl_vect_rsv(traits, vect, ncap)
# endif
#endif
/// \}


/** Assert at the index provided then read the value in the array.
 * \param vect Pointer to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
/// \{
#ifndef bstc_vect_at
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_at(...) bstc_ctuple_call(bstc_dtl_vect_at, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_at(traits, vect, i) bstc_dtl_vect_at(traits, vect, i)
# endif
#endif
/// \}


/** Checks to see if the vector is empty.
 * \param vect Pointer to the vector.
 * \return Returns one if empty and zero otherwise.
 */
/// \{
#ifndef bstc_vect_empty
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_empty(...) bstc_ctuple_call(bstc_dtl_vect_empty, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_empty(traits, vect) bstc_dtl_vect_empty(traits, vect)
# endif
#endif
/// \}


/** Get the front value of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the value at the first index.
 */
/// \{
#ifndef bstc_vect_front
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_front(...) bstc_ctuple_call(bstc_dtl_vect_front, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_front(traits, vect) bstc_dtl_vect_front(traits, vect)
# endif
#endif
/// \}


/** Get the back value of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the value at the last index.
 */
/// \{
#ifndef bstc_vect_back
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_back(...) bstc_ctuple_call(bstc_dtl_vect_back, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_back(traits, vect) bstc_dtl_vect_back(traits, vect)
# endif
#endif
/// \}


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Pointer to the vector.
 * \param val The value to push on.
 */
/// \{
#ifndef bstc_vect_pushb
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_pushb(...) bstc_ctuple_call(bstc_dtl_vect_pushb, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_pushb(traits, vect, val) bstc_dtl_vect_pushb(traits, vect, val)
# endif
#endif
/// \}


/** Get a forward iterator referencing the first item.
 * \param vect Pointer to the vector.
 * \return Returns the forward iterator to the first item.
 */
/// \{
#ifndef bstc_vect_begin
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_begin(...) bstc_ctuple_call(bstc_dtl_vect_begin, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_begin(traits, vect) bstc_dtl_vect_begin(traits, vect)
# endif
#endif
/// \}


/** Get a forward iterator referencing the end of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the forward iterator to the end of the vector.
 */
/// \{
#ifndef bstc_vect_end
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_end(...) bstc_ctuple_call(bstc_dtl_vect_end, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_end(traits, vect) bstc_dtl_vect_end(traits, vect)
# endif
#endif
/// \}


/** Get a reverse iterator referencing the first item.
 * \param vect Pointer to the vector.
 * \return Returns the reverse iterator to the first item.
 */
/// \{
#ifndef bstc_vect_rbegin
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_rbegin(...) bstc_ctuple_call(bstc_dtl_vect_rbegin, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_rbegin(traits, vect) bstc_dtl_vect_rbegin(traits, vect)
# endif
#endif
/// \}


/** Get a reverse iterator referencing the end of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the reverse iterator to the end of the vector.
 */
/// \{
#ifndef bstc_vect_rend
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_rend(...) bstc_ctuple_call(bstc_dtl_vect_rend, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_rend(traits, vect) bstc_dtl_vect_rend(traits, vect)
# endif
#endif
/// \}


/** Declares the forward iterator type.
 * \param T The base type of the vector or the template.
 */
/// \{
#ifndef bstc_vect_iter_t
# ifdef bstc_container_isa
#  define bstc_vect_iter_t(T) bstc_container_isa(T, bstc_iter_t(bstc_container_iter(T)), bstc_dtl_vect_default_iter_t(T))
# else
#  define bstc_vect_iter_t(traits) bstc_iter_t(bstc_container_iter(traits))
# endif
#endif
/// \}


/** Moves the forward iterator to the next iterator.
 * \param iter The iterator.
 */
/// \{
#ifndef bstc_vect_iter_nxt
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_iter_nxt(...) bstc_ctuple_call(bstc_dtl_vect_iter_nxt, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_iter_nxt(traits, iter) bstc_dtl_vect_iter_nxt(traits, iter)
# endif
#endif
/// \}


/** Detects if two forward iterators are referencing the same location.
 * \param left The left iterator.
 * \param right The right iteratir.
 */
/// \{
#ifndef bstc_vect_iter_eq
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_iter_eq(...) bstc_ctuple_call(bstc_dtl_vect_iter_eq, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_iter_eq(traits, left, right) bstc_dtl_vect_iter_eq(traits, left, right)
# endif
#endif
/// \}


/** Accesses the value of the forward iterator.
 * \param iter The iterator.
 */
/// \{
#ifndef bstc_vect_iter_val
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_iter_val(...) bstc_ctuple_call(bstc_dtl_vect_iter_val, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_iter_val(traits, iter) bstc_dtl_vect_iter_val(traits, iter)
# endif
#endif
/// \}


/** Accesses the value of the forward iterator.
 * \param iter The iterator.
 * \param val The value to assign to where the iterator is referencing.
 */
/// \{
#ifndef bstc_vect_iter_put
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_iter_put(...) bstc_ctuple_call(bstc_dtl_vect_iter_put, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_iter_put(traits, iter, val) bstc_dtl_vect_iter_put(traits, iter, val)
# endif
#endif
/// \}


/** Swaps the contents of to forward iterators.
 * \param left The left iterator.
 * \param right The right iteratir.
 */
/// \{
#ifndef bstc_vect_iter_swap
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_iter_swap(...) bstc_ctuple_call(bstc_dtl_vect_iter_swap, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_iter_swap(traits, left, right) bstc_dtl_vect_iter_swap(traits, left, right)
# endif
#endif
/// \}


/** Declares the reverse iterator type.
 * \param T The base type of the vector or the template.
 */
/// \{
#ifndef bstc_vect_riter_t
# ifdef bstc_container_isa
#  define bstc_vect_riter_t(T) bstc_container_isa(T, bstc_iter_t(bstc_container_riter(T)), bstc_dtl_vect_default_riter_t(T))
# else
#  define bstc_vect_riter_t(traits) bstc_iter_t(bstc_container_riter(traits))
# endif
#endif
/// \}


/** Moves the reverse iterator to the next iterator.
 * \param iter The iterator.
 */
/// \{
#ifndef bstc_vect_riter_nxt
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_riter_nxt(...) bstc_ctuple_call(bstc_dtl_vect_riter_nxt, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_riter_nxt(traits, iter) bstc_dtl_vect_riter_nxt(traits, iter)
# endif
#endif
/// \}


/** Detects if two reverse iterators are referencing the same location.
 * \param left The left iterator.
 * \param right The right iteratir.
 */
/// \{
#ifndef bstc_vect_riter_eq
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_riter_eq(...) bstc_ctuple_call(bstc_dtl_vect_riter_eq, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_riter_eq(traits, left, right) bstc_dtl_vect_riter_eq(traits, left, right)
# endif
#endif
/// \}


/** Accesses the value of the reverse iterator.
 * \param iter The iterator.
 */
/// \{
#ifndef bstc_vect_riter_val
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_riter_val(...) bstc_ctuple_call(bstc_dtl_vect_riter_val, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_riter_val(traits, iter) bstc_dtl_vect_riter_val(traits, iter)
# endif
#endif
/// \}


/** Accesses the value of the reverse iterator.
 * \param iter The iterator.
 * \param val The value to assign to where the iterator is referencing.
 */
/// \{
#ifndef bstc_vect_riter_put
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_riter_put(...) bstc_ctuple_call(bstc_dtl_vect_riter_put, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_riter_put(traits, iter, val) bstc_dtl_vect_riter_put(traits, iter, val)
# endif
#endif
/// \}


/** Swaps the contents of to reverse iterators.
 * \param left The left iterator.
 * \param right The right iteratir.
 */
/// \{
#ifndef bstc_vect_riter_swap
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_riter_swap(...) bstc_ctuple_call(bstc_dtl_vect_riter_swap, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_riter_swap(traits, left, right) bstc_dtl_vect_riter_swap(traits, left, right)
# endif
#endif
/// \}


#endif // BOOSTC__CONTAINER__VECTOR_H
