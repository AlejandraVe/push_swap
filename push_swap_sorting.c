#include "push_swap.h"
#include <stdio.h>

void    sort_three_nodes(Stack **stack_a)
{
    Stack   *max_node;

    max_node = find_max(*stack_a);
    if (max_node == *stack_a)
        ra(stack_a, true);
    else if (max_node == (*stack_a)->next)
        rra(stack_a, true);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a, true);
}

Stack    *find_max(Stack *stack)
{
    Stack   *max_node;
    int     max_value;

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

Stack   *find_min(Stack *stack)
{
    Stack   *min_node;
    int     min_value;

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

bool    check_sorted(Stack *stack)
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
			if (top_b->value < stack_a->value
				&& top_b->value > target_node_int)
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
        printf("target node of top of a %d is: %d\n", stack_a->value, stack_a->target_node->value);
		stack_a = stack_a->next;
	}
}

void	sort_numbers(Stack **stack_a, Stack **stack_b)
{
	Stack	*top_a;
	Stack	*top_b;
    Stack   *cheapest;

	while (stack_len(*stack_a) != 3)
	{
		if (stack_len(*stack_a) == 4 && !check_sorted(*stack_a))
			pb(stack_a, stack_b, true);
		else
		{
			pb(stack_a, stack_b, true);
			pb(stack_a, stack_b, true);
		}
        cheapest = check_properties(*stack_a, *stack_b); // after check properties, the top of stack_b is correct, but maybe I need to set the function here
        if (cheapest->above_median)
            check_rotation_both(*stack_a, *stack_b, cheapest);
        else if (!(cheapest->above_median))
            check_rev_rotation_both(*stack_a, *stack_b, cheapest);
        top_a = *stack_a;
		top_b = *stack_b;
		printf("Top of stack_a: %d and top of stack_b: %d\n", top_a->value,
			top_b->value);
	}
	if (stack_len(*stack_a) == 3)
	{
		sort_three_nodes(stack_a);
	}
}
