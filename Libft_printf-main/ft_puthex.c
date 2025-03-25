/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:06 by alvera-v          #+#    #+#             */
/*   Updated: 2024/12/18 12:13:45 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(unsigned int value)
{
	size_t	total;

	total = 0;
	if (value <= 0)
		total++;
	while (value)
	{
		total++;
		value /= 16;
	}
	return (total);
}

void	ft_printhex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_printhex(num / 16, c);
		ft_printhex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (c == 'x')
				ft_putchar((num - 10 + 'a'));
			if (c == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

void	ft_puthex(unsigned int value, const char c, int *counter)
{
	if (value == 0)
		(*counter) += (write(1, "0", 1));
	else
	{
		ft_printhex(value, c);
		(*counter) += ft_hexlen(value);
	}
}
