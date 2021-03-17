//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_iter_traits
# define bstc_iter_traits(t, nxt, eq, val, put, swap) (t, nxt, eq, val, put, swap)
#endif
/// \}


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
#ifndef bstc_iter_pack_put
# define bstc_iter_pack_put(put) bstc_iter_set_put(bstc_iter_defaults, put)
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
# define bstc_dtl_iter_t(t, nxt, eq, val, put, swap) t
# define bstc_iter_t(tpl) BSTC_EXPAND(bstc_dtl_iter_t tpl)
#endif
/// \}


/** Get the nxt function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_nxt
# define bstc_dtl_iter_nxt(t, nxt, eq, val, put, swap) nxt
# define bstc_iter_nxt(tpl) BSTC_EXPAND(bstc_dtl_iter_nxt tpl)
#endif
/// \}


/** Get the eq function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_eq
# define bstc_dtl_iter_eq(t, nxt, eq, val, put, swap) eq
# define bstc_iter_eq(tpl) BSTC_EXPAND(bstc_dtl_iter_eq tpl)
#endif
/// \}


/** Get the val function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_val
# define bstc_dtl_iter_val(t, nxt, eq, val, put, swap) val
# define bstc_iter_val(tpl) BSTC_EXPAND(bstc_dtl_iter_val tpl)
#endif
/// \}


/** Get the set function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_put
# define bstc_dtl_iter_put(t, nxt, eq, val, put, swap) put
# define bstc_iter_put(tpl) BSTC_EXPAND(bstc_dtl_iter_put tpl)
#endif
/// \}


/** Get the swap function that has been packed into the ctuple. */
/// \{
#ifndef bstc_iter_swap
# define bstc_dtl_iter_swap(t, nxt, eq, val, put, swap) swap
# define bstc_iter_swap(tpl) BSTC_EXPAND(bstc_dtl_iter_swap tpl)
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the iterator type changed to what is provided. */
/// \{
#ifndef bstc_iter_set_t
# define bstc_dtl_iter_set_t(tpl, p) bstc_dtl_iter_set_t_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_t_expand1(L, p))
# define bstc_dtl_iter_set_t_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(p, nxt, eq, val, put, swap)
# define bstc_iter_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_iter_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the nxt function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_nxt
# define bstc_dtl_iter_set_nxt(tpl, p) bstc_dtl_iter_set_nxt_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_nxt_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_nxt_expand1(L, p))
# define bstc_dtl_iter_set_nxt_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(t, p, eq, val, put, swap)
# define bstc_iter_set_nxt(tpl, nxt) BSTC_EXPAND(bstc_dtl_iter_set_nxt(tpl, nxt))
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the eq function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_eq
# define bstc_dtl_iter_set_eq(tpl, p) bstc_dtl_iter_set_eq_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_eq_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_eq_expand1(L, p))
# define bstc_dtl_iter_set_eq_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(t, nxt, p, val, put, swap)
# define bstc_iter_set_eq(tpl, eq) BSTC_EXPAND(bstc_dtl_iter_set_eq(tpl, eq))
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the val function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_val
# define bstc_dtl_iter_set_val(tpl, p) bstc_dtl_iter_set_val_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_val_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_val_expand1(L, p))
# define bstc_dtl_iter_set_val_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(t, nxt, eq, p, put, swap)
# define bstc_iter_set_val(tpl, val) BSTC_EXPAND(bstc_dtl_iter_set_val(tpl, val))
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the set function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_put
# define bstc_dtl_iter_set_put(tpl, p) bstc_dtl_iter_set_put_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_put_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_put_expand1(L, p))
# define bstc_dtl_iter_set_put_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(t, nxt, eq, val, p, swap)
# define bstc_iter_set_put(tpl, put) BSTC_EXPAND(bstc_dtl_iter_set_put(tpl, put))
#endif
/// \}


/** Create a copy of the ctuple as an iterator with the swap function changed to what is provided. */
/// \{
#ifndef bstc_iter_set_swap
# define bstc_dtl_iter_set_swap(tpl, p) bstc_dtl_iter_set_swap_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_iter_set_swap_expand(L, p) BSTC_EXPAND(bstc_dtl_iter_set_swap_expand1(L, p))
# define bstc_dtl_iter_set_swap_expand1(t, nxt, eq, val, put, swap, p) bstc_iter_traits(t, nxt, eq, val, put, p)
# define bstc_iter_set_swap(tpl, swap) BSTC_EXPAND(bstc_dtl_iter_set_swap(tpl, swap))
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
#ifndef bstc_iter_noput
# define bstc_iter_noput(iter, val) ((void)0)
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
# define bstc_iter_defaults bstc_iter_traits(bstc_iter_no_t, bstc_iter_nonxt, bstc_iter_noeq, bstc_iter_noval, bstc_iter_noput, bstc_iter_noswap)
#endif
/// \}


/** Detects if the ctuple provided could be a valid iterator ctuple. */
/// \{
#ifndef bstc_iter_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_iter_isa(tpl, _t, _f) BSTC_EXPAND(bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 6, _t, _f), _f))
# endif
#endif
/// \}


/** Uses the BSTC iterator interface to apply a foreach based off of a perdicate.
 * \param iters The iterator ctuple to extract the iterator interface from.
 * \param iter A reference to the iterator to apply the functions to and will be updated with the location.
 * \param end A reference to the iterator representing the end of the linear search.
 */
/// \{
#ifndef bstc_iter_foreach
# define bstc_iter_foreach(iters, iter, end) \
    for(; !(bstc_iter_eq(iters)(iter, end)); bstc_iter_nxt(iters)(iter))
#endif
/// \}
