/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:37:25 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/27 13:50:49 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	tmp;

	if (*begin_list && cmp)
	{
		tmp = *begin_list;
		while (tmp)
		{
			if (!((*cmp)(tmp->data, data_ref)))
			{
				tmp->next = tmp->next->next;
				free(tmp);
			}
			tmp = tmp->next;
		}
	}
}
