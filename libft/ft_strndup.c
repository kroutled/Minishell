/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:36:41 by kroutled          #+#    #+#             */
/*   Updated: 2017/08/23 15:15:40 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int len)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] != '\0' && i <= len)
		i++;
	dst = (char *)ft_strnew(i);
	if (dst == NULL)
		return (NULL);
	while (i)
	{
		i--;
		dst[i] = src[i];
	}
	return (dst);
}
