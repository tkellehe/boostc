//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__COMPILER__BORLAND_H
#define BOOSTC__CONFIG__COMPILER__BORLAND_H


/* Provide a way to detect the version of BORLAND. */
/// \{
#define BSTC_BORLAND_VER __BORLANDC__
/// \}


/* Detect if has int64 support. */
/// \{
#if !defined(BSTC_HAS_64BIT) && !defined(BSTC_NO_64BIT)
# if defined (__BORLANDC__) && __BORLANDC__ > 0x460
#  define BSTC_HAS_64BIT
#  define bstc_uint64_t unsigned __int64
#  define bstc_int64_t __int64
#  define bstc_uint64_c(v) v ## UI64
#  define bstc_int64_t(v) v ## I64
# else
#  define BSTC_NO_64BIT
# endif
#endif
/// \}


#endif // BOOSTC__CONFIG__COMPILER__BORLAND_H
