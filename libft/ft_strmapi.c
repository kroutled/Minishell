/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:54:05 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 09:06:05 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*mem;
	int		i;

	if (!s || !f)
		return (NULL);
	mem = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	i = 0;
	if (mem == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = f(i, (char)s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
