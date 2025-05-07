/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:54:45 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:19:31 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_Stack *stack)
{
	int	total;

	total = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		total++;
	}
	return (total);
}

void	check_target_node_a(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Stack	*top_b;
	t_Stack	*target;
	long	target_node_int;

	while (stack_a)
	{
		target_node_int = LONG_MIN;
		top_b = stack_b;
		while (top_b)
		{
			if (top_b->value < stack_a->value && top_b->value > target_node_int)
			{
				target_node_int = top_b->value;
				target = top_b;
			}
			top_b = top_b->next;
		}
		if (target_node_int == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void	check_target_node_b(t_Stack *a, t_Stack *b)
{
	t_Stack	*top_a;
	t_Stack	*target;
	long	target_node_int;

	while (b)
	{
		target_node_int = LONG_MAX;
		top_a = a;
		while (top_a)
		{
			if (top_a->value > b->value && top_a->value < target_node_int)
			{
				target_node_int = top_a->value;
				target = top_a;
			}
			top_a = top_a->next;
		}
		if (target_node_int == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

t_Stack	*find_max(t_Stack *stack)
{
	t_Stack	*max_node;
	long	max_value;

	if (!stack)
		return (NULL);
	max_value = INT_MIN;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_Stack	*find_min(t_Stack *stack)
{
	t_Stack	*min_node;
	int		min_value;

	if (!stack)
		return (NULL);
	min_node = (find_max(stack));
	min_value = min_node->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
