/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:57:45 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/08 16:47:17 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	if (!dest && !src)
		return (dest);
	d_cpy = dest;
	s_cpy = (unsigned char *)src;
	while (n > 0)
	{
		*d_cpy = *s_cpy;
		d_cpy++;
		s_cpy++;
		n--;
	}
	return (dest);
}
