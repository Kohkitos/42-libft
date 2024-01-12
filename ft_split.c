/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:11:22 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:46 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **res, size_t i)
{
	while (--i)
		free(res[i]);
	free(res);
	return (NULL);
}

static size_t	string_count(char const *s, char c)
{
	size_t	n;
	size_t	flag;

	n = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			n++;
			flag = 1;
		}
		s++;
	}
	return (n);
}

static char	**assemble(char **res, char const *s, char c, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && *s)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j])
			j++;
		res[i] = (char *)ft_calloc(sizeof(char), (j + 1));
		ft_strlcpy(res[i], s, j + 1);
		if (!res[i])
			return (free_all(res, i));
		i++;
		s += j;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	n;

	if (!s || !*s)
		return ((char **)ft_calloc(sizeof(char *), 1));
	n = string_count(s, c);
	res = ft_calloc(sizeof(char *), (n + 1));
	if (!res)
		return (NULL);
	return (assemble(res, s, c, n));
}
