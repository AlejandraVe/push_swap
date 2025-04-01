/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:04:20 by alvera-v          #+#    #+#             */
/*   Updated: 2025/03/26 10:32:43 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Stack   *stack_a;
    Stack   *stack_b;
    Stack   *temp;
	bool	syntax; // bool can be either true or false
	char	**string = NULL; // doble puntero porque es un array de strings
	int		j;

	j = 0;
	syntax = true;
	temp = (Stack *)malloc(sizeof(Stack));
	stack_a = (Stack *)malloc(sizeof(Stack));
	stack_b = (Stack *)malloc(sizeof(Stack));
	string = handle_errors(argc, argv);
	if (!string)
	{
		printf("Error\n");
		free(stack_a);
		free(temp);
		return (1);
	}
	if ((syntax = check_duplicates(string)) == true)
	{
		int number_of_strings;

		number_of_strings = count_string(string) - 1;
		j = 0;
		while (j <= number_of_strings)
		{
			temp->value = ft_atoi(string[number_of_strings]);
			temp->next = stack_a;
			stack_a = temp;
			number_of_strings--;
		}
		free(string);
		printf("%d\n", stack_a->value);
	}
	sort_numbers(stack_a, stack_b);
	free (temp);
	return (0);
}

char	**handle_errors(int argc, char *argv[])
{
	bool	syntax;
	char	**string = NULL;
	int		j;

	j = 0;
	syntax = true;
	if (argc < 2 || !argv[1][0])
		return (0);
	else if (argc == 2) // this means the given numbers are a string, so we need to split it
	{
		if (argv[1][j] == '"')
			j++;
		while (argv[1][j])
		{
			syntax = check_char(argv[1][j]);
			if (syntax == false)
			{
				return (0);
				break;
			};
			j++;
		}
		string = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
	{
		string = many_strings(argv);
	}
	return (string);
}

char	**many_strings(char *argv[])
{
	int 	n;
	int 	i;
	int 	counter;
	int		number_of_string;
	char 	**string = NULL;
	bool	syntax;

	n = 1;
	i = 0;
	counter = 0;
	number_of_string = count_string(argv) - 1;
	string = (char **)malloc((number_of_string + 1) * sizeof(char *));
	if (!string)
		return (0);
	while (argv[n])
	{
		string[i] = argv[n];
		counter = 0;
		while (argv[n][counter])
		{
			if ((syntax = check_char(string[i][counter])) == false)
			{
				return (0);
				break;
			}
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
	if (ft_isdigit(c) || c == ' ' || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

bool    check_duplicates(char **s)
{
	int i;
	int	j;
	int ret;
	i = count_string(s);
	int *numbers = NULL;

	numbers = (int *)malloc((i + 1) * sizeof(int));
	j = 0;
	while (s[j])
	{
		numbers[j] = ft_atoi(s[j]);
		j++;
	}
	i = 0;
	ret = true;
	while (numbers[i])
	{
		j = 1;
		while (numbers[i] != numbers[i + j] && numbers[i + j])
		{
			j++;
		}
		if (numbers[i] == numbers[i + j])
		{
			ret = false;
			break;
		}
		i++;
	}
	printf("%d\n", ret);
	return (ret);
}
