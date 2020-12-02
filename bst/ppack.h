//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__PPACK_H
#define BST__PPACK_H


#include <bst/config.h>


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


#define ppack_truthy bst_ppack_truthy
#define ppack_falsey bst_ppack_falsey

#define ppack_if bst_ppack_if
#define ppack_is bst_ppack_is
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

#define bst_ppack_size(pkd) bst_ppack_call(bst_dtl_ppack_size, pkd)

#define bst_ppack_reverse(pkd) (bst_ppack_call(BST_JOIN(bst_dtl_ppack_reverse, bst_ppack_size(pkd)), pkd))

#define bst_ppack_argI(pkd, I) bst_ppack_call(BST_JOIN(bst_dtl_ppack_arg, I), pkd)

#define bst_ppack_ltrim(pkd, N) (bst_ppack_call(BST_JOIN(bst_dtl_ppack_ltrim, N), pkd))
#define bst_ppack_rtrim(pkd, N) bst_ppack_reverse(bst_ppack_ltrim(bst_ppack_reverse(pkd), N))

#define bst_ppack_defaults(pkd, defaults) \
    bst_ppack_concat(pkd, bst_ppack_ltrim(defaults, bst_ppack_size(pkd)))

#define bst_ppack_truthy(...) (0)
#define bst_ppack_falsey(...) ()

#define bst_ppack_if(pkd, _t, _f) BST_JOIN(bst_dtl_ppack_if, bst_dtl_ppack_if(pkd))(_t, _f)

// If it is a ppack, then it will call the function else will just be some random symbol.
#define bst_ppack_is(pkd, _t, _f) BST_JOIN(bst_dtl_ppack_is, bst_ppack_size(bst_ppack(0, bst_dtl_ppack_is_expand pkd)))(_t, _f)
/// \}


/* Details for parameter packing */
/// \{
#define bst_dtl_ppack_if(pkd) bst_dtl_ppack_if_eval pkd
#define bst_dtl_ppack_if_eval(...) bst_dtl_ppack_grab(0, ##__VA_ARGS__, bst_dtl_ppack_if_ones())
#define bst_dtl_ppack_if0(_t, _f) _f
#define bst_dtl_ppack_if1(_t, _f) _t

#define bst_dtl_ppack_is2(_t, _f) _f
#define bst_dtl_ppack_is3(_t, _f) _t
#define bst_dtl_ppack_is_expand(...) 0, 0

// The algorithm for counting the arguments comes back as one if nothing is provided.
// Therein by adding one to the ppack that is being sized, we just reduce all of the values by one.
#define bst_dtl_ppack_size(...) bst_dtl_ppack_grab(0, ##__VA_ARGS__, bst_dtl_ppack_size_seq())
#define bst_dtl_ppack_grab(...) bst_dtl_ppack_arg100(__VA_ARGS__)
#define bst_dtl_ppack_size_seq() \
        99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
        89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
        79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
        69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
         9,  8,  7,  6,  5,  4,  3,  2,  1,  0, 0
