/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:06:44 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/28 17:17:29 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list *tmp;
	t_list *bef;
	t_list *nex;

	tmp = *lst;
	bef = NULL;
	if (tmp)
	{
		while (tmp)
		{
			nex = tmp->next;
			tmp->next = bef;
			bef = tmp;
			tmp = nex;
		}
		*lst = bef;
	}
}
