/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:54:19 by moboulir          #+#    #+#             */
/*   Updated: 2025/11/16 21:54:22 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "your_printf.h"


static int	putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len += write(1, s, 1);
		s++;
	}
	return (len);
}
int	putptr_count(void *p)
{
	int	printed;

	printed = 0;
	if (!p)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) != 2)
		return (-1);
	printed += 2;
	printed += put_hex_ul((unsigned long)p, 'x');
	return (printed);
}
