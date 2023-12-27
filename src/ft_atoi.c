/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:10:01 by fsanz-go          #+#    #+#             */
/*   Updated: 2023/12/27 12:36:58 by fsanz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (((c >= 9) && (c <= 13)) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	flag;

	res = 0;
	flag = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		flag = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	if (flag)
		res *= -1;
	return (res);
}
