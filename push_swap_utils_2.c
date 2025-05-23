/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:59:58 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/23 10:44:26 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	count_string(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	first_filter(char *argv[])
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
			i++;
		if (!ft_isdigit(argv[1][i]) || argv[1][i] == '"' || !argv[1][i])
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
