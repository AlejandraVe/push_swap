/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_appendings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:54:10 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/28 12:35:39 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_Stack **stack, int n)
{
	t_Stack	*node;
	t_Stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_Stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	initialize_stack_a(t_Stack **stack_a, char *argv[], int free_argv)
{
	long	n;
	int		i;

	i = 0;
	if (!stack_a)
		return ;
	while (argv[i])
	{
		if (handle_errors(argv[i]) == 1)
			print_error(stack_a, argv, free_argv);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(stack_a, argv, free_argv);
		if (check_duplicates(*stack_a, (int)n) == 1)
			print_error(stack_a, argv, free_argv);
		append_node(stack_a, (int)n);
		i++;
	}
}

t_Stack	*find_last(t_Stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	check_index(t_Stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	begin_sort_b(t_Stack *a, t_Stack *b)
{
	check_index(a);
	check_index(b);
	check_target_node_b(a, b);
}
