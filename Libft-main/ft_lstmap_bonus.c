/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:42:17 by alvera-v          #+#    #+#             */
/*   Updated: 2024/11/01 16:21:09 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (!l || !f)
		return (NULL);
	new = NULL;
	while (l)
	{
		temp = ft_lstnew(NULL);
		if (temp == NULL)
		{
			ft_lstclear(&new, d);
			return (NULL);
		}
		temp->content = f(l->content);
		ft_lstadd_back(&new, temp);
		l = l->next;
	}
	return (new);
}
