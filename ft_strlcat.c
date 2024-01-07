/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:47:40 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/07 19:13:16 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	r;
	size_t	size_d;
	size_t	size_s;

	size_s = ft_strlen(src);
	size_d = ft_strlen(dst);
	if (size <= size_d)
		return (size_s + size);
	i = size_d;
	r = size_d + size_s;
	while ((i < (size - 1)) && (*src))
	{
		*(dst + i) = *src;
		src++;
		i++;
	}
	*(dst + i) = '\0';
	return (r);
}
