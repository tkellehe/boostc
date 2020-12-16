//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__CONFIG__SELECT_COMPILER_H
#define BST__CONFIG__SELECT_COMPILER_H


/* Determine the compiler. */
/// \{
#ifndef BST_COMPILER_CONFIG
# if defined(_GCCXML)
#  define BST_COMPILER_GCCXML
#  define BST_COMPILER_CONFIG "bst/config/compiler/gccxml.h"
# elif defined(__clang__)
#  define BST_COMPILER_CLANG
#  define BST_COMPILER_CONFIG "bst/config/compiler/clang.h"
# elif defined(__GNUC__) && !defined(__ibmxl__)
#  define BST_COMPILER_GCC
#  define BST_COMPILER_CONFIG "bst/config/compiler/gcc.h"
# elif defined(__TINYC__)
#  define BST_COMPILER_TCC
#  define BST_COMPILER_CONFIG "bst/config/compiler/tcc.h"
# elif defined(_CRAYC)
#  define BST_COMPILER_CRAY
#  define BST_COMPILER_CONFIG "bst/config/compiler/cray.h"
# elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#  define BST_COMPILER_INTEL
#  define BST_COMPILER_CONFIG "bst/config/compiler/intel.h"
# elif defined(_MSC_VER)
#  define BST_COMPILER_VISUALC
#  define BST_COMPILER_CONFIG "bst/config/compiler/visualc.h"
# elif defined(__EMSCRIPTEN__)
#  define BST_COMPILER_EMSCRIPTEN
#  define BST_COMPILER_CONFIG "bst/config/compiler/emscripten.h"
# elif defined(__MINGW32__)
#  define BST_COMPILER_MINGW32
#  define BST_COMPILER_CONFIG "bst/config/compiler/mingw32.h"
# elif defined(__MINGW64__)
#  define BST_COMPILER_MINGW64
#  define BST_COMPILER_CONFIG "bst/config/compiler/mingw64.h"
# else
#  define BST_COMPILER_UNKNOWN
# endif
#endif
/// \}


#endif // BST__CONFIG__SELECT_COMPILER_H
