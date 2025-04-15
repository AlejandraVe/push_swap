#include "push_swap.h"

void   check_cost(Stack *stack_a, Stack *stack_b)
{
    int len_a;
    int len_b;

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

void    set_cheapest(Stack *stack)
{
    long    cheapest;
    Stack   *cheapest_node;

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
    cheapest_node->cheapest = true; // is it the stack or the cheapest_node?
}
