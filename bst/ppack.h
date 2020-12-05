//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__PPACK_H
#define BST__PPACK_H


#include <bst/config.h>
#include <bst/detail/ppack.h>


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define ppack bst_ppack
#define unppack bst_unppack

#define ppack_concat bst_ppack_concat
#define ppack_append bst_ppack_append
#define ppack_prepend bst_ppack_prepend

#define ppack_call bst_ppack_call

#define ppack_size bst_ppack_size

#define ppack_reverse bst_ppack_reverse

#define ppack_getI bst_ppack_getI

#define ppack_ltrim bst_ppack_ltrim
#define ppack_rtrim bst_ppack_rtrim
#define ppack_collect bst_ppack_collect

#define ppack_defaults bst_ppack_defaults
#define ppack_defargs bst_ppack_defargs

#define ppack_truthy bst_ppack_truthy
#define ppack_falsy bst_ppack_falsy

#define ppack_if bst_ppack_if
#define ppack_isa bst_ppack_isa
#define ppack_empty bst_ppack_empty
#define ppack_hasGT bst_ppack_hasGT
#define ppack_hasLTE bst_ppack_hasLTE
#define ppack_hasN bst_ppack_hasN
#define ppack_hasLT bst_ppack_hasLT
#define ppack_hasGTE bst_ppack_hasGTE

#define ppack_setI bst_ppack_setI

#define ppack_tostring bst_ppack_tostring
#endif
/// \}


/* Provide a helper that allows for parameter packing and unpacking */
/// \{
#define bst_ppack(...) (__VA_ARGS__)
#define bst_unppack(...) __VA_ARGS__

#define bst_ppack_concat(lpkd, rpkd) \
    bst_ppack_empty(lpkd,\
        rpkd,\
        bst_ppack_empty(rpkd,\
            lpkd,\
            bst_ppack_call(bst_dtl_ppack_append, bst_dtl_ppack_prepend(rpkd, lpkd))\
        )\
    )
#define bst_ppack_append(pkd, ...) \
    bst_ppack_empty(pkd,\
        bst_ppack(__VA_ARGS__),\
        bst_ppack_empty(bst_ppack(__VA_ARGS__),\
            pkd,\
            bst_dtl_ppack_append(pkd, __VA_ARGS__)\
        )\
    )
#define bst_ppack_prepend(pkd, ...) \
    bst_ppack_empty(pkd,\
        bst_ppack(__VA_ARGS__),\
        bst_ppack_empty(bst_ppack(__VA_ARGS__),\
            pkd,\
            bst_dtl_ppack_prepend(pkd, __VA_ARGS__)\
        )\
    )

#define bst_ppack_call(F, pkd) F pkd

#define bst_ppack_size(pkd) bst_ppack_call(bst_dtl_ppack_size, pkd)

#define bst_ppack_reverse(pkd) bst_ppack(bst_ppack_call(BST_JOIN2(bst_dtl_ppack_reverse, bst_ppack_size(pkd)), pkd))

#define bst_ppack_getI(pkd, I) bst_ppack_call(BST_JOIN2(bst_dtl_ppack_get, I), pkd)

#define bst_ppack_ltrim(pkd, N) bst_ppack(bst_ppack_call(BST_JOIN2(bst_dtl_ppack_ltrim, N), pkd))
#define bst_ppack_rtrim(pkd, N) bst_ppack_reverse(bst_ppack_ltrim(bst_ppack_reverse(pkd), N))
#define bst_ppack_collect(pkd, N) bst_ppack(bst_ppack_call(BST_JOIN2(bst_dtl_ppack_collect, N), pkd))

#define bst_ppack_defaults(pkd, defaults) \
    bst_ppack_empty(pkd,\
        defaults,\
        bst_ppack_collect(bst_ppack_concat(pkd, bst_ppack_ltrim(defaults, bst_ppack_size(pkd))), bst_ppack_size(defaults))\
    )

#define bst_ppack_defargs(pkd_args, pkd_defaults) bst_dtl_ppack_defargs(bst_ppack_defaults(pkd_args, pkd_defaults))

#define bst_ppack_truthy(...) (0)
#define bst_ppack_falsy(...) ()

#define bst_ppack_if(pkd, _t, _f) BST_JOIN2(bst_dtl_ppack_if, bst_dtl_ppack_if(pkd))(_t, _f)

// If it is a ppack, then it will call the function else will just be some random symbol.
#define bst_ppack_isa(pkd, _t, _f) BST_JOIN2(bst_dtl_ppack_isa, bst_ppack_size(bst_ppack(0, bst_dtl_ppack_isa_expand pkd)))(_t, _f)

#define bst_ppack_empty(pkd, _t, _f) bst_ppack_hasN(pkd, 0, _t, _f)
#define bst_ppack_hasGT(pkd, N, _t, _f) bst_ppack_if(bst_ppack_ltrim(pkd, N), _t, _f)
#define bst_ppack_hasLTE(pkd, N, _t, _f) bst_ppack_hasGT(pkd, N, _f, _t)
#define bst_ppack_hasN(pkd, N, _t, _f) bst_ppack_hasGT(pkd, N, _f, bst_ppack_hasGT(pkd, bst_dtl_ppack_const_sub1(N), _t, _f))
#define bst_ppack_hasLT(pkd, N, _t, _f) bst_ppack_hasLTE(pkd, N, bst_ppack_hasN(pkd, N, _f, _t), _f)
#define bst_ppack_hasGTE(pkd, N, _t, _f) bst_ppack_hasGT(pkd, N, _t, bst_ppack_hasN(pkd, N, _t, _f))

#define bst_ppack_setI(pkd, I, val) bst_ppack_concat(bst_ppack_append(bst_ppack_collect(pkd, I), val), bst_ppack_ltrim(pkd, bst_dtl_ppack_const_add1(I)))

#define bst_ppack_tostring(pkd) BST_TOSTRING(pkd)
/// \}


#endif // BST__PPACK_H
