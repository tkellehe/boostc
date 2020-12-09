//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__DETAIL__CTUPLE_H
#define BST__DETAIL__CTUPLE_H


#include <bst/config.h>


/* Details for parameter packing */
/// \{
#define bst_dtl_ctuple_append(tpl, ...) (bst_ctuple_expand tpl, __VA_ARGS__)
#define bst_dtl_ctuple_prepend(tpl, ...) (__VA_ARGS__, bst_ctuple_expand tpl)
#define bst_dtl_ctuple_defargs(tpl) bst_ctuple_expand tpl

// TODO: Remove the extra value added to the numbers and get rid of the GNU '##' by forcing ctuples to have a NULL starting element.
#define bst_dtl_ctuple_if(tpl) bst_dtl_ctuple_if_eval tpl
#define bst_dtl_ctuple_if_eval(...) bst_dtl_ctuple_expand_ifs(bst_dtl_ctuple_args_augmenter(0, ##__VA_ARGS__))
#define bst_dtl_ctuple_if0(_t, _f) _f
#define bst_dtl_ctuple_if1(_t, _f) _t

#define bst_dtl_ctuple_isa2(_t, _f) _f
#define bst_dtl_ctuple_isa3(_t, _f) _t
#define bst_dtl_ctuple_isa_expand(...) 0, 0

#define bst_dtl_ctuple_size(...)  bst_dtl_ctuple_expand_sizes(bst_dtl_ctuple_args_augmenter(0, ##__VA_ARGS__))

#define bst_dtl_ctuple_args_augmenter(...) unused, __VA_ARGS__
#define bst_dtl_ctuple_expand(x) x
#define bst_dtl_ctuple_expand_sizes(...) bst_dtl_ctuple_expand(BST_GET_ARG103(__VA_ARGS__,\
    99, 98, 97, 96, 95, 94, 93, 92, 91, 90,\
    89, 88, 87, 86, 85, 84, 83, 82, 81, 80,\
    79, 78, 77, 76, 75, 74, 73, 72, 71, 70,\
    69, 68, 67, 66, 65, 64, 63, 62, 61, 60,\
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50,\
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40,\
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30,\
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20,\
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10,\
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0,\
    0))

#define bst_dtl_ctuple_expand_ifs(...) bst_dtl_ctuple_expand(BST_GET_ARG103(__VA_ARGS__,\
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, \
        bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if1, bst_dtl_ctuple_if0,\
        bst_dtl_ctuple_if0))


