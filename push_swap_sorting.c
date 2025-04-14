#include "push_swap.h"
#include <stdio.h>

void	sort_three_nodes(Stack **stack_a)
{
	Stack	*max_node;

	max_node = find_max(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a, true);
	else if (max_node == (*stack_a)->next)
		rra(stack_a, true);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, true);
}

Stack	*find_max(Stack *stack)
{
	Stack	*max_node;
	int		max_value;

	max_value = 0;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	printf("The max value is %d\n", max_value);
	return (max_node);
}

Stack	*find_min(Stack *stack)
{
	Stack	*min_node;
	int		min_value;

	min_node = (find_max(stack));
	min_value = min_node->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	printf("The min value is %d\n", min_value);
	return (min_node);
}

bool	check_sorted(Stack *stack)
{
	if (!stack)
		return (false);
	else
	{
		while (stack->next)
		{
			if (stack->value > stack->next->value)
				return (false);
			stack = stack->next;
		}
		return (true);
	}
}

static void	check_target_node(Stack *stack_a, Stack *stack_b)
{
	Stack	*min_node;
	Stack	*max_node;
	Stack	*target;
	int		target_node_int;
	int		min_value;

	min_node = find_min(stack_b);
	max_node = find_max(stack_b);
	target_node_int = min_node->value;
	while (stack_a)
	{
		while (stack_b)
		{
			if (stack_a->value > stack_b->value
				&& stack_a->value >= target_node_int)
			{
				target = stack_b;
				target_node_int = stack_b->value;
			}
			else
			{
				target = find_max(stack_b);
				target_node_int = max_node->value;
			}
			stack_b = stack_b->next;
		}
		stack_a->target_node = target;
		stack_a = stack_a->next;
	}
	min_value = min_node->value;
	printf("Min value after checking target nodes: %d\n", min_value);
}

void	sort_numbers(Stack **stack_a, Stack **stack_b)
{
	Stack	*top_a;
	Stack	*top_b;

	while (stack_len(*stack_a) != 3)
	{
		if (stack_len(*stack_a) == 4)
			pa(stack_a, stack_b, true);
		else
		{
			pa(stack_a, stack_b, true);
			pa(stack_a, stack_b, true);
		}
		check_target_node(*stack_a, *stack_b);
		top_a = *stack_a;
		top_b = *stack_b;
		printf("Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
			top_b->value);
	}
	if (stack_len(*stack_a) == 3)
	{
		sort_three_nodes(stack_a);
	}
	top_a = *stack_a;
	top_b = *stack_b;
	printf("top of stack_a %d\ntop of stack b %d\n", top_a->value,
		top_b->value);
}
