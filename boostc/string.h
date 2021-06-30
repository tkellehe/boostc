//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__STRING_H
#define BOOSTC__STRING_H


#include <boostc/config.h>


#ifdef __cplusplus
# include <cstring>
#else
# include <string.h>
#endif


/* Add namespaced version. */
/// \{
#ifndef bstc_memcpy
# define bstc_memcpy memcpy
#endif

#ifndef bstc_memmove
# define bstc_memmove memmove
#endif

#ifndef bstc_strcpy
# define bstc_strcpy strcpy
#endif

#ifndef bstc_strncpy
# define bstc_strncpy strncpy
#endif

#ifndef bstc_strcat
# define bstc_strcat strcat
#endif

#ifndef bstc_strncat
# define bstc_strncat strncat
#endif

#ifndef bstc_memcmp
# define bstc_memcmp memcmp
#endif

#ifndef bstc_strcmp
# define bstc_strcmp strcmp
#endif

#ifndef bstc_strcoll
# define bstc_strcoll strcoll
#endif

#ifndef bstc_strncmp
# define bstc_strncmp strncmp
#endif

#ifndef bstc_strxfrm
# define bstc_strxfrm strxfrm
#endif

#ifndef bstc_memchr
# define bstc_memchr memchr
#endif

#ifndef bstc_strchr
# define bstc_strchr strchr
#endif

#ifndef bstc_strcsp
# define bstc_strcspn strcspn
#endif

#ifndef bstc_strpbrk
# define bstc_strpbrk strpbrk
#endif

#ifndef bstc_strrchr
# define bstc_strrchr strrchr
#endif

#ifndef bstc_strspn
# define bstc_strspn strspn
#endif

#ifndef bstc_strstr
# define bstc_strstr strstr
#endif

#ifndef bstc_strtok
# define bstc_strtok strtok
#endif

#ifndef bstc_memset
# define bstc_memset memset
#endif

#ifndef bstc_strerror
# define bstc_strerror strerror
#endif

#ifndef bstc_strlen
# define bstc_strlen strlen
#endif
/// \}


#endif // BOOSTC__STRING_H
