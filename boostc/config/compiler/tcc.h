//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__TCC_H
#define BOOSTC__CONFIG__COMPILER__TCC_H


/* Provide a way to detect the version of TCC. */
/// \{
#ifndef BSTC_TCC_VER
# define BSTC_TCC_VER __TINYC__
#endif
/// \}


/* Not 100% if always has this... */
/// \{
#if !defined(BSTC_HAS_LONG_LONG) && !defined(BSTC_NO_LONG_LONG)
# define BSTC_HAS_LONG_LONG
#endif
/// \}


/* Indicate that null concat with __VA_ARGS__ works. Turns out does not work the exact same as gcc. */
/// \{
// #if !defined(BSTC_HAS_VA_ARGS_PASTE) && !defined(BSTC_NO_VA_ARGS_PASTE)
// # define BSTC_HAS_VA_ARGS_PASTE
// #endif
/// \}


#endif // BOOSTC__CONFIG__COMPILER__TCC_H
