//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stdlib.h>


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_obj_traits
# define bstc_obj_traits(t, ctor, dtor, cptor, assign) (t, ctor, dtor, cptor, assign)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the type provided. */
/// \{
#ifndef bstc_obj_pack_t
# define bstc_obj_pack_t(t) bstc_obj_set_t(bstc_obj_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the ctor function provided. */
/// \{
#ifndef bstc_obj_pack_ctor
# define bstc_obj_pack_ctor(ctor) bstc_obj_set_ctor(bstc_obj_defaults, ctor)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the dtor function provided. */
/// \{
#ifndef bstc_obj_pack_dtor
# define bstc_obj_pack_dtor(dtor) bstc_obj_set_dtor(bstc_obj_defaults, dtor)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the cptor function provided. */
/// \{
#ifndef bstc_obj_pack_cptor
# define bstc_obj_pack_cptor(cptor) bstc_obj_set_cptor(bstc_obj_defaults, cptor)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the assign function provided. */
/// \{
#ifndef bstc_obj_pack_assign
# define bstc_obj_pack_assign(assign) bstc_obj_set_assign(bstc_obj_defaults, assign)
#endif
/// \}


/** Get the type that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_t
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_obj_t(t, ctor, dtor, cptor, assign) t
#  define bstc_obj_t(tpl) BSTC_EXPAND(bstc_dtl_obj_t tpl)
# endif
#endif
/// \}


/** Get the ctor function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_ctor
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_ctor(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
# else
#  define bstc_dtl_obj_ctor(t, ctor, dtor, cptor, assign) ctor
#  define bstc_obj_ctor(tpl) BSTC_EXPAND(bstc_dtl_obj_ctor tpl)
# endif
#endif
/// \}


/** Get the dtor function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_dtor
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_dtor(tpl) BSTC_EXPAND(BSTC_GET_ARG2 tpl)
# else
#  define bstc_dtl_obj_dtor(t, ctor, dtor, cptor, assign) dtor
#  define bstc_obj_dtor(tpl) BSTC_EXPAND(bstc_dtl_obj_dtor tpl)
# endif
#endif
/// \}


/** Get the cptor function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_cptor
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_cptor(tpl) BSTC_EXPAND(BSTC_GET_ARG3 tpl)
# else
#  define bstc_dtl_obj_cptor(t, ctor, dtor, cptor, assign) cptor
#  define bstc_obj_cptor(tpl) BSTC_EXPAND(bstc_dtl_obj_cptor tpl)
# endif
#endif
/// \}


/** Get the assign function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_assign
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_assign(tpl) BSTC_EXPAND(BSTC_GET_ARG4 tpl)
# else
#  define bstc_dtl_obj_assign(t, ctor, dtor, cptor, assign) assign
#  define bstc_obj_assign(tpl) BSTC_EXPAND(bstc_dtl_obj_assign tpl)
# endif
#endif
/// \}


/** Create a copy of the ctuple as an object with the type changed to what is provided. */
/// \{
#ifndef bstc_obj_set_t
# define bstc_dtl_obj_set_t(tpl, p) bstc_dtl_obj_set_t_expand(BSTC_LAYOUT5 tpl, p)
# define bstc_dtl_obj_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_t_expand1(L, p))
# define bstc_dtl_obj_set_t_expand1(t, ctor, dtor, cptor, assign, p) bstc_obj_traits(p, ctor, dtor, cptor, assign)
# define bstc_obj_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_obj_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as an object with the ctor function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_ctor
# define bstc_dtl_obj_set_ctor(tpl, p) bstc_dtl_obj_set_ctor_expand(BSTC_LAYOUT5 tpl, p)
# define bstc_dtl_obj_set_ctor_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_ctor_expand1(L, p))
# define bstc_dtl_obj_set_ctor_expand1(t, ctor, dtor, cptor, assign, p) bstc_obj_traits(t, p, dtor, cptor, assign)
# define bstc_obj_set_ctor(tpl, ctor) BSTC_EXPAND(bstc_dtl_obj_set_ctor(tpl, ctor))
#endif
/// \}


/** Create a copy of the ctuple as an object with the dtor function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_dtor
# define bstc_dtl_obj_set_dtor(tpl, p) bstc_dtl_obj_set_dtor_expand(BSTC_LAYOUT5 tpl, p)
# define bstc_dtl_obj_set_dtor_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_dtor_expand1(L, p))
# define bstc_dtl_obj_set_dtor_expand1(t, ctor, dtor, cptor, assign, p) bstc_obj_traits(t, ctor, p, cptor, assign)
# define bstc_obj_set_dtor(tpl, dtor) BSTC_EXPAND(bstc_dtl_obj_set_dtor(tpl, dtor))
#endif
/// \}


/** Create a copy of the ctuple as an object with the cptor function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_cptor
# define bstc_dtl_obj_set_cptor(tpl, p) bstc_dtl_obj_set_cptor_expand(BSTC_LAYOUT5 tpl, p)
# define bstc_dtl_obj_set_cptor_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_cptor_expand1(L, p))
# define bstc_dtl_obj_set_cptor_expand1(t, ctor, dtor, cptor, assign, p) bstc_obj_traits(t, ctor, dtor, p, assign)
# define bstc_obj_set_cptor(tpl, cptor) BSTC_EXPAND(bstc_dtl_obj_set_cptor(tpl, cptor))
#endif
/// \}


/** Create a copy of the ctuple as an object with the assign function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_assign
# define bstc_dtl_obj_set_assign(tpl, p) bstc_dtl_obj_set_assign_expand(BSTC_LAYOUT5 tpl, p)
# define bstc_dtl_obj_set_assign_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_assign_expand1(L, p))
# define bstc_dtl_obj_set_assign_expand1(t, ctor, dtor, cptor, assign, p) bstc_obj_traits(t, ctor, dtor, cptor, p)
# define bstc_obj_set_assign(tpl, assign) BSTC_EXPAND(bstc_dtl_obj_set_assign(tpl, assign))
#endif
/// \}


/** Default object ctuple that uses the no-op object functions. */
/// \{
#ifndef bstc_obj_defaults
# define bstc_obj_defaults bstc_obj_traits(bstc_obj_no_t, bstc_obj_noctor, bstc_obj_nodtor, bstc_obj_nocptor, bstc_obj_noassign)
#endif
/// \}


/** Default object type that is just int. */
/// \{
#ifndef bstc_obj_no_t
# define bstc_obj_no_t(traits, ptr) int
#endif
/// \}


/** Default ctor function that does nothing. */
/// \{
#ifndef bstc_obj_noctor
# define bstc_obj_noctor(traits, ptr) ((void)0)
#endif
/// \}


/** Default dtor function that does nothing. */
/// \{
#ifndef bstc_obj_nodtor
# define bstc_obj_nodtor(traits, ptr) ((void)0)
#endif
/// \}


/** Default cptor function that works for basic types. */
/// \{
#ifndef bstc_obj_nocptor
# define bstc_obj_nocptor(traits, ptr, other) *(ptr) = (other)
#endif
/// \}


/** Default assign function that works for basic types. */
/// \{
#ifndef bstc_obj_noassign
# define bstc_obj_noassign(traits, ptr, other) *(ptr) = (other)
#endif
/// \}


/** Detects if the ctuple provided could be a valid object ctuple. */
/// \{
#ifndef bstc_object_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 5, _t, _f), _f)
# endif
#endif
/// \}
