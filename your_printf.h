#ifndef YOUR_PRINTF_H
#define YOUR_PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
int ft_printf(const char *format,...);
int putchar_count(char c);
int putstr_count(const char *s);
int putnbr_count(int n);
char	*ft_itoa(int n);
int putptr_count(void *p);
int put_hex_ul(unsigned long n, char c);
int putunbr_count(unsigned int n);

#endif