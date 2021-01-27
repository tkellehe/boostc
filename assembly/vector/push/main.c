//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/vector.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    bstc_vect_t(int) v;
    bstc_vect_init(v);
    bstc_vect_push(v, 11);
    bstc_vect_push(v, 12);
    printf("%i\n", v[0]);
    bstc_vect_destroy(v);
    return 0;
}
