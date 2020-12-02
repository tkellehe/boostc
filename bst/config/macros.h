//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__MACROS_H
#define BST__CONFIG__MACROS_H


#ifdef __cplusplus
extern "C" {
#endif


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

#define ppack_argI bst_ppack_argI

#define ppack_ltrim bst_ppack_ltrim
#define ppack_rtrim bst_ppack_rtrim

#define ppack_defaults bst_ppack_defaults
#endif
/// \}


/* Provide a helper that allows for parameter packing and unpacking */
/// \{
#define bst_ppack(...) (__VA_ARGS__)
#define bst_unppack(...) __VA_ARGS__

#define bst_ppack_concat(lpkd, rpkd) bst_ppack_call(bst_ppack_append, bst_ppack_prepend(rpkd, lpkd))
#define bst_ppack_append(pkd, ...) (bst_unppack pkd, __VA_ARGS__)
#define bst_ppack_prepend(pkd, ...) (__VA_ARGS__, bst_unppack pkd)

#define bst_ppack_call(F, pkd) F pkd

#define bst_ppack_size(pkd) bst_dtl_ppack_size pkd

#define bst_ppack_reverse(pkd) (bst_ppack_call(BST_JOIN(bst_dtl_ppack_reverse, bst_ppack_size(pkd)), pkd))

#define bst_ppack_argI(pkd, I) bst_ppack_call(BST_JOIN(bst_dtl_ppack_arg, I), pkd)

#define bst_ppack_ltrim(pkd, N) (bst_ppack_call(BST_JOIN(bst_dtl_ltrim, N), pkd))
#define bst_ppack_rtrim(pkd, N) bst_ppack_reverse(bst_ppack_ltrim(bst_ppack_reverse(pkd), N))

#define bst_ppack_defaults(pkd, defaults) \
    bst_ppack_concat(pkd, bst_ppack_ltrim(defaults, bst_ppack_size(pkd)))
/// \}


/* Details for parameter packing */
/// \{
#define bst_dtl_ppack_size(...) BST_NARG(__VA_ARGS__)

#define bst_dtl_ppack_arg0(_0, ...) _0
#define bst_dtl_ppack_arg1(_0, ...) bst_dtl_ppack_arg0(__VA_ARGS__)
#define bst_dtl_ppack_arg2(_0, ...) bst_dtl_ppack_arg1(__VA_ARGS__)
#define bst_dtl_ppack_arg3(_0, ...) bst_dtl_ppack_arg2(__VA_ARGS__)
#define bst_dtl_ppack_arg4(_0, ...) bst_dtl_ppack_arg3(__VA_ARGS__)
#define bst_dtl_ppack_arg5(_0, ...) bst_dtl_ppack_arg4(__VA_ARGS__)
#define bst_dtl_ppack_arg6(_0, ...) bst_dtl_ppack_arg5(__VA_ARGS__)
#define bst_dtl_ppack_arg7(_0, ...) bst_dtl_ppack_arg6(__VA_ARGS__)
#define bst_dtl_ppack_arg8(_0, ...) bst_dtl_ppack_arg7(__VA_ARGS__)
#define bst_dtl_ppack_arg9(_0, ...) bst_dtl_ppack_arg8(__VA_ARGS__)

#define bst_dtl_ppack_reverse0()
#define bst_dtl_ppack_reverse1(_0) _0
#define bst_dtl_ppack_reverse2(_0, _1) _1, _0
#define bst_dtl_ppack_reverse3(_0, ...) bst_dtl_ppack_reverse2(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse4(_0, ...) bst_dtl_ppack_reverse3(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse5(_0, ...) bst_dtl_ppack_reverse4(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse6(_0, ...) bst_dtl_ppack_reverse5(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse7(_0, ...) bst_dtl_ppack_reverse6(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse8(_0, ...) bst_dtl_ppack_reverse7(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse9(_0, ...) bst_dtl_ppack_reverse8(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse10(_0, ...) bst_dtl_ppack_reverse9(__VA_ARGS__), _0

#define bst_dtl_ltrim0(...) __VA_ARGS__
#define bst_dtl_ltrim1(_0, ...) bst_dtl_ltrim0(__VA_ARGS__)
#define bst_dtl_ltrim2(_0, ...) bst_dtl_ltrim1(__VA_ARGS__)
#define bst_dtl_ltrim3(_0, ...) bst_dtl_ltrim2(__VA_ARGS__)
#define bst_dtl_ltrim4(_0, ...) bst_dtl_ltrim3(__VA_ARGS__)
#define bst_dtl_ltrim5(_0, ...) bst_dtl_ltrim4(__VA_ARGS__)
#define bst_dtl_ltrim6(_0, ...) bst_dtl_ltrim5(__VA_ARGS__)
#define bst_dtl_ltrim7(_0, ...) bst_dtl_ltrim6(__VA_ARGS__)
#define bst_dtl_ltrim8(_0, ...) bst_dtl_ltrim7(__VA_ARGS__)
#define bst_dtl_ltrim9(_0, ...) bst_dtl_ltrim8(__VA_ARGS__)
#define bst_dtl_ltrim10(_0, ...) bst_dtl_ltrim9(__VA_ARGS__)
/// \}


/* Provide a helper that joins two symbols */
/// \{
#define BST_DTL_JOIN(L, R) L ## R
#define BST_JOIN(L, R) BST_DTL_JOIN(L, R)
/// \}


/* Provide a helper that allows for counting the number of parameters passed to a variadic macro */
/// \{
#define BST_NARG(...) \
         BST_DTL_NARG(__VA_ARGS__, BST_DTL_SEQ())
#define BST_DTL_NARG(...) \
         BST_DTL_ARGN(__VA_ARGS__)
#define BST_DTL_ARGN( \
         _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
        _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
        _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
        _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
        _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
        _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, \
        _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, \
        _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, \
        _91, _92, _93, _94, _95, _96, _97, _98, _99,  N, ...) N
