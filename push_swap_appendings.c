#include "push_swap.h"

static void	append_node(Stack **stack, int n)
{
	Stack	*node;
	Stack	*last_node;

	node = malloc(sizeof(Stack));
	if (!node || !stack)
		return ;
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	initialize_stack_a(Stack **stack_a, char *string[])
{
	int	n;
	int	i;

	i = 0;
	if (!stack_a)
		return ;
	while (string[i])
	{
		n = ft_atoi(string[i]);
		append_node(stack_a, n);
		i++;
	}
}

Stack	*find_last(Stack *stack)
// Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) // Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}
