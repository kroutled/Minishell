/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:15:47 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/04 07:33:38 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **str, char *app)
{
	char	*temp;

	if (str && app)
	{
		if (*str)
		{
			temp = ft_strjoin(*str, app);
			if (temp)
			{
				ft_strdel(str);
				*str = temp;
			}
		}
		else
			*str = ft_strdup(app);
	}
}
