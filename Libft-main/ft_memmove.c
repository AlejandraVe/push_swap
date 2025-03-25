/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:42:24 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:44:32 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copies n bytes from memory area src to memory area dest. It returns a pointer
to dest. The memory areas may overlap: copying takes place as though the  bytes
in src are  first copied into a temporary array that does not overlap src or
dest, and the bytes are then copied from the temporary array to dest*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d == s)
		return (d);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
