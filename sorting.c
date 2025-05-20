/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:09:50 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/20 10:45:27 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_Stack **stack_a)
{
	t_Stack	*max_node;

	if (!stack_a)
		return ;
	max_node = find_max(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a);
	else if (max_node == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

static void	move_a_to_b(t_Stack **stack_a, t_Stack **stack_b)
{
	t_Stack	*cheapest;

	if (!stack_a)
		return ;
	cheapest = store_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		check_rotation_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		check_rev_rotation_both(stack_a, stack_b, cheapest);
	before_push(stack_a, cheapest, 'a');
	before_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a);
}

void	before_push(t_Stack **stack, t_Stack *top_node, char letter)
{
	while (*stack != top_node)
	{
		if (letter == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (letter == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	sort_numbers(t_Stack **stack_a, t_Stack **stack_b)
{
	int		len_a;

	len_a = stack_len(*stack_a);
	if (!stack_a || len_a == 3)
		return ;
	if (len_a-- > 3 && !check_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !check_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (len_a-- > 3 && !check_sorted(*stack_a))
	{
		check_properties(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three_nodes(stack_a);
	while (*stack_b)
	{
		begin_sort_b(*stack_a, *stack_b);
		before_push(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b);
	}
	check_index(*stack_a);
	min_at_top(stack_a);
}

void	check_properties(t_Stack *stack_a, t_Stack *stack_b)
{
	check_index(stack_a);
	check_index(stack_b);
	check_target_node_a(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}
