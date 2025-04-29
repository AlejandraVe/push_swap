#include "push_swap.h"

static void	check_b_position(Stack **a, Stack **b, Stack *cheapest) // I also have to check if the cheapest is in the second position; if so, i just need to swap
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

static void	check_rev_b_position(Stack **a, Stack **b, Stack *cheapest)
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

void	check_rotation_both(Stack **a, Stack **b, Stack *cheapest) // target node and cheapet are above median
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

void	check_rev_rotation_both(Stack **a, Stack **b, Stack *cheapest) // target node and cheapest are below median
{
	if (!a || !b)
		return ;
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	check_rev_b_position(a, b, cheapest);
	check_index(*a);
	check_index(*b);
}
