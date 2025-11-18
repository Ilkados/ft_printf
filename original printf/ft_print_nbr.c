/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:12:05 by moboulir          #+#    #+#             */
/*   Updated: 2025/11/16 22:12:10 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "your_printf.h"

int	putnbr_count(int n)
{
    char    buf[11];      // up to 10 digits + safety for int
    long    nb;
    int     i;
    int     len;

    nb = n;              
    i = 0;
    len = 0;

    if (nb == 0)
        return putchar_count('0');

    if (nb < 0)
    {
        len += putchar_count('-'); 
        nb = -nb;                  
    }

    while (nb > 0)
    {
        buf[i++] = (char)('0' + (nb % 10));
        nb /= 10;
    }
    while (i-- > 0)
        len += putchar_count(buf[i]);

    return len;
}
