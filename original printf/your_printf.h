#ifndef YOUR_PRINTF_H
#define YOUR_PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
// our main printf
int ft_printf(const char *format,...);

// helpers function
int putchar_count(char c);
int putstr_count(const char *s);
int putnbr_count(int n);
int put_unsigned_count(unsigned int n);
int putptr_count(void *p);
int put_hex_ul(unsigned long n, char c);
int ft_formats(va_list args, const char *str, size_t *i);

#endif