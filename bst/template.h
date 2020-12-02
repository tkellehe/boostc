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
#include <bst/iterator.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define tmplt_ppack bst_tmplt_ppack

#define tmplt_type bst_tmplt_type
#define tmplt_info bst_tmplt_info
#define tmplt_iter bst_tmplt_iter
#define tmplt_alloc bst_tmplt_alloc
#endif
/// \}


/** Provide operations on bst template types.
 * type: The actual type for the template.
 * info: A ppack of the information about the type.
 * iter: The bst iterator calls as a ppack for the type.
 * alloc: The bst allocator calls as a ppack for the type.
 */
/// \{
#define bst_tmplt_ppack(type, info, iter, alloc, ...) bst_ppack(type, info, iter, alloc)

#define bst_tmplt_type(pkd) bst_dtl_tmplt_type pkd
#define bst_tmplt_info(pkd) bst_dtl_tmplt_info pkd
#define bst_tmplt_iter(pkd) bst_dtl_tmplt_iter pkd
#define bst_tmplt_alloc(pkd) bst_dtl_tmplt_alloc pkd

#define bst_dtl_tmplt_type(type, info, iter, alloc, ...) type
#define bst_dtl_tmplt_info(type, info, iter, alloc, ...) info
#define bst_dtl_tmplt_iter(type, info, iter, alloc, ...) iter
#define bst_dtl_tmplt_alloc(type, info, iter, alloc, ...) alloc
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__TEMPLATE_H
