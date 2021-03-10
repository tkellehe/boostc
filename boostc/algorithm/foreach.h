//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/traits/iterator.h>


/** Uses the BSTC iterator interface to apply a foreach based off of a perdicate.
 * \param iters The iterator ctuple to extract the iterator interface from.
 * \param iter A reference to the iterator to apply the functions to and will be updated with the location.
 * \param end A reference to the iterator representing the end of the linear search.
 * \param expr The expression to run each iteration.
 */
/// \{
#ifndef bstc_alg_foreach
# define bstc_alg_foreach(iters, iter, end, expr) \
    {\
        for(; !(bstc_iter_eq(iters)(iter, end)); bstc_iter_nxt(iters)(iter))\
            {expr}\
    }
#endif
/// \}