#define bst_dtl_ctuple_reverse0()
#define bst_dtl_ctuple_reverse1(_0) _0
#define bst_dtl_ctuple_reverse2(_0, _1) _1, _0
#define bst_dtl_ctuple_reverse3(_0, ...) bst_dtl_ctuple_reverse2(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse4(_0, ...) bst_dtl_ctuple_reverse3(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse5(_0, ...) bst_dtl_ctuple_reverse4(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse6(_0, ...) bst_dtl_ctuple_reverse5(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse7(_0, ...) bst_dtl_ctuple_reverse6(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse8(_0, ...) bst_dtl_ctuple_reverse7(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse9(_0, ...) bst_dtl_ctuple_reverse8(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse10(_0, ...) bst_dtl_ctuple_reverse9(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse11(_0, ...) bst_dtl_ctuple_reverse10(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse12(_0, ...) bst_dtl_ctuple_reverse11(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse13(_0, ...) bst_dtl_ctuple_reverse12(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse14(_0, ...) bst_dtl_ctuple_reverse13(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse15(_0, ...) bst_dtl_ctuple_reverse14(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse16(_0, ...) bst_dtl_ctuple_reverse15(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse17(_0, ...) bst_dtl_ctuple_reverse16(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse18(_0, ...) bst_dtl_ctuple_reverse17(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse19(_0, ...) bst_dtl_ctuple_reverse18(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse20(_0, ...) bst_dtl_ctuple_reverse19(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse21(_0, ...) bst_dtl_ctuple_reverse20(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse22(_0, ...) bst_dtl_ctuple_reverse21(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse23(_0, ...) bst_dtl_ctuple_reverse22(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse24(_0, ...) bst_dtl_ctuple_reverse23(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse25(_0, ...) bst_dtl_ctuple_reverse24(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse26(_0, ...) bst_dtl_ctuple_reverse25(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse27(_0, ...) bst_dtl_ctuple_reverse26(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse28(_0, ...) bst_dtl_ctuple_reverse27(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse29(_0, ...) bst_dtl_ctuple_reverse28(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse30(_0, ...) bst_dtl_ctuple_reverse29(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse31(_0, ...) bst_dtl_ctuple_reverse30(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse32(_0, ...) bst_dtl_ctuple_reverse31(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse33(_0, ...) bst_dtl_ctuple_reverse32(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse34(_0, ...) bst_dtl_ctuple_reverse33(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse35(_0, ...) bst_dtl_ctuple_reverse34(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse36(_0, ...) bst_dtl_ctuple_reverse35(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse37(_0, ...) bst_dtl_ctuple_reverse36(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse38(_0, ...) bst_dtl_ctuple_reverse37(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse39(_0, ...) bst_dtl_ctuple_reverse38(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse40(_0, ...) bst_dtl_ctuple_reverse39(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse41(_0, ...) bst_dtl_ctuple_reverse40(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse42(_0, ...) bst_dtl_ctuple_reverse41(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse43(_0, ...) bst_dtl_ctuple_reverse42(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse44(_0, ...) bst_dtl_ctuple_reverse43(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse45(_0, ...) bst_dtl_ctuple_reverse44(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse46(_0, ...) bst_dtl_ctuple_reverse45(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse47(_0, ...) bst_dtl_ctuple_reverse46(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse48(_0, ...) bst_dtl_ctuple_reverse47(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse49(_0, ...) bst_dtl_ctuple_reverse48(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse50(_0, ...) bst_dtl_ctuple_reverse49(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse51(_0, ...) bst_dtl_ctuple_reverse50(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse52(_0, ...) bst_dtl_ctuple_reverse51(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse53(_0, ...) bst_dtl_ctuple_reverse52(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse54(_0, ...) bst_dtl_ctuple_reverse53(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse55(_0, ...) bst_dtl_ctuple_reverse54(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse56(_0, ...) bst_dtl_ctuple_reverse55(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse57(_0, ...) bst_dtl_ctuple_reverse56(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse58(_0, ...) bst_dtl_ctuple_reverse57(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse59(_0, ...) bst_dtl_ctuple_reverse58(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse60(_0, ...) bst_dtl_ctuple_reverse59(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse61(_0, ...) bst_dtl_ctuple_reverse60(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse62(_0, ...) bst_dtl_ctuple_reverse61(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse63(_0, ...) bst_dtl_ctuple_reverse62(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse64(_0, ...) bst_dtl_ctuple_reverse63(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse65(_0, ...) bst_dtl_ctuple_reverse64(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse66(_0, ...) bst_dtl_ctuple_reverse65(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse67(_0, ...) bst_dtl_ctuple_reverse66(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse68(_0, ...) bst_dtl_ctuple_reverse67(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse69(_0, ...) bst_dtl_ctuple_reverse68(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse70(_0, ...) bst_dtl_ctuple_reverse69(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse71(_0, ...) bst_dtl_ctuple_reverse70(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse72(_0, ...) bst_dtl_ctuple_reverse71(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse73(_0, ...) bst_dtl_ctuple_reverse72(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse74(_0, ...) bst_dtl_ctuple_reverse73(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse75(_0, ...) bst_dtl_ctuple_reverse74(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse76(_0, ...) bst_dtl_ctuple_reverse75(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse77(_0, ...) bst_dtl_ctuple_reverse76(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse78(_0, ...) bst_dtl_ctuple_reverse77(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse79(_0, ...) bst_dtl_ctuple_reverse78(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse80(_0, ...) bst_dtl_ctuple_reverse79(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse81(_0, ...) bst_dtl_ctuple_reverse80(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse82(_0, ...) bst_dtl_ctuple_reverse81(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse83(_0, ...) bst_dtl_ctuple_reverse82(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse84(_0, ...) bst_dtl_ctuple_reverse83(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse85(_0, ...) bst_dtl_ctuple_reverse84(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse86(_0, ...) bst_dtl_ctuple_reverse85(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse87(_0, ...) bst_dtl_ctuple_reverse86(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse88(_0, ...) bst_dtl_ctuple_reverse87(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse89(_0, ...) bst_dtl_ctuple_reverse88(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse90(_0, ...) bst_dtl_ctuple_reverse89(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse91(_0, ...) bst_dtl_ctuple_reverse90(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse92(_0, ...) bst_dtl_ctuple_reverse91(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse93(_0, ...) bst_dtl_ctuple_reverse92(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse94(_0, ...) bst_dtl_ctuple_reverse93(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse95(_0, ...) bst_dtl_ctuple_reverse94(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse96(_0, ...) bst_dtl_ctuple_reverse95(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse97(_0, ...) bst_dtl_ctuple_reverse96(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse98(_0, ...) bst_dtl_ctuple_reverse97(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse99(_0, ...) bst_dtl_ctuple_reverse98(__VA_ARGS__), _0
#define bst_dtl_ctuple_reverse100(_0, ...) bst_dtl_ctuple_reverse99(__VA_ARGS__), _0


