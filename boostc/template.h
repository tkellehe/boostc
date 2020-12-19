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


/** Creates a ctuple with the defaults set except for the template type provided. */
/// \{
#ifndef bstc_tmplt_pack_t
# define bstc_tmplt_pack_t(t) bstc_tmplt_set_t(bstc_tmplt_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the info ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_info
# define bstc_tmplt_pack_info(info) bstc_ctuple_isa(info, bstc_tmplt_set_info(bstc_tmplt_defaults, info), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the functions ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_fns
# define bstc_tmplt_pack_fns(fns) bstc_ctuple_isa(fns, bstc_tmplt_set_fns(bstc_tmplt_defaults, fns), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the iterator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_iter
# define bstc_tmplt_pack_iter(iter) bstc_iter_isa(iter, bstc_tmplt_set_iter(bstc_tmplt_defaults, iter), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the reverse iterator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_riter
# define bstc_tmplt_pack_riter(riter) bstc_iter_isa(riter, bstc_tmplt_set_riter(bstc_tmplt_defaults, riter), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the allocator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_alloc
# define bstc_tmplt_pack_alloc(alloc) bstc_alloc_isa(alloc, bstc_tmplt_set_alloc(bstc_tmplt_defaults, alloc), BSTC_TMPLT_NOT_CREATED_ERROR)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the function provided which will be packed into a ctuple. */
/// \{
#ifndef bstc_tmplt_pack_fn
# define bstc_tmplt_pack_fn(fn) bstc_tmplt_pack_fns(bstc_ctuple(fn))
#endif
/// \}


/** Get the template type that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_t
# define bstc_tmplt_t(tpl) BSTC_EXPAND(BSTC_GET_ARG0 tpl)
#endif
/// \}


/** Get the template info ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_info
# define bstc_tmplt_info(tpl) BSTC_EXPAND(BSTC_GET_ARG1 tpl)
#endif
/// \}


/** Get the template functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_fns
# define bstc_tmplt_fns(tpl) BSTC_EXPAND(BSTC_GET_ARG2 tpl)
#endif
/// \}


/** Get the template iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_iter
# define bstc_tmplt_iter(tpl) BSTC_EXPAND(BSTC_GET_ARG3 tpl)
#endif
/// \}


/** Get the template reverse iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_riter
# define bstc_tmplt_riter(tpl) BSTC_EXPAND(BSTC_GET_ARG4 tpl)
#endif
/// \}


/** Get the template allocator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_alloc
# define bstc_tmplt_alloc(tpl) BSTC_EXPAND(BSTC_GET_ARG5 tpl)
#endif
/// \}


/** Get the first item in the template functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_fn
# define bstc_tmplt_fn(tpl) bstc_ctuple_getI(bstc_tmplt_fns(tpl), 0)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template type changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_t
# define bstc_tmplt_set_t(tpl, t) bstc_ctuple_setI(tpl, 0, t)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template info ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_info
# define bstc_tmplt_set_info(tpl, info) bstc_ctuple_setI(tpl, 1, info)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template functions ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_fns
# define bstc_tmplt_set_fns(tpl, fns) bstc_ctuple_setI(tpl, 2, fns)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_iter
# define bstc_tmplt_set_iter(tpl, iter) bstc_ctuple_setI(tpl, 3, iter)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template reverse iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_riter
# define bstc_tmplt_set_riter(tpl, riter) bstc_ctuple_setI(tpl, 4, riter)
#endif
/// \}


/** Create a copy of the ctuple as a template with the template allocator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_alloc
# define bstc_tmplt_set_alloc(tpl, alloc) bstc_ctuple_setI(tpl, 5, alloc)
#endif
/// \}


/** Default template function that does nothing. */
/// \{
#ifndef bstc_tmplt_fn_default
# define bstc_tmplt_fn_default(...) ((void)0)
#endif
/// \}


/** Default template ctuple that uses the default iterators, allocator, info, type, and functions. */
/// \{
#ifndef bstc_tmplt_defaults
# define bstc_tmplt_defaults bstc_ctuple(int, bstc_ctuple(0), bstc_ctuple(bstc_tmplt_fn_default), bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Detects if the ctuple provided could be a valid template ctuple. */
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
