/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:21:18 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/07 09:50:42 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define IS_QUOTE(c) (c == '"' || c == '\'')

typedef struct	s_var
{
	int		i;
	int		wrds;
	int		count;
	int		len;
	char	*hold;
	char	*sub;
	char	*temp;
	size_t	cnt;
	size_t	r_cnt;
}				t_var;

char			**g_myenv;

char			**realloc_myenv(int size);
char			**ft_mystrsplit(const char *str);
char			**qsave(const char *str, char **ret,
		size_t *r_cnt, size_t *cnt);
char			**envinit(void);
char			**pathcheck(void);
char			*get_env_var(char *var);
char			*tilda(char **args);
int				builtin_cd(char **args);
int				change_dir(char *path);
int				builtin_echo(char **args);
int				sh_fork(char *temp, char **args, char **path);
int				sh_launch(char **args);
int				sh_exec(char **args);
int				seek_env_var(char *var);
int				set_env(char **args);
int				unset_env(char **args);
int				builtin_env(void);
void			sh_run(void);
void			set_env_var(char *key, char *value);
void			delete_env_var(int pos);

#endif
