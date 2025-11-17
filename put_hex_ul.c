#include "your_printf.h"

int put_hex_ul(unsigned long n, char c)
{
    char        buf[16];    // enough for 64-bit in hex
    const char  *base;
    int         i = 0;
    int         len = 0;

    if (c == 'x'|| c =='p')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";

    if (n == 0)
        return putchar_count('0');

    while (n > 0)
    {
        buf[i++] = base[n % 16];
        n /= 16;
    }
    while (i-- > 0)
        len += putchar_count(buf[i]);
    return len;
}
