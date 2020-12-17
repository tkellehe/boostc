#include <bstc/vector.h>
#include <bstc/algorithm/find.h>
#include <stdio.h>

int main()
{
    #define tmplt bstc_vect_tmplt_t(int)
    typedef bstc_vect_t(tmplt) vect_int_t;
    typedef bstc_vect_iter_t(tmplt) vect_int_iter_t;
    typedef bstc_vect_riter_t(tmplt) vect_int_riter_t;

    vect_int_t v;
    vect_int_iter_t iter;
    vect_int_riter_t riter;

    typedef struct { int x; int y; } s_t;
    typedef bstc_vect_t(s_t) vect_s_t;
    vect_s_t u;

    int x = 3;
    bstc_vect_init(v);
    bstc_vect_rsv(v, 100);
    bstc_vect_push(tmplt, v, 1);
    bstc_vect_push(v, 2);
    bstc_vect_push(v, x);
    bstc_vect_push(v, 4);
    bstc_vect_push(v, x);
    bstc_vect_push(v, 5);

    iter = bstc_vect_begin(v);

    bstc_alg_find(bstc_tmplt_iter(tmplt), iter, bstc_vect_end(v), x);
    if(iter != bstc_vect_end(v))
    {
        printf("%i\n", bstc_vect_iter_val(iter));
    }

    riter = bstc_vect_rbegin(v);
    bstc_alg_find(bstc_tmplt_riter(tmplt), riter, bstc_vect_rend(v), x);
    if(riter != bstc_vect_rend(v))
    {
        printf("%i\n", bstc_vect_riter_val(riter));
    }

    bstc_vect_iter_set(iter, 90);
    bstc_vect_riter_set(riter, 100);

    iter = bstc_vect_begin(v);
    bstc_alg_find(bstc_tmplt_iter(tmplt), iter, bstc_vect_end(v), x);
    if(iter == bstc_vect_end(v))
    {
        printf("not found\n");
    }

    riter = bstc_vect_rbegin(v);
    bstc_alg_find(bstc_tmplt_riter(tmplt), riter, bstc_vect_rend(v), x);
    if(riter == bstc_vect_rend(v))
    {
        printf("not found\n");
    }

    for(x = 0; x < bstc_vect_len(v); ++x)
    {
        printf("v[%i] = %i\n", x, v[x]);
    }

    bstc_vect_destroy(v);

    bstc_vect_init(u);
    {
        s_t t = {1, 2};
        bstc_vect_push(u, t);
    }
    {
        s_t t = {3, 4};
        bstc_vect_push(u, t);
    }

    for(x = 0; x < bstc_vect_len(u); ++x)
    {
        printf("u[%i] = {.x=%i, .y=%i}\n", x, u[x].x, u[x].y);
    }

    bstc_vect_destroy(u);
    return 0;
}
