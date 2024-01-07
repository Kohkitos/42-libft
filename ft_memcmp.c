/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:25:44 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/07 19:13:16 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cpy_s1[i] == cpy_s2[i])
			i++;
		else
			return (cpy_s1[i] - cpy_s2[i]);
	}
	return (0);
}
