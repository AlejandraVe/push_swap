#include "push_swap.h"

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
	if (!stack)
		return ;
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
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	check_properties(Stack *stack_a, Stack *stack_b)
{
	check_index(stack_a);
	check_index(stack_b);
	check_target_node_a(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}
