#include <bst/ctuple.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    #define tpl1 ctuple('a', 'b', 'c', 'd')
    #define tpl2 ctuple_empty()
    #define tpl3 ctuple(,,,,,)
    #define tpl4 ctuple(18, 17, 16, 15, 14, 13, 12, 11)

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_isa(tpl1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_isa(tpl2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_isa(tpl3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_isa(tpl4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_isa(%s)\n", bst_ctuple_tostring(A));
    bst_ctuple_isa(A, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl1));
    BST_IFEQ(bst_ctuple_size(tpl1), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl2));
    BST_IFEQ(bst_ctuple_size(tpl2), 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl3));
    BST_IFEQ(bst_ctuple_size(tpl3), 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_size(tpl4), 8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_size(%s)\n", bst_ctuple_tostring(A));
    BST_IFEQ(bst_ctuple_size(A), 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_if(%s)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_if(tpl1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_if(%s)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_if(tpl2, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_if(%s)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_if(tpl3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_if(%s)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_if(tpl4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_if(%s)\n", bst_ctuple_tostring(A));
    bst_ctuple_if(A, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_ifempty(%s)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_ifempty(tpl1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_ifempty(%s)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_ifempty(tpl2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_ifempty(%s)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_ifempty(tpl3, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_ifempty(%s)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_ifempty(tpl4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_ifempty(%s)\n", bst_ctuple_tostring(A));
    bst_ctuple_ifempty(A, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_hasN(%s, 4)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasN(tpl1, 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasN(%s, 0)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasN(tpl2, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasN(%s, 6)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasN(tpl3, 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasN(%s, 8)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl4, 8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasN(%s, 0)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasN(A, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasN(%s, 25)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasN(tpl1, 25, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasN(%s, 90)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasN(tpl2, 90, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasN(%s, 21)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasN(tpl3, 21, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasN(%s, 45)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl4, 45, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasN(%s, 7)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasN(A, 7, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_hasLT(%s, 4)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasLT(tpl1, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasLT(%s, 0)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasLT(tpl2, 0, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasLT(%s, 6)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasLT(tpl3, 6, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasLT(%s, 8)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasLT(tpl4, 8, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasLT(%s, 0)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasLT(A, 0, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasLT(%s, 25)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasLT(tpl1, 25, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasLT(%s, 90)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasLT(tpl2, 90, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasLT(%s, 21)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasLT(tpl3, 21, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasLT(%s, 45)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasLT(tpl4, 45, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasLT(%s, 7)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasLT(A, 7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("bst_ctuple_hasGT(%s, 4)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasGT(tpl1, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 0)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasGT(tpl2, 0, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 6)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasGT(tpl3, 6, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 8)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasGT(tpl4, 8, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 0)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasGT(A, 0, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 3)\n", bst_ctuple_tostring(tpl1));
    bst_ctuple_hasGT(tpl1, 3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasGT(%s, 90)\n", bst_ctuple_tostring(tpl2));
    bst_ctuple_hasGT(tpl2, 90, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 1)\n", bst_ctuple_tostring(tpl3));
    bst_ctuple_hasGT(tpl3, 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_hasGT(%s, 45)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasGT(tpl4, 45, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("bst_ctuple_hasGT(%s, 7)\n", bst_ctuple_tostring(A));
    bst_ctuple_hasGT(A, 7, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? -1 : 0;
}
