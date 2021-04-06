//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/traits/allocator.h>
#include <boostc/traits/object.h>


/** Provide operations on bstc container types.
 * type: The actual type for the container.
 * info: A ctuple of the information about the type.
 * subtraits: A object traits representing what it contains.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_container_traits
# define bstc_container_traits(t, info, subtraits, alloc, init, destroy, clone, copy, move, assign) bstc_obj_traits(t, init, destroy, clone, copy, move, assign, (info, subtraits, alloc))
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
# define bstc_container_pack_info(info) bstc_container_set_info(bstc_container_defaults, info)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the subtraits ctuple provided. */
/// \{
#ifndef bstc_container_pack_subtraits
# define bstc_container_pack_subtraits(subtraits) bstc_container_set_subtraits(bstc_container_defaults, subtraits)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the allocator ctuple provided. */
/// \{
#ifndef bstc_container_pack_alloc
# define bstc_container_pack_alloc(alloc) bstc_container_set_alloc(bstc_container_defaults, alloc)
#endif
/// \}


/** Get the container type that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_t
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_container_t(tpl) bstc_obj_t(tpl)
# endif
#endif
/// \}


/** Get the container info that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_info
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_dtl_container_info(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
#  define bstc_container_info(tpl) bstc_dtl_container_info(bstc_obj_extend(tpl))
# else
#  define bstc_dtl_container_info(tpl) BSTC_EXPAND(bstc_dtl_container_info_expand tpl)
#  define bstc_dtl_container_info_expand(info, subtraits, alloc) info
#  define bstc_container_info(tpl) bstc_dtl_container_info(bstc_obj_extend(tpl))
# endif
#endif
/// \}


/** Get the container subtraits ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_subtraits
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_dtl_container_subtraits(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
#  define bstc_container_subtraits(tpl) bstc_dtl_container_subtraits(bstc_obj_extend(tpl))
# else
#  define bstc_dtl_container_subtraits(tpl) BSTC_EXPAND(bstc_dtl_container_subtraits_expand tpl)
#  define bstc_dtl_container_subtraits_expand(info, subtraits, alloc) subtraits
#  define bstc_container_subtraits(tpl) bstc_dtl_container_subtraits(bstc_obj_extend(tpl))
# endif
#endif
/// \}


/** Get the container allocator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_alloc
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_dtl_container_alloc(tpl) BSTC_EXPAND(BSTC_GET_ARG2 tpl)
#  define bstc_container_alloc(tpl) bstc_dtl_container_alloc(bstc_obj_extend(tpl))
# else
#  define bstc_dtl_container_alloc(tpl) BSTC_EXPAND(bstc_dtl_container_alloc_expand tpl)
#  define bstc_dtl_container_alloc_expand(info, subtraits, alloc) alloc
#  define bstc_container_alloc(tpl) bstc_dtl_container_alloc(bstc_obj_extend(tpl))
# endif
#endif
/// \}


/** Create a copy of the ctuple as a container with the container type changed to what is provided. */
/// \{
#ifndef bstc_container_set_t
# define bstc_container_set_t(tpl, t) bstc_obj_set_t(tpl, t)
#endif
/// \}


/** Create a copy of the ctuple as a container with the container info changed to what is provided. */
/// \{
#ifndef bstc_container_set_info
# define bstc_dtl_container_set_info(tpl, p) bstc_dtl_container_set_info_expand(BSTC_LAYOUT3 tpl, p)
# define bstc_dtl_container_set_info_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_info_expand1(L, p))
# define bstc_dtl_container_set_info_expand1(info, subtraits, alloc, p) BSTC_CTUPLE3(p, subtraits, alloc)
# define bstc_container_set_info(tpl, info) BSTC_EXPAND(bstc_obj_set_extend(tpl, bstc_dtl_container_set_info(bstc_obj_extend(tpl), info)))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container subtraits ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_subtraits
# define bstc_dtl_container_set_subtraits(tpl, p) bstc_dtl_container_set_subtraits_expand(BSTC_LAYOUT3 tpl, p)
# define bstc_dtl_container_set_subtraits_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_subtraits_expand1(L, p))
# define bstc_dtl_container_set_subtraits_expand1(info, subtraits, alloc, p) BSTC_CTUPLE3(info, p, alloc)
# define bstc_container_set_subtraits(tpl, subtraits) BSTC_EXPAND(bstc_obj_set_extend(tpl, bstc_dtl_container_set_subtraits(bstc_obj_extend(tpl), subtraits)))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container allocator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_alloc
# define bstc_dtl_container_set_alloc(tpl, p) bstc_dtl_container_set_alloc_expand(BSTC_LAYOUT3 tpl, p)
# define bstc_dtl_container_set_alloc_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_alloc_expand1(L, p))
# define bstc_dtl_container_set_alloc_expand1(info, subtraits, alloc, p) BSTC_CTUPLE3(info, subtraits, p)
# define bstc_container_set_alloc(tpl, alloc) BSTC_EXPAND(bstc_obj_set_extend(tpl, bstc_dtl_container_set_alloc(bstc_obj_extend(tpl), alloc)))
#endif
/// \}


/** Default container ctuple that uses the default allocator, subtraits, type, and functions. */
/// \{
#ifndef bstc_container_defaults
# define bstc_container_defaults bstc_container_traits(int, (0), bstc_obj_defaults, bstc_alloc_defaults, bstc_obj_noinit, bstc_obj_nodestroy, bstc_obj_noclone, bstc_obj_nocopy, bstc_obj_nomove, bstc_obj_noassign)
#endif
/// \}


/** Detects if the ctuple provided could be a valid container ctuple. */
/// \{
#ifndef bstc_container_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_container_isa(tpl, _t, _f) bstc_obj_isa(tpl, _t, _f)
# endif
#endif
/// \}
