/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:15 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/07 14:34:45 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = ft_strlen(s);
	while ((*(s + i) != ch) && (i > 0))
		i--;
	if (ch == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}
