#ifndef BST__ALLOCATOR_H
#define BST__ALLOCATOR_H


#include <bst/config.h>
#include <bst/ppack.h>


#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define alloc_pack_fmr bst_alloc_pack_fmr
#define alloc_pack_mfr bst_alloc_pack_mfr
#define alloc_pack_mrf bst_alloc_pack_mrf
#define alloc_pack_rmf bst_alloc_pack_rmf
#define alloc_pack_rfm bst_alloc_pack_rfm
#define alloc_pack_frm bst_alloc_pack_frm

#define alloc_pack_mr bst_alloc_pack_mr
#define alloc_pack_fr bst_alloc_pack_fr
#define alloc_pack_rf bst_alloc_pack_rf
#define alloc_pack_mf bst_alloc_pack_mf
#define alloc_pack_fm bst_alloc_pack_fm
#define alloc_pack_rm bst_alloc_pack_rm

#define alloc_pack_m bst_alloc_pack_m
#define alloc_pack_f bst_alloc_pack_f
#define alloc_pack_r bst_alloc_pack_r

#define alloc_pack bst_alloc_pack

#define alloc_unpack bst_alloc_unpack

#define alloc_nofree bst_alloc_nofree
#define alloc_nomalloc bst_alloc_nomalloc
#define alloc_norealloc bst_alloc_norealloc
#endif
/// \}


/* Provide the stdlib calls with the namespace */
/// \{
#define bst_free free
#define bst_malloc malloc
#define bst_realloc realloc
/// \}


/* Pack arguments provided into a single ppack maintaining the standard order where defaults are stdlib */
/// \{
#define bst_alloc_pack_fmr(f, m, r) bst_ppack((f), (m), (r))
#define bst_alloc_pack_mfr(m, f, r) bst_ppack((f), (m), (r))
#define bst_alloc_pack_mrf(m, r, f) bst_ppack((f), (m), (r))
#define bst_alloc_pack_rmf(r, m, f) bst_ppack((f), (m), (r))
#define bst_alloc_pack_rfm(r, f, m) bst_ppack((f), (m), (r))
#define bst_alloc_pack_frm(f, r, m) bst_ppack((f), (m), (r))

#define bst_alloc_pack_mr(m, r) bst_ppack((bst_free), (m), (r))
#define bst_alloc_pack_fr(f, r) bst_ppack((f), (bst_malloc), (r))
#define bst_alloc_pack_rf(r, f) bst_ppack((f), (bst_malloc), (r))
#define bst_alloc_pack_mf(m, f) bst_ppack((f), (m), (bst_realloc))
#define bst_alloc_pack_fm(f, m) bst_ppack((f), (m), (bst_realloc))
#define bst_alloc_pack_rm(r, m) bst_ppack((bst_free), (m), (r))

#define bst_alloc_pack_m(m) bst_ppack((bst_free), (m), (bst_realloc))
#define bst_alloc_pack_f(f) bst_ppack((f), (bst_malloc), (bst_realloc))
#define bst_alloc_pack_r(r) bst_ppack((bst_free), (bst_malloc), (r))
/// \}


/** Packs the stdlib calls
 * \return Returns a ppack of the stdlib calls.
 */
#define bst_alloc_pack() bst_ppack((bst_free), (bst_malloc), (bst_realloc))


/* Default do-nothing memory management functions */
/// \{
#define bst_alloc_nofree(...) ((void)0)
#define bst_alloc_nomalloc(...) 0
#define bst_alloc_norealloc(...) 0
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__ALLOCATOR_H