#define bst_dtl_ctuple_ltrim0(...) __VA_ARGS__
#define bst_dtl_ctuple_ltrim1(_0, ...) bst_dtl_ctuple_ltrim0(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim2(_0, ...) bst_dtl_ctuple_ltrim1(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim3(_0, ...) bst_dtl_ctuple_ltrim2(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim4(_0, ...) bst_dtl_ctuple_ltrim3(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim5(_0, ...) bst_dtl_ctuple_ltrim4(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim6(_0, ...) bst_dtl_ctuple_ltrim5(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim7(_0, ...) bst_dtl_ctuple_ltrim6(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim8(_0, ...) bst_dtl_ctuple_ltrim7(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim9(_0, ...) bst_dtl_ctuple_ltrim8(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim10(_0, ...) bst_dtl_ctuple_ltrim9(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim11(_0, ...) bst_dtl_ctuple_ltrim10(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim12(_0, ...) bst_dtl_ctuple_ltrim11(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim13(_0, ...) bst_dtl_ctuple_ltrim12(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim14(_0, ...) bst_dtl_ctuple_ltrim13(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim15(_0, ...) bst_dtl_ctuple_ltrim14(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim16(_0, ...) bst_dtl_ctuple_ltrim15(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim17(_0, ...) bst_dtl_ctuple_ltrim16(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim18(_0, ...) bst_dtl_ctuple_ltrim17(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim19(_0, ...) bst_dtl_ctuple_ltrim18(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim20(_0, ...) bst_dtl_ctuple_ltrim19(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim21(_0, ...) bst_dtl_ctuple_ltrim20(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim22(_0, ...) bst_dtl_ctuple_ltrim21(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim23(_0, ...) bst_dtl_ctuple_ltrim22(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim24(_0, ...) bst_dtl_ctuple_ltrim23(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim25(_0, ...) bst_dtl_ctuple_ltrim24(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim26(_0, ...) bst_dtl_ctuple_ltrim25(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim27(_0, ...) bst_dtl_ctuple_ltrim26(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim28(_0, ...) bst_dtl_ctuple_ltrim27(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim29(_0, ...) bst_dtl_ctuple_ltrim28(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim30(_0, ...) bst_dtl_ctuple_ltrim29(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim31(_0, ...) bst_dtl_ctuple_ltrim30(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim32(_0, ...) bst_dtl_ctuple_ltrim31(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim33(_0, ...) bst_dtl_ctuple_ltrim32(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim34(_0, ...) bst_dtl_ctuple_ltrim33(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim35(_0, ...) bst_dtl_ctuple_ltrim34(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim36(_0, ...) bst_dtl_ctuple_ltrim35(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim37(_0, ...) bst_dtl_ctuple_ltrim36(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim38(_0, ...) bst_dtl_ctuple_ltrim37(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim39(_0, ...) bst_dtl_ctuple_ltrim38(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim40(_0, ...) bst_dtl_ctuple_ltrim39(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim41(_0, ...) bst_dtl_ctuple_ltrim40(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim42(_0, ...) bst_dtl_ctuple_ltrim41(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim43(_0, ...) bst_dtl_ctuple_ltrim42(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim44(_0, ...) bst_dtl_ctuple_ltrim43(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim45(_0, ...) bst_dtl_ctuple_ltrim44(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim46(_0, ...) bst_dtl_ctuple_ltrim45(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim47(_0, ...) bst_dtl_ctuple_ltrim46(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim48(_0, ...) bst_dtl_ctuple_ltrim47(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim49(_0, ...) bst_dtl_ctuple_ltrim48(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim50(_0, ...) bst_dtl_ctuple_ltrim49(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim51(_0, ...) bst_dtl_ctuple_ltrim50(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim52(_0, ...) bst_dtl_ctuple_ltrim51(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim53(_0, ...) bst_dtl_ctuple_ltrim52(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim54(_0, ...) bst_dtl_ctuple_ltrim53(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim55(_0, ...) bst_dtl_ctuple_ltrim54(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim56(_0, ...) bst_dtl_ctuple_ltrim55(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim57(_0, ...) bst_dtl_ctuple_ltrim56(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim58(_0, ...) bst_dtl_ctuple_ltrim57(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim59(_0, ...) bst_dtl_ctuple_ltrim58(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim60(_0, ...) bst_dtl_ctuple_ltrim59(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim61(_0, ...) bst_dtl_ctuple_ltrim60(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim62(_0, ...) bst_dtl_ctuple_ltrim61(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim63(_0, ...) bst_dtl_ctuple_ltrim62(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim64(_0, ...) bst_dtl_ctuple_ltrim63(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim65(_0, ...) bst_dtl_ctuple_ltrim64(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim66(_0, ...) bst_dtl_ctuple_ltrim65(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim67(_0, ...) bst_dtl_ctuple_ltrim66(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim68(_0, ...) bst_dtl_ctuple_ltrim67(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim69(_0, ...) bst_dtl_ctuple_ltrim68(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim70(_0, ...) bst_dtl_ctuple_ltrim69(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim71(_0, ...) bst_dtl_ctuple_ltrim70(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim72(_0, ...) bst_dtl_ctuple_ltrim71(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim73(_0, ...) bst_dtl_ctuple_ltrim72(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim74(_0, ...) bst_dtl_ctuple_ltrim73(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim75(_0, ...) bst_dtl_ctuple_ltrim74(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim76(_0, ...) bst_dtl_ctuple_ltrim75(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim77(_0, ...) bst_dtl_ctuple_ltrim76(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim78(_0, ...) bst_dtl_ctuple_ltrim77(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim79(_0, ...) bst_dtl_ctuple_ltrim78(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim80(_0, ...) bst_dtl_ctuple_ltrim79(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim81(_0, ...) bst_dtl_ctuple_ltrim80(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim82(_0, ...) bst_dtl_ctuple_ltrim81(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim83(_0, ...) bst_dtl_ctuple_ltrim82(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim84(_0, ...) bst_dtl_ctuple_ltrim83(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim85(_0, ...) bst_dtl_ctuple_ltrim84(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim86(_0, ...) bst_dtl_ctuple_ltrim85(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim87(_0, ...) bst_dtl_ctuple_ltrim86(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim88(_0, ...) bst_dtl_ctuple_ltrim87(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim89(_0, ...) bst_dtl_ctuple_ltrim88(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim90(_0, ...) bst_dtl_ctuple_ltrim89(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim91(_0, ...) bst_dtl_ctuple_ltrim90(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim92(_0, ...) bst_dtl_ctuple_ltrim91(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim93(_0, ...) bst_dtl_ctuple_ltrim92(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim94(_0, ...) bst_dtl_ctuple_ltrim93(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim95(_0, ...) bst_dtl_ctuple_ltrim94(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim96(_0, ...) bst_dtl_ctuple_ltrim95(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim97(_0, ...) bst_dtl_ctuple_ltrim96(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim98(_0, ...) bst_dtl_ctuple_ltrim97(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim99(_0, ...) bst_dtl_ctuple_ltrim98(__VA_ARGS__)
#define bst_dtl_ctuple_ltrim100(_0, ...) bst_dtl_ctuple_ltrim99(__VA_ARGS__)


