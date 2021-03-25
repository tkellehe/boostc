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
# define bstc_obj_traits(t, init, destroy, clone, copy, move, assign, extend) (t, init, destroy, clone, copy, move, assign, extend)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the type provided. */
/// \{
#ifndef bstc_obj_pack_t
# define bstc_obj_pack_t(t) bstc_obj_set_t(bstc_obj_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the init function provided. */
/// \{
#ifndef bstc_obj_pack_init
# define bstc_obj_pack_init(init) bstc_obj_set_init(bstc_obj_defaults, init)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the destroy function provided. */
/// \{
#ifndef bstc_obj_pack_destroy
# define bstc_obj_pack_destroy(destroy) bstc_obj_set_destroy(bstc_obj_defaults, destroy)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the clone function provided. */
/// \{
#ifndef bstc_obj_pack_clone
# define bstc_obj_pack_clone(clone) bstc_obj_set_clone(bstc_obj_defaults, clone)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the copy function provided. */
/// \{
#ifndef bstc_obj_pack_copy
# define bstc_obj_pack_copy(copy) bstc_obj_set_copy(bstc_obj_defaults, copy)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the move function provided. */
/// \{
#ifndef bstc_obj_pack_move
# define bstc_obj_pack_move(move) bstc_obj_set_move(bstc_obj_defaults, move)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the assign function provided. */
/// \{
#ifndef bstc_obj_pack_assign
# define bstc_obj_pack_assign(assign) bstc_obj_set_assign(bstc_obj_defaults, assign)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the extend ctuple provided. */
/// \{
#ifndef bstc_obj_pack_extend
# define bstc_obj_pack_extend(extend) bstc_obj_set_extend(bstc_obj_defaults, extend)
#endif
/// \}


/** Get the type that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_t
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_obj_t(t, init, destroy, clone, copy, move, assign, extend) t
#  define bstc_obj_t(tpl) BSTC_EXPAND(bstc_dtl_obj_t tpl)
# endif
#endif
/// \}


/** Get the init function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_init
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_init(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
# else
#  define bstc_dtl_obj_init(t, init, destroy, clone, copy, move, assign, extend) init
#  define bstc_obj_init(tpl) BSTC_EXPAND(bstc_dtl_obj_init tpl)
# endif
#endif
/// \}


/** Get the destroy function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_destroy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_destroy(tpl) BSTC_EXPAND(BSTC_GET_ARG2 tpl)
# else
#  define bstc_dtl_obj_destroy(t, init, destroy, clone, copy, move, assign, extend) destroy
#  define bstc_obj_destroy(tpl) BSTC_EXPAND(bstc_dtl_obj_destroy tpl)
# endif
#endif
/// \}


/** Get the clone function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_clone
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_clone(tpl) BSTC_EXPAND(BSTC_GET_ARG3 tpl)
# else
#  define bstc_dtl_obj_clone(t, init, destroy, clone, copy, move, assign, extend) clone
#  define bstc_obj_clone(tpl) BSTC_EXPAND(bstc_dtl_obj_clone tpl)
# endif
#endif
/// \}


/** Get the copy function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_copy
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_copy(tpl) BSTC_EXPAND(BSTC_GET_ARG4 tpl)
# else
#  define bstc_dtl_obj_copy(t, init, destroy, clone, copy, move, assign, extend) copy
#  define bstc_obj_copy(tpl) BSTC_EXPAND(bstc_dtl_obj_copy tpl)
# endif
#endif
/// \}


/** Get the move function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_move
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_move(tpl) BSTC_EXPAND(BSTC_GET_ARG5 tpl)
# else
#  define bstc_dtl_obj_move(t, init, destroy, clone, copy, move, assign, extend) move
#  define bstc_obj_move(tpl) BSTC_EXPAND(bstc_dtl_obj_move tpl)
# endif
#endif
/// \}


/** Get the assign function that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_assign
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_assign(tpl) BSTC_EXPAND(BSTC_GET_ARG6 tpl)
# else
#  define bstc_dtl_obj_assign(t, init, destroy, clone, copy, move, assign, extend) assign
#  define bstc_obj_assign(tpl) BSTC_EXPAND(bstc_dtl_obj_assign tpl)
# endif
#endif
/// \}


/** Get the extend ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_obj_extend
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_extend(tpl) BSTC_EXPAND(BSTC_GET_ARG7 tpl)
# else
#  define bstc_dtl_obj_extend(t, init, destroy, clone, copy, move, assign, extend) extend
#  define bstc_obj_extend(tpl) BSTC_EXPAND(bstc_dtl_obj_extend tpl)
# endif
#endif
/// \}


/** Create a copy of the ctuple as an object with the type changed to what is provided. */
/// \{
#ifndef bstc_obj_set_t
# define bstc_dtl_obj_set_t(tpl, p) bstc_dtl_obj_set_t_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_t_expand1(L, p))
# define bstc_dtl_obj_set_t_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(p, init, destroy, clone, copy, move, assign, extend)
# define bstc_obj_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_obj_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as an object with the init function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_init
# define bstc_dtl_obj_set_init(tpl, p) bstc_dtl_obj_set_init_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_init_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_init_expand1(L, p))
# define bstc_dtl_obj_set_init_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, p, destroy, clone, copy, move, assign, extend)
# define bstc_obj_set_init(tpl, init) BSTC_EXPAND(bstc_dtl_obj_set_init(tpl, init))
#endif
/// \}


