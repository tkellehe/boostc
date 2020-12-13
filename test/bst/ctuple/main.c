#include <bst/ctuple.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    #define tpl1 ctuple('a', 'b', 'c', 'd')
    #define tpl2 ctuple_empty()
    #define tpl3 ctuple(,,,,,)
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl1));
    BST_IFEQ(bst_ctuple_size(tpl1), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl2));
    BST_IFEQ(bst_ctuple_size(tpl2), 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl3));
    BST_IFEQ(bst_ctuple_size(tpl3), 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(A));
    BST_IFEQ(bst_ctuple_size(A), 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_isa(tpl1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_isa(tpl2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_isa(tpl3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(A));
    bst_ctuple_isa(A, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? -1 : 0;
}
