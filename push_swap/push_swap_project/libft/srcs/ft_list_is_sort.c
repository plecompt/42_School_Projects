/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:47:38 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/04 19:35:32 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_list_is_sort(t_list *lst, t_bool order)
{
	t_list *tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
		{
			if (order == 1 && !((*(int*)tmp->content) <
			(*(int*)tmp->next->content)))
				return (0);
			if (order == 0 && !((*(int*)tmp->content) >
			(*(int*)tmp->next->content)))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
