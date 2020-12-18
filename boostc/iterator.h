//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>


/** Creates a ctuple with the defaults set except for the iterator type provided. */
/// \{
#ifndef bstc_iter_pack_t
# define bstc_iter_pack_t(t) bstc_iter_set_t(bstc_iter_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the nxt function provided. */
/// \{
#ifndef bstc_iter_pack_nxt
# define bstc_iter_pack_nxt(nxt) bstc_iter_set_nxt(bstc_iter_defaults, nxt)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the eq function provided. */
/// \{
#ifndef bstc_iter_pack_eq
# define bstc_iter_pack_eq(eq) bstc_iter_set_eq(bstc_iter_defaults, eq)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the val function provided. */
/// \{
#ifndef bstc_iter_pack_val
# define bstc_iter_pack_val(val) bstc_iter_set_val(bstc_iter_defaults, val)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the set function provided. */
/// \{
#ifndef bstc_iter_pack_set
# define bstc_iter_pack_set(set) bstc_iter_set_set(bstc_iter_defaults, set)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the swap function provided. */
/// \{
#ifndef bstc_iter_pack_swap
# define bstc_iter_pack_swap(swap) bstc_iter_set_swap(bstc_iter_defaults, swap)
#endif
/// \}


/** Get the iterator type that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_t
# define bstc_iter_t(tpl) bstc_ctuple_getI(tpl, 0)
#endif
/// \}


/** Get the nxt function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_nxt
# define bstc_iter_nxt(tpl) bstc_ctuple_getI(tpl, 1)
#endif
/// \}


/** Get the eq function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_eq
# define bstc_iter_eq(tpl) bstc_ctuple_getI(tpl, 2)
#endif
/// \}


/** Get the val function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_val
# define bstc_iter_val(tpl) bstc_ctuple_getI(tpl, 3)
#endif
/// \}


/** Get the set function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_set
# define bstc_iter_set(tpl) bstc_ctuple_getI(tpl, 4)
#endif
/// \}


/** Get the swap function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_swap
# define bstc_iter_swap(tpl) bstc_ctuple_getI(tpl, 5)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the iterator type changed to what is provided. */
/// \{
#ifndef bstc_iter_set_t
# define bstc_iter_set_t(tpl, t) bstc_ctuple_setI(tpl, 0, t)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the nxt function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_nxt
# define bstc_iter_set_nxt(tpl, nxt) bstc_ctuple_setI(tpl, 1, nxt)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the eq function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_eq
# define bstc_iter_set_eq(tpl, eq) bstc_ctuple_setI(tpl, 2, eq)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the val function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_val
# define bstc_iter_set_val(tpl, val) bstc_ctuple_setI(tpl, 3, val)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the set function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_set
# define bstc_iter_set_set(tpl, set) bstc_ctuple_setI(tpl, 4, set)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the swap function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_swap
# define bstc_iter_set_swap(tpl, swap) bstc_ctuple_setI(tpl, 5, swap)
#endif
/// \}


/** Default iterator type that is just int. */
/// \{
#ifndef bstc_iter_no_t
# define bstc_iter_no_t int
#endif
/// \}


/** Default nxt function that does nothing. */
/// \{
#ifndef bstc_iter_nonxt
# define bstc_iter_nonxt(iter) ((void)0)
#endif
/// \}


/** Default eq function that does nothing. */
/// \{
#ifndef bstc_iter_noeq
# define bstc_iter_noeq(left, right) 0
#endif
/// \}


/** Default val function that does nothing. */
/// \{
#ifndef bstc_iter_noval
# define bstc_iter_noval(iter) ((void)0)
#endif
/// \}


/** Default set function that does nothing. */
/// \{
#ifndef bstc_iter_noset
# define bstc_iter_noset(iter, val) ((void)0)
#endif
/// \}


/** Default swap function that does nothing. */
/// \{
#ifndef bstc_iter_noswap
# define bstc_iter_noswap(left, right) ((void)0)
#endif
/// \}


/** Default iterator ctuple that uses the no-op iterator functions. */
/// \{
#ifndef bstc_iter_defaults
# define bstc_iter_defaults bstc_ctuple(bstc_iter_no_t, bstc_iter_nonxt, bstc_iter_noeq, bstc_iter_noval, bstc_iter_noset, bstc_iter_noswap)
#endif
/// \}


/** Detects if the ctuple provided could be a valid iterator ctuple. */
/// \{
#ifndef bstc_iter_isa
# define bstc_iter_isa(tpl, _t, _f) BSTC_EXPAND(bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 6, _t, _f), _f))
#endif
/// \}
