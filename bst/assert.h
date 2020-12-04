//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__ASSERT_H
#define BST__ASSERT_H


#include <bst/config.h>


#ifdef __cplusplus
# include <cassert>
#else
# include <assert.h>
#endif


/* Add namespaced version */
/// \{
#define bst_assert assert
/// \}


#endif // BST__ASSERT_H
