/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:31:26 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/10 14:31:32 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		rev_rotate(t_list **p_a)
{
	t_list *tmp;
	t_list *end;

	tmp = *p_a;
	end = *p_a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = *p_a;
	*p_a = end;
}

void			rev_rotate_b(t_push *list)
{
	t_list *tmp;
	t_list *end;

	if (list->p_b && (list->p_b)->next)
	{
		tmp = list->p_b;
		end = list->p_b;
		while (tmp->next->next)
			tmp = tmp->next;
		end = tmp->next;
		tmp->next = NULL;
		end->next = list->p_b;
		list->p_b = end;
		ft_lstadd(&list->op, ft_lstnew("rrb", 3));
		register_data(list);
	}
}

void			rev_rotate_a(t_push *list)
{
	t_list *tmp;
	t_list *end;

	if (list->p_a && (list->p_a)->next)
	{
		tmp = list->p_a;
		end = list->p_a;
		while (tmp->next->next)
			tmp = tmp->next;
		end = tmp->next;
		tmp->next = NULL;
		end->next = list->p_a;
		list->p_a = end;
		ft_lstadd(&list->op, ft_lstnew("rra", 3));
		register_data(list);
	}
}

void			rev_rotate_rr(t_push *list)
{
	if (list->p_a && (list->p_a)->next)
		rev_rotate(&list->p_a);
	if (list->p_b && (list->p_b)->next)
		rev_rotate(&list->p_b);
	ft_lstadd(&list->op, ft_lstnew("rrr", 3));
	register_data(list);
}
