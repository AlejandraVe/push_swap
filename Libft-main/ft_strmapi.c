/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:46:52 by alvera-v          #+#    #+#             */
/*   Updated: 2024/10/25 11:46:44 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function f to each character of the string s,
passing its index as the first argument and the character
itself as the second. A new string is created (malloc) to collect
the results. It returns the string created from the successive
applications of "f"*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	i = 0;
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
