/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:46 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:52:47 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			loop_hook_part_2(t_env *env)
{
	int		tab_coord[2];

	if (env->tree && env->tree_is_destroyed == 0)
	{
		mlx_destroy_image(env->mlx, env->img_tree);
		env->nb_of_pixel = 0;
		env->img_tree = mlx_new_image(env->mlx, TREE_WIDTH, TREE_HEIGHT);
		tab_coord[0] = env->start_x_tree;
		tab_coord[1] = env->start_y_tree;
		ft_calc_tree(env, tab_coord, env->angle_tree, env->nbr_branch);
		mlx_put_image_to_window(env->mlx, env->win_tree, env->img_tree, 0, 0);
		env->display_debug == 1 ? ft_display_debug_tree(env) : 0;
	}
}

static int			loop_hook(t_env *env)
{
	if (env->number_of_fractal_still_alive == 0)
		ft_exit(0);
	if (env->julia && env->julia_is_destroyed == 0)
	{
		ft_calc_julia(env);
		mlx_put_image_to_window(env->mlx, env->win_julia, env->img_julia, 0, 0);
	}
	if (env->mandelbrot && env->mandelbrot_is_destroyed == 0)
	{
		ft_calc_mandelbrot(env);
		mlx_put_image_to_window(env->mlx,
			env->win_mandelbrot, env->img_mandelbrot, 0, 0);
	}
	loop_hook_part_2(env);
	return (0);
}

void				ft_run(t_env *env)
{
	if (env->julia == 1 && env->julia_is_destroyed == 0)
	{
		mlx_hook(env->win_julia, 2, 1 << 0, key_hook_julia, env);
		mlx_mouse_hook(env->win_julia, mouse_hook_julia, env);
		mlx_hook(env->win_julia, 6, 1 << 6, move_hook_julia, env);
	}
	if (env->mandelbrot == 1 && env->mandelbrot_is_destroyed == 0)
	{
		mlx_hook(env->win_mandelbrot, 2, 1 << 0, key_hook_mandelbrot, env);
		mlx_mouse_hook(env->win_mandelbrot, mouse_hook_mandelbrot, env);
	}
	if (env->tree == 1 && env->tree_is_destroyed == 0)
	{
		mlx_hook(env->win_tree, 2, 1 << 0, key_hook_tree, env);
		mlx_mouse_hook(env->win_tree, mouse_hook_tree, env);
		mlx_hook(env->win_tree, 6, 1 << 6, move_hook_tree, env);
	}
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
}
