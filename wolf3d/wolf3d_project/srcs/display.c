/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:56:30 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 12:56:42 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_controls(t_env *e, int pos)
{
	if (e->controls == 1)
	{
		mlx_string_put(e->mlx, e->win, pos, 20, C,
			"---------Control keys---------");
		mlx_string_put(e->mlx, e->win, pos, 35, C,
			"W,A,S,D or Arrow keys to move");
		mlx_string_put(e->mlx, e->win, pos, 50, C,
			"R to reset");
		mlx_string_put(e->mlx, e->win, pos, 65, C,
			"P to pause");
		mlx_string_put(e->mlx, e->win, pos, 80, C,
			"T to activate the troll mode");
		mlx_string_put(e->mlx, e->win, pos, 95, C,
			"Shift to sprint");
		mlx_string_put(e->mlx, e->win, pos, 110, C,
			"Command to infitine rotation");
		mlx_string_put(e->mlx, e->win, pos, 125, C,
			"+ or - to change the speed or rotation");
		mlx_string_put(e->mlx, e->win, pos, 140, C,
			"CTRL to show/hide controls");
		mlx_string_put(e->mlx, e->win, pos, 155, C,
			"TAB to show/hide FPS");
		mlx_string_put(e->mlx, e->win, pos, 170, C,
			"ESC to quit wolf3D");
	}
}

int				loop_hook(t_env *e)
{
	if (e->img != NULL && e->pause == 0)
		mlx_destroy_image(e->mlx, e->img);
	if (e->pause == 0)
		ft_raycasting(e);
	return (1);
}

void			ft_display(t_env *e)
{
	char	*tmp;
	int		pos;

	pos = WIN_WIDTH - 400;
	tmp = ft_itoa((int)(1 / (e->frame_time / 1000)));
	if (e->fps == 1)
		mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF, "FPS : ");
	if (e->fps == 1)
		mlx_string_put(e->mlx, e->win, 80, 20, 0xFFFFFF, tmp);
	ft_controls(e, pos);
	free(tmp);
}

void			ft_calculate_degrade(t_env *e)
{
	e->degrad_color_1 = (double)98 / ((WIN_HEIGHT + 1) * 0.80);
	e->degrad_color_2 = (double)35 / ((WIN_HEIGHT + 1) * 0.80);
	e->degrad_color_3 = (double)6 / ((WIN_HEIGHT + 1) * 0.80);
}

void			ft_calculate_degrade_floor(t_env *e)
{
	e->degrad_color_1 = (double)15 / (WIN_HEIGHT);
	e->degrad_color_2 = (double)112 / (WIN_HEIGHT);
	e->degrad_color_3 = (double)184 / (WIN_HEIGHT);
}
