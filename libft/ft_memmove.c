/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:45:32 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 07:51:29 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pd;
	char	*ps;
	size_t	i;

	pd = (char*)dst;
	ps = (char*)src;
	i = -1;
	if (ps < pd)
	{
		while ((int)(--len) >= 0)
			pd[len] = ps[len];
	}
	else
	{
		while (++i < len)
			pd[i] = ps[i];
	}
	return (pd);
}
