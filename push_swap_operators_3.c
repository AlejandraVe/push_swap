#include "push_swap.h"
#include <stdio.h>

static void	check_b_position(Stack **a, Stack **b, Stack *cheapest) // I also have to check if the cheapest is in the second position; if so, i just need to swap
{
	Stack	*top_b;
	Stack	*top_a;

	while (*b != cheapest->target_node || *a != cheapest)
	{
		top_b = *b;
		if (*b != cheapest->target_node && *a == cheapest)
        {
			if (top_b->next == cheapest->target_node)
                sb(b, true);
            else
                rb(b, true);
        }
		top_a = *a;
		if (*b == cheapest->target_node && *a != cheapest)
		{
			if (top_a->next == cheapest)
				sa(a, true);
			else
				ra(a, true);
		}
    }
	top_b = *b;
	printf("in function check_b_position, top of stack_b: %d\n", top_b->value);
}

static void	check_rev_b_position(Stack **a, Stack **b, Stack *cheapest)
{
    Stack *top_b;

	while (*b != cheapest->target_node || *a != cheapest)
	{
		if (*b != cheapest->target_node && *a == cheapest)
			rrb(b, true);
		else if (*b == cheapest->target_node && *a != cheapest)
			rra(a, true);
    }
	top_b = *b;
	printf("in function check_rev_b_position, top of stack_b: %d\n", top_b->value);
}

void	check_rotation_both(Stack **a, Stack **b, Stack *cheapest) // target node and cheapet are above median
{
	Stack	*top_a;
	Stack	*top_b;
	while (*b != cheapest->target_node && *a != cheapest)
	{
		top_a = *a;
		top_b = *b;
		if (top_a->next == cheapest && top_b->next == cheapest->target_node)
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
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	check_rev_b_position(a, b, cheapest);
	check_index(*a);
	check_index(*b);
}
