/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:38:44 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:45:17 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*appends the NUL-terminated string src to the end of dst. It will append at
most size - strlen(dst) - 1 bytes, NUL-terminating the result.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	i = 0;
	d = ft_strlen((char const *)dst);
	s = ft_strlen(src);
	if (dst == NULL && src == NULL)
		return (0);
	if (size <= d)
		return (size + s);
	else
	{
		while ((src[i] != '\0') && (d + i < size - 1))
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
	}
	return (d + s);
}
