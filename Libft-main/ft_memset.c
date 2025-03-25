/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:46:06 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:43:09 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memset() function fills the first n bytes of the memory area pointed to
by s with the constant byte c.*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	value;
	size_t			i;

	i = 0;
	value = (unsigned char)c;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = value;
		i++;
	}
	return (temp);
}
