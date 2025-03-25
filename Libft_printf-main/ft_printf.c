/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:10:20 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/07 10:49:15 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(const char c, va_list value, int *counter)
{
	if (c == 'c')
	{
		++(*counter);
		ft_putchar(va_arg(value, int));
	}
	else if (c == 's')
		ft_putstr(va_arg(value, char *), counter);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(value, int), counter);
	else if (c == 'p')
		ft_putptr(va_arg(value, unsigned long long), counter);
	else if (c == 'u')
		ft_putunsigned(va_arg(value, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(value, unsigned int), c, counter);
	else if (c != 0)
	{
		++(*counter);
		ft_putchar(c);
	}
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			counter += ft_putchar(*str);
		else
			ft_type(*++str, args, &counter);
		++str;
	}
	va_end(args);
	return (counter);
}
