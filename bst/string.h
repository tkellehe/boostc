//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__ASSERT_H
#define BST__ASSERT_H


#include <bst/config.h>


#ifdef __cplusplus
# include <cstring>
#else
# include <string.h>
#endif


/* Add namespaced version */
/// \{
#define bst_memcpy memcpy
#define bst_memmove memmove
#define bst_strcpy strcpy
#define bst_strncpy strncpy
#define bst_strcat strcat
#define bst_strncat strncat
#define bst_memcmp memcmp
#define bst_strcmp strcmp
#define bst_strcoll strcoll
#define bst_strncmp strncmp
#define bst_strxfrm strxfrm
#define bst_memchr memchr
#define bst_strchr strchr
#define bst_strcspn strcspn
#define bst_strpbrk strpbrk
#define bst_strrchr strrchr
#define bst_strspn strspn
#define bst_strstr strstr
#define bst_strtok strtok
#define bst_memset memset
#define bst_strerror strerror
#define bst_strlen strlen
/// \}


#endif // BST__ASSERT_H
