//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__TEMPLATE_H
#define BST__TEMPLATE_H


#include <bst/config.h>
#include <bst/ppack.h>
#include <bst/allocator.h>
#include <bst/iterator.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define tmplt_ppack bst_tmplt_ppack

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
 * info: A ppack of the information about the type.
 * fns: A ppack of the functions for the type.
 * iter: The bst iterator calls as a ppack for the type.
 * riter: The bst reverse iterator calls as a ppack for the type.
 * alloc: The bst allocator calls as a ppack for the type.
 */
/// \{
#define bst_tmplt_ppack_type(type) bst_ppack(type, (0), (bst_dtl_tmplt_fn_default), bst_iter_defaults, bst_iter_defaults, bst_alloc_defaults)
#define bst_tmplt_ppack_info(info) bst_ppack(int, info, (bst_dtl_tmplt_fn_default), bst_iter_defaults, bst_iter_defaults, bst_alloc_defaults)
#define bst_tmplt_ppack_fns(fns) bst_ppack(int, (0), fns, bst_iter_defaults, bst_iter_defaults, bst_alloc_defaults)
#define bst_tmplt_ppack_iter(iter) bst_ppack(int, (0), (bst_dtl_tmplt_fn_default), iter, bst_iter_defaults, bst_alloc_defaults)
#define bst_tmplt_ppack_riter(riter) bst_ppack(int, (0), (bst_dtl_tmplt_fn_default), bst_iter_defaults, riter, bst_alloc_defaults)
#define bst_tmplt_ppack_alloc(alloc) bst_ppack(int, (0), (bst_dtl_tmplt_fn_default), bst_iter_defaults, bst_iter_defaults, alloc)


#define bst_tmplt_ppack(...) \
    bst_tmplt_isa(bst_dtl_tmplt_ppack(__VA_ARGS__), bst_dtl_tmplt_ppack(__VA_ARGS__), BST_TMPLT_NOT_CREATED_ERROR)
#define bst_dtl_tmplt_ppack(...) \
    bst_ppack_defaults(\
        bst_ppack(__VA_ARGS__),\
        bst_tmplt_defaults\
    )

#define bst_tmplt_type(pkd) bst_ppack_getI(pkd, 0)
#define bst_tmplt_info(pkd) bst_ppack_getI(pkd, 1)
#define bst_tmplt_fns(pkd) bst_ppack_getI(pkd, 2)
#define bst_tmplt_iter(pkd) bst_ppack_getI(pkd, 3)
#define bst_tmplt_riter(pkd) bst_ppack_getI(pkd, 4)
#define bst_tmplt_alloc(pkd) bst_ppack_getI(pkd, 5)

#define bst_tmplt_fn(pkd) bst_ppack_getI(bst_tmplt_fns(pkd), 0)

#define bst_tmplt_set_type(pkd, type) bst_ppack_setI(pkd, 0, type)
#define bst_tmplt_set_info(pkd, info) bst_ppack_setI(pkd, 1, info)
#define bst_tmplt_set_fns(pkd, fns) bst_ppack_setI(pkd, 2, fns)
#define bst_tmplt_set_iter(pkd, iter) bst_ppack_setI(pkd, 3, iter)
#define bst_tmplt_set_riter(pkd, riter) bst_ppack_setI(pkd, 4, riter)
#define bst_tmplt_set_alloc(pkd, alloc) bst_ppack_setI(pkd, 5, alloc)
/// \}


/* Packs the defaults */
#define bst_dtl_tmplt_fn_default(...) ((void)0)
#define bst_tmplt_defaults bst_ppack(int, (0), (bst_dtl_tmplt_fn_default), bst_iter_defaults, bst_iter_defaults, bst_alloc_defaults)


/* Detect if provided a ppack that could be a template */
#define bst_tmplt_isa(pkd, _t, _f) \
    bst_ppack_isa(pkd,\
        bst_ppack_hasN(pkd, 6,\
            bst_iter_isa(bst_tmplt_iter(pkd),\
                bst_iter_isa(bst_tmplt_riter(pkd),\
                    bst_alloc_isa(bst_tmplt_alloc(pkd),\
                        bst_ppack_isa(bst_tmplt_info(pkd), bst_ppack_isa(bst_tmplt_fns(pkd), _t, _f), _f),\
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


#ifdef __cplusplus
}
#endif


#endif // BST__TEMPLATE_H
