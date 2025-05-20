/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:12:06 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/20 10:47:02 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_cost(t_Stack *pusher, t_Stack *receiver)
{
	int	len_pusher;
	int	len_receiver;

	len_pusher = stack_len(pusher);
	len_receiver = stack_len(receiver);
	while (pusher)
	{
		pusher->push_cost = pusher->index;
		if (!(pusher->above_median))
			pusher->push_cost = len_pusher - (pusher->index);
		if (pusher->target_node->above_median)
			pusher->push_cost += pusher->target_node->index;
		else
			pusher->push_cost += len_receiver - (pusher->target_node->index);
		pusher = pusher->next;
	}
}

void	set_cheapest(t_Stack *stack)
{
	long	cheapest;
	t_Stack	*cheapest_node;

	cheapest = LONG_MAX;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_Stack	*store_cheapest(t_Stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	min_at_top(t_Stack **stack_a)
{
	if (!stack_a)
		return ;
	while (find_min(*stack_a)->value != (*stack_a)->value)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

bool	check_sorted(t_Stack *stack)
{
	if (!stack)
		return (false);
	else
	{
		while (stack->next)
		{
			if (stack->value > stack->next->value)
				return (false);
			stack = stack->next;
		}
		return (true);
	}
}
