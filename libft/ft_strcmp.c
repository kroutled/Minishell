/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 07:31:08 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/17 11:09:52 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while (ps1[i] && ps2[i] && ps1[i] == ps2[i])
	{
		i++;
	}
	return (ps1[i] - ps2[i]);
}
