#include "push_swap.h"

static void	swap(Stack **top) // swaps the position of the top and second node
{
	if (!*top || !(*top)->next) // Check if the top node or second node of a stack exists
		return ;
	*top = (*top)->next; // Update so the pointer of top points to the next node
	(*top)->prev->prev = *top; // Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*top)->prev->next = (*top)->next; // Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*top)->next) // if there's a node after the new top
		(*top)->next->prev = (*top)->prev; // if so, update its prev pointer to point back to the new top
	(*top)->next = (*top)->prev; // The next pointer of new top will point to the old top
	(*top)->prev = NULL; // this is to complete the swap
}

void swap_a(Stack **stack_a, bool print) // print the instruction
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}
