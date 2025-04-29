#include "push_swap.h"

void	check_rotation_a_above(Stack **a, Stack **b, Stack *cheapest)
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

void	check_rotation_b_above(Stack **a, Stack **b, Stack *cheapest)
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