#define bst_dtl_ctuple_collect0(...)
#define bst_dtl_ctuple_collect1(_0, ...) _0
#define bst_dtl_ctuple_collect2(_0, ...) _0, bst_dtl_ctuple_collect1(__VA_ARGS__)
#define bst_dtl_ctuple_collect3(_0, ...) _0, bst_dtl_ctuple_collect2(__VA_ARGS__)
#define bst_dtl_ctuple_collect4(_0, ...) _0, bst_dtl_ctuple_collect3(__VA_ARGS__)
#define bst_dtl_ctuple_collect5(_0, ...) _0, bst_dtl_ctuple_collect4(__VA_ARGS__)
#define bst_dtl_ctuple_collect6(_0, ...) _0, bst_dtl_ctuple_collect5(__VA_ARGS__)
#define bst_dtl_ctuple_collect7(_0, ...) _0, bst_dtl_ctuple_collect6(__VA_ARGS__)
#define bst_dtl_ctuple_collect8(_0, ...) _0, bst_dtl_ctuple_collect7(__VA_ARGS__)
#define bst_dtl_ctuple_collect9(_0, ...) _0, bst_dtl_ctuple_collect8(__VA_ARGS__)
#define bst_dtl_ctuple_collect10(_0, ...) _0, bst_dtl_ctuple_collect9(__VA_ARGS__)
#define bst_dtl_ctuple_collect11(_0, ...) _0, bst_dtl_ctuple_collect10(__VA_ARGS__)
#define bst_dtl_ctuple_collect12(_0, ...) _0, bst_dtl_ctuple_collect11(__VA_ARGS__)
#define bst_dtl_ctuple_collect13(_0, ...) _0, bst_dtl_ctuple_collect12(__VA_ARGS__)
#define bst_dtl_ctuple_collect14(_0, ...) _0, bst_dtl_ctuple_collect13(__VA_ARGS__)
#define bst_dtl_ctuple_collect15(_0, ...) _0, bst_dtl_ctuple_collect14(__VA_ARGS__)
#define bst_dtl_ctuple_collect16(_0, ...) _0, bst_dtl_ctuple_collect15(__VA_ARGS__)
#define bst_dtl_ctuple_collect17(_0, ...) _0, bst_dtl_ctuple_collect16(__VA_ARGS__)
#define bst_dtl_ctuple_collect18(_0, ...) _0, bst_dtl_ctuple_collect17(__VA_ARGS__)
#define bst_dtl_ctuple_collect19(_0, ...) _0, bst_dtl_ctuple_collect18(__VA_ARGS__)
#define bst_dtl_ctuple_collect20(_0, ...) _0, bst_dtl_ctuple_collect19(__VA_ARGS__)
#define bst_dtl_ctuple_collect21(_0, ...) _0, bst_dtl_ctuple_collect20(__VA_ARGS__)
#define bst_dtl_ctuple_collect22(_0, ...) _0, bst_dtl_ctuple_collect21(__VA_ARGS__)
#define bst_dtl_ctuple_collect23(_0, ...) _0, bst_dtl_ctuple_collect22(__VA_ARGS__)
#define bst_dtl_ctuple_collect24(_0, ...) _0, bst_dtl_ctuple_collect23(__VA_ARGS__)
#define bst_dtl_ctuple_collect25(_0, ...) _0, bst_dtl_ctuple_collect24(__VA_ARGS__)
#define bst_dtl_ctuple_collect26(_0, ...) _0, bst_dtl_ctuple_collect25(__VA_ARGS__)
#define bst_dtl_ctuple_collect27(_0, ...) _0, bst_dtl_ctuple_collect26(__VA_ARGS__)
#define bst_dtl_ctuple_collect28(_0, ...) _0, bst_dtl_ctuple_collect27(__VA_ARGS__)
#define bst_dtl_ctuple_collect29(_0, ...) _0, bst_dtl_ctuple_collect28(__VA_ARGS__)
#define bst_dtl_ctuple_collect30(_0, ...) _0, bst_dtl_ctuple_collect29(__VA_ARGS__)
#define bst_dtl_ctuple_collect31(_0, ...) _0, bst_dtl_ctuple_collect30(__VA_ARGS__)
#define bst_dtl_ctuple_collect32(_0, ...) _0, bst_dtl_ctuple_collect31(__VA_ARGS__)
#define bst_dtl_ctuple_collect33(_0, ...) _0, bst_dtl_ctuple_collect32(__VA_ARGS__)
#define bst_dtl_ctuple_collect34(_0, ...) _0, bst_dtl_ctuple_collect33(__VA_ARGS__)
#define bst_dtl_ctuple_collect35(_0, ...) _0, bst_dtl_ctuple_collect34(__VA_ARGS__)
#define bst_dtl_ctuple_collect36(_0, ...) _0, bst_dtl_ctuple_collect35(__VA_ARGS__)
#define bst_dtl_ctuple_collect37(_0, ...) _0, bst_dtl_ctuple_collect36(__VA_ARGS__)
#define bst_dtl_ctuple_collect38(_0, ...) _0, bst_dtl_ctuple_collect37(__VA_ARGS__)
#define bst_dtl_ctuple_collect39(_0, ...) _0, bst_dtl_ctuple_collect38(__VA_ARGS__)
#define bst_dtl_ctuple_collect40(_0, ...) _0, bst_dtl_ctuple_collect39(__VA_ARGS__)
#define bst_dtl_ctuple_collect41(_0, ...) _0, bst_dtl_ctuple_collect40(__VA_ARGS__)
#define bst_dtl_ctuple_collect42(_0, ...) _0, bst_dtl_ctuple_collect41(__VA_ARGS__)
#define bst_dtl_ctuple_collect43(_0, ...) _0, bst_dtl_ctuple_collect42(__VA_ARGS__)
#define bst_dtl_ctuple_collect44(_0, ...) _0, bst_dtl_ctuple_collect43(__VA_ARGS__)
#define bst_dtl_ctuple_collect45(_0, ...) _0, bst_dtl_ctuple_collect44(__VA_ARGS__)
#define bst_dtl_ctuple_collect46(_0, ...) _0, bst_dtl_ctuple_collect45(__VA_ARGS__)
#define bst_dtl_ctuple_collect47(_0, ...) _0, bst_dtl_ctuple_collect46(__VA_ARGS__)
#define bst_dtl_ctuple_collect48(_0, ...) _0, bst_dtl_ctuple_collect47(__VA_ARGS__)
#define bst_dtl_ctuple_collect49(_0, ...) _0, bst_dtl_ctuple_collect48(__VA_ARGS__)
#define bst_dtl_ctuple_collect50(_0, ...) _0, bst_dtl_ctuple_collect49(__VA_ARGS__)
#define bst_dtl_ctuple_collect51(_0, ...) _0, bst_dtl_ctuple_collect50(__VA_ARGS__)
#define bst_dtl_ctuple_collect52(_0, ...) _0, bst_dtl_ctuple_collect51(__VA_ARGS__)
#define bst_dtl_ctuple_collect53(_0, ...) _0, bst_dtl_ctuple_collect52(__VA_ARGS__)
#define bst_dtl_ctuple_collect54(_0, ...) _0, bst_dtl_ctuple_collect53(__VA_ARGS__)
#define bst_dtl_ctuple_collect55(_0, ...) _0, bst_dtl_ctuple_collect54(__VA_ARGS__)
#define bst_dtl_ctuple_collect56(_0, ...) _0, bst_dtl_ctuple_collect55(__VA_ARGS__)
#define bst_dtl_ctuple_collect57(_0, ...) _0, bst_dtl_ctuple_collect56(__VA_ARGS__)
#define bst_dtl_ctuple_collect58(_0, ...) _0, bst_dtl_ctuple_collect57(__VA_ARGS__)
#define bst_dtl_ctuple_collect59(_0, ...) _0, bst_dtl_ctuple_collect58(__VA_ARGS__)
#define bst_dtl_ctuple_collect60(_0, ...) _0, bst_dtl_ctuple_collect59(__VA_ARGS__)
#define bst_dtl_ctuple_collect61(_0, ...) _0, bst_dtl_ctuple_collect60(__VA_ARGS__)
#define bst_dtl_ctuple_collect62(_0, ...) _0, bst_dtl_ctuple_collect61(__VA_ARGS__)
#define bst_dtl_ctuple_collect63(_0, ...) _0, bst_dtl_ctuple_collect62(__VA_ARGS__)
#define bst_dtl_ctuple_collect64(_0, ...) _0, bst_dtl_ctuple_collect63(__VA_ARGS__)
#define bst_dtl_ctuple_collect65(_0, ...) _0, bst_dtl_ctuple_collect64(__VA_ARGS__)
#define bst_dtl_ctuple_collect66(_0, ...) _0, bst_dtl_ctuple_collect65(__VA_ARGS__)
#define bst_dtl_ctuple_collect67(_0, ...) _0, bst_dtl_ctuple_collect66(__VA_ARGS__)
#define bst_dtl_ctuple_collect68(_0, ...) _0, bst_dtl_ctuple_collect67(__VA_ARGS__)
#define bst_dtl_ctuple_collect69(_0, ...) _0, bst_dtl_ctuple_collect68(__VA_ARGS__)
#define bst_dtl_ctuple_collect70(_0, ...) _0, bst_dtl_ctuple_collect69(__VA_ARGS__)
#define bst_dtl_ctuple_collect71(_0, ...) _0, bst_dtl_ctuple_collect70(__VA_ARGS__)
#define bst_dtl_ctuple_collect72(_0, ...) _0, bst_dtl_ctuple_collect71(__VA_ARGS__)
#define bst_dtl_ctuple_collect73(_0, ...) _0, bst_dtl_ctuple_collect72(__VA_ARGS__)
#define bst_dtl_ctuple_collect74(_0, ...) _0, bst_dtl_ctuple_collect73(__VA_ARGS__)
#define bst_dtl_ctuple_collect75(_0, ...) _0, bst_dtl_ctuple_collect74(__VA_ARGS__)
#define bst_dtl_ctuple_collect76(_0, ...) _0, bst_dtl_ctuple_collect75(__VA_ARGS__)
#define bst_dtl_ctuple_collect77(_0, ...) _0, bst_dtl_ctuple_collect76(__VA_ARGS__)
#define bst_dtl_ctuple_collect78(_0, ...) _0, bst_dtl_ctuple_collect77(__VA_ARGS__)
#define bst_dtl_ctuple_collect79(_0, ...) _0, bst_dtl_ctuple_collect78(__VA_ARGS__)
#define bst_dtl_ctuple_collect80(_0, ...) _0, bst_dtl_ctuple_collect79(__VA_ARGS__)
#define bst_dtl_ctuple_collect81(_0, ...) _0, bst_dtl_ctuple_collect80(__VA_ARGS__)
#define bst_dtl_ctuple_collect82(_0, ...) _0, bst_dtl_ctuple_collect81(__VA_ARGS__)
#define bst_dtl_ctuple_collect83(_0, ...) _0, bst_dtl_ctuple_collect82(__VA_ARGS__)
#define bst_dtl_ctuple_collect84(_0, ...) _0, bst_dtl_ctuple_collect83(__VA_ARGS__)
#define bst_dtl_ctuple_collect85(_0, ...) _0, bst_dtl_ctuple_collect84(__VA_ARGS__)
#define bst_dtl_ctuple_collect86(_0, ...) _0, bst_dtl_ctuple_collect85(__VA_ARGS__)
#define bst_dtl_ctuple_collect87(_0, ...) _0, bst_dtl_ctuple_collect86(__VA_ARGS__)
#define bst_dtl_ctuple_collect88(_0, ...) _0, bst_dtl_ctuple_collect87(__VA_ARGS__)
#define bst_dtl_ctuple_collect89(_0, ...) _0, bst_dtl_ctuple_collect88(__VA_ARGS__)
#define bst_dtl_ctuple_collect90(_0, ...) _0, bst_dtl_ctuple_collect89(__VA_ARGS__)
#define bst_dtl_ctuple_collect91(_0, ...) _0, bst_dtl_ctuple_collect90(__VA_ARGS__)
#define bst_dtl_ctuple_collect92(_0, ...) _0, bst_dtl_ctuple_collect91(__VA_ARGS__)
#define bst_dtl_ctuple_collect93(_0, ...) _0, bst_dtl_ctuple_collect92(__VA_ARGS__)
#define bst_dtl_ctuple_collect94(_0, ...) _0, bst_dtl_ctuple_collect93(__VA_ARGS__)
#define bst_dtl_ctuple_collect95(_0, ...) _0, bst_dtl_ctuple_collect94(__VA_ARGS__)
#define bst_dtl_ctuple_collect96(_0, ...) _0, bst_dtl_ctuple_collect95(__VA_ARGS__)
#define bst_dtl_ctuple_collect97(_0, ...) _0, bst_dtl_ctuple_collect96(__VA_ARGS__)
#define bst_dtl_ctuple_collect98(_0, ...) _0, bst_dtl_ctuple_collect97(__VA_ARGS__)
#define bst_dtl_ctuple_collect99(_0, ...) _0, bst_dtl_ctuple_collect98(__VA_ARGS__)
#define bst_dtl_ctuple_collect100(_0, ...) _0, bst_dtl_ctuple_collect99(__VA_ARGS__)


