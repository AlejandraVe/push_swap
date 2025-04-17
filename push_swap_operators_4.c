#include "push_swap.h"
#include <stdio.h>

Stack	*check_rotation_a_above(Stack *a, Stack *b, Stack *cheapest)
{
    Stack *top_b;

	while (b != cheapest->target_node || a != cheapest)
	{
		if (b != cheapest->target_node && a != cheapest)
		{
			ra(&a, true);
			rrb(&b, true);
		}
		if (a == cheapest && b != cheapest->target_node)
		{
			rrb(&b, true);
		}
		if (b == cheapest->target_node && a != cheapest)
		{
			if (a->next == cheapest)
				sa(&a, true);
			else
				ra(&a, true);
		}
    }
	top_b = b;
	printf("in function check_rotation_a_above, top of stack_b: %d\nand the next of stack_b is %d\n", top_b->value, top_b->next->value);
	return (top_b);
}

Stack	*check_rotation_b_above(Stack *a, Stack *b, Stack *cheapest)
{
    Stack *top_b;

	while (b != cheapest->target_node || a != cheapest)
	{
		if (b != cheapest->target_node && a != cheapest)
		{
			rra(&a, true);
			rb(&b, true);
		}
		if (b == cheapest->target_node && a != cheapest)
			rra(&a, true);
		if (a == cheapest && b != cheapest->target_node)
		{
			if (b->next == cheapest->target_node)
				sb(&b, true);
			else
				rb(&b, true);
		}
    }
	top_b = b;
	printf("in function check_rotation_b_above, top of stack_b: %d\nand the next of stack_b is %d\n", top_b->value, top_b->next->value);
	return (top_b);
}
