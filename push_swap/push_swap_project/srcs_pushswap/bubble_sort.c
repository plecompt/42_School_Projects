/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:14:38 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/23 15:21:24 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*sort_int_tab(t_list *p_a, int size)
{
	t_list	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tmp = p_a;
	if (!(tab = malloc(sizeof(int) * size)))
		error();
	while (tmp)
	{
		tab[i++] = *((int*)tmp->content);
		tmp = tmp->next;
	}
	ft_insertion_sort(tab, size);
	return (tab);
}

t_bool		whos_next(int *tab, int size, int nb, int next)
{
	int i;

	i = 0;
	while (i < size && tab[i] != nb)
		i++;
	if (tab[i + 1] == next)
		return (1);
	else
		return (0);
}

void		sort_pile_b(t_push *list)
{
	while (ELEM_B >= 2 && PA < PB && MAX_B > PA && MIN_B < PA)
		if (ft_list_find_more(list->p_b, PA) <= ELEM_B / 2)
			rotate_b(list);
		else
			rev_rotate_b(list);
	push_b(list);
	while (!(ft_list_is_sort(list->p_b, 0)))
		if (ft_list_find(list->p_b, MAX_B) <= ELEM_B / 2)
			while (!(ft_list_is_sort(list->p_b, 0)))
				rotate_b(list);
		else
			while (!(ft_list_is_sort(list->p_b, 0)))
				rev_rotate_b(list);
}

void		sort_bubble(t_push *list)
{
	int		*tab;
	int		elem;

	elem = ELEM_A;
	tab = sort_int_tab(list->p_a, ELEM_A);
	while (!(ft_list_is_sort(list->p_a, 1)) || list->p_b)
	{
		if (list->p_a->next && whos_next(tab, elem, PA_N, PA))
			swap_a(list);
		else if ((list->p_a->next && !(whos_next(tab, elem, PA, PA_N)) &&
		PA != MAX))
			sort_pile_b(list);
		else if (list->p_b && list->p_a && whos_next(tab, elem, PB, PA))
			push_a(list);
		else
		{
			if (list->p_b && list->p_a && whos_next(tab, elem, PB, LAST_A))
				rev_rotate_a(list);
			else if (ft_lst_not_sort(list->p_a, 1) >= ELEM_A / 2)
				rev_rotate_a(list);
			else if (ft_lst_not_sort(list->p_a, 1) <= ELEM_A / 2)
				rotate_a(list);
		}
	}
	free(tab);
}
