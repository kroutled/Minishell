/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 06:56:30 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/20 07:59:15 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char*)s);
	while (i >= 0 && s[i] != (unsigned char)c)
		i--;
	if (s[i] == (unsigned char)c)
		return ((char*)&s[i]);
	else
		return (NULL);
}
