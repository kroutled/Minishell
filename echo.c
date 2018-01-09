/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:41:36 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/04 07:27:18 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo(char **str, int count)
{
	int		starts;
	int		ends;
	int		strlen;

	starts = IS_QUOTE(str[count][0]);
	strlen = ft_strlen(str[count]);
	ends = IS_QUOTE(str[count][strlen - 1]);
	if (ends && starts)
		ft_putnstr(str[count] + 1, strlen);
	else if (ends)
		ft_putnstr(str[count], strlen - 1);
	else if (starts)
		ft_putstr(str[count] + 1);
	else
		ft_putstr(str[count]);
	if (str[count])
		ft_putchar(' ');
}

int				builtin_echo(char **args)
{
	t_var	var;

	var.len = 1;
	var.count = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		var.count = 1;
	while (args[var.count])
	{
		if (args[var.count][0] == '$')
		{
			while (args[var.count][var.len] != '=' &&
					args[var.count][var.len] != '\0')
				var.len++;
			var.sub = ft_strsub(args[var.count], 1, var.len);
			var.hold = get_env_var(var.sub);
			ft_putstr(var.hold);
			free(var.sub);
		}
		else
			echo(args, var.count);
		var.count++;
	}
	ft_putchar('\n');
	return (1);
}
