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

#include <unistd.h>
#include "your_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		putstr_count("-2147483648");
		return ;
	}
	if (n < 0)
	{
		putchar_count('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		putchar_count(n + '0');
}

static int	int_len(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	putnbr_count(int n)
{
	ft_putnbr(n);
	return (int_len(n));
}
