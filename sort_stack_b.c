#include "push_swap.h"

void	b_to_a_both_above(Stack **a, Stack **b, Stack *cheapest)
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
        {
        	ra(a, true);
        }
		if (*a == cheapest->target_node && *b != cheapest)
		{
			rb(b, true);
		}
    }
}

void	b_above_to_a(Stack **a, Stack **b, Stack *cheapest)
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

void	begin_sort_b(Stack *a, Stack *b)
{
	check_index(a);
	check_index(b);
	check_target_node_b(a, b);
    check_cost(b, a);
    set_cheapest(b);
}

void	b_to_a_both_below(Stack **a, Stack **b, Stack *cheapest)
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

void	b_below_to_a(Stack **a, Stack **b, Stack *cheapest)
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
