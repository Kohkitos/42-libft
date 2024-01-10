/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:29:26 by fsanz-go          #+#    #+#             */
/*   Updated: 2024/01/10 10:25:00 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	r_power(int n, size_t pwr)
{
	int	res;

	if (pwr < 0)
		return (0);
	else if (pwr == 0)
		return (1);
	res = 1;
	if (pwr > 0)
		res *= n * r_power(n, pwr - 1);
	return (res);
}

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
	len = 0;
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

	len = n_digits(n);
	if (n < 0)
		cpy = -n;
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
		res[i++] = '-';
	while (len > 0)
	{
		res[i++] = (cpy / r_power(10, len - 1)) + 48;
		cpy %= r_power(10, len);
		len--;
	}
	res[i] = '\0';
	return (res);
}
