/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:16:25 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 07:59:46 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int				i;
	int				l;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		l = 0;
		while (big[i + l] == little[l])
		{
			if (little[l + 1] == '\0')
				return ((char*)big + i);
			l++;
		}
		i++;
	}
	return (NULL);
}
