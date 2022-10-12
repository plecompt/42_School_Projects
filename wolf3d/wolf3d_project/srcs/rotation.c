/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:29 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:16:31 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_rotate_left(t_env *e)
{
	e->move.old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-(e->move.rot_speed)) - e->dir_y * \
		sin(-(e->move.rot_speed));
	e->dir_y = e->move.old_dir_x * sin(-(e->move.rot_speed)) + e->dir_y * \
		cos(-(e->move.rot_speed));
	e->move.old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(-(e->move.rot_speed)) - e->plane_y * \
		sin(-(e->move.rot_speed));
	e->plane_y = e->move.old_plane_x * sin(-(e->move.rot_speed)) + e->plane_y *\
		cos(-(e->move.rot_speed));
}

void		ft_rotate_right(t_env *e)
{
	e->move.old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->move.rot_speed) - e->dir_y * \
		sin(e->move.rot_speed);
	e->dir_y = e->move.old_dir_x * sin(e->move.rot_speed) + e->dir_y * \
		cos(e->move.rot_speed);
	e->move.old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(e->move.rot_speed) - e->plane_y * \
		sin(e->move.rot_speed);
	e->plane_y = e->move.old_plane_x * sin(e->move.rot_speed) + e->plane_y *\
		cos(e->move.rot_speed);
}
