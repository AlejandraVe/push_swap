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

void	sort_numbers(Stack **stack_a, Stack **stack_b)
{
	Stack	*top_a;
	Stack	*top_b;

	if (stack_len(*stack_a) == 3)
	{
		sort_three_nodes(stack_a);
		return ;
	}
	while (stack_len(*stack_a) > 3)
	{
		if (stack_len(*stack_a) == 4 && !check_sorted(*stack_a))
			pb(stack_a, stack_b, true);
		else
		{
			pb(stack_a, stack_b, true);
			pb(stack_a, stack_b, true);
		}
		if (stack_len(*stack_a) == 3)
			break;
		*stack_b = check_properties(*stack_a, *stack_b);
		top_a = *stack_a;
		top_b = *stack_b;
		printf("After pushing a to b: Top of stack_a: %d and next is: %d\n And top of stack_b: %d and next is %d\n", top_a->value, top_a->next->value,
			top_b->value, top_b->next->value);
	}
	sort_three_nodes(stack_a);
	while (*stack_b)
	{
		*stack_a = begin_sort_b(*stack_a, *stack_b);
		*stack_b = set_values_in_b(*stack_a, *stack_b);
		printf("stack_len of b: %d\nstack_len of a: %d\n", stack_len(*stack_b), stack_len(*stack_a));
		top_a = *stack_a;
		top_b = *stack_b;
		/*for (int i = 0; i < stack_len(*stack_a); i++)
		{
			printf("stack_a %d: %d\n", i, top_a->value);
			top_a = top_a->next;
		}
		for (int i = 0; i < stack_len(*stack_b); i++)
		{
			printf("stack_b %d: %d\n", i, top_b->value);
			top_b = top_b->next;
		}*/
		printf("In the loop to sort b: Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
		top_b->value);
	}

	printf("At the end of the function: Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
		top_b->value);
}

Stack	*set_values_in_b(Stack *a, Stack *b)
{
	Stack *top_a = a;
	Stack *top_b = b;

	for (int i = 0; i < stack_len(a); i++)
	{
		printf("stack_a %d: %d\n", i, top_a->value);
		top_a = top_a->next;
	}
	for (int i = 0; i < stack_len(b); i++)
	{
		printf("stack_b %d: %d\n", i, top_b->value);
		top_b = top_b->next;
	}
	return (b);
}
