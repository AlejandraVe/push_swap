/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:11:41 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/20 10:32:46 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_Stack **stack_receiver, t_Stack **stack_pusher)
{
	t_Stack	*push_node;

	if (!stack_pusher)
		return ;
	push_node = *stack_pusher;
	*stack_pusher = (*stack_pusher)->next;
	if (*stack_pusher)
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

void	pb(t_Stack **stack_a, t_Stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_Stack **stack_b, t_Stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
