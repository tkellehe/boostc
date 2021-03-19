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
#ifdef bstc_memcpy 
# define bstc_memcpy memcpy
#endif

#ifdef bstc_memmove 
# define bstc_memmove memmove
#endif

#ifdef bstc_strcpy 
# define bstc_strcpy strcpy
#endif

#ifdef bstc_strncpy 
# define bstc_strncpy strncpy
#endif

#ifdef bstc_strcat 
# define bstc_strcat strcat
#endif

#ifdef bstc_strncat 
# define bstc_strncat strncat
#endif

#ifdef bstc_memcmp 
# define bstc_memcmp memcmp
#endif

#ifdef bstc_strcmp 
# define bstc_strcmp strcmp
#endif

#ifdef bstc_strcoll 
# define bstc_strcoll strcoll
#endif

#ifdef bstc_strncmp 
# define bstc_strncmp strncmp
#endif

#ifdef bstc_strxfrm 
# define bstc_strxfrm strxfrm
#endif

#ifdef bstc_memchr 
# define bstc_memchr memchr
#endif

#ifdef bstc_strchr 
# define bstc_strchr strchr
#endif

#ifdef bstc_strcspn 
# define bstc_strcspn strcspn
#endif

#ifdef bstc_strpbrk 
# define bstc_strpbrk strpbrk
#endif

#ifdef bstc_strrchr 
# define bstc_strrchr strrchr
#endif

#ifdef bstc_strspn 
# define bstc_strspn strspn
#endif

#ifdef bstc_strstr 
# define bstc_strstr strstr
#endif

#ifdef bstc_strtok 
# define bstc_strtok strtok
#endif

#ifdef bstc_memset 
# define bstc_memset memset
#endif

#ifdef bstc_strerror 
# define bstc_strerror strerror
#endif

#ifdef bstc_strlen 
# define bstc_strlen strlen
#endif
/// \}


#endif // BOOSTC__STRING_H
