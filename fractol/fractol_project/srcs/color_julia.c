/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:51:47 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:51:51 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		put_pixel_to_img_julia(t_env *env)
{
	int		i;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

	data = mlx_get_data_addr(env->img_julia, &bpp, &size_line, &endian);
	if (env->color.x_julia > 0 && env->color.y_julia > 0 && \
	env->color.x_julia < JULIA_WIDTH && env->color.y_julia < JULIA_HEIGHT)
	{
		i = env->color.x_julia * 4 + env->color.y_julia * size_line;
		if (endian)
		{
			data[i + 2] = mlx_get_color_value(env->mlx, env->color.red_julia);
			data[i + 1] = mlx_get_color_value(env->mlx, env->color.green_julia);
			data[i] = mlx_get_color_value(env->mlx, env->color.blue_julia);
		}
		else
		{
			data[i + 2] = mlx_get_color_value(env->mlx, env->color.blue_julia);
			data[i + 1] = mlx_get_color_value(env->mlx, env->color.green_julia);
			data[i] = mlx_get_color_value(env->mlx, env->color.red_julia);
		}
	}
}

static void		get_color_julia(int result, int max_iter_julia, t_env *env)
{
	int			start_color;
	int			augment;

	start_color = 0x000000;
	augment = round(255 * (round(result * 150 / max_iter_julia) / 100));
	if (env->handle_red_julia == 1)
		env->color.red_julia = 0;
	else
		env->color.red_julia = (start_color >> 16) + augment;
	if (env->handle_green_julia == 1)
		env->color.green_julia = 0;
	else
		env->color.green_julia = ((start_color >> 8) & 0xFF) + augment;
	if (env->handle_blue_julia == 1)
		env->color.blue_julia = 0;
	else
		env->color.blue_julia = (start_color & 0xFF) + augment;
}

static void		palette_julia(int result, t_env *env)
{
	if (result > env->max_iter_julia - 30 && result <= env->max_iter_julia \
	&& (env->julia == 1))
	{
		env->color.green_julia = result * 3;
		env->color.blue_julia = result * 3;
		env->color.blue_julia =
		env->color.blue_julia > 255 ? 255 : env->color.blue_julia;
		env->color.green_julia =
		env->color.green_julia > 255 ? 255 : env->color.green_julia;
	}
	else if (result != env->max_iter_julia)
	{
		get_color_julia(result, env->max_iter_julia, env);
		env->color.blue_julia =
		env->color.blue_julia > 255 ? 255 : env->color.blue_julia;
		env->color.green_julia =
		env->color.green_julia > 255 ? 255 : env->color.green_julia;
	}
}

void			ft_set_color_jul(int width, int height, int result, t_env *env)
{
	ft_bzero(&(env->color), sizeof(t_color));
	env->color.x_julia = width;
	env->color.y_julia = height;
	palette_julia(result, env);
	put_pixel_to_img_julia(env);
}

void			env_change_julia(int key, t_env *env)
{
	if (key == 18)
		env->handle_red_julia = !env->handle_red_julia ? 1 : 0;
	if (key == 19)
		env->handle_green_julia = !env->handle_green_julia ? 1 : 0;
	if (key == 20)
		env->handle_blue_julia = !env->handle_blue_julia ? 1 : 0;
	if (key == 49)
		env->stop_time_julia = env->stop_time_julia == 0 ? 1 : 0;
}
