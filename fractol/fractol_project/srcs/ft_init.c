/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:42 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:52:43 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_exit(-1);
	env->number_of_fractal_still_alive += env->julia == 1 ? 1 : 0;
	env->number_of_fractal_still_alive += env->mandelbrot == 1 ? 1 : 0;
	env->number_of_fractal_still_alive += env->tree == 1 ? 1 : 0;
	if (env->julia == 1)
	{
		env->win_julia =
		mlx_new_window(env->mlx, JULIA_WIDTH, JULIA_HEIGHT, "Julia");
		env->img_julia =
		mlx_new_image(env->mlx, JULIA_WIDTH, JULIA_HEIGHT);
	}
	if (env->mandelbrot == 1)
	{
		env->win_mandelbrot =
		mlx_new_window(env->mlx, MANBROT_WIDTH, MANBROT_HEIGHT, "Mandelbrot");
		env->img_mandelbrot =
		mlx_new_image(env->mlx, MANBROT_WIDTH, MANBROT_HEIGHT);
	}
	if (env->tree == 1)
	{
		env->win_tree =
		mlx_new_window(env->mlx, TREE_WIDTH, TREE_HEIGHT, "Tree");
		env->img_tree = mlx_new_image(env->mlx, TREE_WIDTH, TREE_HEIGHT);
	}
}

void		ft_init_env(t_env *env)
{
	env->number_of_fractal_still_alive = 0;
	env->julia_is_destroyed = 0;
	env->mandelbrot_is_destroyed = 0;
	env->tree_is_destroyed = 0;
	env->list_arg = NULL;
	env->julia = 0;
	env->mandelbrot = 0;
	env->tree = 0;
	env->res_mandel = 0;
	env->res_julia = 0;
}

void		ft_init_env_for_julia(t_env *env)
{
	env->handle_red_julia = 0;
	env->handle_green_julia = 0;
	env->handle_blue_julia = 0;
	env->max_iter_julia = 85;
	env->pos.zoom_julia = 0.8;
	env->pos.x_julia = 0.0;
	env->pos.y_julia = 0.0;
	env->pos.move_x_julia = -0.71;
	env->pos.move_y_julia = 0.33;
	env->stop_time_julia = 0;
}

void		ft_init_env_for_mandelbrot(t_env *env)
{
	env->handle_red_mandelbrot = 0;
	env->handle_green_mandelbrot = 0;
	env->handle_blue_mandelbrot = 0;
	env->max_iter_mandelbrot = 85;
	env->pos.zoom_m = 0.8;
	env->pos.x_mandelbrot = 0.0;
	env->pos.y_mandelbrot = 0.0;
	env->pos.move_x_mandelbrot = -0.71;
	env->pos.move_y_mandelbrot = 0.33;
	env->stop_time_mandelbrot = 0;
}

void		ft_init_env_for_tree(t_env *env)
{
	env->red_tree = 0;
	env->green_tree = 0XFF;
	env->blue_tree = 0;
	env->start_x_tree = TREE_WIDTH / 2;
	env->start_y_tree = TREE_HEIGHT;
	env->angle_tree = M_PI / 2;
	env->nbr_branch = 5;
	env->nb_branch_total = 32 - 1;
	env->nb_branch_draw = 0;
	env->density = 0;
	env->nb_of_pixel = 0;
	env->stop_time_tree = 0;
	env->display_debug = 1;
	env->value = 100;
	env->size_grow = 2;
}
