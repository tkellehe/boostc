//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BSTC__ALLOCATOR_H
#define BSTC__ALLOCATOR_H


#include <bstc/config.h>
#include <bstc/ctuple.h>
#include <bstc/stdlib.h>


/* Pack arguments provided into a single ctuple maintaining the standard order where defaults are no-ops */
/// \{
#define bstc_alloc_ctuple_free(f) bstc_alloc_set_free(bstc_alloc_defaults, bstc_free)
#define bstc_alloc_ctuple_malloc(m) bstc_alloc_set_malloc(bstc_alloc_defaults, bstc_malloc)
#define bstc_alloc_ctuple_realloc(r) bstc_alloc_set_realloc(bstc_alloc_defaults, bstc_realloc)

#define bstc_alloc_free(tpl) bstc_ctuple_getI(tpl, 0)
#define bstc_alloc_malloc(tpl) bstc_ctuple_getI(tpl, 1)
#define bstc_alloc_realloc(tpl) bstc_ctuple_getI(tpl, 2)

#define bstc_alloc_set_free(tpl, free) bstc_ctuple_setI(tpl, 0, free)
#define bstc_alloc_set_malloc(tpl, malloc) bstc_ctuple_setI(tpl, 1, malloc)
#define bstc_alloc_set_realloc(tpl, realloc) bstc_ctuple_setI(tpl, 2, realloc)
/// \}


/* Packs the stdlib calls */
#define bstc_alloc_stdlib bstc_ctuple(bstc_free, bstc_malloc, bstc_realloc)


/* Packs the default do-nothings */
#define bstc_alloc_defaults bstc_ctuple(bstc_alloc_nofree, bstc_alloc_nomalloc, bstc_alloc_norealloc)


/* Default do-nothing memory management functions */
/// \{
#define bstc_alloc_nofree(...) ((void)0)
#define bstc_alloc_nomalloc(...) ((void*)bstc_null)
#define bstc_alloc_norealloc(...) ((void*)bstc_null)
/// \}


/* Detect if provided a ctuple that could be an allocator */
#define bstc_alloc_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 3, _t, _f), _f)


#endif // BSTC__ALLOCATOR_H
