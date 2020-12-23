//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/iterator.h>


/** Uses the BSTC iterator interface to search for the provided value.
 * \param iters The iterator ctuple to extract the iterator interface from.
 * \param iter A reference to the iterator to apply the functions to and will be updated with the location.
 * \param end A reference to the iterator representing the end of the linear search.
 */
/// \{
#ifndef bstc_alg_find
# define bstc_alg_find(iters, iter, end, val) bstc_iter_foreach(iters, iter, end, {if((bstc_iter_val(iters)(iter) == (val)))break;})
#endif
/// \}
