/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:11:22 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/09 10:55:52 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
	return (NULL);
}

static char	**assemble(char	**arr, char const *s, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = 0;
	while (j < n && s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c)
		{
			len++;
			i++;
		}
		arr[j] = ft_substr(s, k, len);
		if (!arr[j])
			return (free_arr(arr, j));
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	n = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			n++;
		i++;
	}
	arr = malloc(sizeof(char *) * n + 1);
	if (!arr)
		return (NULL);
	return (assemble(arr, s, c, n));
}
