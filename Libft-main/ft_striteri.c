/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:42:23 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 11:49:02 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function "f" on each character of the string passed as argument,
passing its index as first argument.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
