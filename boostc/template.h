//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/allocator.h>
#include <boostc/iterator.h>


/** Provide operations on bstc template types.
 * type: The actual type for the template.
 * info: A ctuple of the information about the type.
 * fns: A ctuple of the functions for the type.
 * iter: The bstc iterator calls as a ctuple for the type.
 * riter: The bstc reverse iterator calls as a ctuple for the type.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */


/** . */
/// \{
#ifndef bstc_tmplt_pack_t
# define bstc_tmplt_pack_t(t) bstc_tmplt_set_t(bstc_tmplt_defaults, t)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_info
# define bstc_tmplt_pack_info(info) bstc_ctuple_isa(info, bstc_tmplt_set_info(bstc_tmplt_defaults, info), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_fns
# define bstc_tmplt_pack_fns(fns) bstc_ctuple_isa(fns, bstc_tmplt_set_fns(bstc_tmplt_defaults, fns), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_iter
# define bstc_tmplt_pack_iter(iter) bstc_iter_isa(iter, bstc_tmplt_set_iter(bstc_tmplt_defaults, iter), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_riter
# define bstc_tmplt_pack_riter(riter) bstc_iter_isa(riter, bstc_tmplt_set_riter(bstc_tmplt_defaults, riter), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_alloc
# define bstc_tmplt_pack_alloc(alloc) bstc_alloc_isa(alloc, bstc_tmplt_set_alloc(bstc_tmplt_defaults, alloc), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_pack_fn
# define bstc_tmplt_pack_fn(fn) bstc_tmplt_pack_fns(bstc_ctuple(fn))
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_t
# define bstc_tmplt_t(tpl) bstc_ctuple_getI(tpl, 0)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_info
# define bstc_tmplt_info(tpl) bstc_ctuple_getI(tpl, 1)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_fns
# define bstc_tmplt_fns(tpl) bstc_ctuple_getI(tpl, 2)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_iter
# define bstc_tmplt_iter(tpl) bstc_ctuple_getI(tpl, 3)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_riter
# define bstc_tmplt_riter(tpl) bstc_ctuple_getI(tpl, 4)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_alloc
# define bstc_tmplt_alloc(tpl) bstc_ctuple_getI(tpl, 5)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_fn
# define bstc_tmplt_fn(tpl) bstc_ctuple_getI(bstc_tmplt_fns(tpl), 0)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_t
# define bstc_tmplt_set_t(tpl, t) bstc_ctuple_setI(tpl, 0, t)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_info
# define bstc_tmplt_set_info(tpl, info) bstc_ctuple_setI(tpl, 1, info)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_fns
# define bstc_tmplt_set_fns(tpl, fns) bstc_ctuple_setI(tpl, 2, fns)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_iter
# define bstc_tmplt_set_iter(tpl, iter) bstc_ctuple_setI(tpl, 3, iter)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_riter
# define bstc_tmplt_set_riter(tpl, riter) bstc_ctuple_setI(tpl, 4, riter)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_set_alloc
# define bstc_tmplt_set_alloc(tpl, alloc) bstc_ctuple_setI(tpl, 5, alloc)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_fn_default
# define bstc_tmplt_fn_default(...) ((void)0)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_defaults
# define bstc_tmplt_defaults bstc_ctuple(int, bstc_ctuple(0), bstc_ctuple(bstc_tmplt_fn_default), bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** . */
/// \{
#ifndef bstc_tmplt_isa
# define bstc_tmplt_isa(tpl, _t, _f) \
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
#endif
/// \}
