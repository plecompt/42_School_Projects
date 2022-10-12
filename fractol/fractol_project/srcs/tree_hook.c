/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:53:03 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:53:04 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			env_change_tree(int key, t_env *env)
{
	if (key == 12 && env->red_tree <= 250)
		env->red_tree += 5;
	if (key == 0 && env->red_tree >= 5)
		env->red_tree -= 5;
	if (key == 13 && env->green_tree <= 250)
		env->green_tree += 5;
	if (key == 1 && env->green_tree >= 5)
		env->green_tree -= 5;
	if (key == 14 && env->blue_tree <= 250)
		env->blue_tree += 5;
	if (key == 2 && env->blue_tree >= 5)
		env->blue_tree -= 5;
	if (key == 49)
		env->stop_time_tree = env->stop_time_tree == 0 ? 1 : 0;
}

static void		key_hook_tree_2(int keycode, t_env *env)
{
	if (keycode == 51)
	{
		env->start_x_tree = TREE_WIDTH / 2;
		env->start_y_tree = TREE_HEIGHT;
		env->angle_tree = M_PI / 2;
		env->size_grow = 2;
		env->density = 0;
		env->nbr_branch = 5;
		env->value = 100;
	}
	if (keycode == 256)
		env->display_debug = env->display_debug == 1 ? 0 : 1;
	if (keycode == 69)
		env->nbr_branch += 1;
	if (keycode == 78 && env->nbr_branch > 0)
		env->nbr_branch -= 1;
	if (keycode == 75 && env->density > 0)
		env->density -= 1;
	if (keycode == 67)
		env->density += 1;
	env_change_tree(keycode, env);
}

int				key_hook_tree(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win_tree);
		env->tree_is_destroyed = 1;
		env->number_of_fractal_still_alive--;
		return (0);
	}
	keycode == 126 ? env->value += 0.025 : 0;
	keycode == 125 ? env->value -= 0.025 : 0;
	keycode == 123 ? env->angle_tree += 0.08 : 0;
	keycode == 124 ? env->angle_tree -= 0.08 : 0;
	keycode == 91 ? env->start_y_tree -= 5 : 0;
	keycode == 86 ? env->start_x_tree -= 5 : 0;
	keycode == 88 ? env->start_x_tree += 5 : 0;
	keycode == 84 ? env->start_y_tree += 5 : 0;
	keycode == 35 ? env->size_grow += 1 : 0;
	keycode == 46 ? env->size_grow -= 1 : 0;
	key_hook_tree_2(keycode, env);
	return (0);
}

int				mouse_hook_tree(int key, int x, int y, t_env *env)
{
	if (key == 1 || key == 2)
	{
		env->start_x_tree = x;
		env->start_y_tree = y;
	}
	if (key == 4)
	{
		env->start_x_tree -=
		((x - (TREE_WIDTH / 2)) * 0.05) * env->size_grow / 2;
		env->start_y_tree -=
		((y - (TREE_HEIGHT / 2)) * 0.05) * env->size_grow / 2;
		env->size_grow += 1;
	}
	if (key == 5)
	{
		env->start_x_tree -=
		((x - (TREE_WIDTH / 2)) * 0.05) * env->size_grow / 2;
		env->start_y_tree -=
		((y - (TREE_HEIGHT / 2)) * 0.05) * env->size_grow / 2;
		env->size_grow -= 1;
	}
	return (0);
}

int				move_hook_tree(int x, int y, t_env *env)
{
	static double		previous_pos[2] = {0, 0};

	if (env->stop_time_tree == 0)
	{
		if (x > previous_pos[0])
			env->angle_tree += 0.05;
		if (x < previous_pos[0])
			env->angle_tree -= 0.05;
		if (y > previous_pos[1])
			env->value += 0.01;
		if (y < previous_pos[1])
			env->value -= 0.01;
		previous_pos[0] = x;
		previous_pos[1] = y;
	}
	return (1);
}
