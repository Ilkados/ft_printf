#include "your_printf.h"

int put_unsigned_count(unsigned int n)
{
  int tmp ;
  int buffer=0;

 // system calle 
  if(n>0)
  {
    tmp= pu_usigned_count(n/10);

    // here when we come back  from recursion:

    if(tmp<0)
       return -1

    buffer+=tmp;
  }

  tmp= putchar_count('0'+(n % 10)); // print last digit

  if(tmp<0)
    return -1;
    buffer+=tmp;
    return buffer;
}
