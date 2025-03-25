/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:45:32 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:37:24 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2);
	ret = malloc(len_s1 + len_s2);
	if (!ret)
		return (NULL);
	ft_strlcpy((char *)ret, (const char *)s1, len_s1);
	ft_strlcat((char *)ret, s2, len_s1 + len_s2);
	return (ret);
}
