/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:11:17 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:20:51 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_b_position(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a || !b)
		return ;
	while (*b != cheapest->target_node || *a != cheapest)
	{
		if (*b != cheapest->target_node && *a == cheapest)
		{
			rb(b, true);
		}
		if (*b == cheapest->target_node && *a != cheapest)
		{
			ra(a, true);
		}
	}
}

static void	check_rev_b_position(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a || !b)
		return ;
	while (*b != cheapest->target_node || *a != cheapest)
	{
		if (*b != cheapest->target_node && *a == cheapest)
			rrb(b, true);
		else if (*b == cheapest->target_node && *a != cheapest)
			rra(a, true);
	}
}

void	check_rotation_both(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a || !b)
		return ;
	while (*b != cheapest->target_node && *a != cheapest)
	{
		if ((*a)->next == cheapest && (*b)->next == cheapest->target_node)
			ss(a, b, true);
		else
			rr(a, b, true);
	}
	check_b_position(a, b, cheapest);
	check_index(*a);
	check_index(*b);
}

void	check_rev_rotation_both(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a || !b)
		return ;
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	check_rev_b_position(a, b, cheapest);
	check_index(*a);
	check_index(*b);
}
