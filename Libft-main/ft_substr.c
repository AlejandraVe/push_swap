/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:16:59 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 10:09:00 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*s is the string which to create the substring.
start is the index of the substring in the string "s".
len is the maximum length of the substring
It returns the substring or NULL if the allocation fails*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s || start >= ft_strlen(s))
	{
		ret = (char *)malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	while (len > 0 && len--)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
