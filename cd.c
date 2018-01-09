/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:39:57 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/05 12:36:46 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pathcheck(void)
{
	char	**paths;
	char	*tmp;

	tmp = get_env_var("PATH");
	paths = NULL;
	if (tmp != NULL)
		paths = ft_strsplit(tmp, ':');
	return (paths);
}

char	*get_env_var(char *var)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	while (var[len] != '=' && var[len] != '\0')
		len++;
	while (g_myenv[count])
	{
		if (ft_strncmp(g_myenv[count], var, len) == 0)
		{
			return (ft_strchr(g_myenv[count], '=') + 1);
		}
		count++;
	}
	return (NULL);
}

int		change_dir(char *path)
{
	char	*cwd;
	char	*pwd;
	char	buff[1024];

	if (!chdir(path))
	{
		pwd = get_env_var("PWD");
		cwd = getcwd(buff, 1023);
		set_env_var("OLDPWD", pwd);
		set_env_var("PWD", cwd);
		return (1);
	}
	else
		return (0);
}

char	*tilda(char **args)
{
	char	*str;
	char	*path;
	char	*home;
	int		i;
	int		len;

	len = ft_strlen(args[1]);
	i = 0;
	while (args[1][i] != '~')
		i++;
	str = ft_strsub(args[1], (i + 1), len);
	home = get_env_var("HOME");
	path = ft_strjoin(home, str);
	ft_strdel(&str);
	return (path);
}

int		builtin_cd(char **args)
{
	char	*path;

	path = NULL;
	if (!args[1])
		path = ft_strdup(get_env_var("HOME"));
	else if (args[1][0] == '~')
		path = tilda(args);
	else if (ft_strcmp(args[1], "-") == 0)
		path = ft_strdup(get_env_var("OLDPWD"));
	else
		path = ft_strdup(args[1]);
	if (path)
	{
		if (change_dir(path) == 0)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putstr(args[1]);
			ft_putchar('\n');
		}
	}
	ft_strdel(&path);
	return (1);
}
