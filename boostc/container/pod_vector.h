//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONTAINER__POD_VECTOR_H
#define BOOSTC__CONTAINER__POD_VECTOR_H


#include <boostc/container/detail/pod_vector.h>


/** Declares the vector container traits.
 * \param T The type of the data in the vector.
 * \param alloc An optional argument which is the allocator for the vector traits.
 * \param subtraits An optional argument which is the subtraits for the type provided (not used in POD vector).
 */
/// \{
#ifndef bstc_podvect_traits
# if defined(BSTC_HAS_VARIADIC_MACROS)
#  define bstc_podvect_traits(...) BSTC_EXPAND(bstc_ctuple_call(bstc_dtl_podvect_traits_select(bstc_ctuple(__VA_ARGS__)), bstc_ctuple(__VA_ARGS__)))
# else
#  define bstc_podvect_traits(T, alloc, subtraits) bstc_dtl_podvect_traits3(T, alloc, subtraits)
# endif
#endif
/// \}


/** Declares the vector type.
 * \param T The vector traits or the template type of the vector.
 */
/// \{
#ifndef bstc_podvect_t
# ifdef bstc_container_isa
#  define bstc_podvect_t(T) bstc_container_isa(T, bstc_container_t(T), T*)
# else
#  define bstc_podvect_t(traits) bstc_container_t(traits)
# endif
#endif
/// \}


/** Initializes the vector structure.
 * \param vect Pointer to the vector.
 */
