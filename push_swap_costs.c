#include "push_swap.h"
#include <stdio.h>

void	check_cost(Stack *pusher, Stack *receiver)
{
	int	len_pusher;
	int	len_receiver;

	len_pusher = stack_len(pusher);
	len_receiver = stack_len(receiver);
	while (pusher)
	{
		pusher->push_cost = pusher->index;
		if (!(pusher->above_median))
			pusher->push_cost = len_pusher - (pusher->index);
		if (pusher->target_node->above_median)
			pusher->push_cost += pusher->target_node->index;
		else
			pusher->push_cost += len_receiver - (pusher->target_node->index);
		pusher = pusher->next;
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
	if (cheapest->above_median && cheapest->target_node->above_median)
		stack_b = check_rotation_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		stack_b = check_rev_rotation_both(stack_a, stack_b, cheapest);
    else if (cheapest->above_median && !(cheapest->target_node->above_median))
        stack_b = check_rotation_a_above(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && cheapest->target_node->above_median)
		stack_b = check_rotation_b_above(stack_a, stack_b, cheapest);
    check_index(stack_a);
    check_index(stack_b);
    top_a = stack_a;
    top_b = stack_b;
	printf("Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
		top_b->value);
    return (stack_b);
}
