/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:28:59 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/18 11:40:35 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		register_data_pb(t_push *list)
{
	t_list *tmp;

	tmp = list->p_b;
	MIN_B = *((int*)tmp->content);
	MAX_B = *((int*)tmp->content);
	while (tmp)
	{
		if (*((int*)tmp->content) > MAX_B)
			MAX_B = *((int*)tmp->content);
		if (*((int*)tmp->content) < MIN_B)
			MIN_B = *((int*)tmp->content);
		LAST_B = *((int*)tmp->content);
		tmp = tmp->next;
	}
}

void		register_data(t_push *list)
{
	t_list *tmp;

	tmp = list->p_a;
	if (tmp)
	{
		MIN_A = *((int*)tmp->content);
		MAX_A = *((int*)tmp->content);
		while (tmp)
		{
			if (*((int*)tmp->content) > MAX_A)
				MAX_A = *((int*)tmp->content);
			if (*((int*)tmp->content) < MIN_A)
				MIN_A = *((int*)tmp->content);
			LAST_A = *((int*)tmp->content);
			tmp = tmp->next;
		}
	}
	if (list->p_b)
		register_data_pb(list);
}

void		data_init(t_data *data, t_push *list)
{
	data->nb_elem_a = 0;
	data->nb_elem_b = 0;
	data->nb_max_a = 0;
	data->nb_max_b = 0;
	data->nb_min_a = 0;
	data->nb_min_b = 0;
	data->last_a = 0;
	data->last_b = 0;
	data->flag = 0;
	list->p_a = NULL;
	list->p_b = NULL;
	list->op = NULL;
}