#define bst_dtl_ppack_if_ones() \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0

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
#define bst_dtl_ppack_arg10(_0, ...) bst_dtl_ppack_arg9(__VA_ARGS__)
#define bst_dtl_ppack_arg11(_0, ...) bst_dtl_ppack_arg10(__VA_ARGS__)
#define bst_dtl_ppack_arg12(_0, ...) bst_dtl_ppack_arg11(__VA_ARGS__)
#define bst_dtl_ppack_arg13(_0, ...) bst_dtl_ppack_arg12(__VA_ARGS__)
#define bst_dtl_ppack_arg14(_0, ...) bst_dtl_ppack_arg13(__VA_ARGS__)
#define bst_dtl_ppack_arg15(_0, ...) bst_dtl_ppack_arg14(__VA_ARGS__)
#define bst_dtl_ppack_arg16(_0, ...) bst_dtl_ppack_arg15(__VA_ARGS__)
#define bst_dtl_ppack_arg17(_0, ...) bst_dtl_ppack_arg16(__VA_ARGS__)
#define bst_dtl_ppack_arg18(_0, ...) bst_dtl_ppack_arg17(__VA_ARGS__)
#define bst_dtl_ppack_arg19(_0, ...) bst_dtl_ppack_arg18(__VA_ARGS__)
#define bst_dtl_ppack_arg20(_0, ...) bst_dtl_ppack_arg19(__VA_ARGS__)
#define bst_dtl_ppack_arg21(_0, ...) bst_dtl_ppack_arg20(__VA_ARGS__)
#define bst_dtl_ppack_arg22(_0, ...) bst_dtl_ppack_arg21(__VA_ARGS__)
#define bst_dtl_ppack_arg23(_0, ...) bst_dtl_ppack_arg22(__VA_ARGS__)
#define bst_dtl_ppack_arg24(_0, ...) bst_dtl_ppack_arg23(__VA_ARGS__)
#define bst_dtl_ppack_arg25(_0, ...) bst_dtl_ppack_arg24(__VA_ARGS__)
#define bst_dtl_ppack_arg26(_0, ...) bst_dtl_ppack_arg25(__VA_ARGS__)
#define bst_dtl_ppack_arg27(_0, ...) bst_dtl_ppack_arg26(__VA_ARGS__)
#define bst_dtl_ppack_arg28(_0, ...) bst_dtl_ppack_arg27(__VA_ARGS__)
#define bst_dtl_ppack_arg29(_0, ...) bst_dtl_ppack_arg28(__VA_ARGS__)
#define bst_dtl_ppack_arg30(_0, ...) bst_dtl_ppack_arg29(__VA_ARGS__)
#define bst_dtl_ppack_arg31(_0, ...) bst_dtl_ppack_arg30(__VA_ARGS__)
#define bst_dtl_ppack_arg32(_0, ...) bst_dtl_ppack_arg31(__VA_ARGS__)
#define bst_dtl_ppack_arg33(_0, ...) bst_dtl_ppack_arg32(__VA_ARGS__)
#define bst_dtl_ppack_arg34(_0, ...) bst_dtl_ppack_arg33(__VA_ARGS__)
#define bst_dtl_ppack_arg35(_0, ...) bst_dtl_ppack_arg34(__VA_ARGS__)
#define bst_dtl_ppack_arg36(_0, ...) bst_dtl_ppack_arg35(__VA_ARGS__)
#define bst_dtl_ppack_arg37(_0, ...) bst_dtl_ppack_arg36(__VA_ARGS__)
#define bst_dtl_ppack_arg38(_0, ...) bst_dtl_ppack_arg37(__VA_ARGS__)
#define bst_dtl_ppack_arg39(_0, ...) bst_dtl_ppack_arg38(__VA_ARGS__)
#define bst_dtl_ppack_arg40(_0, ...) bst_dtl_ppack_arg39(__VA_ARGS__)
#define bst_dtl_ppack_arg41(_0, ...) bst_dtl_ppack_arg40(__VA_ARGS__)
#define bst_dtl_ppack_arg42(_0, ...) bst_dtl_ppack_arg41(__VA_ARGS__)
#define bst_dtl_ppack_arg43(_0, ...) bst_dtl_ppack_arg42(__VA_ARGS__)
#define bst_dtl_ppack_arg44(_0, ...) bst_dtl_ppack_arg43(__VA_ARGS__)
#define bst_dtl_ppack_arg45(_0, ...) bst_dtl_ppack_arg44(__VA_ARGS__)
#define bst_dtl_ppack_arg46(_0, ...) bst_dtl_ppack_arg45(__VA_ARGS__)
#define bst_dtl_ppack_arg47(_0, ...) bst_dtl_ppack_arg46(__VA_ARGS__)
#define bst_dtl_ppack_arg48(_0, ...) bst_dtl_ppack_arg47(__VA_ARGS__)
#define bst_dtl_ppack_arg49(_0, ...) bst_dtl_ppack_arg48(__VA_ARGS__)
#define bst_dtl_ppack_arg50(_0, ...) bst_dtl_ppack_arg49(__VA_ARGS__)
#define bst_dtl_ppack_arg51(_0, ...) bst_dtl_ppack_arg50(__VA_ARGS__)
#define bst_dtl_ppack_arg52(_0, ...) bst_dtl_ppack_arg51(__VA_ARGS__)
#define bst_dtl_ppack_arg53(_0, ...) bst_dtl_ppack_arg52(__VA_ARGS__)
#define bst_dtl_ppack_arg54(_0, ...) bst_dtl_ppack_arg53(__VA_ARGS__)
#define bst_dtl_ppack_arg55(_0, ...) bst_dtl_ppack_arg54(__VA_ARGS__)
#define bst_dtl_ppack_arg56(_0, ...) bst_dtl_ppack_arg55(__VA_ARGS__)
#define bst_dtl_ppack_arg57(_0, ...) bst_dtl_ppack_arg56(__VA_ARGS__)
#define bst_dtl_ppack_arg58(_0, ...) bst_dtl_ppack_arg57(__VA_ARGS__)
#define bst_dtl_ppack_arg59(_0, ...) bst_dtl_ppack_arg58(__VA_ARGS__)
#define bst_dtl_ppack_arg60(_0, ...) bst_dtl_ppack_arg59(__VA_ARGS__)
#define bst_dtl_ppack_arg61(_0, ...) bst_dtl_ppack_arg60(__VA_ARGS__)
#define bst_dtl_ppack_arg62(_0, ...) bst_dtl_ppack_arg61(__VA_ARGS__)
#define bst_dtl_ppack_arg63(_0, ...) bst_dtl_ppack_arg62(__VA_ARGS__)
#define bst_dtl_ppack_arg64(_0, ...) bst_dtl_ppack_arg63(__VA_ARGS__)
#define bst_dtl_ppack_arg65(_0, ...) bst_dtl_ppack_arg64(__VA_ARGS__)
#define bst_dtl_ppack_arg66(_0, ...) bst_dtl_ppack_arg65(__VA_ARGS__)
#define bst_dtl_ppack_arg67(_0, ...) bst_dtl_ppack_arg66(__VA_ARGS__)
#define bst_dtl_ppack_arg68(_0, ...) bst_dtl_ppack_arg67(__VA_ARGS__)
#define bst_dtl_ppack_arg69(_0, ...) bst_dtl_ppack_arg68(__VA_ARGS__)
#define bst_dtl_ppack_arg70(_0, ...) bst_dtl_ppack_arg69(__VA_ARGS__)
#define bst_dtl_ppack_arg71(_0, ...) bst_dtl_ppack_arg70(__VA_ARGS__)
#define bst_dtl_ppack_arg72(_0, ...) bst_dtl_ppack_arg71(__VA_ARGS__)
#define bst_dtl_ppack_arg73(_0, ...) bst_dtl_ppack_arg72(__VA_ARGS__)
#define bst_dtl_ppack_arg74(_0, ...) bst_dtl_ppack_arg73(__VA_ARGS__)
#define bst_dtl_ppack_arg75(_0, ...) bst_dtl_ppack_arg74(__VA_ARGS__)
#define bst_dtl_ppack_arg76(_0, ...) bst_dtl_ppack_arg75(__VA_ARGS__)
#define bst_dtl_ppack_arg77(_0, ...) bst_dtl_ppack_arg76(__VA_ARGS__)
#define bst_dtl_ppack_arg78(_0, ...) bst_dtl_ppack_arg77(__VA_ARGS__)
#define bst_dtl_ppack_arg79(_0, ...) bst_dtl_ppack_arg78(__VA_ARGS__)
#define bst_dtl_ppack_arg80(_0, ...) bst_dtl_ppack_arg79(__VA_ARGS__)
#define bst_dtl_ppack_arg81(_0, ...) bst_dtl_ppack_arg80(__VA_ARGS__)
#define bst_dtl_ppack_arg82(_0, ...) bst_dtl_ppack_arg81(__VA_ARGS__)
#define bst_dtl_ppack_arg83(_0, ...) bst_dtl_ppack_arg82(__VA_ARGS__)
#define bst_dtl_ppack_arg84(_0, ...) bst_dtl_ppack_arg83(__VA_ARGS__)
#define bst_dtl_ppack_arg85(_0, ...) bst_dtl_ppack_arg84(__VA_ARGS__)
#define bst_dtl_ppack_arg86(_0, ...) bst_dtl_ppack_arg85(__VA_ARGS__)
#define bst_dtl_ppack_arg87(_0, ...) bst_dtl_ppack_arg86(__VA_ARGS__)
#define bst_dtl_ppack_arg88(_0, ...) bst_dtl_ppack_arg87(__VA_ARGS__)
#define bst_dtl_ppack_arg89(_0, ...) bst_dtl_ppack_arg88(__VA_ARGS__)
#define bst_dtl_ppack_arg90(_0, ...) bst_dtl_ppack_arg89(__VA_ARGS__)
#define bst_dtl_ppack_arg91(_0, ...) bst_dtl_ppack_arg90(__VA_ARGS__)
#define bst_dtl_ppack_arg92(_0, ...) bst_dtl_ppack_arg91(__VA_ARGS__)
#define bst_dtl_ppack_arg93(_0, ...) bst_dtl_ppack_arg92(__VA_ARGS__)
#define bst_dtl_ppack_arg94(_0, ...) bst_dtl_ppack_arg93(__VA_ARGS__)
#define bst_dtl_ppack_arg95(_0, ...) bst_dtl_ppack_arg94(__VA_ARGS__)
#define bst_dtl_ppack_arg96(_0, ...) bst_dtl_ppack_arg95(__VA_ARGS__)
#define bst_dtl_ppack_arg97(_0, ...) bst_dtl_ppack_arg96(__VA_ARGS__)
#define bst_dtl_ppack_arg98(_0, ...) bst_dtl_ppack_arg97(__VA_ARGS__)
#define bst_dtl_ppack_arg99(_0, ...) bst_dtl_ppack_arg98(__VA_ARGS__)
#define bst_dtl_ppack_arg100(_0, ...) bst_dtl_ppack_arg99(__VA_ARGS__)


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
#define bst_dtl_ppack_reverse11(_0, ...) bst_dtl_ppack_reverse10(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse12(_0, ...) bst_dtl_ppack_reverse11(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse13(_0, ...) bst_dtl_ppack_reverse12(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse14(_0, ...) bst_dtl_ppack_reverse13(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse15(_0, ...) bst_dtl_ppack_reverse14(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse16(_0, ...) bst_dtl_ppack_reverse15(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse17(_0, ...) bst_dtl_ppack_reverse16(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse18(_0, ...) bst_dtl_ppack_reverse17(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse19(_0, ...) bst_dtl_ppack_reverse18(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse20(_0, ...) bst_dtl_ppack_reverse19(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse21(_0, ...) bst_dtl_ppack_reverse20(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse22(_0, ...) bst_dtl_ppack_reverse21(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse23(_0, ...) bst_dtl_ppack_reverse22(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse24(_0, ...) bst_dtl_ppack_reverse23(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse25(_0, ...) bst_dtl_ppack_reverse24(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse26(_0, ...) bst_dtl_ppack_reverse25(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse27(_0, ...) bst_dtl_ppack_reverse26(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse28(_0, ...) bst_dtl_ppack_reverse27(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse29(_0, ...) bst_dtl_ppack_reverse28(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse30(_0, ...) bst_dtl_ppack_reverse29(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse31(_0, ...) bst_dtl_ppack_reverse30(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse32(_0, ...) bst_dtl_ppack_reverse31(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse33(_0, ...) bst_dtl_ppack_reverse32(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse34(_0, ...) bst_dtl_ppack_reverse33(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse35(_0, ...) bst_dtl_ppack_reverse34(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse36(_0, ...) bst_dtl_ppack_reverse35(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse37(_0, ...) bst_dtl_ppack_reverse36(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse38(_0, ...) bst_dtl_ppack_reverse37(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse39(_0, ...) bst_dtl_ppack_reverse38(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse40(_0, ...) bst_dtl_ppack_reverse39(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse41(_0, ...) bst_dtl_ppack_reverse40(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse42(_0, ...) bst_dtl_ppack_reverse41(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse43(_0, ...) bst_dtl_ppack_reverse42(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse44(_0, ...) bst_dtl_ppack_reverse43(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse45(_0, ...) bst_dtl_ppack_reverse44(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse46(_0, ...) bst_dtl_ppack_reverse45(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse47(_0, ...) bst_dtl_ppack_reverse46(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse48(_0, ...) bst_dtl_ppack_reverse47(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse49(_0, ...) bst_dtl_ppack_reverse48(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse50(_0, ...) bst_dtl_ppack_reverse49(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse51(_0, ...) bst_dtl_ppack_reverse50(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse52(_0, ...) bst_dtl_ppack_reverse51(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse53(_0, ...) bst_dtl_ppack_reverse52(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse54(_0, ...) bst_dtl_ppack_reverse53(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse55(_0, ...) bst_dtl_ppack_reverse54(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse56(_0, ...) bst_dtl_ppack_reverse55(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse57(_0, ...) bst_dtl_ppack_reverse56(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse58(_0, ...) bst_dtl_ppack_reverse57(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse59(_0, ...) bst_dtl_ppack_reverse58(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse60(_0, ...) bst_dtl_ppack_reverse59(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse61(_0, ...) bst_dtl_ppack_reverse60(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse62(_0, ...) bst_dtl_ppack_reverse61(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse63(_0, ...) bst_dtl_ppack_reverse62(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse64(_0, ...) bst_dtl_ppack_reverse63(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse65(_0, ...) bst_dtl_ppack_reverse64(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse66(_0, ...) bst_dtl_ppack_reverse65(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse67(_0, ...) bst_dtl_ppack_reverse66(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse68(_0, ...) bst_dtl_ppack_reverse67(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse69(_0, ...) bst_dtl_ppack_reverse68(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse70(_0, ...) bst_dtl_ppack_reverse69(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse71(_0, ...) bst_dtl_ppack_reverse70(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse72(_0, ...) bst_dtl_ppack_reverse71(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse73(_0, ...) bst_dtl_ppack_reverse72(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse74(_0, ...) bst_dtl_ppack_reverse73(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse75(_0, ...) bst_dtl_ppack_reverse74(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse76(_0, ...) bst_dtl_ppack_reverse75(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse77(_0, ...) bst_dtl_ppack_reverse76(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse78(_0, ...) bst_dtl_ppack_reverse77(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse79(_0, ...) bst_dtl_ppack_reverse78(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse80(_0, ...) bst_dtl_ppack_reverse79(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse81(_0, ...) bst_dtl_ppack_reverse80(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse82(_0, ...) bst_dtl_ppack_reverse81(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse83(_0, ...) bst_dtl_ppack_reverse82(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse84(_0, ...) bst_dtl_ppack_reverse83(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse85(_0, ...) bst_dtl_ppack_reverse84(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse86(_0, ...) bst_dtl_ppack_reverse85(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse87(_0, ...) bst_dtl_ppack_reverse86(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse88(_0, ...) bst_dtl_ppack_reverse87(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse89(_0, ...) bst_dtl_ppack_reverse88(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse90(_0, ...) bst_dtl_ppack_reverse89(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse91(_0, ...) bst_dtl_ppack_reverse90(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse92(_0, ...) bst_dtl_ppack_reverse91(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse93(_0, ...) bst_dtl_ppack_reverse92(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse94(_0, ...) bst_dtl_ppack_reverse93(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse95(_0, ...) bst_dtl_ppack_reverse94(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse96(_0, ...) bst_dtl_ppack_reverse95(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse97(_0, ...) bst_dtl_ppack_reverse96(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse98(_0, ...) bst_dtl_ppack_reverse97(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse99(_0, ...) bst_dtl_ppack_reverse98(__VA_ARGS__), _0
#define bst_dtl_ppack_reverse100(_0, ...) bst_dtl_ppack_reverse99(__VA_ARGS__), _0

