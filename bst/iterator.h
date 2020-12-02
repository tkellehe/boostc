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
#endif
/// \}


/* Pack arguments provided into a single ppack maintaining the standard order where defaults are no-ops */
/// \{
/* Packs assuming everything is provided in the std order */
#define bst_iter_ppack(hmmm, ...) bst_ppack(hmmm)
/// \}


/* Default do-nothing memory management functions */
/// \{
// These may need the ppack of the template type.
// #define bst_iter_no_t(...) int
// #define bst_iter_nobegin(...) (bst_null)
// #define bst_iter_noend(...) (bst_null)

// #define bst_iter_nonxt(iter) (++iter)
// #define bst_iter_noeq(left, right) (left == right)
// #define bst_iter_noneq(left, right) (left != right)
// #define bst_iter_noval(iter) (())
// #define bst_iter_noset(iter, val) (val)

// #define bst_vect_rbegin(vect) ((vect)+bst_vect_cnt(vect))
// #define bst_vect_rend(vect) ((vect)+1)

// #define bst_vect_riter_t(bst_vect_t) bst_vect_t
// #define bst_vect_riter_nxt(iter) (--iter)
// #define bst_vect_riter_eq(left, right) (left == right)
// #define bst_vect_riter_neq(left, right) (left != right)
// #define bst_vect_riter_val(iter) *((iter)-1)
// #define bst_vect_riter_set(iter, val) (*((iter)-1) = val)
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__ITERATOR_H
