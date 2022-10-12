/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_slist			*create_list(void)
{
	t_slist		*list;

	if (!(list = (t_slist *)malloc(sizeof(t_slist))))
		return (NULL);
	list->head = NULL;
	return (list);
}

void			push_back(t_slist *list, char *data)
{
	t_line		*line;
	t_line		*tmp;

	if (list)
	{
		if (!(line = (t_line *)malloc(sizeof(t_line))))
			return ;
		line->data = ft_strdup(data);
		line->next = NULL;
		tmp = list->head;
		if (list->head == NULL)
			list->head = line;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = line;
		}
	}
}

void			clear_list(t_slist *list)
{
	t_line		*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ft_strdel(&list->head->data);
		free(list->head);
		list->head = tmp;
	}
	list = NULL;
}

void			print_list(t_slist *list)
{
	t_line		*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}
