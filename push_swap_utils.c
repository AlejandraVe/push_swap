/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:18:37 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/27 12:32:13 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_string(char **string)
{
	int	j;

	j = 0;
	while (string[j])
	{
		free(string[j]);
		j++;
	}
	free(string);
}

char	**ft_split(char *s, char c)
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
			free_string(string);
			return (NULL);
		}
		j = search_c(s, c, j);
		i++;
	}
	string[i] = NULL;
	return (string);
}
