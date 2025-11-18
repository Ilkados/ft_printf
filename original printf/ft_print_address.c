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

#include <unistd.h>
#include <stdint.h>

static int	putchar(char c)
{
	return (write(1, &c, 1));
}

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

static int	put_hex_ul(unsigned long n, char c)
{
	char		buf[16];
	const char	*base;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (c == 'x' || c=='p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (putchar('0'));
	while (n > 0)
	{
		buf[i] = base[n % 16];
		i++;
		n /= 16;
	}
	while (i > 0)
	{
		i--;
		len += putchar(buf[i]);
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
