//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/traits/allocator.h>
#include <boostc/traits/iterator.h>
#include <boostc/traits/object.h>


/** Provide operations on bstc container types.
 * type: The actual type for the container.
 * subtraits: A ctuple of the information about the type.
 * obj: A ctuple of the object traits for the type.
 * iter: The bstc iterator calls as a ctuple for the type.
 * riter: The bstc reverse iterator calls as a ctuple for the type.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_container_traits
# define bstc_container_traits(t, info, subtraits, obj, iter, riter, alloc) (t, info, subtraits, obj, iter, riter, alloc)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the functions ctuple provided. */
/// \{
#ifndef bstc_container_wrap_obj
# if defined(bstc_ctuple_isa)
#  define bstc_container_wrap_obj(obj) bstc_ctuple_isa(obj, bstc_container_set_t(bstc_container_set_obj(bstc_container_defaults, obj), bstc_obj_t(obj)), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_wrap_obj(obj) bstc_container_set_t(bstc_container_set_obj(bstc_container_defaults, obj), bstc_obj_t(obj))
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the container type provided. */
/// \{
#ifndef bstc_container_pack_t
# define bstc_container_pack_t(t) bstc_container_set_t(bstc_container_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the info provided. */
/// \{
#ifndef bstc_container_pack_info
# if defined(bstc_ctuple_isa)
#  define bstc_container_pack_info(info) bstc_ctuple_isa(info, bstc_container_set_info(bstc_container_defaults, info), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_info(info) bstc_container_set_info(bstc_container_defaults, info)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the subtraits ctuple provided. */
/// \{
#ifndef bstc_container_pack_subtraits
# if defined(bstc_ctuple_isa)
#  define bstc_container_pack_subtraits(subtraits) bstc_ctuple_isa(subtraits, bstc_container_set_subtraits(bstc_container_defaults, subtraits), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_subtraits(subtraits) bstc_container_set_subtraits(bstc_container_defaults, subtraits)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the functions ctuple provided. */
/// \{
#ifndef bstc_container_pack_obj
# if defined(bstc_ctuple_isa)
#  define bstc_container_pack_obj(obj) bstc_ctuple_isa(obj, bstc_container_set_obj(bstc_container_defaults, obj), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_obj(obj) bstc_container_set_obj(bstc_container_defaults, obj)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the iterator ctuple provided. */
/// \{
#ifndef bstc_container_pack_iter
# if defined(bstc_iter_isa)
#  define bstc_container_pack_iter(iter) bstc_iter_isa(iter, bstc_container_set_iter(bstc_container_defaults, iter), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_iter(iter) bstc_container_set_iter(bstc_container_defaults, iter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the reverse iterator ctuple provided. */
/// \{
#ifndef bstc_container_pack_riter
# if defined(bstc_iter_isa)
#  define bstc_container_pack_riter(riter) bstc_iter_isa(riter, bstc_container_set_riter(bstc_container_defaults, riter), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_riter(riter) bstc_container_set_riter(bstc_container_defaults, riter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the allocator ctuple provided. */
/// \{
#ifndef bstc_container_pack_alloc
# if defined(bstc_alloc_isa)
#  define bstc_container_pack_alloc(alloc) bstc_alloc_isa(alloc, bstc_container_set_alloc(bstc_container_defaults, alloc), BSTC_CONTAINER_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_alloc(alloc) bstc_container_set_alloc(bstc_container_defaults, alloc)
# endif
#endif
/// \}


