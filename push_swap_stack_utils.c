#include "push_swap.h"
#include <stdio.h>

int	stack_len(Stack *stack)
{
	int total; // see how many nodes there are
	total = 0;
	while (stack) // loop until the end of the stack is reached
	{
		stack = stack->next; // move to the next node
		total++;
	}
	return (total);
}

void	check_index(Stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	check_target_node_a(Stack *stack_a, Stack *stack_b)
{
	Stack	*top_b;
	Stack	*target;
	long	target_node_int;

	while (stack_a)
	{
		target_node_int = LONG_MIN;
		top_b = stack_b;
		while (top_b)
		{
			if (top_b->value < stack_a->value && top_b->value > target_node_int)
			{
				target_node_int = top_b->value;
				target = top_b;
			}
			top_b = top_b->next;
		}
		if (target_node_int == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target;
		printf("target node of top of a %d is: %d\n", stack_a->value,
			stack_a->target_node->value);
		stack_a = stack_a->next;
	}
}
