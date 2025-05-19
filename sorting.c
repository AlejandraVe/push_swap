/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:09:50 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:20:12 by alvera-v         ###   ########.fr       */
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
		ra(stack_a, true);
	else if (max_node == (*stack_a)->next)
		rra(stack_a, true);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, true);
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
	/*else if (cheapest->above_median && !(cheapest->target_node->above_median))
		check_rotation_a_above(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && cheapest->target_node->above_median)
		check_rotation_b_above(stack_a, stack_b, cheapest);*/
	before_push(stack_a, cheapest, 'a');
	before_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a, true);
}

void	before_push(t_Stack **stack, t_Stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);

		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	move_b_to_a(t_Stack **a, t_Stack **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(a, b, true);

	/*
	t_Stack	*cheapest;

	cheapest = store_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		b_to_a_both_above(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		b_to_a_both_below(a, b, cheapest);
	else if (cheapest->above_median && !(cheapest->target_node->above_median))
		b_above_to_a(a, b, cheapest);
	else if (!(cheapest->above_median) && cheapest->target_node->above_median)
		b_below_to_a(a, b, cheapest);
	if (stack_len(*b) > 0)
		pa(b, a, true);*/
}

void	sort_numbers(t_Stack **stack_a, t_Stack **stack_b)
{
	t_Stack	*top_a;
	int	len_a;
	len_a = stack_len(*stack_a);

	if (!stack_a || len_a == 3)
		return ;
	if (len_a-- > 3 && !check_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	if (len_a-- > 3 && !check_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	while (len_a-- > 3 && !check_sorted(*stack_a))
	{
		check_properties(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three_nodes(stack_a);
	while (*stack_b)
	{
		begin_sort_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	check_index(*stack_a);
	min_at_top(stack_a);
	top_a = *stack_a;
	for (int i = 0; i < stack_len(*stack_a); i++)
    {
        printf("stack_a posi %d: %d\n", i, top_a->value);
		top_a = top_a->next;
    }
}
