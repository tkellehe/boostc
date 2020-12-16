//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__COMPILER__CLANG_H
#define BST__CONFIG__COMPILER__CLANG_H


/* Provide a way to detect the version of CLANG. */
/// \{
#define BST_CLANG_VER __clang_version__
/// \}


/* Add branch predictors. */
/// \{
#if defined(__has_builtin)
# if __has_builtin(__builtin_expect)
#  define BST_LIKELY(x) __builtin_expect(x, 1)
#  define BST_UNLIKELY(x) __builtin_expect(x, 0)
# endif
#endif
/// \}


/* Pulled from Boost <boost/config/compiler/clang.hpp>. */
/// \{
#define BST_HAS_LONG_LONG
/// \}


#endif // BST__CONFIG__COMPILER__CLANG_H
