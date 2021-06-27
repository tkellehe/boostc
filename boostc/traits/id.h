//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>


/** Create a variable name with the id. */
/// \{
#ifndef bstc_var
# define bstc_var(name, id) BSTC_JOIN2(name, id)
#endif
/// \}


/** Takes a constant and moves the id to the next value. */
/// \{
#ifndef bstc_nxtid
# define bstc_nxtid(id) BSTC_CONST_ADD1(id)
#endif
/// \}
