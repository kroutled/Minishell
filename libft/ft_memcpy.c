/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 08:14:13 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/07 10:42:17 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dst);
}
