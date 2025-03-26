/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:04:20 by alvera-v          #+#    #+#             */
/*   Updated: 2025/03/26 10:31:01 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc == 1)
	{
		return (1);
	}
	while (argv[i])
	{
		ft_atoi(argv[i]);
		printf("%s\n", argv[i]);
		i++;
	}

	int c[STACK_LENGTH]; // initialize the stack
	Stack * s = stack(STACK_LENGTH); //not sure what s is
	return (0);
}
// to define a stack https://www.digitalocean.com/community/tutorials/stack-in-c
// another option to define a stack https://dev.to/josethz00/data-structures-in-c-stack-55c7#:~:text=Stack%20implementation%20(struct),as%20the%20primitive%20type%20char%20.
