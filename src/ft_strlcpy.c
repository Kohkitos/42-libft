/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:23:35 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/06 20:11:18 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*cpy;

	if (!size)
		return (ft_strlen(src));
	cpy = (char *)src;
	while ((size > 1) && (*cpy))
	{
		*dst = *cpy;
		dst++;
		cpy++;
		size--;
	}
	if (*dst)
		*dst = 0;
	return (ft_strlen(src));
}
