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
		printf("%d\n", syntax);
	}
	else if (argc > 2)
	{
		int n = 1;
		int o = 0;
		int counter = 0;
		int	number_of_string;

		number_of_string = count_string(argv) - 1;
		string = (char **)malloc((number_of_string + 1) * sizeof(char *));

	//	for (int i = 0; argv[2][i]; i++)
	//		printf("%c\n", argv[2][i]);
		while (argv[n])
		{
			string[o] = argv[n];
			counter = 0;
			while (argv[n][counter])
			{
				syntax = check_char(string[o][counter]);
				if (syntax == false)
				{
					printf("Error\n");
					return (1);
					break;
				}
				counter++;
			}
			o++;
			n++;
		}
		string[o] = '\0';
	//	ft_bzero(string[o + 1], ft_strlen(argv[0]));
	}
	for (int a = 0; string[a]; a++)
		printf("%s \n", string[a]);
	printf("Syntax after checking if it's one string or several: %d\n", syntax);
	if (syntax == true)
	{
		int i = 1;
		while (j + 1 > i || argc > i) // mientras que el numero de argumentos - 1 sea mayor que 0, guardaré los argumentos en el stack temp
		{
			temp->value = ft_atoi(argv[i]);
			temp->next = stack_a;
			stack_a = temp;
	//		printf("%d\n", stack_a->value);
			i++;
		}
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

/*bool    check_syntax(char *argv)
{
	int		i;
//	int		j;
	bool	ret;

	ret = false;
	i = 0;
//	j = 0;
	while (argv[i])
	{
		if ((ft_isdigit(argv[i]) || (argv[i] == ' ' || argv[i] == '-' || argv[i] == '\t'
			|| argv[i] == '\n' || argv[i] == '\r' || argv[i] == '\f' || argv[i] == '\v')))
		{
			ret = true;
		}
		i++;
	}
	return (ret);
}

void	sort_numbers(Stack stack_a, Stack stack_b)
{
}*/


