/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:04 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/23 11:42:15 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if ((argc == 1) || (argc == 1 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		while (argv[i])
		{
			argv[i] = argv[i + 1];
			i++;
		}
	}
	initialize_stack_a(&stack_a, argv);
	start_sorting(stack_a, stack_b);
	free_stack(&stack_a);
	return (0);
}

void	start_sorting(t_Stack *stack_a, t_Stack *stack_b)
{
	if (check_sorted(stack_a) == false)
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three_nodes(&stack_a);
		else
			sort_numbers(&stack_a, &stack_b);
	}
}
