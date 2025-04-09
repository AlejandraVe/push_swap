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

void	sort_numbers(Stack **stack_a, Stack **stack_b)
{
    Stack *top_a;
    Stack *top_b;

    while (stack_len(*stack_a) != 3)
    {
        if (stack_len(*stack_a) == 4)
            pa(stack_a, stack_b, true);
        else
        {
            pa(stack_a, stack_b, true);
            pa(stack_a, stack_b, true);
        }
    }
    if (stack_len(*stack_a) == 3)
    {
        sort_three_nodes(&stack_a);
    }


    top_a = *stack_a;
    top_b = *stack_b;
    printf("top of stack_a %d\ntop of stack b %d\n", top_a->value, top_b->value);
}
