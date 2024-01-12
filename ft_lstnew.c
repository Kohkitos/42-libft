/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:03:42 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/11 18:11:55 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	node;

	node = ft_calloc(sizeof(t_list), 1);
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NUll;
	return (node);
}
