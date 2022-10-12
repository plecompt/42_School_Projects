/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:24 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:16:25 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			put_pixel_to_img(t_env *e, int x, int y, t_color *color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		i;

	data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	i = x * 4 + y * sizeline;
	data[i + 2] = mlx_get_color_value(e->mlx, color->red);
	data[i + 1] = mlx_get_color_value(e->mlx, color->green);
	data[i] = mlx_get_color_value(e->mlx, color->blue);
}

static void		move(t_env *e)
{
	ft_init_move(e);
	if (e->input.up)
	{
		if (e->world_map[(int)(e->pos_x + e->dir_x * e->move.move_speed)]
		[(int)(e->pos_y)] == 0)
			e->pos_x += e->dir_x * e->move.move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y * \
				e->move.move_speed)] == 0)
			e->pos_y += e->dir_y * e->move.move_speed;
	}
	if (e->input.down)
	{
		if (e->world_map[(int)(e->pos_x - e->dir_x * e->move.move_speed)]
		[(int)(e->pos_y)] == 0)
			e->pos_x -= e->dir_x * e->move.move_speed;
		if (e->world_map[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y * \
		e->move.move_speed)] == 0)
			e->pos_y -= e->dir_y * e->move.move_speed;
	}
	if (e->input.left)
		ft_rotate_left(e);
	if (e->input.right)
		ft_rotate_right(e);
}

static void		choose_color(t_env *e, int x, int start, int end)
{
	t_color		color2;
	int			y;

	y = 0;
	ft_calculate_degrade(e);
	while (y < start)
	{
		ft_get_color(77 + (y * e->degrad_color_1), 121 +
			(y * e->degrad_color_2), 148 - (y * e->degrad_color_3), &color2);
		put_pixel_to_img(e, x, y, &color2);
		y++;
	}
	while (start < end)
	{
		e->troll_mode == 1 ? put_pixel_to_img(e, x + (rand() % (-1 - 1)) + 1,
			start, &(e->draw.color)) :
			put_pixel_to_img(e, x, start, &(e->draw.color));
		start++;
	}
	while (start < WIN_HEIGHT)
	{
		ft_draw_floor(e, x, start);
		start++;
	}
}

static void		jump_to_next_square(t_env *e)
{
	if (e->draw.side_dist_x < e->draw.side_dist_y)
	{
		e->draw.side_dist_x += e->draw.delta_dist_x;
		e->draw.map_x += e->draw.step_x;
		e->draw.side = 0;
	}
	else
	{
		e->draw.side_dist_y += e->draw.delta_dist_y;
		e->draw.map_y += e->draw.step_y;
		e->draw.side = 1;
	}
}

void			ft_raycasting(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->draw.x = 0;
	while (e->draw.x < WIN_WIDTH)
	{
		ft_init_draw(e);
		ft_calc_steps_and_side_dist(e);
		while (e->draw.hit == 0)
		{
			jump_to_next_square(e);
			if (e->world_map[e->draw.map_x][e->draw.map_y] > 0)
				e->draw.hit = 1;
		}
		ft_calc_wall_dist(e);
		ft_calc_line_height(e);
		choose_color(e, e->draw.x, e->draw.draw_start, \
			e->draw.draw_end);
		e->draw.x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_display(e);
	move(e);
}
