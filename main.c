/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 07:15:15 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/07 11:10:43 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "minishell.h"
#include <sys/wait.h>

int		sh_fork(char *temp, char **args, char **path)
{
	pid_t	pid;

	if (temp)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(temp, args, g_myenv);
			return (0);
		}
		else if (pid < 0)
		{
			ft_putendl("error");
			ft_free2d(path);
		}
		else
			wait(&pid);
		ft_strdel(&temp);
	}
	else
		error(args);
	if (path != NULL)
		ft_free2d(path);
	return (1);
}

int		sh_launch(char **args)
{
	struct stat	sb;
	char		**path;
	t_var		v;

	v.i = 0;
	v.temp = NULL;
	path = pathcheck();
	if (stat(args[0], &sb) == 0 && sb.st_mode & S_IFREG && sb.st_mode & S_IXUSR)
		v.temp = ft_strdup(args[0]);
	if (path && v.temp == NULL)
	{
		while (path[v.i])
		{
			ft_strappend(&v.temp, path[v.i]);
			ft_strappend(&v.temp, "/");
			ft_strappend(&v.temp, args[0]);
			if (stat(v.temp, &sb) == 0 && sb.st_mode &
					S_IFREG && sb.st_mode & S_IXUSR)
				break ;
			ft_strdel(&v.temp);
			v.i++;
		}
	}
	sh_fork(v.temp, args, path);
	return (1);
}

int		sh_exec(char **args)
{
	if (!args || args[0] == NULL)
		return (1);
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args));
	else if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env());
	else if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (set_env(args));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (unset_env(args));
	return (sh_launch(args));
}

void	sh_run(void)
{
	char	**args;
	char	*line;
	int		status;

	status = 1;
	line = NULL;
	args = NULL;
	while (status)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &line) < 0)
			ft_putstr("error\n");
		args = ft_mystrsplit(line);
		free(line);
		status = sh_exec(args);
		ft_free2d(args);
	}
}

int		main(void)
{
	g_myenv = envinit();
	sh_run();
	ft_free2d(g_myenv);
	return (0);
}
