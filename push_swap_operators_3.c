#include "push_swap.h"
#include <stdio.h>

static Stack	*check_b_position(Stack *a, Stack *b, Stack *cheapest)
{
	Stack *top_b;

	if (cheapest->target_node->above_median)
	{
		while (b != cheapest->target_node || a != cheapest)
		{
			if (b != cheapest->target_node && a == cheapest)
				rb(&b, true);
			else if (b == cheapest->target_node && a != cheapest)
				ra(&a, true);
		}
	}
	else if (!cheapest->target_node->above_median)
	{
		while (b != cheapest->target_node || a != cheapest)
		{
			if (b != cheapest->target_node && a == cheapest)
				rrb(&b, true);
			else if (b == cheapest->target_node && a != cheapest)
				rra(&a, true);
		}
	}
	top_b = b;
	printf("in function check_b_position, top of stack_b: %d\n", top_b->value);
	return (top_b);
}

/*static void    check_b_position_reverse(Stack *a, Stack *b, Stack *cheapest)
{
	while (b != cheapest->target_node || a != cheapest)
	{
		if (b != cheapest->target_node && a == cheapest)
			rrb(&b, true);
		else if (b == cheapest->target_node && a != cheapest)
			rra(&a, true);
	}
	check_index(a);
	check_index(b);
}*/
Stack	*check_rotation_both(Stack *a, Stack *b, Stack *cheapest)
{
	Stack *top_b;

	while (b != cheapest->target_node && a != cheapest)
		rr(&a, &b, true);
	/*while (1)
	{
		if (b == cheapest->target_node && a != cheapest)
			ra(&a, true);
		else if (b != cheapest->target_node && a == cheapest)
			rb(&b, true);
		else if (b == cheapest->target_node && a == cheapest)
			break ;
	}*/
	top_b = check_b_position(a, b, cheapest);
	return (top_b);
}

Stack	*check_rev_rotation_both(Stack *a, Stack *b, Stack *cheapest)
{
	Stack *top_b;
	while (b != cheapest->target_node && a != cheapest)
		rrr(&a, &b, true);
	/* while (1)s
		{
			if (b == cheapest->target_node && a != cheapest)
				rra(&a, true);
			else if (b != cheapest->target_node && a == cheapest)
				rrb(&b, true);
			else if (b == cheapest->target_node && a == cheapest)
				break ;
		}*/
	top_b = check_b_position(a, b, cheapest);
	return (top_b);
}
