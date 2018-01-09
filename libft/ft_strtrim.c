/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 10:57:43 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/20 10:56:25 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int	i;
	int	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len--;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && (i < len))
		len--;
	return (ft_strsub(s, i, (len - i + 1)));
}
