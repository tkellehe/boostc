//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/traits/allocator.h>
#include <boostc/traits/iterator.h>


/** Provide operations on bstc template types.
 * type: The actual type for the template.
 * info: A ctuple of the information about the type.
 * fns: A ctuple of the functions for the type.
 * iter: The bstc iterator calls as a ctuple for the type.
 * riter: The bstc reverse iterator calls as a ctuple for the type.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_tmplt_traits
# define bstc_tmplt_traits(t, info, fns, iter, riter, alloc) (t, info, fns, iter, riter, alloc)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the template type provided. */
/// \{
#ifndef bstc_tmplt_pack_t
# define bstc_tmplt_pack_t(t) bstc_tmplt_set_t(bstc_tmplt_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the info ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_info
# if defined(bstc_ctuple_isa)
#  define bstc_tmplt_pack_info(info) bstc_ctuple_isa(info, bstc_tmplt_set_info(bstc_tmplt_defaults, info), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_tmplt_pack_info(info)bstc_tmplt_set_info(bstc_tmplt_defaults, info)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the functions ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_fns
# if defined(bstc_ctuple_isa)
#  define bstc_tmplt_pack_fns(fns) bstc_ctuple_isa(fns, bstc_tmplt_set_fns(bstc_tmplt_defaults, fns), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_tmplt_pack_fns(fns)bstc_tmplt_set_fns(bstc_tmplt_defaults, fns)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the iterator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_iter
# if defined(bstc_iter_isa)
#  define bstc_tmplt_pack_iter(iter) bstc_iter_isa(iter, bstc_tmplt_set_iter(bstc_tmplt_defaults, iter), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_tmplt_pack_iter(iter) bstc_tmplt_set_iter(bstc_tmplt_defaults, iter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the reverse iterator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_riter
# if defined(bstc_iter_isa)
#  define bstc_tmplt_pack_riter(riter) bstc_iter_isa(riter, bstc_tmplt_set_riter(bstc_tmplt_defaults, riter), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_tmplt_pack_riter(riter) bstc_tmplt_set_riter(bstc_tmplt_defaults, riter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the allocator ctuple provided. */
/// \{
#ifndef bstc_tmplt_pack_alloc
# if defined(bstc_alloc_isa)
#  define bstc_tmplt_pack_alloc(alloc) bstc_alloc_isa(alloc, bstc_tmplt_set_alloc(bstc_tmplt_defaults, alloc), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_tmplt_pack_alloc(alloc) bstc_tmplt_set_alloc(bstc_tmplt_defaults, alloc)
# endif
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
# define bstc_dtl_tmplt_t(t, info, fns, iter, riter, alloc) t
# define bstc_tmplt_t(tpl) BSTC_EXPAND(bstc_dtl_tmplt_t tpl)
#endif
/// \}


