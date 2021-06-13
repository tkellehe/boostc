//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_macro_traits
# define bstc_macro_traits(id, macro) (id, macro)
#endif
/// \}


/** Creates a ctuple with the default macro id. */
/// \{
#ifndef bstc_macro_pack
# define bstc_macro_pack(macro) (0, macro)
#endif
/// \}


/** Get the id that has been packed into the ctuple. */
/// \{
#ifndef bstc_macro_id
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_macro_id(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
# else
#  define bstc_dtl_macro_id(id, macro) id
#  define bstc_macro_id(tpl) BSTC_EXPAND(bstc_dtl_macro_id tpl)
# endif
#endif
/// \}


/** Get the macro that has been packed into the ctuple. */
/// \{
#ifndef bstc_macro
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_macro(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
# else
#  define bstc_dtl_macro(id, macro) macro
#  define bstc_macro(tpl) BSTC_EXPAND(bstc_dtl_macro_id tpl)
# endif
#endif
/// \}


/** Create a copy of the ctuple as a macro with the id changed to what is provided. */
/// \{
#ifndef bstc_macro_set_id
# define bstc_dtl_macro_set_id(tpl, p) bstc_dtl_macro_set_id_expand(BSTC_LAYOUT2 tpl, p)
# define bstc_dtl_macro_set_id_expand(L, p) BSTC_EXPAND(bstc_dtl_macro_set_id_expand1(L, p))
# define bstc_dtl_macro_set_id_expand1(id, macro, p) bstc_macro_traits(p, macro)
# define bstc_macro_set_id(tpl, id) BSTC_EXPAND(bstc_dtl_macro_set_id(tpl, id))
#endif
/// \}


/** Create a copy of the ctuple as a macro with the macro changed to what is provided. */
/// \{
#ifndef bstc_macro_set
# define bstc_dtl_macro_set(tpl, p) bstc_dtl_macro_set_expand(BSTC_LAYOUT2 tpl, p)
# define bstc_dtl_macro_set_expand(L, p) BSTC_EXPAND(bstc_dtl_macro_set_expand1(L, p))
# define bstc_dtl_macro_set_expand1(id, macro, p) bstc_macro_traits(id, p)
# define bstc_macro_set(tpl, macro) BSTC_EXPAND(bstc_dtl_macro_set(tpl, macro))
#endif
/// \}


/** Default macro ctuple that uses the no-op macros. */
/// \{
#ifndef bstc_macro_defaults
# define bstc_macro_defaults bstc_macro_traits(0, bstc_macro_no)
#endif
/// \}


/** Default do-nothing macro function that takes in just the id. */
/// \{
#ifndef bstc_macro_no
# define bstc_macro_no(id) ((void)0)
#endif
/// \}


/** Takes a macro ctuple and moves the id to the next value. */
/// \{
#ifndef bstc_macro_next
# define bstc_macro_next(macro) bstc_macro_traits(BSTC_CONST_ADD1(bstc_macro_id(macro)), bstc_macro(macro))
#endif
/// \}


/** Detects if the ctuple provided could be a valid macro ctuple. */
/// \{
#ifndef bstc_macro_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_macro_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 2, _t, _f), _f)
# endif
#endif
/// \}
