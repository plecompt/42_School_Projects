/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:54:54 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 14:24:37 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label			*create_list(void)
{
	t_label		*list;

	if (!(list = (t_label *)malloc(sizeof(t_label))))
		print_error("malloc: asm: create_list", NULL);
	list->head = NULL;
	return (list);
}

void			clear_list(t_label *list)
{
	t_node		*tmp;

	tmp = list->head;
	while (tmp)
	{
		tmp = tmp->next;
		ft_strdel(&list->head->name);
		free(list->head);
		list->head = tmp;
	}
	if (list)
		free(list);
	list = NULL;
}

void			print_list(t_label *list)
{
	t_node		*tmp;

	tmp = list->head;
	if (tmp == NULL)
		ft_putendl("List is empty.");
	else
	{
		ft_putendl("List:");
		while (tmp)
		{
			ft_printf("- <%s>\n", tmp->name);
			tmp = tmp->next;
		}
	}
}

void			list_push_back(t_label *list, char *data)
{
	t_node		*node;
	t_node		*tmp;

	if (list)
	{
		if (!(node = (t_node *)malloc(sizeof(t_node))))
			print_error("malloc: asm: list_push_back error", NULL);
		node->name = ft_strdup(data);
		node->next = NULL;
		if (list->head == NULL)
			list->head = node;
		else
		{
			tmp = list->head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}
