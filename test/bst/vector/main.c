#include <bst/vector.h>
#include <bst/algorithm/find.h>
#include <stdio.h>

int main()
{
    typedef vect_t(int) vect_int_t;
    typedef vect_iter_t(vect_int_t) vect_int_iter_t;
    typedef vect_riter_t(vect_int_t) vect_int_riter_t;
    vect_int_t v;
    vect_int_iter_t iter;
    vect_int_riter_t riter;
    int x = 3;
    vect_init(v);
    vect_rsv(v, 100);
    vect_push(v, 1);
    vect_push(v, 2);
    vect_push(v, x);
    vect_push(v, 4);
    vect_push(v, x);
    vect_push(v, 5);

    iter = vect_begin(v);
    alg_find(vect_iter, iter, vect_end(v), x);
    if(iter != vect_end(v))
    {
        printf("%i\n", vect_iter_val(iter));
    }

    riter = vect_rbegin(v);
    alg_find(vect_riter, riter, vect_rend(v), x);
    if(riter != vect_rend(v))
    {
        printf("%i\n", vect_riter_val(riter));
    }

    vect_iter_set(iter, 90);
    vect_riter_set(riter, 100);

    iter = vect_begin(v);
    alg_find(vect_iter, iter, vect_end(v), x);
    if(iter == vect_end(v))
    {
        printf("not found\n");
    }

    riter = vect_rbegin(v);
    alg_find(vect_riter, riter, vect_rend(v), x);
    if(riter == vect_rend(v))
    {
        printf("not found\n");
    }

    for(x = 0; x < vect_cnt(v); ++x)
    {
        printf("v[%i] = %i\n", x, v[x]);
    }

    vect_destroy(v, alloc_stdlib);
    printf("passed\n");
    return 0;
}
