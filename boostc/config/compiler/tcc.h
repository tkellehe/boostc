//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__TCC_H
#define BOOSTC__CONFIG__COMPILER__TCC_H


/* Provide a way to detect the version of TCC. */
/// \{
#define BSTC_TCC_VER __TINYC__
/// \}


/* Not 100% if always has this... */
/// \{
#define BSTC_HAS_LONG_LONG
/// \}


/* Indicate that null concat with __VA_ARGS__ works. Turns out does not work the exact same as gcc. */
/// \{
// #define BSTC_HAS_VA_ARGS_PASTE
/// \}


#endif // BOOSTC__CONFIG__COMPILER__TCC_H
