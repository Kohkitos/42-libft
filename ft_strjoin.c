/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:17:26 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/08 12:22:09 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len_s1 + len_s2));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len_s1);
	ft_memcpy((ptr + len_s1), s2, len_s2);
	return (ptr);
}
