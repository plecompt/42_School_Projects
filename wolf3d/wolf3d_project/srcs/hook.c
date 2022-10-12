/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:58:42 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 12:59:04 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_reset_value(t_env *e)
{
	e->troll_mode = 0;
	e->mv_speed = 0;
	e->rt_speed = 0;
	e->input.left = 0;
}

void	ft_demo(t_env *e)
{
	if (e->input.left == 0)
	{
		e->rt_speed = 0;
		e->rt_speed -= 0.08;
		e->input.left = 1;
	}
	else if (e->input.left == 1)
	{
		e->input.left = 0;
		ft_reset_value(e);
	}
}

void	ft_key_hook_part2(int key, t_env *e)
{
	if (key == RESTORE && e->pause == 0)
		ft_reset_value(e);
	if (key == PAUSE)
		e->pause = e->pause == 1 ? 0 : 1;
	if (key == TROLL && e->troll_mode == 1 && e->pause == 0)
		e->troll_mode = 0;
	else if (key == TROLL && e->troll_mode == 0 && e->pause == 0)
		e->troll_mode = 1;
	if (key == DEMO && e->pause == 0)
		ft_demo(e);
	if (key == CTRL && e->pause == 0)
		e->controls = e->controls == 1 ? 0 : 1;
	if (key == TAB && e->pause == 0)
		e->fps = e->fps == 1 ? 0 : 1;
}

int		key_hook(int key, t_env *e)
{
	if (key == UP || key == W)
		e->input.up = 1;
	if (key == DOWN || key == S)
		e->input.down = 1;
	if (key == LEFT || key == A)
		e->input.left = 1;
	if (key == RIGHT || key == D)
		e->input.right = 1;
	if (key == SHIFT && e->shift_key == 1 && e->pause == 0)
	{
		e->mv_speed = 0;
		e->shift_key = 0;
	}
	else if (key == SHIFT && e->shift_key == 0 && e->pause == 0)
	{
		e->mv_speed = 0.2;
		e->shift_key = 1;
	}
	if (key == PLUS && e->rt_speed <= 0.9 && e->pause == 0)
		e->rt_speed += 0.1;
	if (key == MINUS && e->rt_speed >= -0.9 && e->pause == 0)
		e->rt_speed -= 0.1;
	ft_key_hook_part2(key, e);
	return (1);
}

int		key_hook_r(int key, t_env *e)
{
	if (key == UP || key == W)
		e->input.up = 0;
	if (key == DOWN || key == S)
		e->input.down = 0;
	if (key == LEFT || key == A)
		e->input.left = 0;
	if (key == RIGHT || key == D)
		e->input.right = 0;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	return (1);
}
