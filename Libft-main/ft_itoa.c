/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:44:34 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 13:52:54 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_char(int size, int n)
{
	char	*ret;
	int		i;
	long	temp;

	i = size - 1;
	temp = n;
	ret = (char *)malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[size] = '\0';
	if (temp < 0)
	{
		ret[0] = '-';
		temp = -temp;
	}
	while (temp)
	{
		ret[i--] = 48 + (temp % 10);
		temp = temp / 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	long	temp;
	int		size;
	char	*ret;

	size = 0;
	temp = (long)n;
	if (temp == 0)
		size = 1;
	if (temp < 0)
	{
		temp = -temp;
		size++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		size++;
	}
	ret = get_char(size, n);
	return (ret);
}
