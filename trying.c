#include "your_printf.h"
#include <stdio.h>

int main(void)
{
    int   x = 42;
    void *p = &x;

    ft_printf("char: %c\n", 'A');
    ft_printf("str: %s\n", "hello");
    ft_printf("ptr: %p\n", p);
    ft_printf("dec: %d\n", -123);
    ft_printf("int: %i\n", 456);
    ft_printf("uns: %u\n", 3000000000u);
    ft_printf("hex: %x\n", 48879);
    ft_printf("HEX: %X\n", 48879);
    ft_printf("percent: %%\n");

    return 0;
}
