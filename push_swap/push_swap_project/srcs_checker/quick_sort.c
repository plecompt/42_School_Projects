/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:14:38 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/18 11:40:59 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		index_tab(int *tab, int size, int pivot)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (pivot == tab[i])
			return (i);
		i++;
	}
	return (0);
}

static t_bool	partition_is_over(t_push *list, int *elem, int *pivot, int size)
{
	int *tab;

	tab = NULL;
	if (*elem - *elem / (*elem / size) >= ELEM_A)
	{
		tab = sort_int_tab(list->p_a, ELEM_A);
		if (ELEM_A / (ELEM_A / size) < ELEM_A)
			*pivot = tab[ELEM_A / (ELEM_A / size)];
		else
			*pivot = MAX_A;
		*elem = ELEM_A;
	}
	free(tab);
	if (ELEM_A <= 1)
		return (0);
	else
		return (1);
}

static void		compare_pa_at_pivot(t_push *list, int pivot, int size, int *tab)
{
	int index;

	index = index_tab(tab, ELEM_A + ELEM_B, pivot);
	if (PA > tab[index - size / 2 - 1])
	{
		push_b(list);
		if (!(PA < pivot))
			rotate_rr(list);
		else
			rotate_b(list);
	}
	else
		push_b(list);
}

static void		search_next_less_at_pivot(t_push *list, int pivot)
{
	if (ft_list_find_less(list->p_a, pivot) <= ELEM_A / 2)
		while (PA >= pivot)
			rotate_a(list);
	else
		while (PA >= pivot)
			rev_rotate_a(list);
}

void			quick_sort(t_push *list)
{
	int	*tab;
	int	elem;
	int	pivot;
	int	size;

	elem = ELEM_A;
	tab = NULL;
	tab = sort_int_tab(list->p_a, ELEM_A);
	size = (elem > 200) ? 62 : 25;
	size = (elem < 50) ? 10 : size;
	pivot = tab[elem / (elem / size)];
	while (!(ft_list_is_sort(list->p_b, 1)) || list->p_a)
	{
		if (PA < pivot)
			compare_pa_at_pivot(list, pivot, size, tab);
		else if (partition_is_over(list, &elem, &pivot, size) == 0)
			break ;
		else
			search_next_less_at_pivot(list, pivot);
	}
	free(tab);
	sort_insertion(list);
}
