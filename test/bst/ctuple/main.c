#include <bst/ctuple.h>
#include <stdio.h>

int main()
{
    #define mytpl ctuple('a', 'b', 'c', 'd')

    // Can get sizes of ctuples.
    printf("mytpl size = %i\n", ctuple_size(mytpl));

    // Can get constant access to ctuples.
    printf("mytpl[0] = %c\n", ctuple_getI(mytpl, 0));
    printf("mytpl[1] = %c\n", ctuple_getI(mytpl, 1));
    printf("mytpl[2] = %c\n", ctuple_getI(mytpl, 2));
    printf("mytpl[3] = %c\n", ctuple_getI(mytpl, 3));

    // Can set constant access to ctuples.
    #define smytpl ctuple_setI(mytpl, 1, 'x')
    printf("smytpl[0] = %c\n", ctuple_getI(smytpl, 0));
    printf("smytpl[1] = %c\n", ctuple_getI(smytpl, 1));
    printf("smytpl[2] = %c\n", ctuple_getI(smytpl, 2));
    printf("smytpl[3] = %c\n", ctuple_getI(smytpl, 3));

    // Can get reverse ctuples.
    #define rmytpl ctuple_reverse(mytpl)
    printf("rmytpl[0] = %c\n", ctuple_getI(rmytpl, 0));
    printf("rmytpl[1] = %c\n", ctuple_getI(rmytpl, 1));
    printf("rmytpl[2] = %c\n", ctuple_getI(rmytpl, 2));
    printf("rmytpl[3] = %c\n", ctuple_getI(rmytpl, 3));
    printf("rmytpl size = %i\n", ctuple_size(rmytpl));

    // Can get trim ctuples.
    #define ltmytpl ctuple_ltrim(mytpl, 2)
    printf("ltmytpl[0] = %c\n", ctuple_getI(ltmytpl, 0));
    printf("ltmytpl[1] = %c\n", ctuple_getI(ltmytpl, 1));
    printf("ltmytpl size = %i\n", ctuple_size(ltmytpl));
    #define rtmytpl ctuple_rtrim(mytpl, 2)
    printf("rtmytpl[0] = %c\n", ctuple_getI(rtmytpl, 0));
    printf("rtmytpl[1] = %c\n", ctuple_getI(rtmytpl, 1));
    printf("rtmytpl size = %i\n", ctuple_size(rtmytpl));
    
    // Can create if-statements and check if has minimum size.
    printf("mytpl %s\n", ctuple_hasLT(mytpl, 5, "size < 5", "size >= 5"));
    printf("mytpl %s\n", ctuple_if(ctuple_ltrim(mytpl, 2), "size > 4", "size < 5"));
    printf("mytpl %s\n", ctuple_if(ctuple_ltrim(mytpl, 0), "size > 3", "size < 4"));
    printf("mytpl %s\n", ctuple_hasN(mytpl, 4, "size == 4", "size != 4"));
    printf("mytpl %s\n", ctuple_hasN(mytpl, 40, "size == 40", "size != 40"));

    // Define symbols in a ctuple to be called.
    #define myf0() a
    #define myf1(a) a
    #define myf2(a, b) a + b
    #define mytplf ctuple(myf0, myf1, myf2)

    #define params ctuple(100, 101)

    printf(
        "invoke %s = %i\n",
        BST_TOSTRING(ctuple_getI(mytplf, ctuple_size(params))),
        ctuple_call(ctuple_getI(mytplf, ctuple_size(params)), params)
    );

    // Can detect if is a ctuple or not.
    printf("is mytpl ctuple? %s\n", ctuple_isa(mytpl, "yes", "no"));
    printf("is int ctuple? %s\n", ctuple_isa(int, "yes", "no"));

    // Force ctuples to resolve and print as a string even if they have symbols.
    printf("rmytpl tostring = %s\n", ctuple_tostring(rmytpl));

    return 0;
}
