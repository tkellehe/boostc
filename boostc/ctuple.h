//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CTUPLE_H
#define BOOSTC__CTUPLE_H


#include <boostc/config.h>
#include <boostc/ctuple/detail.h>


/** Resolves the symbols in a ctuple and converts to a string. */
/// \{
#ifndef bstc_ctuple_tostring
# define bstc_ctuple_tostring(tpl) BSTC_TOSTRING(tpl)
#endif
/// \}


/** Packs variable arguments into a ctuple to be more explicit. */
/// \{
#ifndef bstc_ctuple
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_ctuple(...) (__VA_ARGS__)
# endif
#endif
/// \}


/** Expands a ctuple if called `bstc_ctuple_layout tpl`. */
/// \{
#ifndef bstc_ctuple_layout
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_ctuple_layout(...) __VA_ARGS__
# endif
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
# ifdef BSTC_ISA_TUPLE 
#  define bstc_ctuple_isa(tpl, _t, _f) BSTC_ISA_TUPLE(tpl, _t, _f)
# endif
#endif
/// \}


/** Gets the size of the ctuple and properly handles empty ctuples. */
/// \{
#ifndef bstc_ctuple_size
# if defined(bstc_ctuple_isa) && defined(BSTC_IF_ARG0_EMPTY) && defined(BSTC_IFEQ) && defined(BSTC_ARGCNT)
#  define bstc_dtl_ctuple_size_isa(tpl) BSTC_IF_ARG0_EMPTY(tpl, BSTC_IFEQ(BSTC_ARGCNT tpl, 1, 0, BSTC_ARGCNT tpl), BSTC_ARGCNT tpl)
#  define bstc_dtl_ctuple_size_nope(tpl) 0
#  define bstc_ctuple_size(tpl) bstc_ctuple_isa(tpl, bstc_dtl_ctuple_size_isa, bstc_dtl_ctuple_size_nope) (tpl)
# endif
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) == N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasN
# if defined(BSTC_IFEQ) && defined(bstc_ctuple_size)
#  define bstc_ctuple_hasN(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFEQ(bstc_ctuple_size(tpl), N, _t, _f))
# endif
#endif
/// \}


/** Selects the `_t` statement if the ctuple is empty and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_ifempty
# ifdef bstc_ctuple_hasN
#  define bstc_ctuple_ifempty(tpl, _t, _f) bstc_ctuple_hasN(tpl, 0, _t, _f)
# endif
#endif
/// \}


/** Selects the `_t` statement if the ctuple is truthy and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_if
# ifdef bstc_ctuple_ifempty
#  define bstc_ctuple_if(tpl, _t, _f) bstc_ctuple_ifempty(tpl, _f, _t)
# endif
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) > N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasGT
# if defined(BSTC_IFGT) && defined(bstc_ctuple_size)
#  define bstc_ctuple_hasGT(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFGT(bstc_ctuple_size(tpl), N, _t, _f))
# endif
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) <= N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasLTE
# if defined(BSTC_IFGT) && defined(bstc_ctuple_size)
#  define bstc_ctuple_hasLTE(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFGT(bstc_ctuple_size(tpl), N, _f, _t))
# endif
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) < N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasLT
# if defined(BSTC_IFLT) && defined(bstc_ctuple_size)
#  define bstc_ctuple_hasLT(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFLT(bstc_ctuple_size(tpl), N, _t, _f))
# endif
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) >= N` and the `_f` otherwise. */
/// \{
#ifndef bstc_ctuple_hasGTE
# if defined(BSTC_IFLT) && defined(bstc_ctuple_size)
#  define bstc_ctuple_hasGTE(tpl, N, _t, _f) BSTC_EXPAND(BSTC_IFLT(bstc_ctuple_size(tpl), N, _f, _t))
# endif
#endif
/// \}


/** Gets the Ith item in a ctuple then resolves to that value and will not compile if out-of-bounds. */
/// \{
#ifndef bstc_ctuple_getI
# if defined(bstc_ctuple_isa) && defined(bstc_ctuple_hasGT)
#  define bstc_ctuple_getI(tpl, I) \
    bstc_ctuple_isa(tpl,\
        bstc_ctuple_hasGT(tpl, I, bstc_ctuple_call(BSTC_JOIN2(BSTC_GET_ARG, I), tpl), BSTC_CTUPLE_OUT_OF_BOUNDS),\
        BSTC_CTUPLE_NOT_TUPLE\
    )
# endif
#endif
/// \}


/** Creates a new ctuple with the list of items added to the back. */
/// \{
#ifndef bstc_ctuple_append
# if defined(bstc_ctuple_ifempty) && defined(bstc_ctuple)
#  define bstc_ctuple_append(tpl, ...) \
    bstc_ctuple_ifempty(tpl,\
        bstc_ctuple(__VA_ARGS__),\
        bstc_ctuple_ifempty(bstc_ctuple(__VA_ARGS__),\
            tpl,\
            bstc_dtl_ctuple_append(tpl, __VA_ARGS__)\
        )\
    )
