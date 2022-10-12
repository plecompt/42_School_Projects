/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:19:14 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/14 13:59:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push *list)
{
	t_list	*tmp;

	if ((list->p_a) && (list->p_a)->next)
	{
		tmp = ((list->p_a))->next;
		((list->p_a))->next = ((list->p_a))->next->next;
		tmp->next = (list->p_a);
		(list->p_a) = tmp;
		ft_lstadd(&(list->op), ft_lstnew("sa", 2));
	}
}

void	swap_b(t_push *list)
{
	t_list	*tmp;

	if ((list->p_b))
	{
		tmp = ((list->p_b))->next;
		((list->p_b))->next = ((list->p_b))->next->next;
		tmp->next = (list->p_b);
		(list->p_b) = tmp;
		ft_lstadd(&(list->op), ft_lstnew("sb", 2));
	}
}

void	swap_ss(t_push *list)
{
	t_list	*tmp;

	if ((list->p_a && list->p_b))
	{
		tmp = ((list->p_a))->next;
		((list->p_a))->next = ((list->p_a))->next->next;
		tmp->next = (list->p_a);
		(list->p_a) = tmp;
		tmp = ((list->p_b))->next;
		((list->p_b))->next = ((list->p_b))->next->next;
		tmp->next = (list->p_b);
		(list->p_b) = tmp;
		ft_lstadd(&(list->op), ft_lstnew("ss", 2));
	}
}