#define bst_dtl_ctuple_const_add1(N) BST_JOIN2(bst_dtl_ctuple_const_add1_, N)
#define bst_dtl_ctuple_const_add1_0 1
#define bst_dtl_ctuple_const_add1_1 2
#define bst_dtl_ctuple_const_add1_2 3
#define bst_dtl_ctuple_const_add1_3 4
#define bst_dtl_ctuple_const_add1_4 5
#define bst_dtl_ctuple_const_add1_5 6
#define bst_dtl_ctuple_const_add1_6 7
#define bst_dtl_ctuple_const_add1_7 8
#define bst_dtl_ctuple_const_add1_8 9
#define bst_dtl_ctuple_const_add1_9 10
#define bst_dtl_ctuple_const_add1_10 11
#define bst_dtl_ctuple_const_add1_11 12
#define bst_dtl_ctuple_const_add1_12 13
#define bst_dtl_ctuple_const_add1_13 14
#define bst_dtl_ctuple_const_add1_14 15
#define bst_dtl_ctuple_const_add1_15 16
#define bst_dtl_ctuple_const_add1_16 17
#define bst_dtl_ctuple_const_add1_17 18
#define bst_dtl_ctuple_const_add1_18 19
#define bst_dtl_ctuple_const_add1_19 20
#define bst_dtl_ctuple_const_add1_20 21
#define bst_dtl_ctuple_const_add1_21 22
#define bst_dtl_ctuple_const_add1_22 23
#define bst_dtl_ctuple_const_add1_23 24
#define bst_dtl_ctuple_const_add1_24 25
#define bst_dtl_ctuple_const_add1_25 26
#define bst_dtl_ctuple_const_add1_26 27
#define bst_dtl_ctuple_const_add1_27 28
#define bst_dtl_ctuple_const_add1_28 29
#define bst_dtl_ctuple_const_add1_29 30
#define bst_dtl_ctuple_const_add1_30 31
#define bst_dtl_ctuple_const_add1_31 32
#define bst_dtl_ctuple_const_add1_32 33
#define bst_dtl_ctuple_const_add1_33 34
#define bst_dtl_ctuple_const_add1_34 35
#define bst_dtl_ctuple_const_add1_35 36
#define bst_dtl_ctuple_const_add1_36 37
#define bst_dtl_ctuple_const_add1_37 38
#define bst_dtl_ctuple_const_add1_38 39
#define bst_dtl_ctuple_const_add1_39 40
#define bst_dtl_ctuple_const_add1_40 41
#define bst_dtl_ctuple_const_add1_41 42
#define bst_dtl_ctuple_const_add1_42 43
#define bst_dtl_ctuple_const_add1_43 44
#define bst_dtl_ctuple_const_add1_44 45
#define bst_dtl_ctuple_const_add1_45 46
#define bst_dtl_ctuple_const_add1_46 47
#define bst_dtl_ctuple_const_add1_47 48
#define bst_dtl_ctuple_const_add1_48 49
#define bst_dtl_ctuple_const_add1_49 50
#define bst_dtl_ctuple_const_add1_50 51
#define bst_dtl_ctuple_const_add1_51 52
#define bst_dtl_ctuple_const_add1_52 53
#define bst_dtl_ctuple_const_add1_53 54
#define bst_dtl_ctuple_const_add1_54 55
#define bst_dtl_ctuple_const_add1_55 56
#define bst_dtl_ctuple_const_add1_56 57
#define bst_dtl_ctuple_const_add1_57 58
#define bst_dtl_ctuple_const_add1_58 59
#define bst_dtl_ctuple_const_add1_59 60
#define bst_dtl_ctuple_const_add1_60 61
#define bst_dtl_ctuple_const_add1_61 62
#define bst_dtl_ctuple_const_add1_62 63
#define bst_dtl_ctuple_const_add1_63 64
#define bst_dtl_ctuple_const_add1_64 65
#define bst_dtl_ctuple_const_add1_65 66
#define bst_dtl_ctuple_const_add1_66 67
#define bst_dtl_ctuple_const_add1_67 68
#define bst_dtl_ctuple_const_add1_68 69
#define bst_dtl_ctuple_const_add1_69 70
#define bst_dtl_ctuple_const_add1_70 71
#define bst_dtl_ctuple_const_add1_71 72
#define bst_dtl_ctuple_const_add1_72 73
#define bst_dtl_ctuple_const_add1_73 74
#define bst_dtl_ctuple_const_add1_74 75
#define bst_dtl_ctuple_const_add1_75 76
#define bst_dtl_ctuple_const_add1_76 77
#define bst_dtl_ctuple_const_add1_77 78
#define bst_dtl_ctuple_const_add1_78 79
#define bst_dtl_ctuple_const_add1_79 80
#define bst_dtl_ctuple_const_add1_80 81
#define bst_dtl_ctuple_const_add1_81 82
#define bst_dtl_ctuple_const_add1_82 83
#define bst_dtl_ctuple_const_add1_83 84
#define bst_dtl_ctuple_const_add1_84 85
#define bst_dtl_ctuple_const_add1_85 86
#define bst_dtl_ctuple_const_add1_86 87
#define bst_dtl_ctuple_const_add1_87 88
#define bst_dtl_ctuple_const_add1_88 89
#define bst_dtl_ctuple_const_add1_89 90
#define bst_dtl_ctuple_const_add1_90 91
#define bst_dtl_ctuple_const_add1_91 92
#define bst_dtl_ctuple_const_add1_92 93
#define bst_dtl_ctuple_const_add1_93 94
#define bst_dtl_ctuple_const_add1_94 95
#define bst_dtl_ctuple_const_add1_95 96
#define bst_dtl_ctuple_const_add1_96 97
#define bst_dtl_ctuple_const_add1_97 98
#define bst_dtl_ctuple_const_add1_98 99
#define bst_dtl_ctuple_const_add1_99 100
#define bst_dtl_ctuple_const_add1_100 101

