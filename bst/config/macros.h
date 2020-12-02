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


/* Provide a helper that joins two symbols */
/// \{
#define BST_DTL_JOIN(L, R) L ## R
#define BST_JOIN(L, R) BST_DTL_JOIN(L, R)
/// \}


/* Provide a helper that converts symbols to strings */
/// \{
#define BST_DTL_DTL_TOSTRING(X) #X
#define BST_DTL_TOSTRING(X) BST_DTL_DTL_TOSTRING(X)
#define BST_TOSTRING(X) BST_DTL_TOSTRING(X)
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
