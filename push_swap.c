/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:04 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/27 12:30:50 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		should_free_argv;

	stack_a = NULL;
	stack_b = NULL;
	should_free_argv = 0;
	if ((argc == 1) || (argc == 1 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		initialize_stack_a(&stack_a, argv, should_free_argv);
		should_free_argv = 1;
	}
	else if (argc > 2)
		initialize_stack_a(&stack_a, &argv[1], 0);
	start_sorting(stack_a, stack_b);
	if (should_free_argv)
		free_split(argv);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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
	free_stack(&stack_a);
}
