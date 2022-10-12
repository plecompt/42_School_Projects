/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:53:13 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:53:14 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_mandelbrot_set_position(int width, int height, t_env *env)
{
	double			c_re;
	double			c_im;
	double			old_re;
	double			old_im;
	double			new_re;

	env->res_mandel = 0;
	old_re = 0;
	old_im = 0;
	c_re = 1.5 * (width - MANBROT_WIDTH / 2) / \
		(0.5 * env->pos.zoom_m * MANBROT_WIDTH) +
		env->pos.x_mandelbrot;
	c_im = (height - MANBROT_HEIGHT / 2) / \
		(0.5 * env->pos.zoom_m * MANBROT_HEIGHT) +
		env->pos.y_mandelbrot;
	while (((old_re * old_re) + (old_im * old_im)) < 4 &&
		env->res_mandel < env->max_iter_mandelbrot)
	{
		new_re = (old_re * old_re) - (old_im * old_im) + c_re;
		old_im = (2 * old_re * old_im) + c_im;
		old_re = new_re;
		env->res_mandel++;
	}
	return (env->res_mandel);
}

void			ft_calc_mandelbrot(t_env *env)
{
	int width;
	int height;
	int result;

	height = 0;
	result = 0;
	while (height < MANBROT_HEIGHT)
	{
		width = 0;
		while (width < MANBROT_WIDTH)
		{
			result = ft_mandelbrot_set_position(width, height, env);
			ft_set_color_m(width, height, result, env);
			width++;
		}
		height++;
	}
}

int				key_hook_mandelbrot(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win_mandelbrot);
		env->mandelbrot_is_destroyed = 1;
		env->number_of_fractal_still_alive--;
		return (0);
	}
	keycode == 126 ? env->pos.y_mandelbrot -= 0.006 / env->pos.zoom_m : 0;
	keycode == 125 ? env->pos.y_mandelbrot += 0.006 / env->pos.zoom_m : 0;
	keycode == 123 ? env->pos.x_mandelbrot -= 0.006 / env->pos.zoom_m : 0;
	keycode == 124 ? env->pos.x_mandelbrot += 0.006 / env->pos.zoom_m : 0;
	keycode == 67 ? env->max_iter_mandelbrot += 5 : 0;
	keycode == 75 ? env->max_iter_mandelbrot -= 5 : 0;
	keycode == 78 ? env->pos.zoom_m /= 1.04 : 0;
	keycode == 69 ? env->pos.zoom_m *= 1.04 : 0;
	if (keycode == 51)
	{
		env->pos.zoom_m = 0.8;
		env->pos.x_mandelbrot = 0.0;
		env->pos.move_x_mandelbrot = -0.71;
		env->pos.move_y_mandelbrot = 0.33;
	}
	env_change_mandelbrot(keycode, env);
	return (0);
}

int				mouse_hook_mandelbrot(int key, int x, int y, t_env *env)
{
	if (key == 1)
	{
		env->pos.x_mandelbrot +=
		((x - (MANBROT_WIDTH / 2)) * 0.003) / env->pos.zoom_m;
		env->pos.y_mandelbrot +=
		((y - (MANBROT_HEIGHT / 2)) * 0.003) / env->pos.zoom_m;
	}
	if (key == 4)
	{
		env->pos.x_mandelbrot +=
		((x - (MANBROT_WIDTH / 2)) * 0.003) / env->pos.zoom_m;
		env->pos.y_mandelbrot +=
		((y - (MANBROT_HEIGHT / 2)) * 0.003) / env->pos.zoom_m;
		env->pos.zoom_m *= pow(1.001, 100);
	}
	if (key == 5)
	{
		env->pos.x_mandelbrot +=
		((x - (MANBROT_WIDTH / 2)) * 0.003) / env->pos.zoom_m;
		env->pos.y_mandelbrot +=
		((y - (MANBROT_HEIGHT / 2)) * 0.003) / env->pos.zoom_m;
		env->pos.zoom_m /= pow(1.001, 100);
	}
	return (0);
}
