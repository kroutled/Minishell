/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:05:49 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 08:00:17 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			k;

	i = 0;
	if (little[0] == 0)
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		while (big[i + k] == little[k] && (i + k) < len)
		{
			if (little[k + 1] == '\0')
				return ((char*)big + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
