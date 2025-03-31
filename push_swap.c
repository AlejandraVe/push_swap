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
 //   Stack   *stack_b;
    Stack   *temp;
	bool	syntax; // bool can be either true or false
	char	**string = NULL; // doble puntero porque es un array de strings
	int		j;

	j = 0;
	syntax = true;
	temp = (Stack *)malloc(sizeof(Stack));
	stack_a = (Stack *)malloc(sizeof(Stack));
//	stack_b = (Stack *)malloc(sizeof(Stack));
	if (argc < 2 || !argv[1][0])
		return (1);
	else if (argc == 2) // this means the given numbers are a string, so we need to split it
	{
		if (argv[1][j] == '"')
			j++;
		while (argv[1][j])
		{
			syntax = check_char(argv[1][j]);
			if (syntax == false)
			{
				printf("Error\n");
				return (1);
				break;
			};
			j++;
		}
		string = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
	{
		int n = 1;
		int i = 0;
		int counter = 0;
		int	number_of_string;

		number_of_string = count_string(argv) - 1;
		string = (char **)malloc((number_of_string + 1) * sizeof(char *));

	//	for (int i = 0; argv[2][i]; i++)
	//		printf("%c\n", argv[2][i]);
		while (argv[n])
		{
			string[i] = argv[n];
			counter = 0;
			while (argv[n][counter])
			{
				syntax = check_char(string[i][counter]);
				if (syntax == false)
				{
					printf("Error\n");
					return (1);
					break;
				}
				counter++;
			}
			i++;
			n++;
		}
		string[i] = '\0';
	//	ft_bzero(string[o + 1], ft_strlen(argv[0]));
	}
	printf("%d\n", syntax);
	syntax = check_duplicates(string);
	printf("chck dupo: %d\n", syntax);
	if (syntax == true)
	{
		// I need a function that checks out for duplicates and for integer overflowing
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
		printf("%d\n", stack_a->value);
	}
//	sort_numbers(stack_a, stack_b);
	free (temp);
	return (0);
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

	for (int o = 0; s[o]; o++)
	{
		numbers[o] = ft_atoi(s[o]);
		printf("%d\n", numbers[o]);
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
/*

void	sort_numbers(Stack stack_a, Stack stack_b)
{
}*/
