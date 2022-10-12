/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:53:27 by plecompt          #+#    #+#             */
/*   Updated: 2017/01/23 18:57:04 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_less(t_list *lst, int nb)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			if (*((int*)tmp->content) < nb)
				i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
