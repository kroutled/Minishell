/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroutled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 08:51:26 by kroutled          #+#    #+#             */
/*   Updated: 2017/07/27 10:54:52 by kroutled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_start;

	ret_start = f(lst);
	lst = lst->next;
	ret = ret_start;
	while (lst)
	{
		ret->next = f(lst);
		ret = ret->next;
		lst = lst->next;
	}
	ret = NULL;
	return (ret_start);
}
