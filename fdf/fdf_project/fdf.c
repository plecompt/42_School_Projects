/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 23:32:49 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/16 15:51:49 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env			*ft_init_env(void)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->nb = 0;
	e->move_hori = 2;
	e->move_verti = 4;
	e->height = 3;
	e->zoom_x = 35;
	e->zoom_y = 20;
	e->color_mod = 1;
	return (e);
}

int				key_hook(int keycode, t_env *e)
{
	(keycode == 65362 ? e->move_verti += 1 : 0);
	(keycode == 65364 ? e->move_verti -= 1 : 0);
	(keycode == 65361 ? e->move_hori += 1 : 0);
	((keycode == 65363 && e->move_hori != 1) ? e->move_hori -= 1 : 0);
	(keycode == 65307 ? exit(0) : 0);
	(keycode == 65451 ? e->height += 1 : 0);
	(keycode == 65453 ? e->height -= 1 : 0);
	(keycode == 99 ? e->color_mod += 1 : 0);
	(keycode == 112 ? e->zoom_x *= 1.25, e->zoom_y *= 1.25 : 0);
	(keycode == 109 ? e->zoom_x *= 0.75, e->zoom_y *= 0.75 : 0);
	expose_hook(e);
	return (0);
}

int				expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	print_fdf(*e);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		*e;
	int			fd;

	((fd = open(av[1], O_RDONLY)) == -1 ? ft_putstr("Failed to open"),
	close (fd), exit(0) : 0);
	(!(e = ft_init_env()) ? exit(0) : 0);
	(!(e->mlx = mlx_init()) ? exit(0) : 0);
	((ac > 2) ? ft_putstr("Too many arguments...\n"), exit(0) : 0);
	e->av = av;
	ft_init_env();
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, LENGTH, WIDTH, "FdF");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
