#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<stdarg.h>
#include<string.h>
int max(int num_args,...);
void print(char *placeholders,...);

int main(void)
{
    //int mx= max(3,12,99,16);

   // printf("the max num %d\n: ",mx);

   //print("ffdd",12.2,14.3,45,78);

   fprintf(stdout,"hello\n");
    return 0;
}

int max(int num_args,...)
{

       return INT_MIN;

    va_list args;
    va_start(args,num_args);

    int mx= va_arg(args,int);  //read the first number;
    for(int i=0;i<num_args;i++)
    {
        int x=va_arg(args,int);// read next number

        if(x>mx)
        {
            mx=x;     //keep the largest
        }
    }

    va_end(args);       //cleanup;
    return mx;
}

void print(char *placeholders,...)
{
    int num_args = strlen(placeholders);

    va_list args;
    va_start(args,placeholders);

    for(int i=0;i<num_args;i++)
    {
        if(placeholders[i]=='d')
        {
            int x=va_arg(args,int);
            printf("%d\n",x);
        }
        else if(placeholders[i]=='f')
        {
            double x=va_arg(args,double);
            printf("%f\n",x);
        }
    }
    va_end(args);
}


void print_ints_twice(int n,...)
{
    va_list a,b;
    va_start(a,n); //start reading after n
    va_copy(b,a);

   // 1st pass user 'a' 
   
   printf("pass 1: ");
    for(int i=0; i<n;i++)
    {
        printf("%d ",va_arg(a,int));
    }
    printf("\n");



    //2nd pass user the Copy 'b'

    printf("pass 2: ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",va_arg(b,int));
    }
    printf("\n");

    va_end(b);
    va_end(a);
}