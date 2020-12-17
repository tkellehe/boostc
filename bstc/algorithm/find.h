//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BSTC__ALGORITHM__FIND_H
#define BSTC__ALGORITHM__FIND_H


#include <bstc/config.h>
#include <bstc/iterator.h>


/* Uses the BSTC iterator interface to interact with unordered content */
/// \{
#define bstc_alg_find(iters, iter, end, val) bstc_alg_findpred(iters, iter, end, (bstc_iter_val(iters)(iter) == val))
#define bstc_alg_findpred(iters, iter, end, pred) \
    {\
        for(; !(bstc_iter_eq(iters)(iter, end)); bstc_iter_nxt(iters)(iter))\
            if((pred)) break;\
    }
/// \}


#endif
