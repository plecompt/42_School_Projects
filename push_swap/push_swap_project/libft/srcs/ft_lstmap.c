/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:04:56 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/14 11:28:55 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *bef;
	t_list *new;

	if (!f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new)
		{
			new = tmp;
			bef = new;
			new->next = NULL;
		}
		else
		{
			new->next = tmp;
			tmp->next = NULL;
			new = new->next;
		}
		lst = lst->next;
	}
	return (bef);
}
