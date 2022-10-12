/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:14:38 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/14 13:28:43 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_next(int *tab, int size, int number)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] < number && tab[i + 1] > number)
			break ;
		i++;
	}
	return (tab[i + 1]);
}

static void	sort_in_sort_pb(t_push *list, int *tab)
{
	int	next;

	while (ELEM_A >= 2 && !(PB < PA && PB > LAST_A))
	{
		if (list->p_b && list->p_b->next && PB_N < PA && PB_N > LAST_A
		&& !(PB < PA && PB > LAST_A))
			swap_b(list);
		else
		{
			tab = sort_int_tab(list->p_a, ELEM_A);
			next = search_next(tab, ELEM_A, PB);
			if (ft_list_find(list->p_a, next) >= ELEM_A / 2)
				rev_rotate_a(list);
			else
				rotate_a(list);
			free(tab);
		}
	}
}

static void	sort_pb(t_push *list, int *tab)
{
	if (PB > MAX_A)
		while (ELEM_A >= 2 && LAST_A != MAX_A)
			if (ft_list_find(list->p_a, MAX_A) <= ELEM_A / 2)
				rotate_a(list);
			else
				rev_rotate_a(list);
	else if (PB < MIN_A)
		while (ELEM_A >= 2 && PA != MIN_A)
			if (ft_list_find(list->p_a, MIN_A) <= ELEM_A / 2)
				rotate_a(list);
			else
				rev_rotate_a(list);
	else
		sort_in_sort_pb(list, tab);
	push_a(list);
}

void		sort_insertion(t_push *list)
{
	int	*tab;
	int	elem;

	tab = NULL;
	elem = ELEM_A;
	while (!(ft_list_is_sort(list->p_a, 1)) || list->p_b)
	{
		if (list->p_b && ELEM_B)
			sort_pb(list, tab);
		else
		{
			if (!ELEM_B)
			{
				if (ft_list_find(list->p_a, MIN) <= ELEM_A / 2)
					rotate_a(list);
				else
					rev_rotate_a(list);
			}
			else
				rotate_b(list);
		}
	}
	free(tab);
}
