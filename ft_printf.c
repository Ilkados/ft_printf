#include"your_printf.h"
int ft_printf(const char *restrict format, ...)
  {
    va_list args;
    va_start(args,format);

    size_t i=0;

    int count=0;
     int k=0;
    while( format && format[i]!='\0')
    {
        if(format[i]!='%')
        {
           k=putchar_count(format[i++]);
          if(k<0)
          {
            va_end(args);
            return -1;
          }
            count+=k;
        }
        else{
            i++;
            if(format[i]=='\0')
                break;
            
            if(format[i]=='%')
            {
                k=putchar_count('%');
                if(k<0)
                {
                    va_end(args);
                    return -1;
                } 

                count+=k;
                i++;
                continue;
            }
            else  if(format[i]=='s')
             {
                int k=putstr_count(va_arg(args,char *));

                if(k<0)
                {
                    va_end(args);
                    return -1;
                }
                count+=k;
                i++;
                continue;
             }
          
            else if(format[i]=='d')
            {
               k= putnbr_count(va_arg(args,int));

              if(k<0)
              {
                va_end(args);
                return -1;     
              }
                count+=k;
                i++;
                continue;

            }
            else  if(format[i]=='p')
            {
                k= putptr_count(va_arg(args,void *));

               if(k<0)
               {
                 va_end(args);
                 return -1;
               }
               count+=k;
               i++;
               continue;
            }
        }
        va_end(args);
   }
  }
