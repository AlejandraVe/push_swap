/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:07:20 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:08:17 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*allocates memory for an array of nmemb elements of size
bytes each and returns a pointer to the allocated memory.  The memory is set to
zero.  */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*temp;

	temp = malloc(nmeb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmeb * size);
	return (temp);
}