/** Get the container type that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_t
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_container_t(t, info, subtraits, obj, iter, riter, alloc) t
#  define bstc_container_t(tpl) BSTC_EXPAND(bstc_dtl_container_t tpl)
# endif
#endif
/// \}


/** Get the container info that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_info
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_info(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
# else
#  define bstc_dtl_container_info(t, info, subtraits, obj, iter, riter, alloc) info
#  define bstc_container_info(tpl) BSTC_EXPAND(bstc_dtl_container_info tpl)
# endif
#endif
/// \}


/** Get the container subtraits ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_subtraits
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_subtraits(tpl) BSTC_EXPAND(BSTC_GET_ARG2 tpl)
# else
#  define bstc_dtl_container_subtraits(t, info, subtraits, obj, iter, riter, alloc) subtraits
#  define bstc_container_subtraits(tpl) BSTC_EXPAND(bstc_dtl_container_subtraits tpl)
# endif
#endif
/// \}


/** Get the container functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_obj
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_obj(tpl) BSTC_EXPAND(BSTC_GET_ARG3 tpl)
# else
#  define bstc_dtl_container_obj(t, info, subtraits, obj, iter, riter, alloc) obj
#  define bstc_container_obj(tpl) BSTC_EXPAND(bstc_dtl_container_obj tpl)
# endif
#endif
/// \}


/** Get the container iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_iter
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_iter(tpl) BSTC_EXPAND(BSTC_GET_ARG4 tpl)
# else
#  define bstc_dtl_container_iter(t, info, subtraits, obj, iter, riter, alloc) iter
#  define bstc_container_iter(tpl) BSTC_EXPAND(bstc_dtl_container_iter tpl)
# endif
#endif
/// \}


/** Get the container reverse iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_riter
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_riter(tpl) BSTC_EXPAND(BSTC_GET_ARG5 tpl)
# else
#  define bstc_dtl_container_riter(t, info, subtraits, obj, iter, riter, alloc) riter
#  define bstc_container_riter(tpl) BSTC_EXPAND(bstc_dtl_container_riter tpl)
# endif
#endif
/// \}


/** Get the container allocator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_alloc
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_alloc(tpl) BSTC_EXPAND(BSTC_GET_ARG6 tpl)
# else
#  define bstc_dtl_container_alloc(t, info, subtraits, obj, iter, riter, alloc) alloc
#  define bstc_container_alloc(tpl) BSTC_EXPAND(bstc_dtl_container_alloc tpl)
# endif
#endif
/// \}


/** Create a copy of the ctuple as a container with the container type changed to what is provided. */
/// \{
#ifndef bstc_container_set_t
# define bstc_dtl_container_set_t(tpl, p) bstc_dtl_container_set_t_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_t_expand1(L, p))
# define bstc_dtl_container_set_t_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(p, info, subtraits, obj, iter, riter, alloc)
# define bstc_container_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_container_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container info changed to what is provided. */
/// \{
#ifndef bstc_container_set_info
# define bstc_dtl_container_set_info(tpl, p) bstc_dtl_container_set_info_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_info_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_info_expand1(L, p))
# define bstc_dtl_container_set_info_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, p, subtraits, obj, iter, riter, alloc)
# define bstc_container_set_info(tpl, info) BSTC_EXPAND(bstc_dtl_container_set_info(tpl, info))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container subtraits ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_subtraits
# define bstc_dtl_container_set_subtraits(tpl, p) bstc_dtl_container_set_subtraits_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_subtraits_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_subtraits_expand1(L, p))
# define bstc_dtl_container_set_subtraits_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, info, p, obj, iter, riter, alloc)
# define bstc_container_set_subtraits(tpl, subtraits) BSTC_EXPAND(bstc_dtl_container_set_subtraits(tpl, subtraits))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container functions ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_obj
# define bstc_dtl_container_set_obj(tpl, p) bstc_dtl_container_set_obj_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_obj_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_obj_expand1(L, p))
# define bstc_dtl_container_set_obj_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, info, subtraits, p, iter, riter, alloc)
# define bstc_container_set_obj(tpl, obj) BSTC_EXPAND(bstc_dtl_container_set_obj(tpl, obj))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_iter
# define bstc_dtl_container_set_iter(tpl, p) bstc_dtl_container_set_iter_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_iter_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_iter_expand1(L, p))
# define bstc_dtl_container_set_iter_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, info, subtraits, obj, p, riter, alloc)
# define bstc_container_set_iter(tpl, iter) BSTC_EXPAND(bstc_dtl_container_set_iter(tpl, iter))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container reverse iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_riter
# define bstc_dtl_container_set_riter(tpl, p) bstc_dtl_container_set_riter_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_riter_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_riter_expand1(L, p))
# define bstc_dtl_container_set_riter_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, info, subtraits, obj, iter, p, alloc)
# define bstc_container_set_riter(tpl, riter) BSTC_EXPAND(bstc_dtl_container_set_riter(tpl, riter))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container allocator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_alloc
# define bstc_dtl_container_set_alloc(tpl, p) bstc_dtl_container_set_alloc_expand(BSTC_LAYOUT7 tpl, p)
# define bstc_dtl_container_set_alloc_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_alloc_expand1(L, p))
# define bstc_dtl_container_set_alloc_expand1(t, info, subtraits, obj, iter, riter, alloc, p) bstc_container_traits(t, info, subtraits, obj, iter, riter, p)
# define bstc_container_set_alloc(tpl, alloc) BSTC_EXPAND(bstc_dtl_container_set_alloc(tpl, alloc))
#endif
/// \}


/** Default container subtraits. */
/// \{
#ifndef bstc_container_default_subtraits
# define bstc_container_default_subtraits bstc_container_traits(int, 0, BSTC_CTUPLE1(0), bstc_obj_defaults, bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Default container ctuple that uses the default iterators, allocator, subtraits, type, and functions. */
/// \{
#ifndef bstc_container_defaults
# define bstc_container_defaults bstc_container_traits(int, 0, bstc_container_default_subtraits, bstc_obj_defaults, bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Detects if the ctuple provided could be a valid container ctuple. */
/// \{
#ifndef bstc_container_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 7, _t, _f), _f)
# endif
#endif
/// \}
