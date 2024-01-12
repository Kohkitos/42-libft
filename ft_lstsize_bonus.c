/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:51:17 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/12 09:56:25 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*pointer;

	if (!lst)
		return (0);
	len = 0;
	pointer = lst;
	while (pointer)
	{
		pointer = pointer -> next;
		len++;
	}
	return (len);
}
