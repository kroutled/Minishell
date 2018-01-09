/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:14:28 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/27 11:17:14 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	numnbr(int c)
{
	int		i;

	i = 1;
	if (c < 0)
	{
		c = -c;
		i++;
	}
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*arr;
	int		count;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	count = numnbr(n);
	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (arr == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		sign = (-1);
	}
	arr[count] = '\0';
	while (count-- >= 0)
	{
		arr[count] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		arr[0] = '-';
	return (arr);
}
