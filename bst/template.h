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

#define tmplt_defaults bst_tmplt_defaults
#endif
/// \}


/** Provide operations on bst template types.
 * type: The actual type for the template.
 * info: A ppack of the information about the type.
 * iter: The bst iterator calls as a ppack for the type.
 * alloc: The bst allocator calls as a ppack for the type.
 */
/// \{
#define bst_tmplt_ppack(...) \
    bst_ppack_defaults(\
        bst_ppack(__VA_ARGS__),\
        bst_tmplt_defaults\
    )

#define bst_tmplt_type(pkd) bst_ppack_argI(pkd, 0)
#define bst_tmplt_info(pkd) bst_ppack_argI(pkd, 1)
#define bst_tmplt_iter(pkd) bst_ppack_argI(pkd, 2)
#define bst_tmplt_alloc(pkd) bst_ppack_argI(pkd, 3)
/// \}


/* Packs the defaults */
#define bst_tmplt_defaults bst_ppack(int, (), bst_iter_defaults, bst_alloc_defaults)


#ifdef __cplusplus
}
#endif


#endif // BST__TEMPLATE_H
