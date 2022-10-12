/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:10 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:52:13 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		put_pixel_to_img_mandelbrot(t_env *env)
{
	int		i;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

	data = mlx_get_data_addr(env->img_mandelbrot, &bpp, &size_line, &endian);
	if (env->color.x_mandelbrot > 0 && env->color.y_mandelbrot > 0 && \
	env->color.x_mandelbrot <
	MANBROT_WIDTH && env->color.y_mandelbrot < MANBROT_HEIGHT)
	{
		i = env->color.x_mandelbrot * 4 + env->color.y_mandelbrot * size_line;
		if (endian)
		{
			data[i + 2] = mlx_get_color_value(env->mlx, env->color.red_m);
			data[i + 1] = mlx_get_color_value(env->mlx, env->color.green_m);
			data[i] = mlx_get_color_value(env->mlx, env->color.blue_m);
		}
		else
		{
			data[i + 2] = mlx_get_color_value(env->mlx, env->color.blue_m);
			data[i + 1] = mlx_get_color_value(env->mlx, env->color.green_m);
			data[i] = mlx_get_color_value(env->mlx, env->color.red_m);
		}
	}
}

static void		get_color_mandelbrot(int result, int max_iter, t_env *env)
{
	int		start_color;
	int		augment;

	start_color = 0x000000;
	augment = round(255 * (round(result * 150 / max_iter) / 100));
	if (env->handle_red_mandelbrot == 1)
		env->color.red_m = 0;
	else
		env->color.red_m = (start_color >> 16) + augment;
	if (env->handle_green_mandelbrot == 1)
		env->color.green_m = 0;
	else
		env->color.green_m = ((start_color >> 8) & 0xFF) + augment;
	if (env->handle_blue_mandelbrot == 1)
		env->color.blue_m = 0;
	else
		env->color.blue_m = (start_color & 0xFF) + augment;
}

static void		palette_mandelbrot(int result, t_env *env)
{
	if (result > env->max_iter_mandelbrot - 30 &&
		result < env->max_iter_mandelbrot \
	&& (env->mandelbrot == 1))
	{
		env->color.green_m = result * 4;
		env->color.blue_m = result * 4;
		env->color.blue_m =
		env->color.blue_m > 255 ? 255 : env->color.blue_m;
		env->color.green_m =
		env->color.green_m > 255 ? 255 : env->color.green_m;
	}
	else if (result != env->max_iter_mandelbrot)
	{
		get_color_mandelbrot(result, env->max_iter_mandelbrot, env);
		env->color.blue_m = env->color.blue_m > 255 ?
		255 : env->color.blue_m;
		env->color.green_m = env->color.green_m > 255 ?
		255 : env->color.green_m;
	}
}

void			ft_set_color_m(int width, int height, int result, t_env *env)
{
	ft_bzero(&(env->color), sizeof(t_color));
	env->color.x_mandelbrot = width;
	env->color.y_mandelbrot = height;
	palette_mandelbrot(result, env);
	put_pixel_to_img_mandelbrot(env);
}

void			env_change_mandelbrot(int key, t_env *env)
{
	if (key == 18)
		env->handle_red_mandelbrot = !env->handle_red_mandelbrot ? 1 : 0;
	if (key == 19)
		env->handle_green_mandelbrot = !env->handle_green_mandelbrot ? 1 : 0;
	if (key == 20)
		env->handle_blue_mandelbrot = !env->handle_blue_mandelbrot ? 1 : 0;
	if (key == 49)
		env->stop_time_mandelbrot = env->stop_time_mandelbrot == 0 ? 1 : 0;
}
