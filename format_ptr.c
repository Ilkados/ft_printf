#include <stdarg.h>
#include <stdio.h>

#include <unistd.h>   // write
#include <stdint.h>   // uintptr_t

static int  putchar_fd(char c)
{
    return write(1, &c, 1);
}

static int  putstr_fd(const char *s)
{
    int len = 0;

    if (!s)
        return 0;
    while (*s)
    {
        len += write(1, s, 1);
        s++;
    }
    return len;
}

static int  put_hex_ul(unsigned long n,char c)
{
    char            buf[16];                 // enough for 64-bit in hex
    const char      *base ;
    int             i = 0;
    int             len = 0;

    if(c=='x')
    {
        base="0123456789abcdef";
    }
    else
      base= "0123456789ABCDEF";
    if (n == 0)
        return putchar_fd('0');

    // fill buffer from end (least significant digit first)
    while (n > 0)
    {
        buf[i++] = base[n % 16];
        n /= 16;
    }

    while (i-- > 0)
        len += putchar_fd(buf[i]);
    return len;
}

int putptr_count(void*p)
{
        int printed=0;


    if(!p)
    {
        if(write(1,"(nil)",5)!=1)
        {return -1;}
        return printed+1;
    }
    
    if(write(1,"0x",2)!=2) //size_t
    {return -1;}
    printed+2;

    put_hex_ul((unsigned long )p,'x');
    

    //so now we on the part of turn the pointer into a number for hex;
}
int main()
{

    void *p="ilyas";

    int len=putptr_count(p);

    printf("\nlen %d :",len);
}