/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 10:25:48 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/27 14:45:07 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				cnt;
	int				sign;
	unsigned long	rslt;
	unsigned long	test;

	rslt = 0;
	sign = 1;
	cnt = 0;
	while (str[cnt] == ' ' || str[cnt] == '\n' || str[cnt] == '\t' ||
			str[cnt] == '\f' || str[cnt] == '\v' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '-')
		sign = -1;
	if (str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		test = rslt;
		rslt = (rslt * 10) + (str[cnt] - '0');
		cnt++;
		if (rslt < test)
			return (sign < 0 ? 0 : -1);
	}
	return (rslt * sign);
}
