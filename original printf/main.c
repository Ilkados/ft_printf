#include"your_printf.h"
#include<stdio.h>
#include<limits.h>

int main()
{
    int ret_ft;
    int ret_or;

    int a= 42;
    int b=-42;

    unsigned int  u= 4294967295u;

    char  c= 'a';
    char *s = "HELLO";

    char *null_s = NULL;

    void *p =&a;

    void *null_p = NULL:

        printf("=== %%c ===\n");

    ret_ft = ft_printf("ft : [%c]\n",c);
    ret_or = printf("or : [%c]\n",c);
    printf("ret ft = %d, ret or  = %d\n\n",ret_ft,ret_or);
}