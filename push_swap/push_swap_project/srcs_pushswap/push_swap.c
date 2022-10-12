/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:48 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/05 12:06:37 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				number_sup(int *tab, int size, int number)
{
	int i;
	int number_is_sup_to_number;

	number_is_sup_to_number = 0;
	i = 0;
	while (i <= size)
	{
		if (tab[i] > number)
			number_is_sup_to_number++;
		i++;
	}
	return (number_is_sup_to_number);
}

int				main(int argc, char **argv)
{
	t_push *list;
	t_data data;
	t_list *del;

	if (!(list = malloc(sizeof(t_push))))
		return (0);
	data_init(&data, list);
	list->data = &data;
	parser(argc, argv, list);
	MIN = MIN_A;
	MAX = MAX_A;
	if (ELEM_A <= 50)
		sort_bubble(list);
	else
		quick_sort(list);
	ft_lstreverse(&(list->op));
	while (list->op)
	{
		ft_putendl((char*)list->op->content);
		del = list->op;
		list->op = list->op->next;
		free(del->content);
		free(del);
	}
	return (0);
}
