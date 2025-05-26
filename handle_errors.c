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
	if (!(*argv == '-' || ft_isdigit(*argv)))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(ft_isdigit(argv[1])))
		return (1);
	while (*++argv)
	{
		if (!(ft_isdigit(*argv)))
			return (1);
	}
	return (0);
}

void	print_error(t_Stack **stack)
{
	free_stack(stack);
	write (1, "Error\n", 6);
	exit (1);
}

void	free_stack(t_Stack **stack)
{
	t_Stack *temp;
	t_Stack *top;

	if (!stack)
		return ;
	top = *stack;
	while (top)
	{
		temp = top->next;
		top->value = 0;
		free(top);
		top = temp;
	}
	*stack = NULL;
}

int	check_duplicates(t_Stack *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
