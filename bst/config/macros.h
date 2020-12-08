//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__MACROS_H
#define BST__CONFIG__MACROS_H


/* Provide a helper that joins two symbols */
/// \{
#define BST_DTL_JOIN2(L, R) L ## R
#define BST_JOIN2(L, R) BST_DTL_JOIN2(L, R)
/// \}


/* Provide a helper that converts symbols to strings */
/// \{
#define BST_DTL_DTL_TOSTRING(X) #X
#define BST_DTL_TOSTRING(X) BST_DTL_DTL_TOSTRING(X)
#define BST_TOSTRING(X) BST_DTL_TOSTRING(X)
/// \}


#endif // BST__CONFIG__MACROS_H
