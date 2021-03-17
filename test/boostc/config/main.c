//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    bstc_unused_param(argc);;
    bstc_unused_param(argv);;
    int num_pass = 0;
    int num_fail = 0;

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC Environment:\n");
    #if defined(BSTC_OSAPI_WINDOWS)
    printf("    BSTC_OSAPI_WINDOWS\n");
    #elif defined(BSTC_OSAPI_POSIX)
    printf("    BSTC_OSAPI_POSIX\n");
    #endif
    printf("    BSTC_COMPILER_CONFIG: %s\n", BSTC_COMPILER_CONFIG);
    printf("    BSTC_PLATFORM_CONFIG: %s\n", BSTC_PLATFORM_CONFIG);

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_IFEQ(0, 0)\n");
    BSTC_IFEQ(0, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IFEQ(0, 1)\n");
    BSTC_IFEQ(0, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IFEQ(10, 1)\n");
    BSTC_IFEQ(10, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_IFLT(0, 1)\n");
    BSTC_IFLT(0, 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IFLT(30, 4)\n");
    BSTC_IFLT(30, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IFLT(1, 1)\n");
    BSTC_IFLT(1, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_IFGT(0, 1)\n");
    BSTC_IFGT(1, 0, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IFGT(3, 4)\n");
    BSTC_IFGT(3, 4, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IFGT(1, 1)\n");
    BSTC_IFGT(1, 1, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_GET_ARG0(8, 7, 6, 5)\n");
    BSTC_IFEQ(BSTC_GET_ARG0(8, 7, 6, 5), 8, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_GET_ARG1(8, 7, 6, 5)\n");
    BSTC_IFEQ(BSTC_GET_ARG1(8, 7, 6, 5), 7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_GET_ARG2(8, 7, 6, 5)\n");
    BSTC_IFEQ(BSTC_GET_ARG2(8, 7, 6, 5), 6, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_GET_ARG3(8, 7, 6, 5)\n");
    BSTC_IFEQ(BSTC_GET_ARG3(8, 7, 6, 5), 5, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_CONST_ADD1(3)\n");
    BSTC_IFEQ(BSTC_CONST_ADD1(3), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_CONST_ADD1(8)\n");
    BSTC_IFEQ(BSTC_CONST_ADD1(8), 9, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_CONST_ADD1(30)\n");
    BSTC_IFEQ(BSTC_CONST_ADD1(30), 31, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_CONST_SUB1(3)\n");
    BSTC_IFEQ(BSTC_CONST_SUB1(3), 2, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_CONST_SUB1(8)\n");
    BSTC_IFEQ(BSTC_CONST_SUB1(8), 7, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_CONST_SUB1(30)\n");
    BSTC_IFEQ(BSTC_CONST_SUB1(30), 29, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_ARGCNT(A, B, C, D)\n");
    BSTC_IFEQ(BSTC_ARGCNT(A, B, C, D), 4, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_ARGCNT(A)\n");
    BSTC_IFEQ(BSTC_ARGCNT(A), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_ARGCNT((A, B, C))\n");
    BSTC_IFEQ(BSTC_ARGCNT((A, B, C)), 1, (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_ISA_TUPLE(())\n");
    BSTC_ISA_TUPLE((), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_ISA_TUPLE(A)\n");
    BSTC_ISA_TUPLE(A, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_ISA_TUPLE()\n");
    BSTC_ISA_TUPLE(, (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("BSTC_IF_ARG0_EMPTY(())\n");
    BSTC_IF_ARG0_EMPTY((), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IF_ARG0_EMPTY((,))\n");
    BSTC_IF_ARG0_EMPTY((,), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IF_ARG0_EMPTY((,A))\n");
    BSTC_IF_ARG0_EMPTY((,A), (++num_pass, printf("    passed\n")), (++num_fail, printf("    failed\n")));
    printf("BSTC_IF_ARG0_EMPTY((1,2))\n");
    BSTC_IF_ARG0_EMPTY((1,2), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY((B,A))\n");
    BSTC_IF_ARG0_EMPTY((B,A), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY(('1','2'))\n");
    BSTC_IF_ARG0_EMPTY(('1','2'), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY((\"1\",\"2\"))\n");
    BSTC_IF_ARG0_EMPTY(("1","2"), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY(((\"1\"),\"2\"))\n");
    BSTC_IF_ARG0_EMPTY((("1"),"2"), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY(((),\"2\"))\n");
    BSTC_IF_ARG0_EMPTY(((),"2"), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    printf("BSTC_IF_ARG0_EMPTY((((),),\"2\",,))\n");
    BSTC_IF_ARG0_EMPTY((((),),"2",,), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));
    #define ARG0_EMPTY_TEST() 0,0
    printf("BSTC_IF_ARG0_EMPTY((ARG0_EMPTY_TEST))\n");
    BSTC_IF_ARG0_EMPTY((ARG0_EMPTY_TEST), (++num_fail, printf("    failed\n")), (++num_pass, printf("    passed\n")));

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");

    return num_fail ? bstc_exit_failure : bstc_exit_success;
}
