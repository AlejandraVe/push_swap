/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:25:36 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/09 09:58:26 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	size;

	size = ft_strlen(s) + 1;
	temp = (char *)malloc(size);
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s, size);
	return (temp);
}
