/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:31:55 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:47:08 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compares the first n bytes (each interpreted as unsigned
       char) of the memory areas s1 and s2. returns an integer less than,
	   equal to, or  greater  than zero  if  the  first  n bytes of s1 is
	   found, respectively, to be less than, to match, or be greater than the
	   first n bytes of s2.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((i < n) && (ss1 || ss2))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
