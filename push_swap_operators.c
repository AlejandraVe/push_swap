#include "push_swap.h"

void	swap(Stack stack)
{
	Stack *temp;

	temp = (Stack *)malloc(sizeof(Stack));
	temp = stack;
	stack->value = temp->next;
	stack->next = temp->value;
	free(temp);
}
