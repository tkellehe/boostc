#ifndef BST__ALLOCATOR_H
#define BST__ALLOCATOR_H


#include <bst/config.h>
#include <bst/ctuple.h>


#include <stdlib.h>


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define alloc_ctuple_free bst_alloc_ctuple_free
#define alloc_ctuple_malloc bst_alloc_ctuple_malloc
#define alloc_ctuple_realloc bst_alloc_ctuple_realloc

#define alloc_ctuple bst_alloc_ctuple

#define alloc_free bst_alloc_free
#define alloc_malloc bst_alloc_malloc
#define alloc_realloc bst_alloc_realloc

#define alloc_set_free bst_alloc_set_free
#define alloc_set_malloc bst_alloc_set_malloc
#define alloc_set_realloc bst_alloc_set_realloc

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


/* Pack arguments provided into a single ctuple maintaining the standard order where defaults are no-ops */
/// \{
#define bst_alloc_ctuple_free(f) bst_alloc_set_free(bst_alloc_defaults, free)
#define bst_alloc_ctuple_malloc(m) bst_alloc_set_malloc(bst_alloc_defaults, malloc)
#define bst_alloc_ctuple_realloc(r) bst_alloc_set_realloc(bst_alloc_defaults, realloc)

/* Packs assuming everything is provided in the std order */
#define bst_alloc_ctuple(...) \
    bst_ctuple_defaults(\
        bst_ctuple(__VA_ARGS__),\
        bst_alloc_defaults\
    )

#define bst_alloc_free(tpl) bst_ctuple_getI(tpl, 0)
#define bst_alloc_malloc(tpl) bst_ctuple_getI(tpl, 1)
#define bst_alloc_realloc(tpl) bst_ctuple_getI(tpl, 2)

#define bst_alloc_set_free(tpl, free) bst_ctuple_setI(tpl, 0, free)
#define bst_alloc_set_malloc(tpl, malloc) bst_ctuple_setI(tpl, 1, malloc)
#define bst_alloc_set_realloc(tpl, realloc) bst_ctuple_setI(tpl, 2, realloc)
/// \}


/* Packs the stdlib calls */
#define bst_alloc_stdlib bst_ctuple(bst_free, bst_malloc, bst_realloc)


/* Packs the default do-nothings */
#define bst_alloc_defaults bst_ctuple(bst_alloc_nofree, bst_alloc_nomalloc, bst_alloc_norealloc)


/* Default do-nothing memory management functions */
/// \{
#define bst_alloc_nofree(...) ((void)0)
#define bst_alloc_nomalloc(...) ((void*)bst_null)
#define bst_alloc_norealloc(...) ((void*)bst_null)
/// \}


/* Detect if provided a ctuple that could be an allocator */
#define bst_alloc_isa(tpl, _t, _f) bst_ctuple_isa(tpl, bst_ctuple_hasN(tpl, 3, _t, _f), _f)


#endif // BST__ALLOCATOR_H
