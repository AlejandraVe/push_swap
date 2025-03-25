/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:20:18 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:34:18 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*function  compares the two strings s1 and s2; it compares only the first
n bytes of s1 and s2. Is done with unsigned chars. Returns an integer less than,
equal to, or greater han zero.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
