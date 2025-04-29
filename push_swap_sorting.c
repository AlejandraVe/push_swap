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

static void	move_a_to_b(Stack **stack_a, Stack **stack_b)
{
	Stack	*cheapest;
	Stack	*top_a;
	Stack	*top_b;

	cheapest = store_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		check_rotation_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		check_rev_rotation_both(stack_a, stack_b, cheapest);
    else if (cheapest->above_median && !(cheapest->target_node->above_median))
        check_rotation_a_above(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && cheapest->target_node->above_median)
		check_rotation_b_above(stack_a, stack_b, cheapest);
    top_a = *stack_a;
    top_b = *stack_b;
	printf("Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
		top_b->value);
}

static void	move_b_to_a(Stack **a, Stack **b)
{
	Stack	*cheapest;

	cheapest = store_cheapest(*b);
	printf("Cheapest from b has been stored\n");
	printf("Above median: %d %d\n", cheapest->above_median, cheapest->target_node->above_median);
	if (cheapest->above_median && cheapest->target_node->above_median)
		b_to_a_both_above(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		b_to_a_both_below(a, b, cheapest);
    else if (cheapest->above_median && !(cheapest->target_node->above_median))
        b_above_to_a(a, b, cheapest);
	else if (!(cheapest->above_median) && cheapest->target_node->above_median)
		b_below_to_a(a, b, cheapest);
	if (stack_len(*b) > 0)
		pa(b, a, true);
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
		check_properties(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
		top_a = *stack_a;
		top_b = *stack_b;
		printf("After pushing a to b: Top of stack_a: %d and next is: %d\n And top of stack_b: %d and next is %d\n", top_a->value, top_a->next->value,
			top_b->value, top_b->next->value);
	}
	sort_three_nodes(stack_a);
	while (stack_len(*stack_b) > 0)
	{
		begin_sort_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
		printf("stack_len of b: %d\nstack_len of a: %d\n", stack_len(*stack_b), stack_len(*stack_a));
		check_index(*stack_a);
		if (!(*stack_b))
			break;
		else
			check_index(*stack_b);
	}
	top_a = *stack_a;
	for (int i = 0; i < stack_len(*stack_a); i++)
	{
		printf("stack_a posi %d: %d\n", i, top_a->value);
		top_a = top_a->next;
	}
}

void	min_at_top(Stack **stack_a)
{
	Stack	*min;

	min = find_min(*stack_a);
	while (min != *stack_a)
	{
		if (!min->above_median)
			rra(stack_a, true);
		else
			ra(stack_a, true);
	}
}
