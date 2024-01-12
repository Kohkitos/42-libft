/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:44:21 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/12 12:38:28 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew(f(lst -> content));
	if (!res)
	{
		ft_lstclear(&res, del);
		return (NULL);
	}
	res -> next = NULL;
	lst = lst -> next;
	while (lst)
	{
		aux = ft_lstnew(f(lst -> content));
		if (!aux)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, aux);
		lst = lst -> next;
	}
	return (res);
}
