/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:28:39 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/10 14:28:52 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_push *list)
{
	t_list *tmp;

	if ((list->p_b))
	{
		tmp = (list->p_b);
		(list->p_b) = ((list->p_b))->next;
		tmp->next = (list->p_a);
		(list->p_a) = tmp;
		(ELEM_A)++;
		(ELEM_B)--;
		ft_lstadd((&list->op), ft_lstnew("pa", 2));
		register_data(list);
	}
}

void	push_b(t_push *list)
{
	t_list *tmp;

	if ((list->p_a))
	{
		tmp = (list->p_a);
		(list->p_a) = ((list->p_a))->next;
		tmp->next = (list->p_b);
		(list->p_b) = tmp;
		(ELEM_A)--;
		(ELEM_B)++;
		ft_lstadd(&(list->op), ft_lstnew("pb", 2));
		register_data(list);
	}
}
