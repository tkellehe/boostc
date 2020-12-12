//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__DETAIL__CTUPLE_H
#define BST__DETAIL__CTUPLE_H


#include <bst/config.h>


/* Details for ctuples */
/// \{
#if defined(BST_HAS_VA_ARGS_PASTE)
# define BST_CTUPLE_SIZE0
#endif

#define bst_dtl_ctuple_append(tpl, ...) (bst_ctuple_expand tpl, __VA_ARGS__)
#define bst_dtl_ctuple_prepend(tpl, ...) (__VA_ARGS__, bst_ctuple_expand tpl)


#define bst_dtl_ctuple_isa(tpl, _t, _f) BST_JOIN2(bst_dtl_ctuple_isa, BST_ARGCNT(0, bst_dtl_ctuple_isa_expand tpl))(_t, _f)
#define bst_dtl_ctuple_isa2(_t, _f) _f
#define bst_dtl_ctuple_isa3(_t, _f) _t
#define bst_dtl_ctuple_isa_expand(...) 0, 0


#define bst_dtl_ctuple_ifarg0empty(tpl, _t, _f) BST_EXPAND(bst_dtl_ctuple_ifarg0empty_(_t, _f, bst_dtl_ctuple_detect_empty_arg0(tpl)))
#define bst_dtl_ctuple_ifarg0empty_(_t, _f, ...) BST_EXPAND(BST_IFEQ(BST_ARGCNT(__VA_ARGS__), 2, _t, _f))
#define L 0, 0
#define bst_dtl_ctuple_detect_empty_arg0(tpl) BST_EXPAND(bst_dtl_ctuple_detect_empty_arg0_(bst_ctuple_expand tpl))
#define bst_dtl_ctuple_detect_empty_arg0_(...) BST_EXPAND(bst_dtl_ctuple_detect_empty_arg0__(__VA_ARGS__))
#define bst_dtl_ctuple_detect_empty_arg0__(A,...) L ## A


#if defined(BST_CTUPLE_SIZE0)
# define bst_dtl_ctuple_size(...)  bst_dtl_ctuple_expand_sizes(BST_AUGMENTED(0, ##__VA_ARGS__))
# define bst_dtl_ctuple_expand_sizes(...) BST_EXPAND(BST_GET_ARG101(__VA_ARGS__,\
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
#endif


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
/// \}


#endif // BST__DETAIL__CTUPLE_H