# endif
#endif
/// \}


/** Creates a new ctuple with the list of items added to the front. */
/// \{
#ifndef bstc_ctuple_prepend
# if defined(bstc_ctuple_ifempty) && defined(bstc_ctuple)
#  define bstc_ctuple_prepend(tpl, ...) \
    bstc_ctuple_ifempty(tpl,\
        bstc_ctuple(__VA_ARGS__),\
        bstc_ctuple_ifempty(bstc_ctuple(__VA_ARGS__),\
            tpl,\
            bstc_dtl_ctuple_prepend(tpl, __VA_ARGS__)\
        )\
    )
# endif
#endif
/// \}


/** Creates a new ctuple by concatenating the two ctuples provided. */
/// \{
#ifndef bstc_ctuple_concat
# if defined(bstc_ctuple_ifempty)
#  define bstc_ctuple_concat(ltpl, rtpl) \
    bstc_ctuple_ifempty(ltpl,\
        rtpl,\
        bstc_ctuple_ifempty(rtpl,\
            ltpl,\
            bstc_ctuple_call(bstc_dtl_ctuple_append, bstc_dtl_ctuple_prepend(rtpl, ltpl))\
        )\
    )
# endif
#endif
/// \}


/** Creates a new ctuple in reverse. */
/// \{
#ifndef bstc_ctuple_reverse
# if defined(bstc_ctuple) && defined(bstc_ctuple_size)
#  define bstc_ctuple_reverse(tpl) bstc_ctuple(bstc_ctuple_call(BSTC_JOIN2(bstc_dtl_ctuple_reverse, bstc_ctuple_size(tpl)), tpl))
# endif
#endif
/// \}


/** Creates a new ctuple and collects the first N cells. */
/// \{
#ifndef bstc_ctuple_collect
# if defined(BSTC_IFEQ) && defined(bstc_ctuple_hasGT) && defined(bstc_ctuple) && defined(bstc_ctuple_hasN)
#  define bstc_ctuple_collect(tpl, N) \
    BSTC_IFEQ(N, 0,\
        bstc_ctuple_empty(),\
        BSTC_IFEQ(N, 1,\
            bstc_ctuple(BSTC_GET_ARG0 tpl),\
            bstc_ctuple_hasGT(tpl, N,\
                bstc_ctuple(BSTC_CALL(BSTC_JOIN2(bstc_dtl_ctuple_collect, N), bstc_dtl_ctuple_collect_augmented(tpl))),\
                bstc_ctuple_hasN(tpl, N, tpl, BSTC_CTUPLE_OUT_OF_BOUNDS)\
            )\
        )\
    )
# endif
#endif
/// \}


/** Creates a new ctuple by removing the first N items. */
/// \{
#ifndef bstc_ctuple_ltrim
# if defined(BSTC_IFEQ)
#  define bstc_ctuple_ltrim(tpl, N) \
    BSTC_IFEQ(N, 0,\
        tpl,\
        bstc_dtl_ctuple_ltrim(tpl, N)\
    )
# endif
#endif
/// \}


/** Creates a new ctuple by removing the last N items. */
/// \{
#ifndef bstc_ctuple_rtrim
# if defined(BSTC_IFEQ) && defined(bstc_ctuple_reverse) && defined(bstc_ctuple_ltrim)
#  define bstc_ctuple_rtrim(tpl, N) \
    BSTC_IFEQ(N, 0,\
        tpl,\
        bstc_ctuple_reverse(bstc_ctuple_ltrim(bstc_ctuple_reverse(tpl), N))\
    )
# endif
#endif
/// \}


/** Creates a new ctuple and sets the value at the provided location. */
/// \{
#ifndef bstc_ctuple_setI
# if defined(BSTC_IFEQ) && defined(bstc_ctuple_hasN) && defined(bstc_ctuple_ltrim) && defined(bstc_ctuple) && defined(bstc_ctuple_collect) && defined(bstc_ctuple_prepend) && defined(bstc_ctuple_append)
#  define bstc_ctuple_setI(tpl, I, val) \
    BSTC_IFEQ(I, 0,\
        bstc_ctuple_hasN(tpl, 1, bstc_ctuple(val), bstc_ctuple_prepend(bstc_ctuple_ltrim(tpl, 1), val)),\
        bstc_ctuple_hasN(tpl, BSTC_CONST_ADD1(I), bstc_ctuple_append(bstc_ctuple_collect(tpl, I), val), bstc_dtl_ctuple_setI(tpl, I, val))\
    )
# endif
#endif
/// \}


#endif // BOOSTC__CTUPLE_H
