/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:49:47 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/20 13:42:07 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handle_errors(int argc, char *argv[])
{
	char	**string;

	string = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	else if (argc > 2)
		string = many_strings(argv);
	if (!string)
		return (0);
	return (string);
}

bool	one_string(char *argv[])
{
	int	i;

	i = 0;
	if (argv[1][i] == '"')
		i++;
	if (argv[1][i] == ' ' || !ft_isdigit(argv[1][i]) || argv[1][i] != '-')
		return (0);
	while (argv[1][i])
	{
		if (check_char(argv[1][i]) == false)
		{
			return (0);
			break ;
		}
		i++;
	}
	return (1);
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
	return (string);
}

char	**set_string(char **string, char **argv)
{
	int		n;
	int		i;
	int		counter;

	n = 1;
	i = 0;
	while (argv[n])
	{
		string[i] = argv[n];
		counter = 0;
		if (string[i][counter] == '-')
			counter++;
		while (argv[n][counter])
		{
			if ((check_char(string[i][counter])) == false)
				return (0);
			counter++;
		}
		i++;
		n++;
	}
	string[i] = '\0';
	return (string);
}

bool	check_char(char c)
{
	if (ft_isdigit(c))
		return (1);
	else
		return (0);
}
