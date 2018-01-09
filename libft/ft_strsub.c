/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:13:43 by kroutled          #+#    #+#             */
/*   Updated: 2017/08/24 10:34:52 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	mem = (char*)malloc(sizeof(char) * len + 1);
	if (mem == NULL || !s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		mem[i] = s[start];
		start++;
		i++;
	}
	mem[i] = '\0';
	return (mem);
	free(mem);
}
