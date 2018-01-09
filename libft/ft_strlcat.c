/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:33:42 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/20 13:10:03 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (size <= dstl)
		return (srcl + size);
	i = dstl;
	while ((i + 1) < size && src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dstl + srcl);
}
