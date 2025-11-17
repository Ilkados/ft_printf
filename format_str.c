#include<unistd.h>
#include<stdio.h>
#include "your_printf.h"

int putstr_count(const char *s)
{
    int len=0;
    
    if(!s)
    {
      write(1,"(null)",5);
      return 6;

    }
    
    while(s[len])
      len++;
    
    ssize_t st= write(1,s,(size_t)len);
    
    if(st<0)
    {return -1;}

    return (int)st;
}