/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:14 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:16:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		mouse_hook(void)
{
	exit(0);
	return (1);
}

static void		ft_check_last(t_env *e)
{
	if (e->nb_wall != (e->nb_line * 2 + ((e->nb_line - 2) * 2)))
		ft_putstr_color("Invalid map\n", 1, 2);
	if (e->nb_wall != (e->nb_line * 2 + ((e->nb_line - 2) * 2)))
		exit(0);
}

static void		ft_check_map_first(t_env *e)
{
	if (e->nb_line * e->nb_line != e->nb_square || e->nb_square < 8)
		ft_putstr_color("Invalid map\n", 1, 2);
	if (e->nb_line * e->nb_line != e->nb_square)
		exit(0);
}

static void		ft_check_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_check_map_first(e);
	while (i < e->nb_line)
	{
		if (i == 0 || i == e->nb_line - 1)
		{
			while (j <= e->nb_line - 1)
			{
				if (e->world_map[i][j] >= 1)
					e->nb_wall++;
				j++;
			}
			j = 0;
		}
		else if (e->world_map[i][0] >= 1 &&
			e->world_map[i][e->nb_line - 1] >= 1)
			e->nb_wall += 2;
		i++;
	}
	ft_check_last(e);
}

int				main(void)
{
	t_env	e;

	ft_init_env(&e);
	ft_fill_paint(&(e.paint));
	ft_init_map(&e);
	ft_check_map(&e);
	if (!(e.mlx = mlx_init()))
	{
		ft_putstr_color("Nop, nop c'est propre <3\n", 1, 2);
		return (-1);
	}
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	mlx_hook(e.win, 2, 1L << 0, &key_hook, &e);
	mlx_hook(e.win, 3, 1L << 1, &key_hook_r, &e);
	mlx_hook(e.win, 17, (1L << 17), &mouse_hook, &e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
