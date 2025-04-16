#include "push_swap.h"
#include <stdio.h>

static Stack	*check_rotation_a_above(Stack *a, Stack *b, Stack *cheapest)
{
    Stack *top_b;

	if (a->next == cheapest && b->next == cheapest->target_node)
		ss(&a, &b, true);
	while (b != cheapest->target_node || a != cheapest)
	{
		if (a->next == cheapest && b->next == cheapest->target_node)
			ss(&a, &b, true);
		else if (a == cheapest && b != cheapest->target_node)
		{
			if (b->next == cheapest->target_node)
				sb(&b, true);
			else
				rb(&b, true);
		}
		else if (b == cheapest->target_node && a != cheapest)
		{
			if (a->next == cheapest)
				sa(&b, true);
			else
				ra(&b, true);
		}
    }
	top_b = b;
	printf("in function check_b_position, top of stack_b: %d\n", top_b->value);
	return (top_b);
}
