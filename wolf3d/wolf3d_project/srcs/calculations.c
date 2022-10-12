/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:15:51 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:15:52 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw_floor(t_env *e, int x, int start)
{
	ft_calculate_degrade_floor(e);
	ft_get_color(15 - (start * e->degrad_color_1), 50 +
		(start * e->degrad_color_2), 60 +
		(start * e->degrad_color_3), &(e->draw.color));
	put_pixel_to_img(e, x, start, &(e->draw.color));
}

void		ft_calc_steps_and_side_dist(t_env *e)
{
	if (e->draw.ray_dir_x < 0)
	{
		e->draw.step_x = -1;
		e->draw.side_dist_x = (e->draw.ray_pos_x - e->draw.map_x) * \
			e->draw.delta_dist_x;
	}
	else
	{
		e->draw.step_x = 1;
		e->draw.side_dist_x = (e->draw.map_x + 1.0 - e->draw.ray_pos_x) * \
			e->draw.delta_dist_x;
	}
	if (e->draw.ray_dir_y < 0)
	{
		e->draw.step_y = -1;
		e->draw.side_dist_y = (e->draw.ray_pos_y - e->draw.map_y) *
			e->draw.delta_dist_y;
	}
	else
	{
		e->draw.step_y = 1;
		e->draw.side_dist_y = (e->draw.map_y + 1.0 - e->draw.ray_pos_y) *
			e->draw.delta_dist_y;
	}
}

void		ft_calc_wall_dist(t_env *e)
{
	if (e->draw.side == 0)
		e->draw.perp_wall_dist = fabs((e->draw.map_x - e->draw.ray_pos_x + \
			(1 - e->draw.step_x) / 2) / e->draw.ray_dir_x);
	else
		e->draw.perp_wall_dist = fabs((e->draw.map_y - e->draw.ray_pos_y + \
			(1 - e->draw.step_y) / 2) / e->draw.ray_dir_y);
}

void		ft_calc_line_height(t_env *e)
{
	e->draw.line_height = fabs((WIN_HEIGHT / e->draw.perp_wall_dist));
	e->draw.draw_start = -(e->draw.line_height) / 2 + WIN_HEIGHT / 2;
	if (e->draw.draw_start < 0)
		e->draw.draw_start = 0;
	e->draw.draw_end = e->draw.line_height / 2 + WIN_HEIGHT / 2;
	if (e->draw.draw_end >= WIN_HEIGHT)
		e->draw.draw_end = WIN_HEIGHT - 1;
	if (e->draw.side == 0 && e->draw.ray_dir_x > 0)
		e->draw.color = e->paint.north;
	else if (e->draw.side == 0 && e->draw.ray_dir_x < 0)
		e->draw.color = e->paint.south;
	else if (e->draw.side == 1 && e->draw.ray_dir_y > 0)
		e->draw.color = e->paint.east;
	else
		e->draw.color = e->paint.west;
}
