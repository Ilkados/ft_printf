#infdef YOUR_PRINTF_H
#defind YOUR_PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
int ft_printf(const char *format,...);
int putchar_count(char c);
int putstr_count(const char *s);
int	putnbr_count(int n)
char	*ft_itoa(int n);
int	putptr_count(void *p,char c);
int put_unsigned_count(unsigned int n)

#endif