/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:49:47 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/23 11:45:51 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_errors(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || ft_isdigit(*argv)))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(ft_isdigit(argv[1])))
		return (1);
	while (*++argv)
	{
		if (!(ft_isdigit(*argv))
			return (1);
	}
	return (0);
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

bool	first_filter(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (i == 0 && argv[j][i] == '-')
			{
				i = 1;
			}
			if (!ft_isdigit(argv[j][i]) || argv[j][i] == '"' || !argv[j][i])
			{
				write (1, "Error\n", 6);
				return (0);
				break ;
			}
			i++;
		}
		j++;
	}
	return (1);
}

bool	first_filter_one(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (i == 0 && argv[j][i] == '-')
			{
				i = 1;
			}
			if (!ft_isdigit(argv[j][i]) || argv[j][i] == '"' || !argv[j][i])
			{
				write (1, "Error\n", 6);
				return (1);
				break ;
			}
			i++;
		}
		j++;
	}
	return (0);
}
