#include <boostc/errno.h>
#include <stdio.h>

int main()
{
    int num_pass = 0;
    int num_fail = 0;

    // int error;

    // //--------------------------------------------------------------------------------------------------------
    // error = ETIME;
    // printf("bstc_set_errno & bstc_get_errno\n");
    // bstc_set_errno(error);
    // if(bstc_get_errno() == error)
    // {
    //     ++num_pass;
    //     printf("    passed\n");
    // }
    // else
    // {
    //     ++num_fail;
    //     printf("    failed\n");
    // }

    // //--------------------------------------------------------------------------------------------------------
    // error = EPROTO;
    // printf("errno\n");
    // bstc_errno = error;
    // if((int)bstc_errno == error)
    // {
    //     ++num_pass;
    //     printf("    passed\n");
    // }
    // else
    // {
    //     ++num_fail;
    //     printf("    failed\n");
    // }

    //--------------------------------------------------------------------------------------------------------
    printf("-----------------------------\n");
    printf("     pass     |     fail     \n");
    printf("     %04i     |     %04i     \n", num_pass, num_fail);
    printf("-----------------------------\n");
    return 0;
}
