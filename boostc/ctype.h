//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>


#ifdef __cplusplus
# include <cctype>
#else
# include <ctype.h>
#endif


/* Add namespaced version. */
/// \{
#if defined(BSTC_LEAST_C99) || defined(BSTC_LEAST_CPP11)
# ifndef bstc_isblank
#  define bstc_isblank isblank
# endif
#endif

#ifndef bstc_isalnum
# define bstc_isalnum isalnum
#endif

#ifndef bstc_isalpha
# define bstc_isalpha isalpha
#endif

#ifndef bstc_islower
# define bstc_islower islower
#endif

#ifndef bstc_isupper
# define bstc_isupper isupper
#endif

#ifndef bstc_isdigit
# define bstc_isdigit isdigit
#endif

#ifndef bstc_isxdigit
# define bstc_isxdigit isxdigit
#endif

#ifndef bstc_iscntrl
# define bstc_iscntrl iscntrl
#endif

#ifndef bstc_isgraph
# define bstc_isgraph isgraph
#endif

#ifndef bstc_isspace
# define bstc_isspace isspace
#endif

#ifndef bstc_isprint
# define bstc_isprint isprint
#endif

#ifndef bstc_ispunct
# define bstc_ispunct ispunct
#endif

#ifndef bstc_tolower
# define bstc_tolower tolower
#endif

#ifndef bstc_toupper
# define bstc_toupper toupper
#endif
/// \}
