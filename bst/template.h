//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__TEMPLATE_H
#define BST__TEMPLATE_H


#include <bst/config.h>
#include <bst/ctuple.h>
#include <bst/allocator.h>
#include <bst/iterator.h>


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define tmplt_ctuple_type bst_tmplt_ctuple_type
#define tmplt_ctuple_info bst_tmplt_ctuple_info
#define tmplt_ctuple_fns bst_tmplt_ctuple_fns
#define tmplt_ctuple_iter bst_tmplt_ctuple_iter
#define tmplt_ctuple_riter bst_tmplt_ctuple_riter
#define tmplt_ctuple_alloc bst_tmplt_ctuple_alloc

#define tmplt_ctuple_fn bst_tmplt_ctuple_fn

#define tmplt_type bst_tmplt_type
#define tmplt_info bst_tmplt_info
#define tmplt_fns bst_tmplt_fns
#define tmplt_iter bst_tmplt_iter
#define tmplt_riter bst_tmplt_riter
#define tmplt_alloc bst_tmplt_alloc

#define tmplt_fn bst_tmplt_fn

#define tmplt_set_type bst_tmplt_set_type
#define tmplt_set_info bst_tmplt_set_info
#define tmplt_set_fns bst_tmplt_set_fns
#define tmplt_set_iter bst_tmplt_set_iter
#define tmplt_set_riter bst_tmplt_set_riter
#define tmplt_set_alloc bst_tmplt_set_alloc

#define tmplt_defaults bst_tmplt_defaults

#define tmplt_isa bst_tmplt_isa
#endif
/// \}


/** Provide operations on bst template types.
 * type: The actual type for the template.
 * info: A ctuple of the information about the type.
 * fns: A ctuple of the functions for the type.
 * iter: The bst iterator calls as a ctuple for the type.
 * riter: The bst reverse iterator calls as a ctuple for the type.
 * alloc: The bst allocator calls as a ctuple for the type.
 */
/// \{
#define bst_tmplt_ctuple_type(type) bst_tmplt_set_type(bst_tmplt_defaults, type)
#define bst_tmplt_ctuple_info(info) bst_ctuple_isa(info, bst_tmplt_set_info(bst_tmplt_defaults, info), BST_TMPLT_NOT_CREATED_ERROR)
#define bst_tmplt_ctuple_fns(fns) bst_ctuple_isa(fns, bst_tmplt_set_fns(bst_tmplt_defaults, fns), BST_TMPLT_NOT_CREATED_ERROR)
#define bst_tmplt_ctuple_iter(iter) bst_iter_isa(iter, bst_tmplt_set_iter(bst_tmplt_defaults, iter), BST_TMPLT_NOT_CREATED_ERROR)
#define bst_tmplt_ctuple_riter(riter) bst_iter_isa(riter, bst_tmplt_set_riter(bst_tmplt_defaults, riter), BST_TMPLT_NOT_CREATED_ERROR)
#define bst_tmplt_ctuple_alloc(alloc) bst_alloc_isa(alloc, bst_tmplt_set_alloc(bst_tmplt_defaults, alloc), BST_TMPLT_NOT_CREATED_ERROR)

#define bst_tmplt_ctuple_fn(fn) bst_tmplt_ctuple_fns(bst_ctuple(fn))

#define bst_dtl_tmplt_ctuple(...) \
    bst_ctuple_defaults(\
        bst_ctuple(__VA_ARGS__),\
        bst_tmplt_defaults\
    )

#define bst_tmplt_type(tpl) bst_ctuple_getI(tpl, 0)
#define bst_tmplt_info(tpl) bst_ctuple_getI(tpl, 1)
#define bst_tmplt_fns(tpl) bst_ctuple_getI(tpl, 2)
#define bst_tmplt_iter(tpl) bst_ctuple_getI(tpl, 3)
#define bst_tmplt_riter(tpl) bst_ctuple_getI(tpl, 4)
#define bst_tmplt_alloc(tpl) bst_ctuple_getI(tpl, 5)

#define bst_tmplt_fn(tpl) bst_ctuple_getI(bst_tmplt_fns(tpl), 0)

#define bst_tmplt_set_type(tpl, type) bst_ctuple_setI(tpl, 0, type)
#define bst_tmplt_set_info(tpl, info) bst_ctuple_setI(tpl, 1, info)
#define bst_tmplt_set_fns(tpl, fns) bst_ctuple_setI(tpl, 2, fns)
#define bst_tmplt_set_iter(tpl, iter) bst_ctuple_setI(tpl, 3, iter)
#define bst_tmplt_set_riter(tpl, riter) bst_ctuple_setI(tpl, 4, riter)
#define bst_tmplt_set_alloc(tpl, alloc) bst_ctuple_setI(tpl, 5, alloc)
/// \}


/* Packs the defaults */
#define bst_tmplt_fn_default(...) ((void)0)
#define bst_tmplt_defaults bst_ctuple(int, (0), (bst_tmplt_fn_default), bst_iter_defaults, bst_iter_defaults, bst_alloc_defaults)


/* Detect if provided a ctuple that could be a template */
#define bst_tmplt_isa(tpl, _t, _f) \
    bst_ctuple_isa(tpl,\
        bst_ctuple_hasN(tpl, 6,\
            bst_iter_isa(bst_tmplt_iter(tpl),\
                bst_iter_isa(bst_tmplt_riter(tpl),\
                    bst_alloc_isa(bst_tmplt_alloc(tpl),\
                        bst_ctuple_isa(bst_tmplt_info(tpl), bst_ctuple_isa(bst_tmplt_fns(tpl), _t, _f), _f),\
                        _f\
                    ),\
                    _f\
                ),\
                _f\
            ),\
            _f\
        ),\
        _f\
    )


#endif // BST__TEMPLATE_H