/// \{
#ifndef bstc_podvect_init
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_init(...) bstc_ctuple_call(bstc_dtl_podvect_init, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_init(traits, vect, id) bstc_dtl_podvect_init(traits, vect, id)
# endif
#endif
/// \}


/** Initializes the vector structure from another vector as an exact clone.
 * \param vect Pointer to the vector.
 * \param other Pointer to the vector to copy.
 */
/// \{
#ifndef bstc_podvect_clone
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_clone(...) bstc_ctuple_call(bstc_dtl_podvect_clone, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_clone(traits, vect, other, id) bstc_dtl_podvect_clone(traits, vect, other, id)
# endif
#endif
/// \}


/** Initializes the vector structure from another vector as a move potentially invalidating the copied vector.
 * \param vect Pointer to the vector.
 * \param other Reference to the vector to move.
 */
/// \{
#ifndef bstc_podvect_move
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_move(...) bstc_ctuple_call(bstc_dtl_podvect_move, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_move(traits, vect, other, id) bstc_dtl_podvect_move(traits, vect, other, id)
# endif
#endif
/// \}


/** Copies the other vector structure provided assuming both vectors have been initialized.
 * \param vect Pointer to the vector.
 * \param other Pointer to the vector to copy.
 */
/// \{
#ifndef bstc_podvect_copy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_copy(...) bstc_ctuple_call(bstc_dtl_podvect_copy, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_copy(traits, vect, other, id) bstc_dtl_podvect_copy(traits, vect, other, id)
# endif
#endif
/// \}


/** Shallow copies the other vector structure provided assuming both vectors have been initialized.
 * \param vect Pointer to the vector.
 * \param other Reference to the vector to copy.
 */
/// \{
#ifndef bstc_podvect_assign
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_assign(...) bstc_ctuple_call(bstc_dtl_podvect_assign, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_assign(traits, vect, other, id) bstc_dtl_podvect_assign(traits, vect, other, id)
# endif
#endif
/// \}


/** Destroys and frees any memory allocated for the vector.
 * \param vect Pointer to the vector.
 */
/// \{
#ifndef bstc_podvect_destroy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_destroy(...) bstc_ctuple_call(bstc_dtl_podvect_destroy, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_destroy(traits, vect, id) bstc_dtl_podvect_destroy(traits, vect, id)
# endif
#endif
/// \}


/** Gets the number of items that have been added or resized to.
 * \param vect Pointer to the vector.
 * \return Returns the number of items.
 */
/// \{
#ifndef bstc_podvect_len
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_len(...) bstc_ctuple_call(bstc_dtl_podvect_len, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_len(traits, vect, id) bstc_dtl_podvect_len(traits, vect, id)
# endif
#endif
/// \}


/** Gets the capacity that the vector has been allocated for.
 * \param vect Pointer to the vector.
 * \return Returns the capacity for the vector.
 */
/// \{
#ifndef bstc_podvect_cap
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_cap(...) bstc_ctuple_call(bstc_dtl_podvect_cap, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_cap(traits, vect, id) bstc_dtl_podvect_cap(traits, vect, id)
# endif
#endif
/// \}


/** Gets the data array that the vector has been allocated with.
 * \param vect Pointer to the vector.
 * \return Returns the data array for the vector.
 */
/// \{
#ifndef bstc_podvect_data
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_data(...) bstc_ctuple_call(bstc_dtl_podvect_data, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_data(traits, vect, id) bstc_dtl_podvect_data(traits, vect, id)
# endif
#endif
/// \}


/** Resizes the vector to be able to hold the new size.
 * \param vect Pointer to the vector.
 * \param nsz The new size for the vector.
 */
/// \{
#ifndef bstc_podvect_rsz
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_rsz(...) bstc_ctuple_call(bstc_dtl_podvect_rsz, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_rsz(traits, vect, nsz, id) bstc_dtl_podvect_rsz(traits, vect, nsz, id)
# endif
#endif
/// \}


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Pointer to the vector.
 * \param ncap The new capacity for the vector.
 */
/// \{
#ifndef bstc_podvect_rsv
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_rsv(...) bstc_ctuple_call(bstc_dtl_podvect_rsv, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_rsv(traits, vect, ncap, id) bstc_dtl_podvect_rsv(traits, vect, ncap, id)
# endif
#endif
/// \}


/** Assert at the index provided then read the value in the array.
 * \param vect Pointer to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
/// \{
#ifndef bstc_podvect_at
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_at(...) bstc_ctuple_call(bstc_dtl_podvect_at, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_at(traits, vect, i, id) bstc_dtl_podvect_at(traits, vect, i, id)
# endif
#endif
/// \}


/** Checks to see if the vector is empty.
 * \param vect Pointer to the vector.
 * \return Returns one if empty and zero otherwise.
 */
/// \{
#ifndef bstc_podvect_empty
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_empty(...) bstc_ctuple_call(bstc_dtl_podvect_empty, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_empty(traits, vect, id) bstc_dtl_podvect_empty(traits, vect, id)
# endif
#endif
/// \}


/** Get the front value of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the value at the first index.
 */
/// \{
#ifndef bstc_podvect_front
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_front(...) bstc_ctuple_call(bstc_dtl_podvect_front, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_front(traits, vect, id) bstc_dtl_podvect_front(traits, vect, id)
# endif
#endif
/// \}


/** Get the back value of the vector.
 * \param vect Pointer to the vector.
 * \return Returns the value at the last index.
 */
/// \{
#ifndef bstc_podvect_back
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_back(...) bstc_ctuple_call(bstc_dtl_podvect_back, bstc_dtl_podvect_add_id(2, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_back(traits, vect, id) bstc_dtl_podvect_back(traits, vect, id)
# endif
#endif
/// \}


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Pointer to the vector.
 * \param val The value to push on.
 */
/// \{
#ifndef bstc_podvect_pushb
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_podvect_pushb(...) bstc_ctuple_call(bstc_dtl_podvect_pushb, bstc_dtl_podvect_add_id(3, bstc_dtl_podvect_add_traits(bstc_ctuple(__VA_ARGS__))))
# else
#  define bstc_podvect_pushb(traits, vect, val, id) bstc_dtl_podvect_pushb(traits, vect, val, id)
# endif
#endif
/// \}


#endif // BOOSTC__CONTAINER__POD_VECTOR_H
