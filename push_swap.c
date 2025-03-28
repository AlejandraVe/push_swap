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
    int		i;
	int		j;
	int		n;

	i = 1;
	j = 0;
	n = 1;
	if (argc < 2 || !argv[1][0])
		return (1);
	temp = (Stack *)malloc(sizeof(Stack));
	stack_a = (Stack *)malloc(sizeof(Stack));
//	stack_b = (Stack *)malloc(sizeof(Stack));
	if (argc == 2) // this means the given numbers are a string, so we need to split it
	{
		char	**string; // doble puntero porque es un array de strings
		string = ft_split(argv[1], ' ');
		while (string[j])
		{
			argv[j + 1] = string[j]; // I store every string of array "string" in argv[j + 1], so that it's in position 1
			j++;
			//printf("%s\n", argv[j + 1]);
		}
	}
	while (argv[n])
	{
		syntax = check_syntax(argv[n]);
		if (syntax == false)
			break;
	}
	if (syntax == true)
	{
		while (j + 1 > i || argc > i) // mientras que el numero de argumentos - 1 sea mayor que 0, guardaré los argumentos en el stack temp
		{
			temp->value = ft_atoi(argv[i]);
			temp->next = stack_a;
			stack_a = temp;
			printf("%d\n", stack_a->value);
			i++;
		}
	}
	else
	{
		printf("Error\n");
	}
//	sort_numbers(stack_a, stack_b);
	free (temp);
	return (0);
}

bool    check_syntax(char *argv)
{
	int		i;
//	int		j;
	bool	ret;

	ret = true;
	i = 0; // because i want to check the info from the argument value 1st position
//	j = 0;
	while (argv[i])
	{
		if ((ft_isdigit(argv[i]) || (argv[i][j] != ' ' || argv[i][j] != '-' || argv[i][j] != '\t'
			|| argv[i][j] != '\n' || argv[i][j] != '\r' || argv[i][j] != '\f' || argv[i][j] != '\v')))
		{
			ret = true;
		}
		else
		{
			ret = false;
			break;
		}
	i++;
	}
	return (ret);
}

/*void	sort_numbers(Stack stack_a, Stack stack_b)
{
}*/



// to define a stack https://www.digitalocean.com/community/tutorials/stack-in-c
// another option to define a stack https://dev.to/josethz00/data-structures-in-c-stack-55c7#:~:text=Stack%20implementation%20(struct),as%20the%20primitive%20type%20char%20.
