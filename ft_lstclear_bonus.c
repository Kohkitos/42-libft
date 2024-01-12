/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:25:57 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/12 17:03:51 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*aux;

	if (!lst || !del || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		aux = ptr -> next;
		ft_lstdelone(ptr, del);
		ptr = aux;
	}
	*lst = NULL;
}
