#include "push_swap.h"
#include <stdio.h>

static Stack	*check_b_position(Stack *a, Stack *b, Stack *cheapest) // I also have to check if the cheapest is in the second position; if so, i just need to swap
{
	Stack *top_b;

	while (b != cheapest->target_node || a != cheapest)
	{
		if (a->next == cheapest && b->next == cheapest->target_node)
			ss(&a, &b, true);
		else if (b != cheapest->target_node && a == cheapest)
        {
			if (b->next == cheapest)
                sb(&b, true);
            else
                rb(&b, true);
        }
		else if (b == cheapest->target_node && a != cheapest)
			ra(&a, true);
    }
	top_b = b;
	printf("in function check_b_position, top of stack_b: %d\n", top_b->value);
	return (top_b);
}

static Stack	*check_rev_b_position(Stack *a, Stack *b, Stack *cheapest)
{
    Stack *top_b;

	while (b != cheapest->target_node || a != cheapest)
	{
		if (b != cheapest->target_node && a == cheapest)
			rrb(&b, true);
		else if (b == cheapest->target_node && a != cheapest)
			rra(&a, true);
    }
	top_b = b;
	printf("in function check_b_position, top of stack_b: %d\n", top_b->value);
	return (top_b);
}

Stack	*check_rotation_both(Stack *a, Stack *b, Stack *cheapest) // target node and cheapet are above median
{
	Stack *top_b;

	while (b != cheapest->target_node && a != cheapest)
	{
		if (a->next == cheapest && b->next == cheapest->target_node)
			ss(&a, &b, true);
		else
			rr(&a, &b, true);
	}
	top_b = check_b_position(a, b, cheapest);
	return (top_b);
}

Stack	*check_rev_rotation_both(Stack *a, Stack *b, Stack *cheapest) // target node and cheapest are below median
{
	Stack *top_b;
	while (b != cheapest->target_node && a != cheapest)
		rrr(&a, &b, true);
	top_b = check_rev_b_position(a, b, cheapest);
	return (top_b);
}
