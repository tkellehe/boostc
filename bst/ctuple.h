//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <bst/config.h>
#include <bst/detail/ctuple.h>


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
# ifndef ctuple_tostring
#  define ctuple_tostring bst_ctuple_tostring
# endif

# ifndef ctuple
#  define ctuple bst_ctuple
# endif
# ifndef ctuple_expand
#  define ctuple_expand bst_ctuple_expand
# endif
# ifndef ctuple_empty
#  define ctuple_empty bst_ctuple_empty
# endif
# ifndef ctuple_call
#  define ctuple_call bst_ctuple_call
# endif

# ifndef ctuple_isa
#  define ctuple_isa bst_ctuple_isa
# endif

# ifndef ctuple_if
#  define ctuple_if bst_ctuple_if
# endif
# ifndef ctuple_ifempty
#  define ctuple_ifempty bst_ctuple_ifempty
# endif
# ifndef ctuple_hasGT
#  define ctuple_hasGT bst_ctuple_hasGT
# endif
# ifndef ctuple_hasLTE
#  define ctuple_hasLTE bst_ctuple_hasLTE
# endif
# ifndef ctuple_hasN
#  define ctuple_hasN bst_ctuple_hasN
# endif
# ifndef ctuple_hasLT
#  define ctuple_hasLT bst_ctuple_hasLT
# endif
# ifndef ctuple_hasGTE
#  define ctuple_hasGTE bst_ctuple_hasGTE
# endif

# ifndef ctuple_size
#  define ctuple_size bst_ctuple_size
# endif

# ifndef ctuple_getI
#  define ctuple_getI bst_ctuple_getI
# endif

# ifndef ctuple_concat
#  define ctuple_concat bst_ctuple_concat
# endif
# ifndef ctuple_append
#  define ctuple_append bst_ctuple_append
# endif
# ifndef ctuple_prepend
#  define ctuple_prepend bst_ctuple_prepend
# endif

# ifndef ctuple_reverse
#  define ctuple_reverse bst_ctuple_reverse
# endif

# ifndef ctuple_ltrim
#  define ctuple_ltrim bst_ctuple_ltrim
# endif
# ifndef ctuple_rtrim
#  define ctuple_rtrim bst_ctuple_rtrim
# endif
# ifndef ctuple_collect
#  define ctuple_collect bst_ctuple_collect
# endif

# ifndef ctuple_setI
#  define ctuple_setI bst_ctuple_setI
# endif
#endif
/// \}


/** Resolves the symbols in a ctuple and converts to a string. */
/// \{
#ifndef bst_ctuple_tostring
# define bst_ctuple_tostring(tpl) BST_TOSTRING(tpl)
#endif
/// \}


/** Packs variable arguments into a ctuple to be more explicit. */
/// \{
#ifndef bst_ctuple
# define bst_ctuple(...) (__VA_ARGS__)
#endif
/// \}


/** Expands a ctuple if called `bst_ctuple_expand tpl`. */
/// \{
#ifndef bst_ctuple_expand
# define bst_ctuple_expand(...) __VA_ARGS__
#endif
/// \}


/** Expands a ctuple if called `bst_ctuple_expand tpl`. */
/// \{
#ifndef bst_ctuple_empty
# define bst_ctuple_empty() ()
#endif
/// \}


/** Calls the function with the provided ctuple. */
/// \{
#ifndef bst_ctuple_call
# define bst_ctuple_call(F, tpl) BST_EXPAND(F tpl)
#endif
/// \}


/** Determines if the provided argument is a ctuple. */
/// \{
#ifndef bst_ctuple_isa
# define bst_ctuple_isa(tpl, _t, _f) BST_ISA_TUPLE(tpl, _t, _f)
#endif
/// \}

/** Selects the `_t` statement if the ctuple is truthy and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_if
# define bst_ctuple_if(tpl, _t, _f) bst_ctuple_ifempty(tpl, _f, _t)
#endif
/// \}


/** Selects the `_t` statement if the ctuple is empty and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_ifempty
# define bst_ctuple_ifempty(tpl, _t, _f) bst_ctuple_hasN(tpl, 0, _t, _f)
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) > N` and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_hasGT
# define bst_ctuple_hasGT(tpl, N, _t, _f) BST_EXPAND(BST_IFGT(bst_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) <= N` and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_hasLTE
# define bst_ctuple_hasLTE(tpl, N, _t, _f) BST_EXPAND(BST_IFGT(bst_ctuple_size(tpl), N, _f, _t))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) == N` and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_hasN
# define bst_ctuple_hasN(tpl, N, _t, _f) BST_EXPAND(BST_IFEQ(bst_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) < N` and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_hasLT
# define bst_ctuple_hasLT(tpl, N, _t, _f) BST_EXPAND(BST_IFLT(bst_ctuple_size(tpl), N, _t, _f))
#endif
/// \}


/** Selects the `_t` statement if `size(tpl) >= N` and the `_f` otherwise. */
/// \{
#ifndef bst_ctuple_hasGTE
# define bst_ctuple_hasGTE(tpl, N, _t, _f) BST_EXPAND(BST_IFLT(bst_ctuple_size(tpl), N, _f, _t))
#endif
/// \}

