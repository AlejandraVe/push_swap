/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:11:12 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:20:41 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotation_a_above(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a)
		return ;
	while (*b != cheapest->target_node || *a != cheapest)
	{
		if (*b != cheapest->target_node && *a != cheapest)
		{
			ra(a, true);
			rrb(b, true);
		}
		if (*a == cheapest && *b != cheapest->target_node)
			rrb(b, true);
		if (*b == cheapest->target_node && *a != cheapest)
		{
			ra(a, true);
		}
	}
}

void	check_rotation_b_above(t_Stack **a, t_Stack **b, t_Stack *cheapest)
{
	if (!a)
		return ;
	while (*b != cheapest->target_node || *a != cheapest)
	{
		if (*b != cheapest->target_node && *a != cheapest)
		{
			rra(a, true);
			rb(b, true);
		}
		if (*b == cheapest->target_node && *a != cheapest)
			rra(a, true);
		if (*a == cheapest && *b != cheapest->target_node)
		{
			rb(b, true);
		}
	}
}
