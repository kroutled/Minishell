/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:25:16 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/21 15:10:30 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	l;

	l = ft_strlen((char *)src);
	i = 0;
	while (i < len)
	{
		if (i > l)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
