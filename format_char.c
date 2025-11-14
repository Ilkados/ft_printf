#include"your_printf.h"
int putchar_count(char c)
{
    return (int)write(1,&c,1);
}