#define bst_dtl_ppack_ltrim0(...) __VA_ARGS__
#define bst_dtl_ppack_ltrim1(_0, ...) bst_dtl_ppack_ltrim0(__VA_ARGS__)
#define bst_dtl_ppack_ltrim2(_0, ...) bst_dtl_ppack_ltrim1(__VA_ARGS__)
#define bst_dtl_ppack_ltrim3(_0, ...) bst_dtl_ppack_ltrim2(__VA_ARGS__)
#define bst_dtl_ppack_ltrim4(_0, ...) bst_dtl_ppack_ltrim3(__VA_ARGS__)
#define bst_dtl_ppack_ltrim5(_0, ...) bst_dtl_ppack_ltrim4(__VA_ARGS__)
#define bst_dtl_ppack_ltrim6(_0, ...) bst_dtl_ppack_ltrim5(__VA_ARGS__)
#define bst_dtl_ppack_ltrim7(_0, ...) bst_dtl_ppack_ltrim6(__VA_ARGS__)
#define bst_dtl_ppack_ltrim8(_0, ...) bst_dtl_ppack_ltrim7(__VA_ARGS__)
#define bst_dtl_ppack_ltrim9(_0, ...) bst_dtl_ppack_ltrim8(__VA_ARGS__)
#define bst_dtl_ppack_ltrim10(_0, ...) bst_dtl_ppack_ltrim9(__VA_ARGS__)
#define bst_dtl_ppack_ltrim11(_0, ...) bst_dtl_ppack_ltrim10(__VA_ARGS__)
#define bst_dtl_ppack_ltrim12(_0, ...) bst_dtl_ppack_ltrim11(__VA_ARGS__)
#define bst_dtl_ppack_ltrim13(_0, ...) bst_dtl_ppack_ltrim12(__VA_ARGS__)
#define bst_dtl_ppack_ltrim14(_0, ...) bst_dtl_ppack_ltrim13(__VA_ARGS__)
#define bst_dtl_ppack_ltrim15(_0, ...) bst_dtl_ppack_ltrim14(__VA_ARGS__)
#define bst_dtl_ppack_ltrim16(_0, ...) bst_dtl_ppack_ltrim15(__VA_ARGS__)
#define bst_dtl_ppack_ltrim17(_0, ...) bst_dtl_ppack_ltrim16(__VA_ARGS__)
#define bst_dtl_ppack_ltrim18(_0, ...) bst_dtl_ppack_ltrim17(__VA_ARGS__)
#define bst_dtl_ppack_ltrim19(_0, ...) bst_dtl_ppack_ltrim18(__VA_ARGS__)
#define bst_dtl_ppack_ltrim20(_0, ...) bst_dtl_ppack_ltrim19(__VA_ARGS__)
#define bst_dtl_ppack_ltrim21(_0, ...) bst_dtl_ppack_ltrim20(__VA_ARGS__)
#define bst_dtl_ppack_ltrim22(_0, ...) bst_dtl_ppack_ltrim21(__VA_ARGS__)
#define bst_dtl_ppack_ltrim23(_0, ...) bst_dtl_ppack_ltrim22(__VA_ARGS__)
#define bst_dtl_ppack_ltrim24(_0, ...) bst_dtl_ppack_ltrim23(__VA_ARGS__)
#define bst_dtl_ppack_ltrim25(_0, ...) bst_dtl_ppack_ltrim24(__VA_ARGS__)
#define bst_dtl_ppack_ltrim26(_0, ...) bst_dtl_ppack_ltrim25(__VA_ARGS__)
#define bst_dtl_ppack_ltrim27(_0, ...) bst_dtl_ppack_ltrim26(__VA_ARGS__)
#define bst_dtl_ppack_ltrim28(_0, ...) bst_dtl_ppack_ltrim27(__VA_ARGS__)
#define bst_dtl_ppack_ltrim29(_0, ...) bst_dtl_ppack_ltrim28(__VA_ARGS__)
#define bst_dtl_ppack_ltrim30(_0, ...) bst_dtl_ppack_ltrim29(__VA_ARGS__)
#define bst_dtl_ppack_ltrim31(_0, ...) bst_dtl_ppack_ltrim30(__VA_ARGS__)
#define bst_dtl_ppack_ltrim32(_0, ...) bst_dtl_ppack_ltrim31(__VA_ARGS__)
#define bst_dtl_ppack_ltrim33(_0, ...) bst_dtl_ppack_ltrim32(__VA_ARGS__)
#define bst_dtl_ppack_ltrim34(_0, ...) bst_dtl_ppack_ltrim33(__VA_ARGS__)
#define bst_dtl_ppack_ltrim35(_0, ...) bst_dtl_ppack_ltrim34(__VA_ARGS__)
#define bst_dtl_ppack_ltrim36(_0, ...) bst_dtl_ppack_ltrim35(__VA_ARGS__)
#define bst_dtl_ppack_ltrim37(_0, ...) bst_dtl_ppack_ltrim36(__VA_ARGS__)
#define bst_dtl_ppack_ltrim38(_0, ...) bst_dtl_ppack_ltrim37(__VA_ARGS__)
#define bst_dtl_ppack_ltrim39(_0, ...) bst_dtl_ppack_ltrim38(__VA_ARGS__)
#define bst_dtl_ppack_ltrim40(_0, ...) bst_dtl_ppack_ltrim39(__VA_ARGS__)
#define bst_dtl_ppack_ltrim41(_0, ...) bst_dtl_ppack_ltrim40(__VA_ARGS__)
#define bst_dtl_ppack_ltrim42(_0, ...) bst_dtl_ppack_ltrim41(__VA_ARGS__)
#define bst_dtl_ppack_ltrim43(_0, ...) bst_dtl_ppack_ltrim42(__VA_ARGS__)
#define bst_dtl_ppack_ltrim44(_0, ...) bst_dtl_ppack_ltrim43(__VA_ARGS__)
#define bst_dtl_ppack_ltrim45(_0, ...) bst_dtl_ppack_ltrim44(__VA_ARGS__)
#define bst_dtl_ppack_ltrim46(_0, ...) bst_dtl_ppack_ltrim45(__VA_ARGS__)
#define bst_dtl_ppack_ltrim47(_0, ...) bst_dtl_ppack_ltrim46(__VA_ARGS__)
#define bst_dtl_ppack_ltrim48(_0, ...) bst_dtl_ppack_ltrim47(__VA_ARGS__)
#define bst_dtl_ppack_ltrim49(_0, ...) bst_dtl_ppack_ltrim48(__VA_ARGS__)
#define bst_dtl_ppack_ltrim50(_0, ...) bst_dtl_ppack_ltrim49(__VA_ARGS__)
#define bst_dtl_ppack_ltrim51(_0, ...) bst_dtl_ppack_ltrim50(__VA_ARGS__)
#define bst_dtl_ppack_ltrim52(_0, ...) bst_dtl_ppack_ltrim51(__VA_ARGS__)
#define bst_dtl_ppack_ltrim53(_0, ...) bst_dtl_ppack_ltrim52(__VA_ARGS__)
#define bst_dtl_ppack_ltrim54(_0, ...) bst_dtl_ppack_ltrim53(__VA_ARGS__)
#define bst_dtl_ppack_ltrim55(_0, ...) bst_dtl_ppack_ltrim54(__VA_ARGS__)
#define bst_dtl_ppack_ltrim56(_0, ...) bst_dtl_ppack_ltrim55(__VA_ARGS__)
#define bst_dtl_ppack_ltrim57(_0, ...) bst_dtl_ppack_ltrim56(__VA_ARGS__)
#define bst_dtl_ppack_ltrim58(_0, ...) bst_dtl_ppack_ltrim57(__VA_ARGS__)
#define bst_dtl_ppack_ltrim59(_0, ...) bst_dtl_ppack_ltrim58(__VA_ARGS__)
#define bst_dtl_ppack_ltrim60(_0, ...) bst_dtl_ppack_ltrim59(__VA_ARGS__)
#define bst_dtl_ppack_ltrim61(_0, ...) bst_dtl_ppack_ltrim60(__VA_ARGS__)
#define bst_dtl_ppack_ltrim62(_0, ...) bst_dtl_ppack_ltrim61(__VA_ARGS__)
#define bst_dtl_ppack_ltrim63(_0, ...) bst_dtl_ppack_ltrim62(__VA_ARGS__)
#define bst_dtl_ppack_ltrim64(_0, ...) bst_dtl_ppack_ltrim63(__VA_ARGS__)
#define bst_dtl_ppack_ltrim65(_0, ...) bst_dtl_ppack_ltrim64(__VA_ARGS__)
#define bst_dtl_ppack_ltrim66(_0, ...) bst_dtl_ppack_ltrim65(__VA_ARGS__)
#define bst_dtl_ppack_ltrim67(_0, ...) bst_dtl_ppack_ltrim66(__VA_ARGS__)
#define bst_dtl_ppack_ltrim68(_0, ...) bst_dtl_ppack_ltrim67(__VA_ARGS__)
#define bst_dtl_ppack_ltrim69(_0, ...) bst_dtl_ppack_ltrim68(__VA_ARGS__)
#define bst_dtl_ppack_ltrim70(_0, ...) bst_dtl_ppack_ltrim69(__VA_ARGS__)
#define bst_dtl_ppack_ltrim71(_0, ...) bst_dtl_ppack_ltrim70(__VA_ARGS__)
#define bst_dtl_ppack_ltrim72(_0, ...) bst_dtl_ppack_ltrim71(__VA_ARGS__)
#define bst_dtl_ppack_ltrim73(_0, ...) bst_dtl_ppack_ltrim72(__VA_ARGS__)
#define bst_dtl_ppack_ltrim74(_0, ...) bst_dtl_ppack_ltrim73(__VA_ARGS__)
#define bst_dtl_ppack_ltrim75(_0, ...) bst_dtl_ppack_ltrim74(__VA_ARGS__)
#define bst_dtl_ppack_ltrim76(_0, ...) bst_dtl_ppack_ltrim75(__VA_ARGS__)
#define bst_dtl_ppack_ltrim77(_0, ...) bst_dtl_ppack_ltrim76(__VA_ARGS__)
#define bst_dtl_ppack_ltrim78(_0, ...) bst_dtl_ppack_ltrim77(__VA_ARGS__)
#define bst_dtl_ppack_ltrim79(_0, ...) bst_dtl_ppack_ltrim78(__VA_ARGS__)
#define bst_dtl_ppack_ltrim80(_0, ...) bst_dtl_ppack_ltrim79(__VA_ARGS__)
#define bst_dtl_ppack_ltrim81(_0, ...) bst_dtl_ppack_ltrim80(__VA_ARGS__)
#define bst_dtl_ppack_ltrim82(_0, ...) bst_dtl_ppack_ltrim81(__VA_ARGS__)
#define bst_dtl_ppack_ltrim83(_0, ...) bst_dtl_ppack_ltrim82(__VA_ARGS__)
#define bst_dtl_ppack_ltrim84(_0, ...) bst_dtl_ppack_ltrim83(__VA_ARGS__)
#define bst_dtl_ppack_ltrim85(_0, ...) bst_dtl_ppack_ltrim84(__VA_ARGS__)
#define bst_dtl_ppack_ltrim86(_0, ...) bst_dtl_ppack_ltrim85(__VA_ARGS__)
#define bst_dtl_ppack_ltrim87(_0, ...) bst_dtl_ppack_ltrim86(__VA_ARGS__)
#define bst_dtl_ppack_ltrim88(_0, ...) bst_dtl_ppack_ltrim87(__VA_ARGS__)
#define bst_dtl_ppack_ltrim89(_0, ...) bst_dtl_ppack_ltrim88(__VA_ARGS__)
#define bst_dtl_ppack_ltrim90(_0, ...) bst_dtl_ppack_ltrim89(__VA_ARGS__)
#define bst_dtl_ppack_ltrim91(_0, ...) bst_dtl_ppack_ltrim90(__VA_ARGS__)
#define bst_dtl_ppack_ltrim92(_0, ...) bst_dtl_ppack_ltrim91(__VA_ARGS__)
#define bst_dtl_ppack_ltrim93(_0, ...) bst_dtl_ppack_ltrim92(__VA_ARGS__)
#define bst_dtl_ppack_ltrim94(_0, ...) bst_dtl_ppack_ltrim93(__VA_ARGS__)
#define bst_dtl_ppack_ltrim95(_0, ...) bst_dtl_ppack_ltrim94(__VA_ARGS__)
#define bst_dtl_ppack_ltrim96(_0, ...) bst_dtl_ppack_ltrim95(__VA_ARGS__)
#define bst_dtl_ppack_ltrim97(_0, ...) bst_dtl_ppack_ltrim96(__VA_ARGS__)
#define bst_dtl_ppack_ltrim98(_0, ...) bst_dtl_ppack_ltrim97(__VA_ARGS__)
#define bst_dtl_ppack_ltrim99(_0, ...) bst_dtl_ppack_ltrim98(__VA_ARGS__)
#define bst_dtl_ppack_ltrim100(_0, ...) bst_dtl_ppack_ltrim99(__VA_ARGS__)
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__PPACK_H
