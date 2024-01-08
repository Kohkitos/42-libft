/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:40:23 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/08 21:55:59 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_end(char const *s1, char const *set, size_t i, size_t j)
{
	size_t	res;
	size_t	set_len;

	res = 0;
	set_len = ft_strlen(set);
	while (i < j)
	{
		if (ft_strnstr(set, ft_substr(s1, i, 1), set_len))
			res++;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	s1_len;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	start = start_end(s1, set, 0, set_len);
	end = start_end(s1, set, s1_len - set_len, s1_len);
	return (ft_substr(s1, start, s1_len - start - end));
}
