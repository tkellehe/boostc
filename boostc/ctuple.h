//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/detail/ctuple.h>


/** Resolves the symbols in a ctuple and converts to a string. */
/// \{
#ifndef bstc_ctuple_tostring
# define bstc_ctuple_tostring(tpl) BSTC_TOSTRING(tpl)
#endif
/// \}


/** Packs variable arguments into a ctuple to be more explicit. */
/// \{
#ifndef bstc_ctuple
# define bstc_ctuple(...) (__VA_ARGS__)
#endif
/// \}


/** Expands a ctuple if called `bstc_ctuple_expand tpl`. */
/// \{
#ifndef bstc_ctuple_expand
# define bstc_ctuple_expand(...) __VA_ARGS__
#endif
/// \}


/** Expands to an empty ctuple. */
/// \{
#ifndef bstc_ctuple_empty
# define bstc_ctuple_empty() ()
#endif
/// \}


/** Calls the function with the provided ctuple. */
/// \{
#ifndef bstc_ctuple_call
# define bstc_ctuple_call(F, tpl) BSTC_EXPAND(F tpl)
#endif
/// \}


/** Determines if the provided argument is a ctuple. */
/// \{
#ifndef bstc_ctuple_isa
# define bstc_ctuple_isa(tpl, _t, _f) BSTC_ISA_TUPLE(tpl, _t, _f)
#endif
/// \}


/** Selects the `_t` statement if the ctuple is truthy and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_if
# define bstc_ctuple_if(tpl, _t, _f) bstc_ctuple_ifempty(tpl, _f, _t)
#endif
/// \}


/** Selects the `_t` statement if the ctuple is empty and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_ifempty
# define bstc_ctuple_ifempty(tpl, _t, _f) bstc_ctuple_hasN(tpl, 0, _t, _f)
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) > N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasGT
# define bstc_ctuple_hasGT(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFGT(bstc_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) <= N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasLTE
# define bstc_ctuple_hasLTE(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFGT(bstc_ctuple_size(tpl), N, _f, _t))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) == N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasN
# define bstc_ctuple_hasN(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFEQ(bstc_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) < N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasLT
# define bstc_ctuple_hasLT(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFLT(bstc_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) >= N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasGTE
# define bstc_ctuple_hasGTE(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFLT(bstc_ctuple_size(tpl), N, _f, _t))
#endif
/// \}


/** Gets the size of the ctuple and properly handles empty ctuples. */
/// \{
#ifndef bstc_ctuple_size
# define bstc_ctuple_size(tpl) bstc_ctuple_isa(tpl, BSTC_IF_ARG0_EMPTY(tpl, BSTC_IFEQ(BSTC_ARGCNT tpl, 1, 0, BSTC_ARGCNT tpl), BSTC_ARGCNT tpl), 0)
#endif
/// \}


/** Gets the Ith item in a ctuple then resolves to that value and will not compile if out-of-bounds. */
/// \{
#ifndef bstc_ctuple_getI
# define bstc_ctuple_getI(tpl, I) \
    bstc_ctuple_isa(tpl,\
        bstc_ctuple_hasGT(tpl, I, bstc_ctuple_call(BSTC_JOIN2(BSTC_GET_ARG, I), tpl), BSTC_CTUPLE_OUT_OF_BOUNDS),\
        BSTC_CTUPLE_NOT_TUPLE\
    )
#endif
/// \}


/** Creates a new ctuple with the list of items added to the back. */
/// \{
#ifndef bstc_ctuple_append
# define bstc_ctuple_append(tpl, ...) \
    bstc_ctuple_ifempty(tpl,\
        bstc_ctuple(__VA_ARGS__),\
        bstc_ctuple_ifempty(bstc_ctuple(__VA_ARGS__),\
            tpl,\
            bstc_dtl_ctuple_append(tpl, __VA_ARGS__)\
        )\
    )
#endif
/// \}


/** Creates a new ctuple with the list of items added to the front. */
/// \{
#ifndef bstc_ctuple_prepend
# define bstc_ctuple_prepend(tpl, ...) \
    bstc_ctuple_ifempty(tpl,\
        bstc_ctuple(__VA_ARGS__),\
        bstc_ctuple_ifempty(bstc_ctuple(__VA_ARGS__),\
            tpl,\
            bstc_dtl_ctuple_prepend(tpl, __VA_ARGS__)\
        )\
    )
#endif
/// \}


/** Creates a new ctuple by concatenating the two ctuples provided. */
/// \{
#ifndef bstc_ctuple_concat
# define bstc_ctuple_concat(ltpl, rtpl) \
    bstc_ctuple_ifempty(ltpl,\
        rtpl,\
        bstc_ctuple_ifempty(rtpl,\
            ltpl,\
            bstc_ctuple_call(bstc_dtl_ctuple_append, bstc_dtl_ctuple_prepend(rtpl, ltpl))\
        )\
    )
#endif
/// \}


/** Creates a new ctuple in reverse. */
/// \{
#ifndef bstc_ctuple_reverse
# define bstc_ctuple_reverse(tpl) bstc_ctuple(bstc_ctuple_call(BSTC_JOIN2(bstc_dtl_ctuple_reverse, bstc_ctuple_size(tpl)), tpl))
#endif
/// \}


/** Creates a new ctuple and collects the first N cells. */
/// \{
#ifndef bstc_ctuple_collect
# define bstc_ctuple_collect(tpl, N) \
    bstc_ctuple_hasGT(tpl, N,\
        (BSTC_CALL(BSTC_JOIN2(bstc_dtl_ctuple_collect, N), bstc_dtl_ctuple_collect_augmented(tpl))),\
        bstc_ctuple_hasN(tpl, N, tpl, BSTC_CTUPLE_OUT_OF_BOUNDS)\
    )
#endif
/// \}


/** Creates a new ctuple by removing the first N items. */
/// \{
#ifndef bstc_ctuple_ltrim
# define bstc_ctuple_ltrim(tpl, N) \
    BSTC_IFEQ(N, 0,\
        tpl,\
        bstc_ctuple_hasLTE(tpl, N,\
            bstc_ctuple_empty(),\
            bstc_ctuple(bstc_ctuple_call(BSTC_JOIN2(bstc_dtl_ctuple_ltrim, N), tpl))\
        )\
    )
#endif
/// \}


/** Creates a new ctuple by removing the last N items. */
/// \{
#ifndef bstc_ctuple_rtrim
# define bstc_ctuple_rtrim(tpl, N) \
    BSTC_IFEQ(N, 0,\
        tpl,\
        bstc_ctuple_hasLTE(tpl, N,\
            bstc_ctuple_empty(),\
            bstc_ctuple_reverse(bstc_ctuple_ltrim(bstc_ctuple_reverse(tpl), N))\
        )\
    )
#endif
/// \}


/** Creates a new ctuple and sets the value at the provided location. */
/// \{
#define bstc_ctuple_setI(tpl, I, val) \
    BSTC_IFEQ(I, 0,\
        bstc_ctuple_hasN(tpl, 1, bstc_ctuple(val), bstc_ctuple_prepend(bstc_ctuple_ltrim(tpl, 1), val)),\
        bstc_ctuple_hasN(tpl, BSTC_CONST_ADD1(I), bstc_ctuple_append(bstc_ctuple_collect(tpl, I), val), bstc_dtl_ctuple_setI(tpl, I, val))\
    )
/// \}
