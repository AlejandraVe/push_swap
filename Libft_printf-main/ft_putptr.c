/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:30:45 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/04 18:41:07 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_ptrlen(uintptr_t value)
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

void	ft_printp(uintptr_t num)
{
	if (num >= 16)
	{
		ft_printp(num / 16);
		ft_printp(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	ft_putptr(unsigned long long value, int *counter)
{
	if (value == 0)
	{
		ft_putstr("(nil)", counter);
	}
	else
	{
		(*counter) += write(1, "0x", 2);
		ft_printp(value);
		(*counter) += ft_ptrlen(value);
	}
}
