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
    Stack   *last_node = NULL;

    if (!stack_a || !stack_b)
        return ;
    last_node = (Stack *)malloc(sizeof(Stack));
    last_node = find_last(*stack_a);
    printf("%d\n", last_node->value);
}

