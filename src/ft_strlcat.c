/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:47:40 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/07 13:42:21 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	r;
	size_t	size_d;
	size_t	size_ss;

	size_ss = size + ft_strlen(src);
	size_d = ft_strlen(dst);
	if (size < size_d)
		return (size_ss);
	i = 0;
	r = size_d + ft_strlen(src);
	while ((i <= (size - size_d - 1)) && (*src))
	{
		dst[size_d + i] = *src;
		src++;
		i++;
	}
	dst[i] = 0;
	return (r);
}
