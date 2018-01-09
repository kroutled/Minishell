/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:04:30 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 07:52:59 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	*ps2;

	ps = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (ps[i] != ps2[i])
			return ((unsigned char)ps[i] - (unsigned char)ps2[i]);
		else
			i++;
	}
	return (0);
}
