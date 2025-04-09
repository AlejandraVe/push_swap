#include "push_swap.h"

static void push(Stack **stack_pusher, Stack **stack_receiver)
{
    Stack *push_node;

    push_node = *stack_pusher;
    *stack_pusher = (*stack_pusher)->next;
    (*stack_pusher)->prev = NULL;
    push_node->prev = NULL;
    if (!(*stack_receiver))
    {
        *stack_receiver = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *stack_receiver;
        push_node->next->prev = push_node;
        *stack_receiver = push_node;
    }
}

void	pa(Stack **stack_a, Stack **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(Stack **stack_b, Stack **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (print)
		write(1, "pb\n", 3);
}
