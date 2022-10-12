/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		result_error(t_slist *list, t_env *e)
{
	if (ft_is_dup(list) == TRUE)
		print_error("Error: duplicates lines");
	if (e->room_nb == 1)
		print_error("Error: not enough rooms");
	if (!e->is_start || !e->is_end)
		print_error("Error: no start/end");
	if (!e->is_pipe)
		print_error("Error: no path found");
	if (e->start_name == NULL || e->end_name == NULL)
		print_error("Error: invalid room");
}

static void		free_all(char *tmp, char *line, t_env *e, t_slist *list)
{
	ft_strdel(&tmp);
	ft_strdel(&line);
	ft_strdel(&e->start_name);
	ft_strdel(&e->end_name);
	clear_list(list);
}

static size_t	get_room_count(t_slist *list)
{
	t_line		*tmp;
	char		**arr;
	int			i;

	i = 0;
	tmp = list->head;
	while (tmp)
	{
		arr = ft_strsplit(tmp->data, ' ');
		if (ft_arrlen(arr) == 3)
		{
			if (ft_isnumber(arr[1]) && ft_isnumber(arr[2]))
				i++;
			else
				print_error("Error: invalid room");
		}
		ft_arrdel(arr);
		tmp = tmp->next;
	}
	return (i);
}

static void		get_data(t_env *e)
{
	char		*line;
	int			i;
	char		*tmp;
	t_slist		*list;

	i = 0;
	tmp = NULL;
	list = create_list();
	if (read(0, &line, 0) == -1)
		print_error("Error: stdin: Is a directory");
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, ""))
			break ;
		error_handling(line, tmp, i++, e);
		ft_strdel(&tmp);
		tmp = ft_strdup(line);
		push_back(list, line);
		ft_strdel(&line);
	}
	e->room_nb = get_room_count(list);
	result_error(list, e);
	fill_matrix(list, e);
	free_all(tmp, line, e, list);
}

int				main(int ac, char **av)
{
	t_env		env;

	(void)av;
	env.is_start = FALSE;
	env.is_end = FALSE;
	env.is_pipe = FALSE;
	env.nb_pipe = 0;
	if (ac > 1)
		print_error("Error: no args needed");
	get_data(&env);
	return (0);
}
