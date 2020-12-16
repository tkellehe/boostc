//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <bst/config.h>


#ifdef __cplusplus
# include <cstring>
#else
# include <string.h>
#endif


/* Add namespaced version. */
/// \{
#ifdef bst_memcpy 
# define bst_memcpy memcpy
#endif

#ifdef bst_memmove 
# define bst_memmove memmove
#endif

#ifdef bst_strcpy 
# define bst_strcpy strcpy
#endif

#ifdef bst_strncpy 
# define bst_strncpy strncpy
#endif

#ifdef bst_strcat 
# define bst_strcat strcat
#endif

#ifdef bst_strncat 
# define bst_strncat strncat
#endif

#ifdef bst_memcmp 
# define bst_memcmp memcmp
#endif

#ifdef bst_strcmp 
# define bst_strcmp strcmp
#endif

#ifdef bst_strcoll 
# define bst_strcoll strcoll
#endif

#ifdef bst_strncmp 
# define bst_strncmp strncmp
#endif

#ifdef bst_strxfrm 
# define bst_strxfrm strxfrm
#endif

#ifdef bst_memchr 
# define bst_memchr memchr
#endif

#ifdef bst_strchr 
# define bst_strchr strchr
#endif

#ifdef bst_strcspn 
# define bst_strcspn strcspn
#endif

#ifdef bst_strpbrk 
# define bst_strpbrk strpbrk
#endif

#ifdef bst_strrchr 
# define bst_strrchr strrchr
#endif

#ifdef bst_strspn 
# define bst_strspn strspn
#endif

#ifdef bst_strstr 
# define bst_strstr strstr
#endif

#ifdef bst_strtok 
# define bst_strtok strtok
#endif

#ifdef bst_memset 
# define bst_memset memset
#endif

#ifdef bst_strerror 
# define bst_strerror strerror
#endif

#ifdef bst_strlen 
# define bst_strlen strlen
#endif
/// \}
