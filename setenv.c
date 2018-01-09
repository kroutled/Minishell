/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:47:12 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/04 15:07:35 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_env(void)
{
	int		count;

	count = 0;
	while (g_myenv[count])
	{
		ft_putstr(g_myenv[count]);
		ft_putchar('\n');
		count++;
	}
	return (1);
}

int			seek_env_var(char *var)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	while (var[len] != '=' && var[len] != '\0')
		len++;
	while (g_myenv[count])
	{
		if (ft_strncmp(g_myenv[count], var, len + 1) == '=')
			return (count);
		count++;
	}
	return (count);
}

char		**realloc_myenv(int size)
{
	char	**newenv;
	int		count;

	newenv = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	count = 0;
	while (g_myenv[count] && count < size)
	{
		newenv[count] = ft_strdup(g_myenv[count]);
		count++;
	}
	g_myenv[count] = NULL;
	ft_free2d(g_myenv);
	return (newenv);
}

void		set_env_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = seek_env_var(key);
	tmp = ft_strjoin("=", value);
	if (g_myenv[pos])
	{
		free(g_myenv[pos]);
		if (value)
			g_myenv[pos] = ft_strjoin(key, tmp);
		else
			g_myenv[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_myenv = realloc_myenv(pos + 1);
		if (value)
			g_myenv[pos] = ft_strjoin(key, tmp);
		else
			g_myenv[pos] = ft_strjoin(key, "=");
	}
	free(tmp);
}

int			set_env(char **args)
{
	if (!args[1])
	{
		builtin_env();
		return (1);
	}
	if (args[2])
	{
		if (args[3])
		{
			ft_putendl("setenv: Too many arguments.");
			return (1);
		}
	}
	set_env_var(args[1], args[2]);
	return (1);
}
