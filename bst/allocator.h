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


#define bst_alloc_pack_fmr(f, m, r) ((f), (m), (r))
#define bst_alloc_pack_mfr(m, f, r) ((f), (m), (r))
#define bst_alloc_pack_mrf(m, r, f) ((f), (m), (r))
#define bst_alloc_pack_rmf(r, m, f) ((f), (m), (r))
#define bst_alloc_pack_rfm(r, f, m) ((f), (m), (r))
#define bst_alloc_pack_frm(f, r, m) ((f), (m), (r))

#define bst_alloc_pack_mr(m, r) ((bst_free), (m), (r))
#define bst_alloc_pack_fr(f, r) ((f), (bst_malloc), (r))
#define bst_alloc_pack_rf(r, f) ((f), (bst_malloc), (r))
#define bst_alloc_pack_mf(m, f) ((f), (m), (bst_realloc))
#define bst_alloc_pack_fm(f, m) ((f), (m), (bst_realloc))
#define bst_alloc_pack_rm(r, m) ((bst_free), (m), (r))

#define bst_alloc_pack_m(m) ((bst_free), (m), (bst_realloc))
#define bst_alloc_pack_f(f) ((f), (bst_malloc), (bst_realloc))
#define bst_alloc_pack_r(r) ((bst_free), (bst_malloc), (r))

#define bst_alloc_pack() ((bst_free), (bst_malloc), (bst_realloc))

// #define bst_dtl_alloc_unpack(f, m, r) f, m, r
// #define bst_alloc_unpack(alloc) BST_ESCP(alloc)


#ifdef __cplusplus
}
#endif


#endif // BST__ALLOCATOR_H
