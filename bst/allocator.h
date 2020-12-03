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
#define alloc_ppack_free bst_alloc_ppack_free
#define alloc_ppack_malloc bst_alloc_ppack_malloc
#define alloc_ppack_realloc bst_alloc_ppack_realloc

#define alloc_ppack bst_alloc_ppack

#define alloc_free bst_alloc_free
#define alloc_malloc bst_alloc_malloc
#define alloc_realloc bst_alloc_realloc

#define alloc_stdlib bst_alloc_stdlib
#define alloc_defaults bst_alloc_defaults

#define alloc_nofree bst_alloc_nofree
#define alloc_nomalloc bst_alloc_nomalloc
#define alloc_norealloc bst_alloc_norealloc

#define alloc_isa bst_alloc_isa
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
#define bst_alloc_ppack_free(f) bst_ppack(f, bst_alloc_nomalloc, bst_realloc)
#define bst_alloc_ppack_malloc(m) bst_ppack(bst_alloc_nofree, m, bst_alloc_norealloc)
#define bst_alloc_ppack_realloc(r) bst_ppack(bst_alloc_nofree, bst_alloc_nomalloc, r)

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


/* Detect if provided a ppack that could be an allocator */
#define bst_alloc_isa(pkd, _t, _f) bst_ppack_isa(pkd, bst_ppack_hasN(pkd, 3, _t, _f), _f)


#ifdef __cplusplus
}
#endif


#endif // BST__ALLOCATOR_H
