/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:36:47 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:47:34 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*locates the first occurrence of the null-terminated string little in the
string big, where not more than len characters are searched.*/

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!l[0])
		return ((char *)b);
	while (b[i] && i < n)
	{
		j = 0;
		while (b[i + j] == l[j] && (i + j) < n)
		{
			if (l[j + 1] == '\0')
				return ((char *)b + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
