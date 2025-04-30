#include "push_swap.h"

static void	swap(Stack **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

static void rotate(Stack **stack)
{
	Stack	*last_node;

	if (!stack)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

static void	reverse_rotate(Stack **stack)
{
	Stack	*last;

	if (!stack)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	sa(Stack **stack_a, bool print) // print the instruction
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(Stack **stack_b, bool print) // print the instruction
{
	swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(Stack **stack_a, Stack **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}

void	ra(Stack **stack_a, bool print)
{
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(Stack **stack_b, bool print)
{
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(Stack **stack_a, Stack **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}

void	rra(Stack **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(Stack **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(Stack **stack_a, Stack **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
