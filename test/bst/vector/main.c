#include <bst/vector.h>
#include <bst/algorithm/find.h>
#include <stdio.h>

int main()
{
    #define bst_vect_int bst_dtl_vect_tmplt_t(int)
    #define tmplt vect_tmplt_t(int)
    typedef vect_t(tmplt) vect_int_t;
    typedef vect_iter_t(tmplt) vect_int_iter_t;
    typedef vect_riter_t(tmplt) vect_int_riter_t;

    vect_int_t v;
    vect_int_iter_t iter;
    vect_int_riter_t riter;

    typedef struct { int x; int y; } s_t;
    typedef vect_t(s_t) vect_s_t;
    vect_s_t u;

    int x = 3;
    vect_init(v);
    vect_rsv(v, 100);
    vect_push(tmplt, v, 1);
    vect_push(v, 2);
    vect_push(v, x);
    vect_push(v, 4);
    vect_push(v, x);
    vect_push(v, 5);

    iter = vect_begin(v);

    alg_find(tmplt_iter(tmplt), iter, vect_end(v), x);
    if(iter != vect_end(v))
    {
        printf("%i\n", vect_iter_val(iter));
    }

    riter = vect_rbegin(v);
    alg_find(tmplt_riter(tmplt), riter, vect_rend(v), x);
    if(riter != vect_rend(v))
    {
        printf("%i\n", vect_riter_val(riter));
    }

    vect_iter_set(iter, 90);
    vect_riter_set(riter, 100);

    iter = vect_begin(v);
    alg_find(tmplt_iter(tmplt), iter, vect_end(v), x);
    if(iter == vect_end(v))
    {
        printf("not found\n");
    }

    riter = vect_rbegin(v);
    alg_find(tmplt_riter(tmplt), riter, vect_rend(v), x);
    if(riter == vect_rend(v))
    {
        printf("not found\n");
    }

    for(x = 0; x < vect_len(v); ++x)
    {
        printf("v[%i] = %i\n", x, v[x]);
    }

    vect_destroy(v);

    vect_init(u);
    {
        s_t t = {1, 2};
        vect_push(u, t);
    }
    {
        s_t t = {3, 4};
        vect_push(u, t);
    }

    for(x = 0; x < vect_len(u); ++x)
    {
        printf("u[%i] = {.x=%i, .y=%i}\n", x, u[x].x, u[x].y);
    }

    vect_destroy(u);
    return 0;
}
