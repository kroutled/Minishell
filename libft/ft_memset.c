/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:37:07 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/21 15:35:59 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*d;
	unsigned char	p;

	i = 0;
	d = (char*)b;
	p = (unsigned char)c;
	while (i < len)
	{
		d[i] = p;
		i++;
	}
	return (d);
}
