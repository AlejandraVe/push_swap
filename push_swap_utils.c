/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:18:37 by alvera-v          #+#    #+#             */
/*   Updated: 2025/03/25 12:44:21 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	neg;

	ret = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = ret * 10 + (*nptr - 48);
		nptr++;
	}
	return (ret * neg);
}

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

static int	count_chars(char const *s, char c)
{
	int	i;
	int	j;
	int	new_word;

	i = 0;
	j = 0;
	new_word = 0;
	while (s[i])
	{
		if (s[i] != c && new_word == 0)
		{
			new_word = 1;
			j++;
		}
		else if (s[i] == c)
		{
			new_word = 0;
		}
		i++;
	}
	return (j);
}

static int	search_c(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	next_char(char const *s, char c, int i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static void	free_string(char **string, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(string[j]);
		j++;
	}
	free(string);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		number_of_chars;
	char	**string;

	i = 0;
	j = 0;
	number_of_chars = count_chars(s, c);
	string = (char **)malloc((number_of_chars + 1) * sizeof(char *));
	if (!string)
		return (NULL);
	while (i < number_of_chars)
	{
		j = next_char(s, c, j);
		string[i] = ft_substr(s, j, search_c(s, c, j) - j);
		if (!string[i])
		{
			free_string(string, i);
			return (NULL);
		}
		j = search_c(s, c, j);
		i++;
	}
	string[i] = NULL;
	return (string);
}

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
