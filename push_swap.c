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

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1) || (argc == 1 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	initialize_stack_a(&stack_a, argv);
	start_sorting(stack_a, stack_b);
	free_stack(stack_a);
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

bool	check_duplicates(char **s)
{
	int	i;
	int	j;
	int	*numbers;

	numbers = NULL;
	numbers = (int *)malloc((count_string(s) + 1) * sizeof(int));
	j = 0;
	while (s[j])
	{
		numbers[j] = ft_atoi(s[j]);
		if (!numbers[j])
			return (false);
		j++;
	}
	i = 0;
	while (numbers[i])
	{
		j = 1;
		while (numbers[i] != numbers[i + j] && numbers[i + j])
			j++;
		if (numbers[i] == numbers[i + j])
			return (false);
		i++;
	}
	return (true);
}

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	ret;
	long	neg;

	ret = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = ret * 10 + ((long)*nptr - 48);
		nptr++;
	}
	return (ret * neg);
}
