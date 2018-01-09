/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:03:10 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/05 12:36:32 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envinit(void)
{
	extern char		**environ;
	int				count;

	count = 0;
	while (environ[count])
		count++;
	g_myenv = (char**)ft_memalloc(sizeof(char**) * (count + 1));
	count = 0;
	while (environ[count])
	{
		g_myenv[count] = ft_strdup(environ[count]);
		count++;
	}
	g_myenv[count] = NULL;
	return (g_myenv);
}
