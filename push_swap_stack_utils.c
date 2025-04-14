#include "push_swap.h"

int stack_len(Stack *stack)
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

void    check_index(Stack *stack)
{
    int i;
    int median;

    i = 0;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}
