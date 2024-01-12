/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:44:21 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/12 15:48:34 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;
	char	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = f(lst -> content);
		aux = ft_lstnew(tmp);
		if (!aux)
		{
			ft_lstclear(&res, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&res, aux);
		lst = lst -> next;
	}
	return (res);
}
