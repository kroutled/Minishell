/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:39:48 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/17 12:51:00 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*mem;
	int		i;

	if (!s || !f)
		return (NULL);
	mem = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (mem == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = f(s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
