#ifndef BSTC__ITERATOR_H
#define BSTC__ITERATOR_H


#include <bstc/config.h>
#include <bstc/ctuple.h>


/* Provide without namespace */
/// \{
#ifdef BSTC_NO_NAMESPACE
#define iter_ctuple_t bstc_iter_ctuple_t
#define iter_ctuple_nxt bstc_iter_ctuple_nxt
#define iter_ctuple_eq bstc_iter_ctuple_eq
#define iter_ctuple_val bstc_iter_ctuple_val
#define iter_ctuple_set bstc_iter_ctuple_set
#define iter_ctuple_swap bstc_iter_ctuple_swap

#define iter_t bstc_iter_t
#define iter_nxt bstc_iter_nxt
#define iter_eq bstc_iter_eq
#define iter_val bstc_iter_val
#define iter_set bstc_iter_set
#define iter_swap bstc_iter_swap

#define iter_set_t bstc_iter_set_t
#define iter_set_nxt bstc_iter_set_nxt
#define iter_set_eq bstc_iter_set_eq
#define iter_set_val bstc_iter_set_val
#define iter_set_set bstc_iter_set_set
#define iter_set_swap bstc_iter_set_swap

#define iter_defaults bstc_iter_defaults
#define iter_no_t bstc_iter_no_t
#define iter_nonxt bstc_iter_nonxt
#define iter_noeq bstc_iter_noeq
#define iter_noval bstc_iter_noval
#define iter_noset bstc_iter_noset
#define iter_noswap bstc_iter_noswap

#define iter_isa bstc_iter_isa
#endif
/// \}


/* Pack arguments provided into a single ctuple maintaining the standard order where defaults are no-ops */
/// \{
#define bstc_iter_ctuple_t(t) bstc_iter_set_t(bstc_iter_defaults, t)
#define bstc_iter_ctuple_nxt(nxt) bstc_iter_set_nxt(bstc_iter_defaults, nxt)
#define bstc_iter_ctuple_eq(eq) bstc_iter_set_eq(bstc_iter_defaults, eq)
#define bstc_iter_ctuple_val(val) bstc_iter_set_val(bstc_iter_defaults, val)
#define bstc_iter_ctuple_set(set) bstc_iter_set_set(bstc_iter_defaults, set)
#define bstc_iter_ctuple_swap(swap) bstc_iter_set_swap(bstc_iter_defaults, swap)

#define bstc_iter_t(tpl) bstc_ctuple_getI(tpl, 0)
#define bstc_iter_nxt(tpl) bstc_ctuple_getI(tpl, 1)
#define bstc_iter_eq(tpl) bstc_ctuple_getI(tpl, 2)
#define bstc_iter_val(tpl) bstc_ctuple_getI(tpl, 3)
#define bstc_iter_set(tpl) bstc_ctuple_getI(tpl, 4)
#define bstc_iter_swap(tpl) bstc_ctuple_getI(tpl, 5)

#define bstc_iter_set_t(tpl, t) bstc_ctuple_setI(tpl, 0, t)
#define bstc_iter_set_nxt(tpl, nxt) bstc_ctuple_setI(tpl, 1, nxt)
#define bstc_iter_set_eq(tpl, eq) bstc_ctuple_setI(tpl, 2, eq)
#define bstc_iter_set_val(tpl, val) bstc_ctuple_setI(tpl, 3, val)
#define bstc_iter_set_set(tpl, set) bstc_ctuple_setI(tpl, 4, set)
#define bstc_iter_set_swap(tpl, swap) bstc_ctuple_setI(tpl, 5, swap)
/// \}


/* Packs the iterator defaults */
#define bstc_iter_defaults bstc_ctuple(bstc_iter_no_t, bstc_iter_nonxt, bstc_iter_noeq, bstc_iter_noval, bstc_iter_noset, bstc_iter_noswap)


/* Default do-nothing iterator functions */
/// \{
#define bstc_iter_no_t(...) int
#define bstc_iter_nonxt(...) ((void)0)
#define bstc_iter_noeq(...) 0
#define bstc_iter_noval(...) ((void)0)
#define bstc_iter_noset(...) ((void)0)
#define bstc_iter_noswap(...) ((void)0)
/// \}


/* Detect if provided a ctuple that could be an iterator */
#define bstc_iter_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 6, _t, _f), _f)


#endif // BSTC__ITERATOR_H
