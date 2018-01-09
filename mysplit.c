/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 09:46:00 by kroutled          #+#    #+#             */
/*   Updated: 2017/09/04 07:36:33 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	quotecheck(const char *str, size_t *cnt, size_t *wdcnt)
{
	if (str[*cnt] == '"')
	{
		while (str[*cnt] && str[*cnt] == '"')
			*cnt += 1;
		while (str[*cnt] && str[*cnt] != '"')
			*cnt += 1;
		while (str[*cnt] && str[*cnt] == '"')
			*cnt += 1;
		*wdcnt += 1;
	}
	return (*wdcnt);
}

static size_t	wdcount(const char *str)
{
	size_t		cnt;
	size_t		wdcnt;

	cnt = 0;
	wdcnt = 0;
	while (str[cnt])
	{
		if (str[cnt] == ' ' || str[cnt] == '\t')
		{
			while (str[cnt] == ' ' || str[cnt] == '\t')
				cnt++;
		}
		quotecheck(str, &cnt, &wdcnt);
		if (str[cnt] && str[cnt] != '"' && str[cnt] != ' ' && str[cnt] != '\t')
		{
			wdcnt++;
			while (str[cnt] && str[cnt] != ' ' && str[cnt] != '\t')
				cnt++;
		}
	}
	return (wdcnt);
}

static size_t	quotelen(const char *str)
{
	size_t		cnt;
	size_t		len;

	cnt = 0;
	len = 0;
	while (str[cnt])
	{
		if (str[cnt] == '"')
		{
			cnt++;
			while (str[cnt] && str[cnt] != '"')
			{
				len++;
				cnt++;
			}
		}
		cnt++;
	}
	return (len);
}

char			**qsave(const char *str, char **ret, size_t *r_cnt, size_t *cnt)
{
	int	tmp;

	if (str[*cnt] == '"')
	{
		ret[*r_cnt] = (char *)ft_memalloc(sizeof(char) *
				(quotelen(&str[*cnt]) + 1));
		while (str[*cnt] == '"')
			*cnt += 1;
		tmp = 0;
		while (str[*cnt] != '"' && str[*cnt])
		{
			ret[*r_cnt][tmp] = str[*cnt];
			*cnt += 1;
			tmp++;
		}
		while (str[*cnt] == '"')
			*cnt += 1;
		ret[*r_cnt][tmp] = '\0';
		*r_cnt += 1;
	}
	return (ret);
}

char			**ft_mystrsplit(const char *str)
{
	char		**ret;
	t_var		vs;

	vs.wrds = wdcount(str);
	if (!str)
		return (NULL);
	vs.cnt = 0;
	vs.r_cnt = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (vs.wrds + 1))))
		return (NULL);
	while (str[vs.cnt])
	{
		while (str[vs.cnt] && (str[vs.cnt] == ' ' || str[vs.cnt] == '\t'))
			vs.cnt++;
		if (str[vs.cnt] && (str[vs.cnt] != ' ' &&
					str[vs.cnt] != '\t' && str[vs.cnt] != '"'))
		{
			ret[vs.r_cnt] = ft_strsub(str, vs.cnt, wdlen(&str[vs.cnt]));
			vs.r_cnt++;
			vs.cnt = vs.cnt + wdlen(&str[vs.cnt]);
		}
		qsave(str, ret, &vs.r_cnt, &vs.cnt);
	}
	ret[vs.r_cnt] = NULL;
	return (ret);
}
