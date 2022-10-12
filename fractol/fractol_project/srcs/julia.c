/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:53:08 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:53:09 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_julia_set_position(int width, int height, t_env *env)
{
	double		c_re;
	double		c_im;
	double		old_re;
	double		old_im;
	double		new_re;

	env->res_julia = 0;
	old_re = 1.5 * (width - JULIA_WIDTH / 2) / \
		(0.5 * env->pos.zoom_julia * JULIA_WIDTH) + env->pos.x_julia;
	old_im = (height - JULIA_HEIGHT / 2) / \
		(0.5 * env->pos.zoom_julia * JULIA_HEIGHT) + env->pos.y_julia;
	c_re = env->pos.move_x_julia;
	c_im = env->pos.move_y_julia;
	while (((old_re * old_re) + (old_im * old_im)) <
		4 && env->res_julia < env->max_iter_julia)
	{
		new_re = (old_re * old_re) - (old_im * old_im) + c_re;
		old_im = (2 * old_re * old_im) + c_im;
		old_re = new_re;
		env->res_julia++;
	}
	return (env->res_julia);
}

void			ft_calc_julia(t_env *env)
{
	int width;
	int height;
	int result;

	height = 0;
	result = 0;
	while (height < JULIA_HEIGHT)
	{
		width = 0;
		while (width < JULIA_WIDTH)
		{
			result = ft_julia_set_position(width, height, env);
			ft_set_color_jul(width, height, result, env);
			width++;
		}
		height++;
	}
}

int				key_hook_julia(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win_julia);
		env->julia_is_destroyed = 1;
		env->number_of_fractal_still_alive--;
		return (0);
	}
	keycode == 126 ? env->pos.y_julia -= 0.006 / env->pos.zoom_julia : 0;
	keycode == 125 ? env->pos.y_julia += 0.006 / env->pos.zoom_julia : 0;
	keycode == 123 ? env->pos.x_julia -= 0.006 / env->pos.zoom_julia : 0;
	keycode == 124 ? env->pos.x_julia += 0.006 / env->pos.zoom_julia : 0;
	keycode == 67 ? env->max_iter_julia += 5 : 0;
	keycode == 75 ? env->max_iter_julia -= 5 : 0;
	keycode == 78 ? env->pos.zoom_julia /= 1.04 : 0;
	keycode == 69 ? env->pos.zoom_julia *= 1.04 : 0;
	if (keycode == 51)
	{
		env->pos.zoom_julia = 0.8;
		env->pos.x_julia = 0.0;
		env->pos.move_x_julia = -0.71;
		env->pos.move_y_julia = 0.33;
	}
	env_change_julia(keycode, env);
	return (0);
}

int				move_hook_julia(int x, int y, t_env *e)
{
	static int		pos[2] = {0, 0};

	if (e->stop_time_julia == 0)
	{
		if (x > pos[0])
			e->pos.move_x_julia += 0.009;
		if (x < pos[0])
			e->pos.move_x_julia -= 0.009;
		if (y > pos[1])
			e->pos.move_y_julia += 0.009;
		if (y < pos[1])
			e->pos.move_y_julia -= 0.009;
		pos[0] = x;
		pos[1] = y;
	}
	return (1);
}

int				mouse_hook_julia(int key, int x, int y, t_env *env)
{
	if (key == 1)
	{
		env->pos.x_julia +=
		((x - (JULIA_WIDTH / 2)) * 0.003) / env->pos.zoom_julia;
		env->pos.y_julia +=
		((y - (JULIA_HEIGHT / 2)) * 0.003) / env->pos.zoom_julia;
	}
	if (key == 4)
	{
		env->pos.x_julia +=
		((x - (JULIA_WIDTH / 2)) * 0.001) / env->pos.zoom_julia;
		env->pos.y_julia +=
		((y - (JULIA_HEIGHT / 2)) * 0.001) / env->pos.zoom_julia;
		env->pos.zoom_julia *= pow(1.001, 100);
	}
	if (key == 5)
	{
		env->pos.x_julia +=
		((x - (JULIA_WIDTH / 2)) * 0.001) / env->pos.zoom_julia;
		env->pos.y_julia +=
		((y - (JULIA_HEIGHT / 2)) * 0.001) / env->pos.zoom_julia;
		env->pos.zoom_julia /= pow(1.001, 100);
	}
	return (0);
}