#define bst_dtl_ctuple_const_sub1(N) BST_JOIN2(bst_dtl_ctuple_const_sub1_, N)
#define bst_dtl_ctuple_const_sub1_1 0
#define bst_dtl_ctuple_const_sub1_2 1
#define bst_dtl_ctuple_const_sub1_3 2
#define bst_dtl_ctuple_const_sub1_4 3
#define bst_dtl_ctuple_const_sub1_5 4
#define bst_dtl_ctuple_const_sub1_6 5
#define bst_dtl_ctuple_const_sub1_7 6
#define bst_dtl_ctuple_const_sub1_8 7
#define bst_dtl_ctuple_const_sub1_9 8
#define bst_dtl_ctuple_const_sub1_10 9
#define bst_dtl_ctuple_const_sub1_11 10
#define bst_dtl_ctuple_const_sub1_12 11
#define bst_dtl_ctuple_const_sub1_13 12
#define bst_dtl_ctuple_const_sub1_14 13
#define bst_dtl_ctuple_const_sub1_15 14
#define bst_dtl_ctuple_const_sub1_16 15
#define bst_dtl_ctuple_const_sub1_17 16
#define bst_dtl_ctuple_const_sub1_18 17
#define bst_dtl_ctuple_const_sub1_19 18
#define bst_dtl_ctuple_const_sub1_20 19
#define bst_dtl_ctuple_const_sub1_21 20
#define bst_dtl_ctuple_const_sub1_22 21
#define bst_dtl_ctuple_const_sub1_23 22
#define bst_dtl_ctuple_const_sub1_24 23
#define bst_dtl_ctuple_const_sub1_25 24
#define bst_dtl_ctuple_const_sub1_26 25
#define bst_dtl_ctuple_const_sub1_27 26
#define bst_dtl_ctuple_const_sub1_28 27
#define bst_dtl_ctuple_const_sub1_29 28
#define bst_dtl_ctuple_const_sub1_30 29
#define bst_dtl_ctuple_const_sub1_31 30
#define bst_dtl_ctuple_const_sub1_32 31
#define bst_dtl_ctuple_const_sub1_33 32
#define bst_dtl_ctuple_const_sub1_34 33
#define bst_dtl_ctuple_const_sub1_35 34
#define bst_dtl_ctuple_const_sub1_36 35
#define bst_dtl_ctuple_const_sub1_37 36
#define bst_dtl_ctuple_const_sub1_38 37
#define bst_dtl_ctuple_const_sub1_39 38
#define bst_dtl_ctuple_const_sub1_40 39
#define bst_dtl_ctuple_const_sub1_41 40
#define bst_dtl_ctuple_const_sub1_42 41
#define bst_dtl_ctuple_const_sub1_43 42
#define bst_dtl_ctuple_const_sub1_44 43
#define bst_dtl_ctuple_const_sub1_45 44
#define bst_dtl_ctuple_const_sub1_46 45
#define bst_dtl_ctuple_const_sub1_47 46
#define bst_dtl_ctuple_const_sub1_48 47
#define bst_dtl_ctuple_const_sub1_49 48
#define bst_dtl_ctuple_const_sub1_50 49
#define bst_dtl_ctuple_const_sub1_51 50
#define bst_dtl_ctuple_const_sub1_52 51
#define bst_dtl_ctuple_const_sub1_53 52
#define bst_dtl_ctuple_const_sub1_54 53
#define bst_dtl_ctuple_const_sub1_55 54
#define bst_dtl_ctuple_const_sub1_56 55
#define bst_dtl_ctuple_const_sub1_57 56
#define bst_dtl_ctuple_const_sub1_58 57
#define bst_dtl_ctuple_const_sub1_59 58
#define bst_dtl_ctuple_const_sub1_60 59
#define bst_dtl_ctuple_const_sub1_61 60
#define bst_dtl_ctuple_const_sub1_62 61
#define bst_dtl_ctuple_const_sub1_63 62
#define bst_dtl_ctuple_const_sub1_64 63
#define bst_dtl_ctuple_const_sub1_65 64
#define bst_dtl_ctuple_const_sub1_66 65
#define bst_dtl_ctuple_const_sub1_67 66
#define bst_dtl_ctuple_const_sub1_68 67
#define bst_dtl_ctuple_const_sub1_69 68
#define bst_dtl_ctuple_const_sub1_70 69
#define bst_dtl_ctuple_const_sub1_71 70
#define bst_dtl_ctuple_const_sub1_72 71
#define bst_dtl_ctuple_const_sub1_73 72
#define bst_dtl_ctuple_const_sub1_74 73
#define bst_dtl_ctuple_const_sub1_75 74
#define bst_dtl_ctuple_const_sub1_76 75
#define bst_dtl_ctuple_const_sub1_77 76
#define bst_dtl_ctuple_const_sub1_78 77
#define bst_dtl_ctuple_const_sub1_79 78
#define bst_dtl_ctuple_const_sub1_80 79
#define bst_dtl_ctuple_const_sub1_81 80
#define bst_dtl_ctuple_const_sub1_82 81
#define bst_dtl_ctuple_const_sub1_83 82
#define bst_dtl_ctuple_const_sub1_84 83
#define bst_dtl_ctuple_const_sub1_85 84
#define bst_dtl_ctuple_const_sub1_86 85
#define bst_dtl_ctuple_const_sub1_87 86
#define bst_dtl_ctuple_const_sub1_88 87
#define bst_dtl_ctuple_const_sub1_89 88
#define bst_dtl_ctuple_const_sub1_90 89
#define bst_dtl_ctuple_const_sub1_91 90
#define bst_dtl_ctuple_const_sub1_92 91
#define bst_dtl_ctuple_const_sub1_93 92
#define bst_dtl_ctuple_const_sub1_94 93
#define bst_dtl_ctuple_const_sub1_95 94
#define bst_dtl_ctuple_const_sub1_96 95
#define bst_dtl_ctuple_const_sub1_97 96
#define bst_dtl_ctuple_const_sub1_98 97
#define bst_dtl_ctuple_const_sub1_99 98
#define bst_dtl_ctuple_const_sub1_100 99
#define bst_dtl_ctuple_const_sub1_101 100
/// \}


#endif // BST__DETAIL__CTUPLE_H
