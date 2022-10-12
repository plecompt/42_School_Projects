/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_cost(int **adj_matrix, t_env *e)
{
	int			i;
	int			j;

	i = -1;
	while (++i < e->room_nb)
	{
		j = -1;
		if (!(e->cost[i] = malloc(sizeof(int) * e->room_nb)))
			return ;
		while (++j < e->room_nb)
		{
			if (adj_matrix[i][j] == 0)
				e->cost[i][j] = INF;
			else
				e->cost[i][j] = adj_matrix[i][j];
		}
	}
}

static void		init_var(t_env *e)
{
	int			i;

	i = -1;
	while (++i < e->room_nb)
	{
		e->dist[i] = e->cost[e->start_index][i];
		e->pred[i] = e->start_index;
		e->visited[i] = 0;
	}
	e->dist[e->start_index] = 0;
	e->visited[e->start_index] = 1;
}

static void		loop(int count, int i, t_env *e)
{
	while (++count < e->room_nb)
	{
		e->min_dist = INF;
		i = -1;
		while (++i < e->room_nb)
		{
			if (e->dist[i] < e->min_dist && !e->visited[i])
			{
				e->min_dist = e->dist[i];
				e->next_room = i;
			}
		}
		e->visited[e->next_room] = 1;
		i = -1;
		while (++i < e->room_nb)
		{
			if (!e->visited[i] && e->min_dist + \
			e->cost[e->next_room][i] < e->dist[i])
			{
				e->dist[i] = e->min_dist + e->cost[e->next_room][i];
				e->pred[i] = e->next_room;
			}
		}
	}
}

void			dijkstra(int **adj_matrix, t_room **room_list, \
t_slist *list, t_env *e)
{
	int			count;
	int			i;

	count = -1;
	i = -1;
	init_cost(adj_matrix, e);
	e->start_index = get_index_from_name(room_list, e->start_name, e);
	e->end_index = get_index_from_name(room_list, e->end_name, e);
	if (e->start_index == -1 || e->end_index == -1)
		print_error("Error: index out of range");
	init_var(e);
	loop(count, i, e);
	print_all(room_list, list, e);
	free_matrix(e->cost, e);
}
