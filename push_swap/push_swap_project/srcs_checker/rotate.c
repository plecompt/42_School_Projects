/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:15:10 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/14 13:02:58 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push *list)
{
	t_list *tmp;
	t_list *end;

	if (list->p_a && (list->p_a)->next)
	{
		tmp = list->p_a;
		end = list->p_a;
		while (tmp->next)
			tmp = tmp->next;
		list->p_a = (list->p_a)->next;
		tmp->next = end;
		end->next = NULL;
		ft_lstadd(&list->op, ft_lstnew("ra", 2));
		register_data(list);
	}
}

void	rotate_b(t_push *list)
{
	t_list *tmp;
	t_list *end;

	if (list->p_b && (list->p_b)->next)
	{
		tmp = list->p_b;
		end = list->p_b;
		while (tmp->next)
			tmp = tmp->next;
		list->p_b = (list->p_b)->next;
		tmp->next = end;
		end->next = NULL;
		ft_lstadd(&list->op, ft_lstnew("rb", 2));
		register_data(list);
	}
}

void	rotate_rr(t_push *list)
{
	t_list *tmp;
	t_list *end;

	if (list->p_a && (list->p_a)->next && list->p_b && (list->p_b)->next)
	{
		tmp = list->p_a;
		end = list->p_a;
		while (tmp->next)
			tmp = tmp->next;
		list->p_a = (list->p_a)->next;
		tmp->next = end;
		end->next = NULL;
		tmp = list->p_b;
		end = list->p_b;
		while (tmp->next)
			tmp = tmp->next;
		list->p_b = (list->p_b)->next;
		tmp->next = end;
		end->next = NULL;
		ft_lstadd(&list->op, ft_lstnew("rr", 2));
		register_data(list);
	}
}
