/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:00:24 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 10:44:26 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

#include "libft.h"

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
