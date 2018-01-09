/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 06:57:21 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/01 12:37:01 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	int	nl;

	i = 0;
	len = ft_strlen(str);
	while ((len - 1) > i)
	{
		nl = str[i];
		str[i] = str[len - 1];
		str[len - 1] = nl;
		len--;
		nl++;
	}
	return (str);
}
