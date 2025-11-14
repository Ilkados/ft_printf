#include<unistd.h>
#include<stdio.h>
int putstr_count(const char *s)
{
    int len=0;
    
    if(!s)
    {
      write(1,"(nil)",5);
      return 5;

    }
    
    while(s[len])
      len++;
    
    ssize_t st= write(1,s,(size_t)len);
    
    if(st<0)
    {return -1;}

    return (int)st;
}