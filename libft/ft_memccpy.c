/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 08:48:27 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 07:50:51 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*pd;
	char			*ps;

	pd = (char*)dst;
	ps = (char*)src;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == (char)c)
			return (&pd[i + 1]);
		i++;
	}
	return (NULL);
}
