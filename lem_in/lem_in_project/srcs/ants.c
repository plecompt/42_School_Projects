/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_ants(char *room_name, t_env *e)
{
	if (e->first_ant != 0)
		ft_putstr(" ");
	ft_putstr("L");
	ft_putnbr(e->ant_index + 1);
	ft_putstr("-");
	ft_putstr(room_name);
	e->first_ant = 1;
}

static void			init(t_env *e)
{
	int				i;

	e->pos = 0;
	e->ant_index = 0;
	i = -1;
	e->ants_in_room = malloc(sizeof(int) * e->ants);
	e->ants_arrived = malloc(sizeof(int) * e->ants);
	while (++i < e->ants)
	{
		e->ants_in_room[i] = 0;
		e->ants_arrived[i] = 0;
	}
}

static void			init_loop(t_env *e)
{
	e->first_ant = e->ant_index == e->ants ? 0 : e->first_ant;
	e->ant_index == e->ants ? ft_putstr("\n") : 0;
	e->ant_index = -1;
}

static void			is_ant_arrived(t_env *e)
{
	if (e->pos == e->nb_elem - 1 && e->ants_arrived[e->ant_index] == 0)
	{
		e->ants_arrived[e->ant_index] = 1;
		e->i++;
	}
}

void				handle_ants(t_room **r_list, int *path, t_env *e)
{
	init(e);
	e->i = 0;
	while (e->i < e->ants)
	{
		init_loop(e);
		while (++e->ant_index < e->ants)
		{
			e->pos = e->ants_in_room[e->ant_index];
			if (e->pos + 1 < e->nb_elem && \
			r_list[path[e->pos + 1]]->ant_nb == 0)
			{
				print_ants(r_list[path[e->pos + 1]]->name, e);
				e->ants_in_room[e->ant_index] = e->pos + 1;
				r_list[path[e->pos]]->ant_nb--;
				if (e->pos + 1 < e->nb_elem - 1)
					r_list[path[e->pos + 1]]->ant_nb++;
			}
			is_ant_arrived(e);
		}
		e->i - 1 == e->ants ? ft_putstr("\n") : 0;
	}
	free(e->ants_in_room);
	free(e->ants_arrived);
}
