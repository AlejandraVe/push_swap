/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:14:14 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:43:52 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  bzero()  function erases the data in the n bytes of the memory starting
at the location pointed to by s, by writing zeros (bytes containing '\0') to
that area. No return value*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
