#include <bst/ctuple.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    #define tpl1 bst_ctuple('a', 'b', 'c', 'd')
    #define tpl2 bst_ctuple_empty()
    #define tpl3 bst_ctuple(,,,,,)
    #define tpl4 bst_ctuple(18, 17, 16, 15, 14, 13, 12, 11)

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
    printf("bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 0), 18, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 1), 17, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 2), 16, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 3)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 3), 15, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 4)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 4), 14, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 5)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 5), 13, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 6)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 6), 12, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_getI(%s, 7)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl4, 7), 11, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl5 bst_ctuple_append(tpl4, 1)
    printf("bst_ctuple_append(%s, 1)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl5, 8), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_append(%s, 2, 3)\n", bst_ctuple_tostring(tpl5));
    BST_IFEQ(bst_ctuple_getI(bst_ctuple_append(tpl5, 2, 3), 10), 3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl6 bst_ctuple_prepend(tpl4, 1)
    printf("bst_ctuple_prepend(%s, 1)\n", bst_ctuple_tostring(tpl4));
    BST_IFEQ(bst_ctuple_getI(tpl6, 0), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_prepend(%s, 2, 3)\n", bst_ctuple_tostring(tpl6));
    BST_IFEQ(bst_ctuple_getI(bst_ctuple_prepend(tpl6, 2, 3), 0), 2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl7 bst_ctuple_concat((1, 2, 3), (4, 5, 6))
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 0), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 1), 2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 2), 3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 3)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 3), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 4)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 4), 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_concat((1, 2, 3), (4, 5, 6)) -> bst_ctuple_getI(%s, 5)\n", bst_ctuple_tostring(tpl7));
    BST_IFEQ(bst_ctuple_getI(tpl7, 5), 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl8 bst_ctuple_reverse(tpl4)
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 0), 11, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 1), 12, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 2), 13, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 3)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 3), 14, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 4)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 4), 15, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 5)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 5), 16, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 6)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 6), 17, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_reverse(%s) -> bst_ctuple_getI(%s, 7)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl8));
    BST_IFEQ(bst_ctuple_getI(tpl8, 7), 18, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl9 bst_ctuple_collect(tpl4, 3)
    printf("bst_ctuple_collect(%s, 3)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl9, 3, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_collect(%s, 3) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl9));
    BST_IFEQ(bst_ctuple_getI(tpl9, 0), 18, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_collect(%s, 3) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl9));
    BST_IFEQ(bst_ctuple_getI(tpl9, 1), 17, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_collect(%s, 3) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl9));
    BST_IFEQ(bst_ctuple_getI(tpl9, 2), 16, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl10 bst_ctuple_ltrim(tpl4, 3)
    printf("bst_ctuple_ltrim(%s, 3)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl10, 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_ltrim(%s, 3) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl9));
    BST_IFEQ(bst_ctuple_getI(tpl10, 0), 15, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_ltrim(%s, 3) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl10));
    BST_IFEQ(bst_ctuple_getI(tpl10, 1), 14, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_ltrim(%s, 3) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl10));
    BST_IFEQ(bst_ctuple_getI(tpl10, 2), 13, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl11 bst_ctuple_rtrim(tpl4, 3)
    printf("bst_ctuple_rtrim(%s, 3)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl11, 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_rtrim(%s, 3) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl9));
    BST_IFEQ(bst_ctuple_getI(tpl11, 2), 16, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_rtrim(%s, 3) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl11));
    BST_IFEQ(bst_ctuple_getI(tpl11, 3), 15, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_rtrim(%s, 3) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl11));
    BST_IFEQ(bst_ctuple_getI(tpl11, 4), 14, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    #define tpl12 bst_ctuple_setI(tpl4, 2, 5)
    printf("bst_ctuple_setI(%s, 3)\n", bst_ctuple_tostring(tpl4));
    bst_ctuple_hasN(tpl12, 8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 0)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 0), 18, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 1)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 1), 17, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 2)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 2), 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 3)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 3), 15, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 4)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 4), 14, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 5)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 5), 13, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 6)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 6), 12, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("bst_ctuple_setI(%s, 3) -> bst_ctuple_getI(%s, 7)\n", bst_ctuple_tostring(tpl4), bst_ctuple_tostring(tpl12));
    BST_IFEQ(bst_ctuple_getI(tpl12, 7), 11, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? -1 : 0;
}
