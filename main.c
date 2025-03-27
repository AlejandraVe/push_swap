/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:04:20 by alvera-v          #+#    #+#             */
/*   Updated: 2025/03/26 10:31:01 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(Stack stack_a);
void	sort_numbers(Stack stack_a, Stack stack_b);

int main(int argc, char *argv[])
{
    Stack   *stack_a;
    Stack   *stack_b;
    Stack   *temp;
    int		i;

	i = 1;
	if (argc < 2)
		return (1);
	temp = (Stack *)malloc(sizeof(Stack));
	stack_a = (Stack *)malloc(sizeof(Stack));
	stack_b = (Stack *)malloc(sizeof(Stack));
	while (argc > i) // mientras que el numero de argumentos - 1 sea mayor que 0, guardaré los argumentos en el stack temp
	{
		temp->value = ft_atoi(argv[i]);
		temp->next = stack_a;
		stack_a = temp;
		i++;
	}
	sort_numbers(stack_a, stack_b);
	return (0);
}

void	sort_numbers(Stack stack_a, Stack stack_b)
{
	Stack	*temp;

	while (stack_a->value != NULL)
    {
        while (stack_a->value > stack_a->next)
        {
			sa(stack_a);
        }
    }
}

void	sa(Stack stack_a)
{
	Stack *temp;

	temp = (Stack *)malloc(sizeof(Stack));
	temp = stack_a;
	stack_a->value = temp->next;
	stack_a->next = temp->value;
	free(temp);
}

// to define a stack https://www.digitalocean.com/community/tutorials/stack-in-c
// another option to define a stack https://dev.to/josethz00/data-structures-in-c-stack-55c7#:~:text=Stack%20implementation%20(struct),as%20the%20primitive%20type%20char%20.
