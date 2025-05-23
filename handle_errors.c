/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:49:47 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/23 11:12:27 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handle_errors(int argc, char *argv[])
{
	char	**string;

	string = NULL;
	if (!argv[1][0])
		return (0);
	else if (argc > 2)
	{
		if (first_filter(argv) == 0)
		{
			free (string);
			return (0);
		}
		else if (first_filter(argv) == 1)
			string = many_strings(argv);
	}
	if (!string)
	{
		free (string);
		return (0);
	}
	return (string);
}

char	**many_strings(char *argv[])
{
	int		number_of_string;
	char	**string;

	string = NULL;
	number_of_string = count_string(argv) - 1;
	string = (char **)malloc((number_of_string + 1) * sizeof(char *));
	if (!string || argv[1][0] == ' ')
		return (0);
	string = set_string(string, argv);
	if (!string)
	{
		free (string);
		return (0);
	}
	return (string);
}

char	**set_string(char **string, char **argv)
{
	int		n;
	int		i;

	n = 1;
	i = 0;
	while (argv[n])
	{
		string[i] = argv[n];
		i++;
		n++;
	}
	string[i] = '\0';
	return (string);
}
