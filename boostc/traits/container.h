//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/traits/allocator.h>
#include <boostc/traits/iterator.h>


/** Provide operations on bstc container types.
 * type: The actual type for the container.
 * subtraits: A ctuple of the information about the type.
 * fns: A ctuple of the functions for the type.
 * iter: The bstc iterator calls as a ctuple for the type.
 * riter: The bstc reverse iterator calls as a ctuple for the type.
 * alloc: The bstc allocator calls as a ctuple for the type.
 */


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_container_traits
# define bstc_container_traits(t, subtraits, fns, iter, riter, alloc) (t, subtraits, fns, iter, riter, alloc)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the container type provided. */
/// \{
#ifndef bstc_container_pack_t
# define bstc_container_pack_t(t) bstc_container_set_t(bstc_container_defaults, t)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the subtraits ctuple provided. */
/// \{
#ifndef bstc_container_pack_subtraits
# if defined(bstc_ctuple_isa)
#  define bstc_container_pack_subtraits(subtraits) bstc_ctuple_isa(subtraits, bstc_container_set_subtraits(bstc_container_defaults, subtraits), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_subtraits(subtraits)bstc_container_set_subtraits(bstc_container_defaults, subtraits)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the functions ctuple provided. */
/// \{
#ifndef bstc_container_pack_fns
# if defined(bstc_ctuple_isa)
#  define bstc_container_pack_fns(fns) bstc_ctuple_isa(fns, bstc_container_set_fns(bstc_container_defaults, fns), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_fns(fns)bstc_container_set_fns(bstc_container_defaults, fns)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the iterator ctuple provided. */
/// \{
#ifndef bstc_container_pack_iter
# if defined(bstc_iter_isa)
#  define bstc_container_pack_iter(iter) bstc_iter_isa(iter, bstc_container_set_iter(bstc_container_defaults, iter), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_iter(iter) bstc_container_set_iter(bstc_container_defaults, iter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the reverse iterator ctuple provided. */
/// \{
#ifndef bstc_container_pack_riter
# if defined(bstc_iter_isa)
#  define bstc_container_pack_riter(riter) bstc_iter_isa(riter, bstc_container_set_riter(bstc_container_defaults, riter), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_riter(riter) bstc_container_set_riter(bstc_container_defaults, riter)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the allocator ctuple provided. */
/// \{
#ifndef bstc_container_pack_alloc
# if defined(bstc_alloc_isa)
#  define bstc_container_pack_alloc(alloc) bstc_alloc_isa(alloc, bstc_container_set_alloc(bstc_container_defaults, alloc), BSTC_TMPLT_NOT_CREATED_ERROR)
# else
#  define bstc_container_pack_alloc(alloc) bstc_container_set_alloc(bstc_container_defaults, alloc)
# endif
#endif
/// \}


/** Creates a ctuple with the defaults set except for the function provided which will be packed into a ctuple. */
/// \{
#ifndef bstc_container_pack_fn
# define bstc_container_pack_fn(fn) bstc_container_pack_fns(bstc_ctuple(fn))
#endif
/// \}


/** Get the container type that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_t
# define bstc_dtl_container_t(t, subtraits, fns, iter, riter, alloc) t
# define bstc_container_t(tpl) BSTC_EXPAND(bstc_dtl_container_t tpl)
#endif
/// \}


/** Get the container subtraits ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_subtraits
# define bstc_dtl_container_subtraits(t, subtraits, fns, iter, riter, alloc) subtraits
# define bstc_container_subtraits(tpl) BSTC_EXPAND(bstc_dtl_container_subtraits tpl)
#endif
/// \}


/** Get the container functions ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_fns
# define bstc_dtl_container_fns(t, subtraits, fns, iter, riter, alloc) fns
# define bstc_container_fns(tpl) BSTC_EXPAND(bstc_dtl_container_fns tpl)
#endif
/// \}


/** Get the container iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_iter
# define bstc_dtl_container_iter(t, subtraits, fns, iter, riter, alloc) iter
# define bstc_container_iter(tpl) BSTC_EXPAND(bstc_dtl_container_iter tpl)
#endif
/// \}


/** Get the container reverse iterator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_riter
# define bstc_dtl_container_riter(t, subtraits, fns, iter, riter, alloc) riter
# define bstc_container_riter(tpl) BSTC_EXPAND(bstc_dtl_container_riter tpl)
#endif
/// \}


/** Get the container allocator ctuple that has been packed into the ctuple. */
/// \{
#ifndef bstc_container_alloc
# define bstc_dtl_container_alloc(t, subtraits, fns, iter, riter, alloc) alloc
# define bstc_container_alloc(tpl) BSTC_EXPAND(bstc_dtl_container_alloc tpl)
#endif
/// \}


/** Get the container functions ctuple then get the constructor. */
/// \{
#ifndef bstc_container_ctor
# define bstc_dtl_container_ctor1(ctor, dtor) ctor
# define bstc_dtl_container_ctor(t, subtraits, fns, iter, riter, alloc) BSTC_EXPAND(bstc_dtl_container_ctor1 fns)
# define bstc_container_ctor(tpl) BSTC_EXPAND(bstc_dtl_container_ctor tpl)
#endif
/// \}


