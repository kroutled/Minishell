/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:28:02 by kroutled          #+#    #+#             */
/*   Updated: 2017/08/14 14:40:34 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	while (i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
	return (dst);
}
