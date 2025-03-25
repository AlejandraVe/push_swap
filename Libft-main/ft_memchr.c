/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:27:15 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 09:35:06 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Scans the initial n bytes of the memory area pointed
to by s for the first instance of c. Returns a pointer
to the matching byte or NULL if the character does not occur.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	ss = (unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
