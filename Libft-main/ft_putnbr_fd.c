/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:12:09 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 12:08:19 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the integer n to the given file descriptor*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putnbr_fd(num / 10, fd);
	string = num % 10 + 48;
	write(fd, &string, 1);
}