/** Get the template info ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_info
# define bstc_dtl_tmplt_info(t, info, fns, iter, riter, alloc) info
# define bstc_tmplt_info(tpl) BSTC_EXPAND(bstc_dtl_tmplt_info tpl)
#endif
/// \}


/** Get the template functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_fns
# define bstc_dtl_tmplt_fns(t, info, fns, iter, riter, alloc) fns
# define bstc_tmplt_fns(tpl) BSTC_EXPAND(bstc_dtl_tmplt_fns tpl)
#endif
/// \}


/** Get the template iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_iter
# define bstc_dtl_tmplt_iter(t, info, fns, iter, riter, alloc) iter
# define bstc_tmplt_iter(tpl) BSTC_EXPAND(bstc_dtl_tmplt_iter tpl)
#endif
/// \}


/** Get the template reverse iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_riter
# define bstc_dtl_tmplt_riter(t, info, fns, iter, riter, alloc) riter
# define bstc_tmplt_riter(tpl) BSTC_EXPAND(bstc_dtl_tmplt_riter tpl)
#endif
/// \}


/** Get the template allocator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_alloc
# define bstc_dtl_tmplt_alloc(t, info, fns, iter, riter, alloc) alloc
# define bstc_tmplt_alloc(tpl) BSTC_EXPAND(bstc_dtl_tmplt_alloc tpl)
#endif
/// \}


/** Get the first item in the template functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_tmplt_fn
# ifdef bstc_ctuple_getI
#  define bstc_tmplt_fn(tpl) bstc_ctuple_getI(bstc_tmplt_fns(tpl), 0)
# endif
#endif
/// \}


/** Create a copy of the ctuple as a template with the template type changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_t
# define bstc_dtl_tmplt_set_t(tpl, p) bstc_dtl_tmplt_set_t_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_t_expand1(L, p))
# define bstc_dtl_tmplt_set_t_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(p, info, fns, iter, riter, alloc)
# define bstc_tmplt_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_tmplt_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as a template with the template info ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_info
# define bstc_dtl_tmplt_set_info(tpl, p) bstc_dtl_tmplt_set_info_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_info_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_info_expand1(L, p))
# define bstc_dtl_tmplt_set_info_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(t, p, fns, iter, riter, alloc)
# define bstc_tmplt_set_info(tpl, info) BSTC_EXPAND(bstc_dtl_tmplt_set_info(tpl, info))
#endif
/// \}


/** Create a copy of the ctuple as a template with the template functions ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_fns
# define bstc_dtl_tmplt_set_fns(tpl, p) bstc_dtl_tmplt_set_fns_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_fns_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_fns_expand1(L, p))
# define bstc_dtl_tmplt_set_fns_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(t, info, p, iter, riter, alloc)
# define bstc_tmplt_set_fns(tpl, fns) BSTC_EXPAND(bstc_dtl_tmplt_set_fns(tpl, fns))
#endif
/// \}


/** Create a copy of the ctuple as a template with the template iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_iter
# define bstc_dtl_tmplt_set_iter(tpl, p) bstc_dtl_tmplt_set_iter_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_iter_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_iter_expand1(L, p))
# define bstc_dtl_tmplt_set_iter_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(t, info, fns, p, riter, alloc)
# define bstc_tmplt_set_iter(tpl, iter) BSTC_EXPAND(bstc_dtl_tmplt_set_iter(tpl, iter))
#endif
/// \}


/** Create a copy of the ctuple as a template with the template reverse iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_riter
# define bstc_dtl_tmplt_set_riter(tpl, p) bstc_dtl_tmplt_set_riter_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_riter_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_riter_expand1(L, p))
# define bstc_dtl_tmplt_set_riter_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(t, info, fns, iter, p, alloc)
# define bstc_tmplt_set_riter(tpl, riter) BSTC_EXPAND(bstc_dtl_tmplt_set_riter(tpl, riter))
#endif
/// \}


/** Create a copy of the ctuple as a template with the template allocator ctuple changed to what is provided. */
/// \{
#ifndef bstc_tmplt_set_alloc
# define bstc_dtl_tmplt_set_alloc(tpl, p) bstc_dtl_tmplt_set_alloc_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_tmplt_set_alloc_expand(L, p) BSTC_EXPAND(bstc_dtl_tmplt_set_alloc_expand1(L, p))
# define bstc_dtl_tmplt_set_alloc_expand1(t, info, fns, iter, riter, alloc, p) bstc_tmplt_traits(t, info, fns, iter, riter, p)
# define bstc_tmplt_set_alloc(tpl, alloc) BSTC_EXPAND(bstc_dtl_tmplt_set_alloc(tpl, alloc))
#endif
/// \}


/** Default template function that does nothing. */
/// \{
#ifndef bstc_tmplt_fn_default
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_tmplt_fn_default(...) ((void)0)
# else
#  define bstc_tmplt_fn_default() ((void)0)
# endif
#endif
/// \}


/** Default template ctuple that uses the default iterators, allocator, info, type, and functions. */
/// \{
#ifndef bstc_tmplt_defaults
# define bstc_tmplt_defaults bstc_tmplt_traits(int, bstc_ctuple(0), bstc_ctuple(bstc_tmplt_fn_default), bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Detects if the ctuple provided could be a valid template ctuple. */
/// \{
#ifndef bstc_tmplt_isa
# if defined(bstc_ctuple_isa) && defined(bstc_ctuple_hasN) && defined(bstc_alloc_isa) && defined(bstc_iter_isa)
#  define bstc_tmplt_isa(tpl, _t, _f) \
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
# endif
#endif
/// \}
