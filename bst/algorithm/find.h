//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BST__ALGORITHM__FIND_H
#define BST__ALGORITHM__FIND_H


#include <bst/config.h>
#include <bst/iterator.h>


/* Provide interface with no namespace */
/// \{
#ifdef BST_NO_NAMESPACE
# define alg_findpred bst_alg_findpred
# define alg_find bst_alg_find
#endif
/// \}


/* Uses the BST iterator interface to interact with unordered content */
/// \{
#define bst_alg_find(iters, iter, end, val) bst_alg_findpred(iters, iter, end, (bst_iter_val(iters)(iter) == val))
#define bst_alg_findpred(iters, iter, end, pred) \
    ({\
        for(; !(bst_iter_eq(iters)(iter, end)); bst_iter_nxt(iters)(iter))\
            if((pred)) break;\
    })
/// \}


#endif
