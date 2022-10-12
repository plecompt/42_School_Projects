/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:07 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:16:08 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ft_init_env(t_env *e)
{
	e->input.up = 0;
	e->input.down = 0;
	e->input.left = 0;
	e->input.right = 0;
	e->img = NULL;
	e->time = 0;
	e->pos_x = 4;
	e->pos_y = 4;
	e->nb_wall = 0;
	e->nb_square = 0;
	e->nb_line = 0;
	e->mv_speed = 0;
	e->rt_speed = 0;
	e->shift_key = 0;
	e->troll_mode = 0;
	e->pause = 0;
	e->fps = 1;
	e->controls = 1;
	e->degrad_color_1 = 0.0;
	e->degrad_color_2 = 0.0;
	e->degrad_color_3 = 0.0;
	e->dir_x = 1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
}

void				ft_get_color(int red, int green, int blue, t_color *color)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

void				ft_fill_paint(t_paint *paint)
{
	ft_get_color(17, 55, 29, &(paint->north));
	ft_get_color(129, 92, 65, &(paint->south));
	ft_get_color(43, 97, 1, &(paint->west));
	ft_get_color(18, 130, 122, &(paint->east));
}

void				ft_init_draw(t_env *e)
{
	e->draw.camera = 2 * e->draw.x / ((double)WIN_WIDTH) - 1;
	e->draw.ray_pos_x = e->pos_x;
	e->draw.ray_pos_y = e->pos_y;
	e->draw.ray_dir_x = e->dir_x + e->plane_x * e->draw.camera;
	e->draw.ray_dir_y = e->dir_y + e->plane_y * e->draw.camera;
	e->draw.map_x = ((int)e->draw.ray_pos_x);
	e->draw.map_y = ((int)e->draw.ray_pos_y);
	e->draw.delta_dist_x = sqrt(1 + (e->draw.ray_dir_y * e->draw.ray_dir_y) /
		(e->draw.ray_dir_x * e->draw.ray_dir_x));
	e->draw.delta_dist_y = sqrt(1 + (e->draw.ray_dir_x * e->draw.ray_dir_x) /
		(e->draw.ray_dir_y * e->draw.ray_dir_y));
	e->draw.hit = 0;
}

void				ft_init_move(t_env *e)
{
	e->old_time = e->time;
	gettimeofday(&(e->move.time), NULL);
	e->move.usec = e->move.time.tv_usec;
	e->move.sec = e->move.time.tv_sec;
	e->time = ((e->move.sec) * 1000 + e->move.usec / 1000.0) + 0.5;
	e->frame_time = (e->time - e->old_time);
	e->move.move_speed = e->frame_time * 0.005 + e->mv_speed;
	e->move.rot_speed = e->frame_time * 0.003 + e->rt_speed;
}
