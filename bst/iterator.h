#ifndef BST__ITERATOR_H
#define BST__ITERATOR_H


#include <bst/config.h>
#include <bst/ppack.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define iter_ppack_t bst_iter_ppack_t
#define iter_ppack_nxt bst_iter_ppack_nxt
#define iter_ppack_eq bst_iter_ppack_eq
#define iter_ppack_val bst_iter_ppack_val
#define iter_ppack_set bst_iter_ppack_set
#define iter_ppack_swap bst_iter_ppack_swap

#define iter_ppack bst_iter_ppack

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


/* Pack arguments provided into a single ppack maintaining the standard order where defaults are no-ops */
/// \{
#define bst_iter_ppack_t(t) bst_ppack(t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ppack_nxt(nxt) bst_ppack(bst_iter_no_t, nxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ppack_eq(eq) bst_ppack(bst_iter_no_t, bst_iter_nonxt, eq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ppack_val(val) bst_ppack(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, val, bst_iter_noset, bst_iter_noswap)
#define bst_iter_ppack_set(set) bst_ppack(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, set, bst_iter_noswap)
#define bst_iter_ppack_swap(swap) bst_ppack(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, swap)

/* Packs assuming everything is provided in the std order */
#define bst_iter_ppack(...) \
    bst_ppack_defaults(\
        bst_ppack(__VA_ARGS__),\
        bst_iter_defaults\
    )

#define bst_iter_t(pkd) bst_ppack_getI(pkd, 0)
#define bst_iter_nxt(pkd) bst_ppack_getI(pkd, 1)
#define bst_iter_eq(pkd) bst_ppack_getI(pkd, 2)
#define bst_iter_val(pkd) bst_ppack_getI(pkd, 3)
#define bst_iter_set(pkd) bst_ppack_getI(pkd, 4)
#define bst_iter_swap(pkd) bst_ppack_getI(pkd, 5)

#define bst_iter_set_t(pkd, t) bst_ppack_setI(pkd, 0, t)
#define bst_iter_set_nxt(pkd, nxt) bst_ppack_setI(pkd, 1, nxt)
#define bst_iter_set_eq(pkd, eq) bst_ppack_setI(pkd, 2, eq)
#define bst_iter_set_val(pkd, val) bst_ppack_setI(pkd, 3, val)
#define bst_iter_set_set(pkd, set) bst_ppack_setI(pkd, 4, set)
#define bst_iter_set_swap(pkd, swap) bst_ppack_setI(pkd, 5, swap)
/// \}


/* Packs the iterator defaults */
#define bst_iter_defaults bst_ppack(bst_iter_no_t, bst_iter_nonxt, bst_iter_noeq, bst_iter_noval, bst_iter_noset, bst_iter_noswap)


/* Default do-nothing iterator functions */
/// \{
#define bst_iter_no_t(...) int
#define bst_iter_nonxt(...) ((void)0)
#define bst_iter_noeq(...) 0
#define bst_iter_noval(...) ((void)0)
#define bst_iter_noset(...) ((void)0)
#define bst_iter_noswap(...) ((void)0)
/// \}


/* Detect if provided a ppack that could be an iterator */
#define bst_iter_isa(pkd, _t, _f) bst_ppack_isa(pkd, bst_ppack_hasN(pkd, 6, _t, _f), _f)


#ifdef __cplusplus
}
#endif


#endif // BST__ITERATOR_H
