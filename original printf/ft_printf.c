#include "your_printf.h"


int ft_formats(va_list args, const char *str, size_t *i)
{
    int buffer = 0;
    int tmp;

    if (str[*i] == 'c')
    {
        tmp = putchar_count(va_arg(args, int));
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i] == 's')
    {
        tmp = putstr_count(va_arg(args, char *));
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i] == 'd' || str[*i] == 'i')
    {
        tmp = putnbr_count(va_arg(args, int));
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i] == 'p')
    {
        tmp = putptr_count(va_arg(args, void *));
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i] == 'x' || str[*i] == 'X')
    {
        unsigned int n = va_arg(args, unsigned int);
        tmp = put_hex_ul(n, str[*i]);   // 'x' or 'X'
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i] == '%')
    {
        tmp = putchar_count('%');
        if (tmp < 0)
            return -1;
        buffer += tmp;
    }
    else if (str[*i]=='u')
    {
      
      tmp= put_unsigned_count(va_arg(args,unsigned int));

      if(tmp<0)
       return -1;
      buffer+=tmp;
    }

    return buffer;
}


int ft_printf(const char *restrict format, ...)
{
    va_list args;
    size_t  i;
    int     count;
    int     buf;

    va_start(args, format);
    i = 0;
    count = 0;

    while (format && format[i] != '\0')
    {
        if (format[i] != '%')
        {
            buf = putchar_count(format[i++]);
            if (buf < 0)
            {
                va_end(args);
                return -1;
            }
            count += buf;
        }
        else
        {
            i++;                    
            if (format[i] == '\0')  
                break;

          
            buf = ft_formats(args, format, &i);
            if (buf < 0)
            {
                va_end(args);
                return -1;
            }
            count += buf;
            i++;                   
        }
    }
    va_end(args);
    return count;
}
