//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__COMPILER__GCC_H
#define BST__CONFIG__COMPILER__GCC_H


/* Provide a way to detect the version of GCC */
/// \{
#define BST_GCC_VER (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
/// \}


/* Add branch predictors */
/// \{
#define BST_LIKELY(x) __builtin_expect(x, 1)
#define BST_UNLIKELY(x) __builtin_expect(x, 0)
/// \}


/* Pulled from Boost <boost/config/compiler/gcc.hpp> */
/// \{
#if !defined(__DARWIN_NO_LONG_LONG)
# define BST_HAS_LONG_LONG
#endif
/// \}


/* Indicate that null concat with __VA_ARGS__ works */
/// \{
#define BST_HAS_VA_ARGS_PASTE
/// \}


#endif // BST__CONFIG__COMPILER__GCC_H
