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


/** Initializes the vector structure from another vector as an exact clone.
 * \param vect Pointer to the vector.
 * \param other Pointer to the vector to copy.
 */
/// \{
#ifndef bstc_vect_clone
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_clone(...) bstc_ctuple_call(bstc_dtl_vect_clone, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_clone(traits, vect, other) bstc_dtl_vect_clone(traits, vect, other)
# endif
#endif
/// \}


/** Initializes the vector structure from another vector as a move potentially invalidating the copied vector.
 * \param vect Pointer to the vector.
 * \param other Reference to the vector to move.
 */
/// \{
#ifndef bstc_vect_move
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_move(...) bstc_ctuple_call(bstc_dtl_vect_move, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_move(traits, vect, other) bstc_dtl_vect_move(traits, vect, other)
# endif
#endif
/// \}


/** Copies the other vector structure provided assuming both vectors have been initialized.
 * \param vect Pointer to the vector.
 * \param other Pointer to the vector to copy.
 */
/// \{
#ifndef bstc_vect_copy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_copy(...) bstc_ctuple_call(bstc_dtl_vect_copy, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_copy(traits, vect, other) bstc_dtl_vect_copy(traits, vect, other)
# endif
#endif
/// \}


/** Shallow copies the other vector structure provided assuming both vectors have been initialized.
 * \param vect Pointer to the vector.
 * \param other Reference to the vector to copy.
 */
/// \{
#ifndef bstc_vect_assign
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_vect_assign(...) bstc_ctuple_call(bstc_dtl_vect_assign, bstc_dtl_vect_add_traits(bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_vect_assign(traits, vect, other) bstc_dtl_vect_assign(traits, vect, other)
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


#endif // BOOSTC__CONTAINER__VECTOR_H
