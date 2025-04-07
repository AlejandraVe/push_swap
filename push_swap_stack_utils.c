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
