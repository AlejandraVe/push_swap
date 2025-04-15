#include "push_swap.h"
#include <stdio.h>

void	check_cost(Stack *stack_a, Stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(Stack *stack)
{
	long	cheapest;
	Stack	*cheapest_node;

	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

Stack	*store_cheapest(Stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

Stack	*check_properties(Stack *stack_a, Stack *stack_b)
{
	Stack	*cheapest;
	Stack	*top_a;
	Stack	*top_b;

	check_index(stack_a);
	check_index(stack_b);
	check_target_node_a(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_cheapest(stack_a);
	cheapest = store_cheapest(stack_a);
	check_index(stack_a);
	check_index(stack_b);
	printf("cheapest of a: %d and is above_median: %d\n", cheapest->value,
		cheapest->above_median);
	printf("target_node of the cheapest is: %d, which is in b and is above median: %d\n", cheapest->target_node->value,
		cheapest->target_node->above_median);
	if (cheapest->above_median)
		stack_b = check_rotation_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median))
		stack_b = check_rev_rotation_both(stack_a, stack_b, cheapest);
    check_index(stack_a);
    check_index(stack_b);
    top_a = stack_a;
    top_b = stack_b;
	printf("Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
		top_b->value);
    return (stack_b);
}
