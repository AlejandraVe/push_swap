/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:16:59 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:17:00 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_both_above(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		if ((*a)->next == cheapest->target_node && (*b)->next == cheapest)
			ss(a, b, true);
		else
			rr(a, b, true);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
			ra(a, true);
		if (*a == cheapest->target_node && *b != cheapest)
			rb(b, true);
	}
}

void	b_above_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rb(b, true);
		rra(a, true);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*b == cheapest && *a != cheapest->target_node)
			rra(a, true);
		else if (*a == cheapest->target_node && *b != cheapest)
			rb(b, true);
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
		rrr(a, b, true);
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
			rra(a, true);
		if (*a == cheapest->target_node && *b != cheapest)
			rrb(b, true);
	}
}

void	b_below_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rrb(b, true);
		ra(a, true);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a == cheapest->target_node && *b != cheapest)
			rrb(b, true);
		if (*b == cheapest && *a != cheapest->target_node)
		{
			ra(a, true);
		}
	}
}
