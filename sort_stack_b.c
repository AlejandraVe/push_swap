#include "push_swap.h"
#include <stdio.h>

static void    check_target_node_b(Stack *a, Stack *b)
{
    Stack	*top_a;
	Stack	*target;
	long	target_node_int;

	while (b)
	{
		target_node_int = LONG_MAX;
		top_a = a;
		while (top_a)
		{
			if (top_a->value > b->value && top_a->value < target_node_int)
			{
				target_node_int = top_a->value;
				target = top_a;
			}
			top_a = top_a->next;
		}
		if (target_node_int == LONG_MIN)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		printf("target node of top of b %d is: %d\n", b->value,
			b->target_node->value);
		b = b->next;
	}
}

void	b_to_a_both_above(Stack **a, Stack **b, Stack *cheapest)
{
	Stack *top_a;
	Stack *top_b;

	while (*a != cheapest->target_node && *b != cheapest)
	{
		top_a = *a;
		top_b = *b;
		if (top_a->next == cheapest->target_node && top_b->next == cheapest)
			ss(a, b, true);
		else
			rr(a, b, true);
	}
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
        {
			top_a = *a;
			if (top_a->next == cheapest->target_node)
                sa(a, true);
            else
                ra(a, true);
        }
		if (*a == cheapest->target_node && *b != cheapest)
		{
			top_b = *b;
			if (top_b->next == cheapest)
				sb(b, true);
			else
				rb(b, true);
		}
    }
	top_a = *a;
	top_b = *b;
	printf("in function *b_to_a_both_above, top of stack_a: %d\nAnd top of stack_b: %d\n", top_a->value, top_b->value);
}

void	b_above_to_a(Stack **a, Stack **b, Stack *cheapest)
{
	Stack *top_a;

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
	top_a = *a;
	printf("in function b_above_to_a, top of stack_a: %d\nand the next of stack_a is %d\n", top_a->value, top_a->next->value);
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
	Stack *top_a;

	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, true);
	while (*a != cheapest->target_node || *b != cheapest)
	{
		if (*a != cheapest->target_node && *b == cheapest)
            rra(a, true);
		if (*a == cheapest->target_node && *b != cheapest)
			rrb(b, true);
    }
	top_a = *a;
	printf("in function *b_to_a_both_below, top of stack_a: %d\n", top_a->value);
}

void	b_below_to_a(Stack **a, Stack **b, Stack *cheapest)
{
    Stack *top_a;

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
			top_a = *a;
			if (top_a->next == cheapest->target_node)
				sa(a, true);
			else
				ra(a, true);
		}
    }
	top_a = *a;
	printf("in function *b_below_to_a, top of stack_a: %d\nand the next of stack_a is %d\n", top_a->value, top_a->next->value);
}
