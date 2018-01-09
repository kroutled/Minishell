/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:32:56 by kroutled          #+#    #+#             */
/*   Updated: 2017/06/23 09:19:26 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*mem;

	mem = malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	else
		ft_memset(mem, '\0', size + 1);
	return (mem);
}
