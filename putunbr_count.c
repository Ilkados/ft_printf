#include "your_printf.h"

int putunbr_count(unsigned int n)
{
    char buf[10];     // max 4294967295 -> 10 digits
    int  i = 0;
    int  len = 0;

    if (n == 0)
        return putchar_count('0');

    while (n > 0)
    {
        buf[i++] = (char)('0' + (n % 10));
        n /= 10;
    }
    while (i-- > 0)
        len += putchar_count(buf[i]);
    return len;
}
