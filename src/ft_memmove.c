/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:13:53 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/06 20:59:24 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;
	size_t			i;

	d_cpy = (unsigned char	*)dest;
	s_cpy = (unsigned char	*)src;
	if (s_cpy == 0 && d_cpy == 0)
		return ("");
	if (dest > src)
	{
		while (n--)
			d_cpy[n] = s_cpy[n];
	}
	else if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			d_cpy[i] = s_cpy[i];
			i++;
		}
	}
	return (dest);
}
