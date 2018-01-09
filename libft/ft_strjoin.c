/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:54:27 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/20 11:19:19 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		k;
	char	*mem;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	mem = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (mem == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		mem[i + k] = s2[k];
		k++;
	}
	mem[i + k] = '\0';
	return (mem);
}
