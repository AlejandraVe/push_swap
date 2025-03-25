/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:38:40 by alvera-v          #+#    #+#             */
/*   Updated: 2024/12/18 12:58:08 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(int value)
{
	size_t	total;

	total = 0;
	if (value <= 0)
		total++;
	while (value)
	{
		total++;
		value /= 10;
	}
	return (total);
}

void	ft_print_nbr(int n, int fd)
{
	char			string;
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	num = (unsigned int)n;
	if (num > 9)
		ft_print_nbr(num / 10, fd);
	string = num % 10 + 48;
	write(fd, &string, 1);
}

void	ft_putnbr(int n, int *counter)
{
	ft_print_nbr(n, 1);
	(*counter) += ft_numlen(n);
}
