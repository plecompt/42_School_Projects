/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			free_rooms(t_room **room_list, t_env *e)
{
	int				i;

	i = -1;
	while (++i < e->room_nb)
	{
		ft_strdel(&room_list[i]->name);
		free(room_list[i]);
	}
	room_list = NULL;
}

static void			bfs_add_rooms(char *name, char *x, char *y, t_room **r_list)
{
	static int		room_count = 0;
	t_room			*room;

	if (!(room = malloc(sizeof(t_room))))
		return ;
	room->name = ft_strdup(name);
	room->x = ft_atoi(x);
	room->y = ft_atoi(y);
	room->visited = FALSE;
	room->ant_nb = 0;
	r_list[room_count++] = room;
}

static void			bfs_add_edge(int start, int end, int **adj_matrix, \
t_room **room_list)
{
	int				i;
	int				coord_array[4];
	float			distance;

	i = -1;
	while (room_list[++i])
	{
		if (i == start)
		{
			coord_array[0] = room_list[i]->x;
			coord_array[1] = room_list[i]->y;
		}
		if (i == end)
		{
			coord_array[2] = room_list[i]->x;
			coord_array[3] = room_list[i]->y;
		}
	}
	if (start >= 0 && end >= 0)
	{
		distance = get_distance(coord_array);
		adj_matrix[start][end] = round(distance);
		adj_matrix[end][start] = round(distance);
	}
}

void				get_cost(t_slist *list, \
t_env *e, int **adj_matrix, t_room **room_list)
{
	char			**arr;
	t_line			*tmp;

	tmp = list->head;
	if (!(e->pipe = (char **)malloc(sizeof(char *) * e->nb_pipe)))
		return ;
	while (tmp)
	{
		e->room1 = 0;
		e->room2 = 0;
		arr = ft_strsplit(tmp->data, '-');
		if (ft_arrlen(arr) == 2)
		{
			e->room1 = get_index_from_name(room_list, arr[0], e);
			e->room2 = get_index_from_name(room_list, arr[1], e);
			bfs_add_edge(e->room1, e->room2, adj_matrix, room_list);
		}
		ft_arrdel(arr);
		tmp = tmp->next;
	}
}

void				fill_matrix(t_slist *list, t_env *e)
{
	t_line			*tmp;
	char			**arr;
	t_room			*room_list[e->room_nb];
	int				*adj_matrix[e->room_nb];

	tmp = list->head;
	init_matrix(adj_matrix, e);
	while (tmp)
	{
		arr = ft_strsplit(tmp->data, ' ');
		if (ft_arrlen(arr) == 3)
			bfs_add_rooms(arr[0], arr[1], arr[2], room_list);
		ft_arrdel(arr);
		tmp = tmp->next;
	}
	get_cost(list, e, adj_matrix, room_list);
	dijkstra(adj_matrix, room_list, list, e);
	free_rooms(room_list, e);
	free_matrix(adj_matrix, e);
}
