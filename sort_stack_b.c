/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:16:59 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/20 10:36:52 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_both_above(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		if ((*a)->next == cheapest->target_node && (*b)->next == cheapest)
			ss(a, b);
		else
			rr(a, b);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
			ra(a);
		if (*a == cheapest->target_node && *b != cheapest)
			rb(b);
	}
}

void	b_above_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rb(b);
		rra(a);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*b == cheapest && *a != cheapest->target_node)
			rra(a);
		else if (*a == cheapest->target_node && *b != cheapest)
			rb(b);
	}
}

void	begin_sort_b(t_Stack *a, t_Stack *b)
{
	check_index(a);
	check_index(b);
	check_target_node_b(a, b);
}

void	b_to_a_both_below(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
			rra(a);
		if (*a == cheapest->target_node && *b != cheapest)
			rrb(b);
	}
}

void	b_below_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rrb(b);
		ra(a);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a == cheapest->target_node && *b != cheapest)
			rrb(b);
		if (*b == cheapest && *a != cheapest->target_node)
		{
			ra(a);
		}
	}
}
