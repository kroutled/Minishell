/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:32:47 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/26 15:42:21 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	pc;

	i = 0;
	pc = (char)c;
	while (s[i] && s[i] != pc)
		i++;
	if (s[i] == pc)
		return ((char*)&s[i]);
	else
		return (NULL);
}
