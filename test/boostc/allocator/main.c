#include <boostc/allocator.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int num_pass = 0;
    int num_fail = 0;

    #define alloc1 bstc_alloc_pack_free(bstc_free)
    #define alloc2 bstc_alloc_pack_malloc(bstc_malloc)
    #define alloc3 bstc_alloc_pack_realloc(bstc_realloc)
    #define alloc4 bstc_ctuple(1, 2, 3, 4)

    //--------------------------------------------------------------------------------------------------------
    printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(alloc1));
    bstc_alloc_isa(alloc1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    // printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(alloc2));
    // bstc_alloc_isa(alloc2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(alloc3));
    bstc_alloc_isa(alloc3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    // printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(alloc4));
    // bstc_alloc_isa(alloc4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    // printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(bstc_alloc_defaults));
    // bstc_alloc_isa(bstc_alloc_defaults, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    // printf("bstc_alloc_isa(%s)\n", bstc_ctuple_tostring(bstc_alloc_stdlib));
    // bstc_alloc_isa(bstc_alloc_stdlib, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