/** Create a copy of the ctuple as an object with the destroy function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_destroy
# define bstc_dtl_obj_set_destroy(tpl, p) bstc_dtl_obj_set_destroy_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_destroy_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_destroy_expand1(L, p))
# define bstc_dtl_obj_set_destroy_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, p, clone, copy, move, assign, extend)
# define bstc_obj_set_destroy(tpl, destroy) BSTC_EXPAND(bstc_dtl_obj_set_destroy(tpl, destroy))
#endif
/// \}


/** Create a copy of the ctuple as an object with the clone function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_clone
# define bstc_dtl_obj_set_clone(tpl, p) bstc_dtl_obj_set_clone_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_clone_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_clone_expand1(L, p))
# define bstc_dtl_obj_set_clone_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, destroy, p, copy, move, assign, extend)
# define bstc_obj_set_clone(tpl, clone) BSTC_EXPAND(bstc_dtl_obj_set_clone(tpl, clone))
#endif
/// \}


/** Create a copy of the ctuple as an object with the copy function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_copy
# define bstc_dtl_obj_set_copy(tpl, p) bstc_dtl_obj_set_copy_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_copy_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_copy_expand1(L, p))
# define bstc_dtl_obj_set_copy_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, destroy, clone, p, move, assign, extend)
# define bstc_obj_set_copy(tpl, copy) BSTC_EXPAND(bstc_dtl_obj_set_copy(tpl, copy))
#endif
/// \}


/** Create a copy of the ctuple as an object with the move function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_move
# define bstc_dtl_obj_set_move(tpl, p) bstc_dtl_obj_set_move_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_move_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_move_expand1(L, p))
# define bstc_dtl_obj_set_move_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, destroy, clone, copy, p, assign, extend)
# define bstc_obj_set_move(tpl, move) BSTC_EXPAND(bstc_dtl_obj_set_move(tpl, move))
#endif
/// \}


/** Create a copy of the ctuple as an object with the assign function changed to what is provided. */
/// \{
#ifndef bstc_obj_set_assign
# define bstc_dtl_obj_set_assign(tpl, p) bstc_dtl_obj_set_assign_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_assign_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_assign_expand1(L, p))
# define bstc_dtl_obj_set_assign_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, destroy, clone, copy, move, p, extend)
# define bstc_obj_set_assign(tpl, assign) BSTC_EXPAND(bstc_dtl_obj_set_assign(tpl, assign))
#endif
/// \}


/** Create a copy of the ctuple as an object with the extend ctuple changed to what is provided. */
/// \{
#ifndef bstc_obj_set_extend
# define bstc_dtl_obj_set_extend(tpl, p) bstc_dtl_obj_set_extend_expand(BSTC_LAYOUT8 tpl, p)
# define bstc_dtl_obj_set_extend_expand(L, p) BSTC_EXPAND(bstc_dtl_obj_set_extend_expand1(L, p))
# define bstc_dtl_obj_set_extend_expand1(t, init, destroy, clone, copy, move, assign, extend, p) bstc_obj_traits(t, init, destroy, clone, copy, move, assign, p)
# define bstc_obj_set_extend(tpl, extend) BSTC_EXPAND(bstc_dtl_obj_set_extend(tpl, extend))
#endif
/// \}


/** Default object ctuple that uses the no-op object functions. */
/// \{
#ifndef bstc_obj_defaults
# define bstc_obj_defaults bstc_obj_traits(bstc_obj_no_t, bstc_obj_noinit, bstc_obj_nodestroy, bstc_obj_noclone, bstc_obj_nocopy, bstc_obj_nomove, bstc_obj_noassign, bstc_obj_noextend)
#endif
/// \}


/** Default object type that is just int. */
/// \{
#ifndef bstc_obj_no_t
# define bstc_obj_no_t int
#endif
/// \}


/** Default init function that does nothing. */
/// \{
#ifndef bstc_obj_noinit
# define bstc_obj_noinit(traits, ptr) ((void)0)
#endif
/// \}


/** Default destroy function that does nothing. */
/// \{
#ifndef bstc_obj_nodestroy
# define bstc_obj_nodestroy(traits, ptr) ((void)0)
#endif
/// \}


/** Default clone function that works for basic types. */
/// \{
#ifndef bstc_obj_noclone
# define bstc_obj_noclone(traits, ptr, other) *(ptr) = *(other)
#endif
/// \}


/** Default copy function that works for basic types. */
/// \{
#ifndef bstc_obj_nocopy
# define bstc_obj_nocopy(traits, ptr, other) *(ptr) = *(other)
#endif
/// \}


/** Default move function that works for basic types. */
/// \{
#ifndef bstc_obj_nomove
# define bstc_obj_nomove(traits, ptr, other) *(ptr) = (other)
#endif
/// \}


/** Default assign function that works for basic types. */
/// \{
#ifndef bstc_obj_noassign
# define bstc_obj_noassign(traits, ptr, other) *(ptr) = (other)
#endif
/// \}


/** Default extend attributes that holds nothing. */
/// \{
#ifndef bstc_obj_noextend
# define bstc_obj_noextend BSTC_CTUPLE1(0)
#endif
/// \}


/** Detects if the ctuple provided could be a valid object ctuple. */
/// \{
#ifndef bstc_object_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_obj_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 8, _t, _f), _f)
# endif
#endif
/// \}