/** Get the container functions ctuple then get the destructor. */
/// \{
#ifndef bstc_container_dtor
# define bstc_dtl_container_dtor1(ctor, dtor) ctor
# define bstc_dtl_container_dtor(t, subtraits, fns, iter, riter, alloc) BSTC_EXPAND(bstc_dtl_container_dtor1 fns)
# define bstc_container_dtor(tpl) BSTC_EXPAND(bstc_dtl_container_dtor tpl)
#endif
/// \}


/** Create a copy of the ctuple as a container with the container type changed to what is provided. */
/// \{
#ifndef bstc_container_set_t
# define bstc_dtl_container_set_t(tpl, p) bstc_dtl_container_set_t_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_t_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_t_expand1(L, p))
# define bstc_dtl_container_set_t_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(p, subtraits, fns, iter, riter, alloc)
# define bstc_container_set_t(tpl, t) BSTC_EXPAND(bstc_dtl_container_set_t(tpl, t))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container subtraits ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_subtraits
# define bstc_dtl_container_set_subtraits(tpl, p) bstc_dtl_container_set_subtraits_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_subtraits_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_subtraits_expand1(L, p))
# define bstc_dtl_container_set_subtraits_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(t, p, fns, iter, riter, alloc)
# define bstc_container_set_subtraits(tpl, subtraits) BSTC_EXPAND(bstc_dtl_container_set_subtraits(tpl, subtraits))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container functions ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_fns
# define bstc_dtl_container_set_fns(tpl, p) bstc_dtl_container_set_fns_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_fns_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_fns_expand1(L, p))
# define bstc_dtl_container_set_fns_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(t, subtraits, p, iter, riter, alloc)
# define bstc_container_set_fns(tpl, fns) BSTC_EXPAND(bstc_dtl_container_set_fns(tpl, fns))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_iter
# define bstc_dtl_container_set_iter(tpl, p) bstc_dtl_container_set_iter_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_iter_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_iter_expand1(L, p))
# define bstc_dtl_container_set_iter_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(t, subtraits, fns, p, riter, alloc)
# define bstc_container_set_iter(tpl, iter) BSTC_EXPAND(bstc_dtl_container_set_iter(tpl, iter))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container reverse iterator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_riter
# define bstc_dtl_container_set_riter(tpl, p) bstc_dtl_container_set_riter_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_riter_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_riter_expand1(L, p))
# define bstc_dtl_container_set_riter_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(t, subtraits, fns, iter, p, alloc)
# define bstc_container_set_riter(tpl, riter) BSTC_EXPAND(bstc_dtl_container_set_riter(tpl, riter))
#endif
/// \}


/** Create a copy of the ctuple as a container with the container allocator ctuple changed to what is provided. */
/// \{
#ifndef bstc_container_set_alloc
# define bstc_dtl_container_set_alloc(tpl, p) bstc_dtl_container_set_alloc_expand(BSTC_LAYOUT6 tpl, p)
# define bstc_dtl_container_set_alloc_expand(L, p) BSTC_EXPAND(bstc_dtl_container_set_alloc_expand1(L, p))
# define bstc_dtl_container_set_alloc_expand1(t, subtraits, fns, iter, riter, alloc, p) bstc_container_traits(t, subtraits, fns, iter, riter, p)
# define bstc_container_set_alloc(tpl, alloc) BSTC_EXPAND(bstc_dtl_container_set_alloc(tpl, alloc))
#endif
/// \}


/** Default constructor function that does nothing. */
/// \{
#ifndef bstc_container_noctor
# define bstc_container_noctor(traits, item) ((void)0)
#endif
/// \}


/** Default destructor function that does nothing. */
/// \{
#ifndef bstc_container_nodtor
# define bstc_container_nodtor(traits, item) ((void)0)
#endif
/// \}


/** Default container functions. */
/// \{
#ifndef bstc_container_default_fns
# define bstc_container_default_fns BSTC_CTUPLE2(bstc_container_noctor, bstc_container_nodtor)
#endif
/// \}


/** Default container subtraits. */
/// \{
#ifndef bstc_container_default_subtraits
# define bstc_container_default_subtraits bstc_container_traits(int, BSTC_CTUPLE1(0), bstc_container_default_fns, bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Default container ctuple that uses the default iterators, allocator, subtraits, type, and functions. */
/// \{
#ifndef bstc_container_defaults
# define bstc_container_defaults bstc_container_traits(int, bstc_container_default_subtraits, bstc_container_default_fns, bstc_iter_defaults, bstc_iter_defaults, bstc_alloc_defaults)
#endif
/// \}


/** Detects if the ctuple provided could be a valid container ctuple. */
/// \{
#ifndef bstc_container_isa
# if defined(bstc_ctuple_isa) && defined(bstc_ctuple_hasN) && defined(bstc_alloc_isa) && defined(bstc_iter_isa)
#  define bstc_container_isa(tpl, _t, _f) \
    bstc_ctuple_isa(tpl,\
        bstc_ctuple_hasN(tpl, 6,\
            bstc_iter_isa(bstc_container_iter(tpl),\
                bstc_iter_isa(bstc_container_riter(tpl),\
                    bstc_alloc_isa(bstc_container_alloc(tpl),\
                        bstc_ctuple_isa(bstc_container_subtraits(tpl), bstc_ctuple_hasN(bstc_container_fns(tpl), 2, _t, _f), _f),\
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
