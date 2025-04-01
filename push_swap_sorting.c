#include "push_swap.h"
#include <stdio.h>

static void    append_node(Stack **stack, int n)
{
    Stack   *node; // store a pointer to the new node to be created with the value n
    Stack   *last_node; // to store a pointer to the current last node of the stack

    if (!stack)
        return ;
    node = malloc(sizeof(Stack));
    if (!node)
        return ;
    node->next = NULL; // set the next pointer to NULL as it'll be the last node of the lost
    node->value = n; // set the value to the number the function receives
    node->cheapest = 0; // initialise the cheapest to 0
    if (!(*stack)) // check if the stack is empty or currently pointing to NULL; this would indicate a 1st node needs to be found
    {
        *stack = node; //if it's empty, we set the tack to point to the node, making it the new head of the stack
        node->prev = NULL; //set the head node's previous pointer to NULL as it's the first node
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
    printf("%d\n", node->value);
}

void    initialize_stack_a(Stack **stack_a, char *string[])
{
    //	int number_of_strings;
	int n;
    int i;
    //	number_of_strings = count_string(string) - 1;
    i = 0;
    while (string[i])
    {
        n = ft_atoi(string[i]);
        append_node(stack_a, n);
        i++;
    }
    free(string);
}

Stack	*find_last(Stack *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
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

void	sort_numbers(Stack *stack_a)
{
    Stack   *last_node = NULL;

    last_node = (Stack *)malloc(sizeof(Stack));
    last_node = find_last(stack_a);
    printf("%d\n", last_node->value);
}
