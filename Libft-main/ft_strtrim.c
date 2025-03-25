/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:17:30 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:37:43 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/

#include "libft.h"

static int	ft_trim(const char c, const char *set);
static char	*ft_newstring(const char *s1, size_t start, size_t len);

int	ft_trim(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_newstring(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (len == 0)
		return (ft_strdup(""));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_trim(s1[i], set))
		i++;
	while (j > i && ft_trim(s1[j], set))
		j--;
	return (ft_newstring(s1, i, j - i + 1));
}
