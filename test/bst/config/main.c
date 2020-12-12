#include <bst/config.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    printf("BST_IFEQ(0, 0)\n");
    BST_IFEQ(0, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_IFEQ(0, 1)\n");
    BST_IFEQ(0, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BST_IFEQ(10, 1)\n");
    BST_IFEQ(10, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_IFLT(0, 1)\n");
    BST_IFLT(0, 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_IFLT(30, 4)\n");
    BST_IFLT(30, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BST_IFLT(1, 1)\n");
    BST_IFLT(1, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_IFGT(0, 1)\n");
    BST_IFGT(1, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_IFGT(3, 4)\n");
    BST_IFGT(3, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BST_IFGT(1, 1)\n");
    BST_IFGT(1, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_GET_ARG0(8, 7, 6, 5)\n");
    BST_IFEQ(BST_GET_ARG0(8, 7, 6, 5), 8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_GET_ARG1(8, 7, 6, 5)\n");
    BST_IFEQ(BST_GET_ARG1(8, 7, 6, 5), 7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_GET_ARG2(8, 7, 6, 5)\n");
    BST_IFEQ(BST_GET_ARG2(8, 7, 6, 5), 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_GET_ARG3(8, 7, 6, 5)\n");
    BST_IFEQ(BST_GET_ARG3(8, 7, 6, 5), 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_CONST_ADD1(3)\n");
    BST_IFEQ(BST_CONST_ADD1(3), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_CONST_ADD1(8)\n");
    BST_IFEQ(BST_CONST_ADD1(8), 9, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_CONST_ADD1(30)\n");
    BST_IFEQ(BST_CONST_ADD1(30), 31, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_CONST_SUB1(3)\n");
    BST_IFEQ(BST_CONST_SUB1(3), 2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_CONST_SUB1(8)\n");
    BST_IFEQ(BST_CONST_SUB1(8), 7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_CONST_SUB1(30)\n");
    BST_IFEQ(BST_CONST_SUB1(30), 29, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BST_ARGCNT(A, B, C, D)\n");
    BST_IFEQ(BST_ARGCNT(A, B, C, D), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_ARGCNT(A)\n");
    BST_IFEQ(BST_ARGCNT(A), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BST_ARGCNT((A, B, C))\n");
    BST_IFEQ(BST_ARGCNT((A, B, C)), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? -1 : 0;
}
