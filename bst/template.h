//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BSTC__TEMPLATE_H
#define BSTC__TEMPLATE_H


#include <bstc/config.h>
#include <bstc/ctuple.h>
#include <bstc/allocator.h>
#include <bstc/iterator.h>


/* Provide without namespace */
/// \{
#ifdef BSTC_NO_NAMESPACE
#define tmplt_ctuple_type bstc_tmplt_ctuple_type
#define tmplt_ctuple_info bstc_tmplt_ctuple_info
#define tmplt_ctuple_fns bstc_tmplt_ctuple_fns
#define tmplt_ctuple_iter bstc_tmplt_ctuple_iter
#define tmplt_ctuple_riter bstc_tmplt_ctuple_riter
#define tmplt_ctuple_alloc bstc_tmplt_ctuple_alloc

#define tmplt_ctuple_fn bstc_tmplt_ctuple_fn

#define tmplt_type bstc_tmplt_type
#define tmplt_info bstc_tmplt_info
#define tmplt_fns bstc_tmplt_fns
#define tmplt_iter bstc_tmplt_iter
#define tmplt_riter bstc_tmplt_riter
#define tmplt_alloc bstc_tmplt_alloc

#define tmplt_fn bstc_tmplt_fn

#define tmplt_set_type bstc_tmplt_set_type
#define tmplt_set_info bstc_tmplt_set_info
#define tmplt_set_fns bstc_tmplt_set_fns
#define tmplt_set_iter bstc_tmplt_set_iter
#define tmplt_set_riter bstc_tmplt_set_riter
#define tmplt_set_alloc bstc_tmplt_set_alloc

#define tmplt_defaults bstc_tmplt_defaults

#define tmplt_isa bstc_tmplt_isa
#endif
/// \}


/** Provide operations on bstc template types.
 * type: The actual type for the template.
 * info: A ctuple of the information about the type.
 * fns: A ctuple of the functions for the type.
 * iter: The bstc iterator calls as a ctuple for the type.
 * riter: The bstc reverse iterator calls as a ctuple for the type.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */
/// \{
#define bstc_tmplt_ctuple_type(type) bstc_tmplt_set_type(bstc_tmplt_defaults, type)
#define bstc_tmplt_ctuple_info(info) bstc_ctuple_isa(info, bstc_tmplt_set_info(bstc_tmplt_defaults, info), BSTC_TMPLT_NOT_CREATED_ERROR)
#define bstc_tmplt_ctuple_fns(fns) bstc_ctuple_isa(fns, bstc_tmplt_set_fns(bstc_tmplt_defaults, fns), BSTC_TMPLT_NOT_CREATED_ERROR)
#define bstc_tmplt_ctuple_iter(iter) bstc_iter_isa(iter, bstc_tmplt_set_iter(bstc_tmplt_defaults, iter), BSTC_TMPLT_NOT_CREATED_ERROR)
#define bstc_tmplt_ctuple_riter(riter) bstc_iter_isa(riter, bstc_tmplt_set_riter(bstc_tmplt_defaults, riter), BSTC_TMPLT_NOT_CREATED_ERROR)
#define bstc_tmplt_ctuple_alloc(alloc) bstc_alloc_isa(alloc, bstc_tmplt_set_alloc(bstc_tmplt_defaults, alloc), BSTC_TMPLT_NOT_CREATED_ERROR)

#define bstc_tmplt_ctuple_fn(fn) bstc_tmplt_ctuple_fns(bstc_ctuple(fn))

#define bstc_dtl_tmplt_ctuple(...) \
    bstc_ctuple_defaults(\
        bstc_ctuple(__VA_ARGS__),\
        bstc_tmplt_defaults\
    )

#define bstc_tmplt_type(tpl) bstc_ctuple_getI(tpl, 0)
#define bstc_tmplt_info(tpl) bstc_ctuple_getI(tpl, 1)
#define bstc_tmplt_fns(tpl) bstc_ctuple_getI(tpl, 2)
#define bstc_tmplt_iter(tpl) bstc_ctuple_getI(tpl, 3)
#define bstc_tmplt_riter(tpl) bstc_ctuple_getI(tpl, 4)
#define bstc_tmplt_alloc(tpl) bstc_ctuple_getI(tpl, 5)

#define bstc_tmplt_fn(tpl) bstc_ctuple_getI(bstc_tmplt_fns(tpl), 0)

#define bstc_tmplt_set_type(tpl, type) bstc_ctuple_setI(tpl, 0, type)
#define bstc_tmplt_set_info(tpl, info) bstc_ctuple_setI(tpl, 1, info)
#define bstc_tmplt_set_fns(tpl, fns) bstc_ctuple_setI(tpl, 2, fns)
#define bstc_tmplt_set_iter(tpl, iter) bstc_ctuple_setI(tpl, 3, iter)
#define bstc_tmplt_set_riter(tpl, riter) bstc_ctuple_setI(tpl, 4, riter)
#define bstc_tmplt_set_alloc(tpl, alloc) bstc_ctuple_setI(tpl, 5, alloc)
/// \}


/* Packs the defaults */
#define bstc_tmplt_fn_default(...) ((void)0)
#define bstc_tmplt_defaults bstc_ctuple(int, (0), (bstc_tmplt_fn_default), bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)


/* Detect if provided a ctuple that could be a template */
#define bstc_tmplt_isa(tpl, _t, _f) \
    bstc_ctuple_isa(tpl,\
        bstc_ctuple_hasN(tpl, 6,\
            bstc_iter_isa(bstc_tmplt_iter(tpl),\
                bstc_iter_isa(bstc_tmplt_riter(tpl),\
                    bstc_alloc_isa(bstc_tmplt_alloc(tpl),\
                        bstc_ctuple_isa(bstc_tmplt_info(tpl), bstc_ctuple_isa(bstc_tmplt_fns(tpl), _t, _f), _f),\
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


#endif // BSTC__TEMPLATE_H
