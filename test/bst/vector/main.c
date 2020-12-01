#include <bst/vector.h>
#include <stdio.h>

int main()
{
    typedef vect_t(int) vect_int_t;
    vect_int_t v;
    vect_init(v);
    vect_push(v, 1);
    vect_rsz(v, 100);
    vect_destroy(v, bst_alloc_pack());
    printf("passed\n");
    return 0;
}