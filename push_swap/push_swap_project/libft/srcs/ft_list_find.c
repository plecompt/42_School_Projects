/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:52:32 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/06 16:04:07 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_find(t_list *begin_list, int nb)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		if (*((int*)tmp->content) == nb)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
