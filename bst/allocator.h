#ifndef BST__ALLOCATOR_H
#define BST__ALLOCATOR_H


#include <bst/config.h>


#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#endif
/// \}


#define bst_free free
#define bst_malloc malloc
#define bst_realloc realloc


#define bst_alloc_pack_fmr(f, m, r) BST_PPACK((f), (m), (r))
#define bst_alloc_pack_mfr(m, f, r) BST_PPACK((f), (m), (r))
#define bst_alloc_pack_mrf(m, r, f) BST_PPACK((f), (m), (r))
#define bst_alloc_pack_rmf(r, m, f) BST_PPACK((f), (m), (r))
#define bst_alloc_pack_rfm(r, f, m) BST_PPACK((f), (m), (r))
#define bst_alloc_pack_frm(f, r, m) BST_PPACK((f), (m), (r))

#define bst_alloc_pack_mr(m, r) BST_PPACK((bst_free), (m), (r))
#define bst_alloc_pack_fr(f, r) BST_PPACK((f), (bst_malloc), (r))
#define bst_alloc_pack_rf(r, f) BST_PPACK((f), (bst_malloc), (r))
#define bst_alloc_pack_mf(m, f) BST_PPACK((f), (m), (bst_realloc))
#define bst_alloc_pack_fm(f, m) BST_PPACK((f), (m), (bst_realloc))
#define bst_alloc_pack_rm(r, m) BST_PPACK((bst_free), (m), (r))

#define bst_alloc_pack_m(m) BST_PPACK((bst_free), (m), (bst_realloc))
#define bst_alloc_pack_f(f) BST_PPACK((f), (bst_malloc), (bst_realloc))
#define bst_alloc_pack_r(r) BST_PPACK((bst_free), (bst_malloc), (r))

#define bst_alloc_pack() BST_PPACK((bst_free), (bst_malloc), (bst_realloc))

#define bst_alloc_unpack(alloc) BST_PUNPACK alloc


#ifdef __cplusplus
}
#endif


#endif // BST__ALLOCATOR_H
