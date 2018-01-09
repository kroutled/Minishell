/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:58:42 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/04 07:38:41 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_env_var(int pos)
{
	int	count;
	int	varcount;

	free(g_myenv[pos]);
	g_myenv[pos] = NULL;
	count = pos;
	varcount = count + 1;
	while (g_myenv[count + 1])
	{
		g_myenv[count] = (g_myenv[count + 1]);
		g_myenv[count + 1] = NULL;
		count++;
		varcount++;
	}
}

int		unset_env(char **args)
{
	int	pos;
	int	count;

	count = 0;
	if (!args[1])
	{
		ft_putstr("Too few arguments\n");
		return (1);
	}
	while (args[count])
	{
		pos = seek_env_var(args[count]);
		if (g_myenv[pos])
			delete_env_var(pos);
		count++;
	}
	return (1);
}
