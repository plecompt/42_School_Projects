/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_not_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:47:38 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/02 17:41:47 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_not_sort(t_list *lst, t_bool order)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp->next)
		{
			if (order == 1 && !((*(int*)tmp->content)
			< (*(int*)tmp->next->content)))
			{
				return (*((int*)tmp->content));
			}
			if (order == 0 && !((*(int*)tmp->content)
			> (*(int*)tmp->next->content)))
				return (*((int*)tmp->content));
			i++;
			tmp = tmp->next;
		}
	}
	return (0);
}
