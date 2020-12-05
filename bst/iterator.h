#ifndef BST__ITERATOR_H
#define BST__ITERATOR_H


#include <bst/config.h>
#include <bst/ctuple.h>


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define iter_ctuple_t bst_iter_ctuple_t
#define iter_ctuple_nxt bst_iter_ctuple_nxt
#define iter_ctuple_eq bst_iter_ctuple_eq
#define iter_ctuple_val bst_iter_ctuple_val
#define iter_ctuple_set bst_iter_ctuple_set
#define iter_ctuple_swap bst_iter_ctuple_swap

#define iter_ctuple bst_iter_ctuple

#define iter_t bst_iter_t
#define iter_nxt bst_iter_nxt
#define iter_eq bst_iter_eq
#define iter_val bst_iter_val
#define iter_set bst_iter_set
#define iter_swap bst_iter_swap

#define iter_set_t bst_iter_set_t
#define iter_set_nxt bst_iter_set_nxt
#define iter_set_eq bst_iter_set_eq
#define iter_set_val bst_iter_set_val
#define iter_set_set bst_iter_set_set
#define iter_set_swap bst_iter_set_swap

#define iter_defaults bst_iter_defaults
#define iter_no_t bst_iter_no_t
#define iter_nonxt bst_iter_nonxt
#define iter_noeq bst_iter_noeq
#define iter_noval bst_iter_noval
#define iter_noset bst_iter_noset
#define iter_noswap bst_iter_noswap

#define iter_isa bst_iter_isa
#endif
/// \}


/* Pack arguments provided into a single ctuple maintaining the standard order where defaults are no-ops */
/// \{
#define bst_iter_ctuple_t(t) bst_ctuple(t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ctuple_nxt(nxt) bst_ctuple(bst_iter_no_t, nxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ctuple_eq(eq) bst_ctuple(bst_iter_no_t, bst_iter_nonxt, eq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ctuple_val(val) bst_ctuple(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, val, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ctuple_set(set) bst_ctuple(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, set, bst_iter_noswap)
#define bst_iter_ctuple_swap(swap) bst_ctuple(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, swap)

/* Packs assuming everything is provided in the std order */
#define bst_iter_ctuple(...) \
    bst_ctuple_defaults(\
        bst_ctuple(__VA_ARGS__),\
        bst_iter_defaults\
    )

#define bst_iter_t(tpl) bst_ctuple_getI(tpl, 0)
#define bst_iter_nxt(tpl) bst_ctuple_getI(tpl, 1)
#define bst_iter_eq(tpl) bst_ctuple_getI(tpl, 2)
#define bst_iter_val(tpl) bst_ctuple_getI(tpl, 3)
#define bst_iter_set(tpl) bst_ctuple_getI(tpl, 4)
#define bst_iter_swap(tpl) bst_ctuple_getI(tpl, 5)

#define bst_iter_set_t(tpl, t) bst_ctuple_setI(tpl, 0, t)
#define bst_iter_set_nxt(tpl, nxt) bst_ctuple_setI(tpl, 1, nxt)
#define bst_iter_set_eq(tpl, eq) bst_ctuple_setI(tpl, 2, eq)
#define bst_iter_set_val(tpl, val) bst_ctuple_setI(tpl, 3, val)
#define bst_iter_set_set(tpl, set) bst_ctuple_setI(tpl, 4, set)
#define bst_iter_set_swap(tpl, swap) bst_ctuple_setI(tpl, 5, swap)
/// \}


/* Packs the iterator defaults */
#define bst_iter_defaults bst_ctuple(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)


/* Default do-nothing iterator functions */
/// \{
#define bst_iter_no_t(...) int
#define bst_iter_nonxt(...) ((void)0)
#define bst_iter_noeq(...) 0
#define bst_iter_noval(...) ((void)0)
#define bst_iter_noset(...) ((void)0)
#define bst_iter_noswap(...) ((void)0)
/// \}


/* Detect if provided a ctuple that could be an iterator */
#define bst_iter_isa(tpl, _t, _f) bst_ctuple_isa(tpl, bst_ctuple_hasN(tpl, 6, _t, _f), _f)


#endif // BST__ITERATOR_H
