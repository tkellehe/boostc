//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/container/vector.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused(argc);
    bstc_unused(argv);
    bstc_vect_t(int) v;
    bstc_vect_init(v);
    bstc_vect_pushb(v, 11);
    bstc_vect_pushb(v, 12);
    {
        bstc_size_t i;
        for(i = 0; i < bstc_vect_len(v); ++i)
            printf("%i\n", v[i]);
    }
    bstc_vect_destroy(v);
    return 0;
}