#define BST_DTL_SEQ() \
        99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
        89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
        79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
        69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
         9,  8,  7,  6,  5,  4,  3,  2,  1,  0
/// \}


/* Provide a helper that assist with variadic parameter default values */
/// \{
#define BST_ARGS1(_0, ...) _0
#define BST_ARGS2(_0, ...) _0, BST_ARGS1(__VA_ARGS__)
#define BST_ARGS3(_0, ...) _0, BST_ARGS2(__VA_ARGS__)
#define BST_ARGS4(_0, ...) _0, BST_ARGS3(__VA_ARGS__)
#define BST_ARGS5(_0, ...) _0, BST_ARGS4(__VA_ARGS__)
#define BST_ARGS6(_0, ...) _0, BST_ARGS5(__VA_ARGS__)
#define BST_ARGS7(_0, ...) _0, BST_ARGS6(__VA_ARGS__)
#define BST_ARGS8(_0, ...) _0, BST_ARGS7(__VA_ARGS__)
#define BST_ARGS9(_0, ...) _0, BST_ARGS8(__VA_ARGS__)
#define BST_ARGS10(_0, ...) _0, BST_ARGS9(__VA_ARGS__)

#define BST_X1ARGS1(_0, ...) BST_ARGS1(__VA_ARGS__)
#define BST_X1ARGS2(_0, ...) BST_ARGS2(__VA_ARGS__)
#define BST_X1ARGS3(_0, ...) BST_ARGS3(__VA_ARGS__)
#define BST_X1ARGS4(_0, ...) BST_ARGS4(__VA_ARGS__)
#define BST_X1ARGS5(_0, ...) BST_ARGS5(__VA_ARGS__)
#define BST_X1ARGS6(_0, ...) BST_ARGS6(__VA_ARGS__)
#define BST_X1ARGS7(_0, ...) BST_ARGS7(__VA_ARGS__)
#define BST_X1ARGS8(_0, ...) BST_ARGS8(__VA_ARGS__)
#define BST_X1ARGS9(_0, ...) BST_ARGS9(__VA_ARGS__)
#define BST_X1ARGS10(_0, ...) BST_ARGS10(__VA_ARGS__)
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__CONFIG__MACROS_H
