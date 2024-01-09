/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:11:22 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/09 18:10:35 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static size_t	string_n(char const *s, char c)
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
		if (j)
		{
			res[i] = ft_substr(s, 0, j);
			if (!res)
				return (free_all(res, i));
		}
		s += j;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	n;

	if (!s)
		return (NULL);
	n = string_n(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (NULL);
	return (assemble(res, s, c, n));
}
