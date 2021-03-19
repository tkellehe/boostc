//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__CLANG_H
#define BOOSTC__CONFIG__COMPILER__CLANG_H


/* Provide a way to detect the version of CLANG. */
/// \{
#ifndef BSTC_CLANG_VER
# define BSTC_CLANG_VER __clang_version__
#endif
/// \}


/* Add branch predictors. */
/// \{
#if defined(__has_builtin)
# if __has_builtin(__builtin_expect)
#  ifndef BSTC_LIKELY
#   define BSTC_LIKELY(x) __builtin_expect(x, 1)
#  endif
#  ifndef BSTC_UNLIKELY
#   define BSTC_UNLIKELY(x) __builtin_expect(x, 0)
#  endif
# endif
#endif
/// \}


/* Pulled from Boost <boost/config/compiler/clang.hpp>. */
/// \{
#if !defined(BSTC_HAS_LONG_LONG) && !defined(BSTC_NO_LONG_LONG)
# define BSTC_HAS_LONG_LONG
#endif
/// \}


#endif // BOOSTC__CONFIG__COMPILER__CLANG_H
