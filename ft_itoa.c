/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:29:26 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/10 09:59:47 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_digits(int n)
{
	size_t	len;
	int		cpy;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
		n *= -1;
	cpy = n;
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
	size_t	i;

	l = n_digits(n);
	if (n < 0)
	{
		l++;
		cpy = -n;
	}
	res = ft_calloc(sizeof(char), l + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
		res[i++] = '-';
	while (l > 0)
	{
		res[i++] = (cpy / (10 ** l)) + 48;
		cpy %= (10 ** l);
		l--; 
	}
	res[i] = '\0';
	return (res);
}