/** Gets the size of the ctuple and properly handles empty ctuples. */
/// \{
#ifndef bst_ctuple_size
# define bst_ctuple_size(tpl) bst_ctuple_isa(tpl, BST_IF_ARG0_EMPTY(tpl, BST_IFEQ(BST_ARGCNT tpl, 1, 0, BST_ARGCNT tpl), BST_ARGCNT tpl), 0)
#endif
/// \}

/**  */
/// \{
#ifndef bst_ctuple_getI
# define bst_ctuple_getI(tpl, I) \
    bst_ctuple_isa(tpl,\
        bst_ctuple_hasGT(tpl, I, bst_ctuple_call(BST_JOIN2(BST_GET_ARG, I), tpl), BST_CTUPLE_OUT_OF_BOUNDS),\
        BST_CTUPLE_NOT_TUPLE\
    )
#endif
/// \}

/* Provide a helper that allows for parameter packing and unpacking */
/// \{
/*
#define bst_ctuple_concat(ltpl, rtpl) \
    bst_ctuple_ifempty(ltpl,\
        rtpl,\
        bst_ctuple_ifempty(rtpl,\
            ltpl,\
            bst_ctuple_call(bst_dtl_ctuple_append, bst_dtl_ctuple_prepend(rtpl, ltpl))\
        )\
    )
#define bst_ctuple_append(tpl, ...) \
    bst_ctuple_ifempty(tpl,\
        bst_ctuple(__VA_ARGS__),\
        bst_ctuple_ifempty(bst_ctuple(__VA_ARGS__),\
            tpl,\
            bst_dtl_ctuple_append(tpl, __VA_ARGS__)\
        )\
    )
#define bst_ctuple_prepend(tpl, ...) \
    bst_ctuple_ifempty(tpl,\
        bst_ctuple(__VA_ARGS__),\
        bst_ctuple_ifempty(bst_ctuple(__VA_ARGS__),\
            tpl,\
            bst_dtl_ctuple_prepend(tpl, __VA_ARGS__)\
        )\
    )
*/
#define bst_ctuple_concat(ltpl, rtpl) bst_ctuple_call(bst_dtl_ctuple_append, bst_dtl_ctuple_prepend(rtpl, ltpl))
#define bst_ctuple_append(tpl, ...) bst_dtl_ctuple_append(tpl, __VA_ARGS__)
#define bst_ctuple_prepend(tpl, ...) bst_dtl_ctuple_prepend(tpl, __VA_ARGS__)

#define bst_ctuple_reverse(tpl) bst_ctuple(bst_ctuple_call(BST_JOIN2(bst_dtl_ctuple_reverse, bst_ctuple_size(tpl)), tpl))

#define bst_ctuple_ltrim(tpl, N) bst_ctuple(bst_ctuple_call(BST_JOIN2(bst_dtl_ctuple_ltrim, N), tpl))
#define bst_ctuple_rtrim(tpl, N) bst_ctuple_reverse(bst_ctuple_ltrim(bst_ctuple_reverse(tpl), N))
#define bst_ctuple_collect(tpl, N) bst_ctuple(bst_ctuple_call(BST_JOIN2(bst_dtl_ctuple_collect, N), tpl))

#define bst_ctuple_setI(tpl, I, val) \
    bst_ctuple_hasN(tpl, BST_CONST_ADD1(I),\
        bst_ctuple_hasN(tpl, 1,\
            bst_ctuple(val),\
            bst_ctuple_append(bst_ctuple_collect(tpl, I), val)\
        ),\
        bst_ctuple_concat(bst_ctuple_append(bst_ctuple_collect(tpl, I), val), bst_ctuple_ltrim(tpl, BST_CONST_ADD1(I)))\
    )
/// \}
