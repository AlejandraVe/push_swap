/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:15:51 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/05 11:46:25 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strrchr() function returns a pointer to the last occurrence of the
character c in the string s. Returns a pointer to the matched character or
NULL if the character is not found*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;
	char			*ret;

	i = 0;
	cc = (unsigned char)c;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			ret = ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		ret = ((char *)&s[i]);
	return (ret);
}
