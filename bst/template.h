//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__TEMPLATE_H
#define BST__TEMPLATE_H


#include <bst/config.h>
#include <bst/ppack.h>
#include <bst/allocator.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define tcc_ppack bst_tcc_ppack

#define tcc_info bst_tcc_info
#define tcc_type bst_tcc_type
#define tcc_alloc bst_tcc_alloc
#endif
/// \}


/* Provide operations on bst template types */
/// \{
#define bst_tcc_ppack(info, type, alloc, ...) bst_ppack(info, type, alloc)

#define bst_tcc_info(pkd) bst_dtl_tcc_info pkd
#define bst_tcc_type(pkd) bst_dtl_tcc_info pkd
#define bst_tcc_alloc(pkd) bst_dtl_tcc_info pkd

#define bst_dtl_tcc_info(info, type, alloc, ...) info
#define bst_dtl_tcc_type(info, type, alloc, ...) type
#define bst_dtl_tcc_alloc(info, type, alloc, ...) alloc
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__TEMPLATE_H
