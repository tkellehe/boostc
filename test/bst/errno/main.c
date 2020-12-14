#include <bst/errno.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    int error;

    //--------------------------------------------------------------------------------------------------------
    error = ETIME;
    printf("bst_set_errno & bst_get_errno\n");
    bst_set_errno(error);
    if(bst_get_errno() == error)
    {
        ++num_pass;
        printf("    passed\n");
    }
    else
    {
        ++num_fail;
        printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    error = EPROTO;
    printf("errno\n");
    errno = error;
    if((int)errno == error)
    {
        ++num_pass;
        printf("    passed\n");
    }
    else
    {
        ++num_fail;
        printf("    failed\n");
    }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");
    return 0;
}
