/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_index(t_env *e)
{
	int			end;

	end = e->end_index;
	printf("\nPath by room index = %d", end);
	while (end != e->start_index)
	{
		end = e->pred[end];
		printf(" \033[33m<-\033[0m %d", end);
		e->nb_elem++;
	}
}

void			print_all(t_room **room_list, t_slist *list, t_env *e)
{
	int			end;
	int			path[e->room_nb - 1];
	int			i;

	i = 0;
	e->nb_elem = 1;
	end = e->end_index;
	if (e->dist[end] == INF)
		print_error("Error: target unreachable");
	print_list(list);
	printf("\nDistance of node %d = \033[33m%d\033[0m ", end, e->dist[end]);
	print_index(e);
	end = e->end_index;
	i = e->nb_elem - 1;
	path[i--] = end;
	printf("\nPath by room name = %s", get_name_from_index(room_list, end, e));
	while (end != e->start_index)
	{
		end = e->pred[end];
		printf(" \033[33m<-\033[0m %s", get_name_from_index(room_list, end, e));
		path[i--] = end;
	}
	printf("\n");
	handle_ants(room_list, path, e);
}
