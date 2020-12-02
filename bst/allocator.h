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
#define alloc_ppack_fmr bst_alloc_ppack_fmr
#define alloc_ppack_mfr bst_alloc_ppack_mfr
#define alloc_ppack_mrf bst_alloc_ppack_mrf
#define alloc_ppack_rmf bst_alloc_ppack_rmf
#define alloc_ppack_rfm bst_alloc_ppack_rfm
#define alloc_ppack_frm bst_alloc_ppack_frm

#define alloc_ppack_mr bst_alloc_ppack_mr
#define alloc_ppack_fr bst_alloc_ppack_fr
#define alloc_ppack_rf bst_alloc_ppack_rf
#define alloc_ppack_mf bst_alloc_ppack_mf
#define alloc_ppack_fm bst_alloc_ppack_fm
#define alloc_ppack_rm bst_alloc_ppack_rm

#define alloc_ppack_m bst_alloc_ppack_m
#define alloc_ppack_f bst_alloc_ppack_f
#define alloc_ppack_r bst_alloc_ppack_r

#define alloc_ppack bst_alloc_ppack

#define alloc_free bst_alloc_free
#define alloc_malloc bst_alloc_malloc
#define alloc_realloc bst_alloc_realloc

#define alloc_nofree bst_alloc_nofree
#define alloc_nomalloc bst_alloc_nomalloc
#define alloc_norealloc bst_alloc_norealloc

#define alloc_stdlib bst_alloc_stdlib
#define alloc_defaults bst_alloc_defaults
#endif
/// \}


/* Provide the stdlib calls with the namespace */
/// \{
#define bst_free free
#define bst_malloc malloc
#define bst_realloc realloc
/// \}


/* Pack arguments provided into a single ppack maintaining the standard order where defaults are no-ops */
/// \{
#define bst_alloc_ppack_fmr(f, m, r) bst_ppack(f, m, r)
#define bst_alloc_ppack_mfr(m, f, r) bst_ppack(f, m, r)
#define bst_alloc_ppack_mrf(m, r, f) bst_ppack(f, m, r)
#define bst_alloc_ppack_rmf(r, m, f) bst_ppack(f, m, r)
#define bst_alloc_ppack_rfm(r, f, m) bst_ppack(f, m, r)
#define bst_alloc_ppack_frm(f, r, m) bst_ppack(f, m, r)

#define bst_alloc_ppack_mr(m, r) bst_ppack(bst_alloc_nofree, m, r)
#define bst_alloc_ppack_fr(f, r) bst_ppack(f, bst_alloc_nomalloc, r)
#define bst_alloc_ppack_rf(r, f) bst_ppack(f, bst_alloc_nomalloc, r)
#define bst_alloc_ppack_mf(m, f) bst_ppack(f, m, bst_alloc_norealloc)
#define bst_alloc_ppack_fm(f, m) bst_ppack(f, m, bst_alloc_norealloc)
#define bst_alloc_ppack_rm(r, m) bst_ppack(bst_alloc_nofree, m, r)

#define bst_alloc_ppack_m(m) bst_ppack(bst_alloc_nofree, m, bst_alloc_norealloc)
#define bst_alloc_ppack_f(f) bst_ppack(f, bst_alloc_nomalloc, bst_realloc)
#define bst_alloc_ppack_r(r) bst_ppack(bst_alloc_nofree, bst_alloc_nomalloc, r)

/* Packs assuming everything is provided in the std order */
#define bst_alloc_ppack(...) \
    bst_ppack_defaults(\
        bst_ppack(__VA_ARGS__),\
        bst_alloc_defaults\
    )

#define bst_alloc_free(pkd) bst_ppack_argI(pkd, 0)
#define bst_alloc_malloc(pkd) bst_ppack_argI(pkd, 1)
#define bst_alloc_realloc(pkd) bst_ppack_argI(pkd, 2)
/// \}


/* Packs the stdlib calls */
#define bst_alloc_stdlib bst_ppack(bst_free, bst_malloc, bst_realloc)


/* Packs the default do-nothings */
#define bst_alloc_defaults bst_ppack(bst_alloc_nofree, bst_alloc_nomalloc, bst_alloc_norealloc)


/* Default do-nothing memory management functions */
/// \{
#define bst_alloc_nofree(...) ((void)0)
#define bst_alloc_nomalloc(...) ((void*)bst_null)
#define bst_alloc_norealloc(...) ((void*)bst_null)
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__ALLOCATOR_H
