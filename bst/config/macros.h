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


#ifdef __cplusplus
}
#endif


#endif // BST__CONFIG__MACROS_H
