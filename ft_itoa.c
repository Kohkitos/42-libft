/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:29:26 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/10 10:48:45 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_digits(int n)
{
	size_t	len;
	int		cpy;

	len = 0;
	cpy = n;
	if (n == 0)
		return (1);
	if (n == INT_MIN || n == INT_MAX)
		return (11);
	if (n < 0)
	{
		len++;
		cpy = -n;
	}
	while (cpy > 0)
	{
		cpy /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	cpy;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	cpy = n;
	len = n_digits(n);
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		cpy = -n;
	}
	len--;
	while (cpy > 0)
	{
		res[len--] = (cpy % 10) + '0';
		cpy /= 10;
	}
	return (res);
}
